/********************************************************************************
** Form generated from reading UI file 'monitor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITOR_H
#define UI_MONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Monitor
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_CPU;
    QTableWidget *tableWidget_CPU;
    QWidget *page_storage;
    QTableWidget *tableWidget_storage;
    QProgressBar *progressBar_storage;
    QLabel *label_memory;
    QTextEdit *textEdit_storage;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_CPU;
    QPushButton *pushButton_storage;

    void setupUi(QDialog *Monitor)
    {
        if (Monitor->objectName().isEmpty())
            Monitor->setObjectName(QString::fromUtf8("Monitor"));
        Monitor->resize(728, 533);
        stackedWidget = new QStackedWidget(Monitor);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-30, 80, 741, 431));
        page_CPU = new QWidget();
        page_CPU->setObjectName(QString::fromUtf8("page_CPU"));
        tableWidget_CPU = new QTableWidget(page_CPU);
        tableWidget_CPU->setObjectName(QString::fromUtf8("tableWidget_CPU"));
        tableWidget_CPU->setGeometry(QRect(80, 0, 621, 411));
        stackedWidget->addWidget(page_CPU);
        page_storage = new QWidget();
        page_storage->setObjectName(QString::fromUtf8("page_storage"));
        tableWidget_storage = new QTableWidget(page_storage);
        tableWidget_storage->setObjectName(QString::fromUtf8("tableWidget_storage"));
        tableWidget_storage->setGeometry(QRect(80, 0, 621, 361));
        progressBar_storage = new QProgressBar(page_storage);
        progressBar_storage->setObjectName(QString::fromUtf8("progressBar_storage"));
        progressBar_storage->setGeometry(QRect(510, 370, 121, 21));
        progressBar_storage->setValue(24);
        label_memory = new QLabel(page_storage);
        label_memory->setObjectName(QString::fromUtf8("label_memory"));
        label_memory->setGeometry(QRect(410, 370, 91, 16));
        textEdit_storage = new QTextEdit(page_storage);
        textEdit_storage->setObjectName(QString::fromUtf8("textEdit_storage"));
        textEdit_storage->setGeometry(QRect(650, 370, 51, 21));
        stackedWidget->addWidget(page_storage);
        layoutWidget = new QWidget(Monitor);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 20, 461, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_CPU = new QPushButton(layoutWidget);
        pushButton_CPU->setObjectName(QString::fromUtf8("pushButton_CPU"));

        horizontalLayout->addWidget(pushButton_CPU);

        pushButton_storage = new QPushButton(layoutWidget);
        pushButton_storage->setObjectName(QString::fromUtf8("pushButton_storage"));

        horizontalLayout->addWidget(pushButton_storage);


        retranslateUi(Monitor);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Monitor);
    } // setupUi

    void retranslateUi(QDialog *Monitor)
    {
        Monitor->setWindowTitle(QApplication::translate("Monitor", "Dialog", nullptr));
        label_memory->setText(QApplication::translate("Monitor", "Used memory:", nullptr));
        pushButton_CPU->setText(QApplication::translate("Monitor", "CPU", nullptr));
        pushButton_storage->setText(QApplication::translate("Monitor", "Internal Storage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Monitor: public Ui_Monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITOR_H
