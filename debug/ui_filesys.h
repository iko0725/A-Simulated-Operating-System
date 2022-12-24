/********************************************************************************
** Form generated from reading UI file 'filesys.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESYS_H
#define UI_FILESYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_FileSys
{
public:
    QPushButton *pushButton_finder;
    QTableWidget *tableWidget_file;
    QPushButton *pushButton_refresh;

    void setupUi(QDialog *FileSys)
    {
        if (FileSys->objectName().isEmpty())
            FileSys->setObjectName(QString::fromUtf8("FileSys"));
        FileSys->resize(897, 427);
        pushButton_finder = new QPushButton(FileSys);
        pushButton_finder->setObjectName(QString::fromUtf8("pushButton_finder"));
        pushButton_finder->setGeometry(QRect(740, 390, 141, 31));
        tableWidget_file = new QTableWidget(FileSys);
        tableWidget_file->setObjectName(QString::fromUtf8("tableWidget_file"));
        tableWidget_file->setGeometry(QRect(10, 30, 871, 341));
        pushButton_refresh = new QPushButton(FileSys);
        pushButton_refresh->setObjectName(QString::fromUtf8("pushButton_refresh"));
        pushButton_refresh->setGeometry(QRect(630, 390, 112, 32));

        retranslateUi(FileSys);

        QMetaObject::connectSlotsByName(FileSys);
    } // setupUi

    void retranslateUi(QDialog *FileSys)
    {
        FileSys->setWindowTitle(QApplication::translate("FileSys", "Dialog", nullptr));
        pushButton_finder->setText(QApplication::translate("FileSys", "Finder", nullptr));
        pushButton_refresh->setText(QApplication::translate("FileSys", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileSys: public Ui_FileSys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESYS_H
