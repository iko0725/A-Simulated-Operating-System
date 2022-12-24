/********************************************************************************
** Form generated from reading UI file 'createaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNT_H
#define UI_CREATEACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAccount
{
public:
    QLabel *label;
    QLineEdit *createpass;
    QLineEdit *createname;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *create;
    QPushButton *delete_button;

    void setupUi(QWidget *CreateAccount)
    {
        if (CreateAccount->objectName().isEmpty())
            CreateAccount->setObjectName(QString::fromUtf8("CreateAccount"));
        CreateAccount->resize(400, 300);
        label = new QLabel(CreateAccount);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 40, 181, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Times"));
        font.setPointSize(20);
        label->setFont(font);
        createpass = new QLineEdit(CreateAccount);
        createpass->setObjectName(QString::fromUtf8("createpass"));
        createpass->setGeometry(QRect(150, 160, 221, 31));
        createname = new QLineEdit(CreateAccount);
        createname->setObjectName(QString::fromUtf8("createname"));
        createname->setGeometry(QRect(150, 110, 221, 31));
        layoutWidget = new QWidget(CreateAccount);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 100, 64, 101));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        create = new QPushButton(CreateAccount);
        create->setObjectName(QString::fromUtf8("create"));
        create->setGeometry(QRect(90, 230, 112, 32));
        delete_button = new QPushButton(CreateAccount);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));
        delete_button->setGeometry(QRect(220, 230, 112, 32));

        retranslateUi(CreateAccount);

        QMetaObject::connectSlotsByName(CreateAccount);
    } // setupUi

    void retranslateUi(QWidget *CreateAccount)
    {
        CreateAccount->setWindowTitle(QApplication::translate("CreateAccount", "Create Account", nullptr));
        label->setText(QApplication::translate("CreateAccount", "Account Creation", nullptr));
        label_8->setText(QApplication::translate("CreateAccount", "Username", nullptr));
        label_9->setText(QApplication::translate("CreateAccount", "Password", nullptr));
        create->setText(QApplication::translate("CreateAccount", "Create", nullptr));
        delete_button->setText(QApplication::translate("CreateAccount", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateAccount: public Ui_CreateAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNT_H
