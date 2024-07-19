#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <curl/curl.h>
#include <sstream>
#include <jsoncpp/json/json.h>
#include "jsonmanager.h"
#include <ctime>
#include "cachemanager.h"

MainWindow::MainWindow(std::shared_ptr<IAPI> APIObjectReference,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)   
{
    ui->setupUi(this);
    City="Giza";
    MyCurlManager.SetAPIObject(APIObjectReference);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_WeatherButton_clicked()
{
    static JsonManager MyJsonManager;
    static CacheManager Cache;
    static time_t curr_time=time(0);
    static tm *tm_local = localtime(&curr_time);
    static constexpr int APICallThreshold=1;
    static int currenttime=tm_local->tm_hour;
    static int lastAPIcallTime=tm_local->tm_hour-APICallThreshold;
    static QString LastCity;


    QString QCity=Getcity();
    std::string Current_City=QCity.toStdString();
    MyCurlManager.ChangeCity(Current_City);
    if(currenttime>=lastAPIcallTime+APICallThreshold || (LastCity.compare(QCity)))//do a new call as long as the last call was 1 hour ago or longer
    {
        //do a new API call
        Cache.WriteCache(MyCurlManager.GetResponse());
        //save the last time we did the call
        tm_local = localtime(&curr_time);
        lastAPIcallTime=tm_local->tm_hour;
        LastCity=QCity;
    }
    else
    {
        //get the cashed value
    }
    MyJsonManager.parseandsave(Cache.GetCache());

    // Display the weather information
    QString cityQ=QString::fromStdString(MyJsonManager.GetCity());
    ui->textEdit->setPlainText(cityQ);

    std::string temperatures=std::to_string(MyJsonManager.GetTemp());
    QString temperatureQ=QString::fromStdString(temperatures);
    ui->textEdit2->setPlainText(temperatureQ);

    QString descriptionQ=QString::fromStdString(MyJsonManager.GetDescription());
    ui->textEdit3->setPlainText(descriptionQ);
}

QString MainWindow::Getcity(void)
{
    return City;
}

void MainWindow::on_CityList_currentTextChanged(const QString &arg1)
{
    QString t(arg1);
    City=t;
}

