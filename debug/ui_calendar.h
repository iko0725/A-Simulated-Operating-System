/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *calendar;
    QPushButton *updtimebtnte;
    QCalendarWidget *calendarWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *le_time;
    QLineEdit *le_date;
    QLineEdit *le_td;
    QLabel *timerLb;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdHour;
    QLCDNumber *lcdMin;
    QLCDNumber *lcdSec;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QProgressBar *progressBar;
    QLabel *label_elapsed;

    void setupUi(QDialog *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName(QString::fromUtf8("Calendar"));
        Calendar->resize(743, 429);
        verticalLayout = new QVBoxLayout(Calendar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calendar = new QGroupBox(Calendar);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        updtimebtnte = new QPushButton(calendar);
        updtimebtnte->setObjectName(QString::fromUtf8("updtimebtnte"));
        updtimebtnte->setGeometry(QRect(110, 320, 112, 32));
        calendarWidget = new QCalendarWidget(calendar);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(40, 30, 304, 173));
        layoutWidget = new QWidget(calendar);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 224, 161, 91));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        le_time = new QLineEdit(layoutWidget);
        le_time->setObjectName(QString::fromUtf8("le_time"));

        verticalLayout_3->addWidget(le_time);

        le_date = new QLineEdit(layoutWidget);
        le_date->setObjectName(QString::fromUtf8("le_date"));

        verticalLayout_3->addWidget(le_date);

        le_td = new QLineEdit(layoutWidget);
        le_td->setObjectName(QString::fromUtf8("le_td"));

        verticalLayout_3->addWidget(le_td);

        timerLb = new QLabel(calendar);
        timerLb->setObjectName(QString::fromUtf8("timerLb"));
        timerLb->setGeometry(QRect(510, 70, 58, 16));
        widget = new QWidget(calendar);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(420, 100, 216, 121));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lcdHour = new QLCDNumber(widget);
        lcdHour->setObjectName(QString::fromUtf8("lcdHour"));

        horizontalLayout->addWidget(lcdHour);

        lcdMin = new QLCDNumber(widget);
        lcdMin->setObjectName(QString::fromUtf8("lcdMin"));

        horizontalLayout->addWidget(lcdMin);

        lcdSec = new QLCDNumber(widget);
        lcdSec->setObjectName(QString::fromUtf8("lcdSec"));

        horizontalLayout->addWidget(lcdSec);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        startBtn = new QPushButton(widget);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));

        horizontalLayout_2->addWidget(startBtn);

        stopBtn = new QPushButton(widget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));

        horizontalLayout_2->addWidget(stopBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        label_elapsed = new QLabel(widget);
        label_elapsed->setObjectName(QString::fromUtf8("label_elapsed"));

        verticalLayout_2->addWidget(label_elapsed);


        verticalLayout->addWidget(calendar);


        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QDialog *Calendar)
    {
        Calendar->setWindowTitle(QApplication::translate("Calendar", "Calendar", nullptr));
        calendar->setTitle(QApplication::translate("Calendar", "Calendar", nullptr));
        updtimebtnte->setText(QApplication::translate("Calendar", "update time", nullptr));
        timerLb->setText(QApplication::translate("Calendar", "Timer", nullptr));
        startBtn->setText(QApplication::translate("Calendar", "Start", nullptr));
        stopBtn->setText(QApplication::translate("Calendar", "Stop", nullptr));
        label_elapsed->setText(QApplication::translate("Calendar", "Eclipsed time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
