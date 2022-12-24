/********************************************************************************
** Form generated from reading UI file 'recorder.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDER_H
#define UI_RECORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Recorder
{
public:
    QLabel *equipment_2;
    QLineEdit *Address;
    QPushButton *record_start;
    QPushButton *record_stop;
    QPushButton *choose;

    void setupUi(QDialog *Recorder)
    {
        if (Recorder->objectName().isEmpty())
            Recorder->setObjectName(QString::fromUtf8("Recorder"));
        Recorder->resize(560, 101);
        equipment_2 = new QLabel(Recorder);
        equipment_2->setObjectName(QString::fromUtf8("equipment_2"));
        equipment_2->setGeometry(QRect(40, 20, 91, 16));
        Address = new QLineEdit(Recorder);
        Address->setObjectName(QString::fromUtf8("Address"));
        Address->setGeometry(QRect(150, 20, 231, 21));
        record_start = new QPushButton(Recorder);
        record_start->setObjectName(QString::fromUtf8("record_start"));
        record_start->setGeometry(QRect(81, 60, 160, 32));
        record_stop = new QPushButton(Recorder);
        record_stop->setObjectName(QString::fromUtf8("record_stop"));
        record_stop->setGeometry(QRect(290, 60, 160, 32));
        choose = new QPushButton(Recorder);
        choose->setObjectName(QString::fromUtf8("choose"));
        choose->setGeometry(QRect(410, 16, 112, 32));

        retranslateUi(Recorder);

        QMetaObject::connectSlotsByName(Recorder);
    } // setupUi

    void retranslateUi(QDialog *Recorder)
    {
        Recorder->setWindowTitle(QApplication::translate("Recorder", "Dialog", nullptr));
        equipment_2->setText(QApplication::translate("Recorder", "Store Address", nullptr));
        record_start->setText(QApplication::translate("Recorder", "Start", nullptr));
        record_stop->setText(QApplication::translate("Recorder", "Stop", nullptr));
        choose->setText(QApplication::translate("Recorder", "choose", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Recorder: public Ui_Recorder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDER_H
