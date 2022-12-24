/********************************************************************************
** Form generated from reading UI file 'memoset.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMOSET_H
#define UI_MEMOSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Memoset
{
public:
    QPushButton *pushButton_memoset;
    QDateTimeEdit *dateTimeEdit_memo;
    QLabel *label_time;
    QLabel *labe_matter;
    QLineEdit *lineEdit_matter;
    QTextEdit *textEdit_matter;
    QLabel *label_todo;
    QPushButton *pushButton_showall;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit_searchmemo;
    QPushButton *pushButton_search;
    QPushButton *pushButton_delete;

    void setupUi(QDialog *Memoset)
    {
        if (Memoset->objectName().isEmpty())
            Memoset->setObjectName(QString::fromUtf8("Memoset"));
        Memoset->resize(739, 401);
        pushButton_memoset = new QPushButton(Memoset);
        pushButton_memoset->setObjectName(QString::fromUtf8("pushButton_memoset"));
        pushButton_memoset->setGeometry(QRect(140, 190, 112, 32));
        dateTimeEdit_memo = new QDateTimeEdit(Memoset);
        dateTimeEdit_memo->setObjectName(QString::fromUtf8("dateTimeEdit_memo"));
        dateTimeEdit_memo->setGeometry(QRect(110, 100, 194, 22));
        label_time = new QLabel(Memoset);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(20, 100, 61, 21));
        labe_matter = new QLabel(Memoset);
        labe_matter->setObjectName(QString::fromUtf8("labe_matter"));
        labe_matter->setGeometry(QRect(20, 140, 58, 16));
        lineEdit_matter = new QLineEdit(Memoset);
        lineEdit_matter->setObjectName(QString::fromUtf8("lineEdit_matter"));
        lineEdit_matter->setGeometry(QRect(110, 140, 241, 21));
        textEdit_matter = new QTextEdit(Memoset);
        textEdit_matter->setObjectName(QString::fromUtf8("textEdit_matter"));
        textEdit_matter->setGeometry(QRect(420, 150, 281, 111));
        label_todo = new QLabel(Memoset);
        label_todo->setObjectName(QString::fromUtf8("label_todo"));
        label_todo->setGeometry(QRect(420, 120, 58, 16));
        pushButton_showall = new QPushButton(Memoset);
        pushButton_showall->setObjectName(QString::fromUtf8("pushButton_showall"));
        pushButton_showall->setGeometry(QRect(400, 90, 112, 32));
        layoutWidget = new QWidget(Memoset);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(410, 60, 300, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dateEdit_searchmemo = new QDateEdit(layoutWidget);
        dateEdit_searchmemo->setObjectName(QString::fromUtf8("dateEdit_searchmemo"));

        horizontalLayout->addWidget(dateEdit_searchmemo);

        pushButton_search = new QPushButton(layoutWidget);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));

        horizontalLayout->addWidget(pushButton_search);

        pushButton_delete = new QPushButton(Memoset);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(600, 90, 112, 32));

        retranslateUi(Memoset);

        QMetaObject::connectSlotsByName(Memoset);
    } // setupUi

    void retranslateUi(QDialog *Memoset)
    {
        Memoset->setWindowTitle(QApplication::translate("Memoset", "Dialog", nullptr));
        pushButton_memoset->setText(QApplication::translate("Memoset", "Set", nullptr));
        label_time->setText(QApplication::translate("Memoset", "Time:", nullptr));
        labe_matter->setText(QApplication::translate("Memoset", "Matter:", nullptr));
        label_todo->setText(QApplication::translate("Memoset", "To do:", nullptr));
        pushButton_showall->setText(QApplication::translate("Memoset", "Show all", nullptr));
        pushButton_search->setText(QApplication::translate("Memoset", "Search", nullptr));
        pushButton_delete->setText(QApplication::translate("Memoset", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Memoset: public Ui_Memoset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMOSET_H
