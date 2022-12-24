/********************************************************************************
** Form generated from reading UI file 'savewarn.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEWARN_H
#define UI_SAVEWARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveWarn
{
public:
    QLabel *label;
    QPushButton *save_yes;
    QPushButton *save_no;

    void setupUi(QWidget *SaveWarn)
    {
        if (SaveWarn->objectName().isEmpty())
            SaveWarn->setObjectName(QString::fromUtf8("SaveWarn"));
        SaveWarn->resize(344, 136);
        label = new QLabel(SaveWarn);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 30, 181, 31));
        save_yes = new QPushButton(SaveWarn);
        save_yes->setObjectName(QString::fromUtf8("save_yes"));
        save_yes->setGeometry(QRect(80, 80, 91, 31));
        save_no = new QPushButton(SaveWarn);
        save_no->setObjectName(QString::fromUtf8("save_no"));
        save_no->setGeometry(QRect(180, 80, 91, 31));

        retranslateUi(SaveWarn);

        QMetaObject::connectSlotsByName(SaveWarn);
    } // setupUi

    void retranslateUi(QWidget *SaveWarn)
    {
        SaveWarn->setWindowTitle(QApplication::translate("SaveWarn", "Warning", nullptr));
        label->setText(QApplication::translate("SaveWarn", "Do you wan to save the file?", nullptr));
        save_yes->setText(QApplication::translate("SaveWarn", "Yes", nullptr));
        save_no->setText(QApplication::translate("SaveWarn", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveWarn: public Ui_SaveWarn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEWARN_H
