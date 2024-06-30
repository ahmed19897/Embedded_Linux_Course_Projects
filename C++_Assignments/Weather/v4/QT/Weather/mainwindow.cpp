#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <curl/curl.h>
#include <sstream>
#include <jsoncpp/json/json.h>
#include "jsonmanager.h"

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

    QString QCity=Getcity();
    std::string Current_City=QCity.toStdString();
    MyCurlManager.ChangeCity(Current_City);
    MyJsonManager.parseandsave(MyCurlManager.GetResponse());


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

