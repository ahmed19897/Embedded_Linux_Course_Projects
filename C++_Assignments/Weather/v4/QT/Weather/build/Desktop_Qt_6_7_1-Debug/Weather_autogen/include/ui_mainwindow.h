/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *WeatherButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QTextEdit *textEdit2;
    QTextEdit *textEdit3;
    QComboBox *CityList;
    QComboBox *CityList_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(827, 335);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        WeatherButton = new QPushButton(centralwidget);
        WeatherButton->setObjectName("WeatherButton");
        WeatherButton->setGeometry(QRect(90, 80, 231, 91));
        WeatherButton->setAutoFillBackground(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(560, 20, 258, 224));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        textEdit2 = new QTextEdit(layoutWidget);
        textEdit2->setObjectName("textEdit2");

        verticalLayout->addWidget(textEdit2);

        textEdit3 = new QTextEdit(layoutWidget);
        textEdit3->setObjectName("textEdit3");

        verticalLayout->addWidget(textEdit3);

        CityList = new QComboBox(centralwidget);
        CityList->addItem(QString());
        CityList->addItem(QString());
        CityList->addItem(QString());
        CityList->addItem(QString());
        CityList->setObjectName("CityList");
        CityList->setGeometry(QRect(340, 100, 181, 24));
        CityList_2 = new QComboBox(centralwidget);
        CityList_2->addItem(QString());
        CityList_2->addItem(QString());
        CityList_2->setObjectName("CityList_2");
        CityList_2->setGeometry(QRect(340, 130, 181, 24));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        WeatherButton->setText(QCoreApplication::translate("MainWindow", "Display Temp", nullptr));
        CityList->setItemText(0, QCoreApplication::translate("MainWindow", "Giza", nullptr));
        CityList->setItemText(1, QCoreApplication::translate("MainWindow", "Cairo", nullptr));
        CityList->setItemText(2, QCoreApplication::translate("MainWindow", "Alexandria", nullptr));
        CityList->setItemText(3, QCoreApplication::translate("MainWindow", "Hurgada", nullptr));

        CityList_2->setItemText(0, QCoreApplication::translate("MainWindow", "Celsius", nullptr));
        CityList_2->setItemText(1, QCoreApplication::translate("MainWindow", "Fahrenheit", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
