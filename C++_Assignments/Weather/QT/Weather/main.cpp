#include "mainwindow.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr< WethearAPI> WAPI=WethearAPI::InitializeandGetInstance();//singleton


    MainWindow w(WAPI);

    w.show();

    return a.exec();
}
