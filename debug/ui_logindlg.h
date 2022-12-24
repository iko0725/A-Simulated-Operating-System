/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QPushButton *loginBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *exitbtn;
    QLineEdit *userlineEdit;
    QLineEdit *pswlineEdit;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QString::fromUtf8("LoginDlg"));
        LoginDlg->resize(1321, 663);
        LoginDlg->setStyleSheet(QString::fromUtf8(""));
        loginBtn = new QPushButton(LoginDlg);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(470, 340, 112, 32));
        layoutWidget = new QWidget(LoginDlg);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 210, 64, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(231, 250, 255);"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(231, 250, 255);"));

        verticalLayout->addWidget(label_2);

        exitbtn = new QPushButton(LoginDlg);
        exitbtn->setObjectName(QString::fromUtf8("exitbtn"));
        exitbtn->setGeometry(QRect(700, 340, 112, 32));
        userlineEdit = new QLineEdit(LoginDlg);
        userlineEdit->setObjectName(QString::fromUtf8("userlineEdit"));
        userlineEdit->setGeometry(QRect(590, 220, 221, 31));
        pswlineEdit = new QLineEdit(LoginDlg);
        pswlineEdit->setObjectName(QString::fromUtf8("pswlineEdit"));
        pswlineEdit->setGeometry(QRect(590, 270, 221, 31));

        retranslateUi(LoginDlg);
        QObject::connect(exitbtn, SIGNAL(clicked()), LoginDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "Login", nullptr));
        loginBtn->setText(QApplication::translate("LoginDlg", "Login", nullptr));
        label->setText(QApplication::translate("LoginDlg", "Username", nullptr));
        label_2->setText(QApplication::translate("LoginDlg", "Password", nullptr));
        exitbtn->setText(QApplication::translate("LoginDlg", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
