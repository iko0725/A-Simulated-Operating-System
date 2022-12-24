/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *battery_label;
    QTextBrowser *textBrowser_3;
    QLabel *logo;
    QLabel *username;
    QLabel *battery_amount;
    QLabel *wifi_label;
    QLabel *time_main;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(2011, 1048);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(800, 70, 431, 411));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgba(8, 15, 63, 150);\n"
"color: rgb(219, 247, 255);"));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(800, 480, 431, 181));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color: rgba(8, 15, 63, 150);\n"
"color: rgb(219, 247, 255);"));
        battery_label = new QLabel(centralwidget);
        battery_label->setObjectName(QString::fromUtf8("battery_label"));
        battery_label->setGeometry(QRect(1240, 3, 31, 16));
        textBrowser_3 = new QTextBrowser(centralwidget);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(-90, 0, 1621, 21));
        textBrowser_3->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255, 30);\n"
"color: rgb(219, 247, 255);"));
        logo = new QLabel(centralwidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(3, 3, 16, 16));
        username = new QLabel(centralwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(22, 3, 131, 16));
        battery_amount = new QLabel(centralwidget);
        battery_amount->setObjectName(QString::fromUtf8("battery_amount"));
        battery_amount->setGeometry(QRect(1205, 3, 41, 16));
        wifi_label = new QLabel(centralwidget);
        wifi_label->setObjectName(QString::fromUtf8("wifi_label"));
        wifi_label->setGeometry(QRect(1183, 3, 18, 14));
        time_main = new QLabel(centralwidget);
        time_main->setObjectName(QString::fromUtf8("time_main"));
        time_main->setGeometry(QRect(1040, 3, 211, 21));
        MainWindow->setCentralWidget(centralwidget);
        textBrowser_3->raise();
        textBrowser->raise();
        textBrowser_2->raise();
        battery_label->raise();
        logo->raise();
        username->raise();
        battery_amount->raise();
        wifi_label->raise();
        time_main->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 2011, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.AppleSystemUIFont';\"><br /></p></body></html>", nullptr));
        textBrowser_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.AppleSystemUIFont';\"><br /></p></body></html>", nullptr));
        battery_label->setText(QString());
        textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.AppleSystemUIFont';\"><br /></p></body></html>", nullptr));
        logo->setText(QString());
        username->setText(QString());
        battery_amount->setText(QString());
        wifi_label->setText(QString());
        time_main->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
