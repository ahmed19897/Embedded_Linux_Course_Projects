#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "WethearAPI.h"
#include "CurlManager.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<IAPI> APIObjectReference,QWidget *parent = nullptr);
    ~MainWindow();
    QString Getcity(void);

private slots:
    void on_WeatherButton_clicked();
    void on_CityList_currentTextChanged(const QString &arg1);
    void on_CityList_2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    CurlManager MyCurlManager;
    QString City;
    int unitindex;

};
#endif // MAINWINDOW_H
