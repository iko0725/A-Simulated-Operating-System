/********************************************************************************
** Form generated from reading UI file 'deleteaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEACCOUNT_H
#define UI_DELETEACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteAccount
{
public:
    QLineEdit *secretepsw;
    QPushButton *deleteconfirm;
    QLabel *label_secretepsw;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QPushButton *refresh;
    QLabel *label;

    void setupUi(QWidget *DeleteAccount)
    {
        if (DeleteAccount->objectName().isEmpty())
            DeleteAccount->setObjectName(QString::fromUtf8("DeleteAccount"));
        DeleteAccount->resize(412, 320);
        DeleteAccount->setLayoutDirection(Qt::LeftToRight);
        secretepsw = new QLineEdit(DeleteAccount);
        secretepsw->setObjectName(QString::fromUtf8("secretepsw"));
        secretepsw->setGeometry(QRect(190, 220, 171, 31));
        deleteconfirm = new QPushButton(DeleteAccount);
        deleteconfirm->setObjectName(QString::fromUtf8("deleteconfirm"));
        deleteconfirm->setGeometry(QRect(60, 270, 112, 32));
        label_secretepsw = new QLabel(DeleteAccount);
        label_secretepsw->setObjectName(QString::fromUtf8("label_secretepsw"));
        label_secretepsw->setGeometry(QRect(40, 213, 119, 45));
        label_secretepsw->setAlignment(Qt::AlignCenter);
        checkBox_1 = new QCheckBox(DeleteAccount);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setGeometry(QRect(60, 60, 131, 20));
        checkBox_2 = new QCheckBox(DeleteAccount);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(60, 90, 131, 20));
        checkBox_3 = new QCheckBox(DeleteAccount);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(60, 120, 131, 20));
        checkBox_4 = new QCheckBox(DeleteAccount);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(60, 150, 131, 20));
        checkBox_5 = new QCheckBox(DeleteAccount);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(60, 180, 131, 20));
        checkBox_6 = new QCheckBox(DeleteAccount);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(210, 60, 131, 20));
        checkBox_7 = new QCheckBox(DeleteAccount);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(210, 90, 131, 20));
        checkBox_8 = new QCheckBox(DeleteAccount);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(210, 120, 131, 20));
        checkBox_9 = new QCheckBox(DeleteAccount);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(210, 150, 131, 20));
        checkBox_10 = new QCheckBox(DeleteAccount);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(210, 180, 121, 20));
        refresh = new QPushButton(DeleteAccount);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setGeometry(QRect(200, 270, 112, 32));
        label = new QLabel(DeleteAccount);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 161, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Times"));
        font.setPointSize(20);
        label->setFont(font);

        retranslateUi(DeleteAccount);

        QMetaObject::connectSlotsByName(DeleteAccount);
    } // setupUi

    void retranslateUi(QWidget *DeleteAccount)
    {
        DeleteAccount->setWindowTitle(QApplication::translate("DeleteAccount", "Delete Account", nullptr));
        deleteconfirm->setText(QApplication::translate("DeleteAccount", "Confirm", nullptr));
        label_secretepsw->setText(QApplication::translate("DeleteAccount", "Secrete Password", nullptr));
        checkBox_1->setText(QString());
        checkBox_2->setText(QString());
        checkBox_3->setText(QString());
        checkBox_4->setText(QString());
        checkBox_5->setText(QString());
        checkBox_6->setText(QString());
        checkBox_7->setText(QString());
        checkBox_8->setText(QString());
        checkBox_9->setText(QString());
        checkBox_10->setText(QString());
        refresh->setText(QApplication::translate("DeleteAccount", "Refresh", nullptr));
        label->setText(QApplication::translate("DeleteAccount", "Account Deletion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteAccount: public Ui_DeleteAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEACCOUNT_H
