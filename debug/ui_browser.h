/********************************************************************************
** Form generated from reading UI file 'browser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSER_H
#define UI_BROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Browser
{
public:
    QPushButton *pushButton_gp;
    QLabel *label_url;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Browser)
    {
        if (Browser->objectName().isEmpty())
            Browser->setObjectName(QString::fromUtf8("Browser"));
        Browser->resize(604, 88);
        pushButton_gp = new QPushButton(Browser);
        pushButton_gp->setObjectName(QString::fromUtf8("pushButton_gp"));
        pushButton_gp->setGeometry(QRect(440, 20, 61, 41));
        label_url = new QLabel(Browser);
        label_url->setObjectName(QString::fromUtf8("label_url"));
        label_url->setGeometry(QRect(90, 30, 58, 16));
        lineEdit = new QLineEdit(Browser);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 30, 311, 21));

        retranslateUi(Browser);

        QMetaObject::connectSlotsByName(Browser);
    } // setupUi

    void retranslateUi(QDialog *Browser)
    {
        Browser->setWindowTitle(QApplication::translate("Browser", "Go to Website", nullptr));
        pushButton_gp->setText(QApplication::translate("Browser", "Go", nullptr));
        label_url->setText(QApplication::translate("Browser", "Url:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Browser: public Ui_Browser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSER_H
