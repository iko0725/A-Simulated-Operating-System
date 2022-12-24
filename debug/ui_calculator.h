/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QTextEdit *textEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_right_bracket;
    QPushButton *button_sub;
    QPushButton *button_9;
    QPushButton *button_5;
    QPushButton *button_1;
    QPushButton *button_8;
    QPushButton *button_3;
    QPushButton *button_4;
    QPushButton *button_add;
    QPushButton *button_equal;
    QPushButton *button_7;
    QPushButton *button_mult;
    QPushButton *button_back;
    QPushButton *button_clear;
    QPushButton *button_2;
    QPushButton *button_div;
    QPushButton *button_0;
    QPushButton *button_point;
    QPushButton *button_6;
    QPushButton *button_left_bracket;

    void setupUi(QDialog *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(519, 411);
        textEdit = new QTextEdit(Calculator);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 20, 451, 51));
        textEdit->setMinimumSize(QSize(20, 25));
        gridLayoutWidget = new QWidget(Calculator);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 100, 454, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        button_right_bracket = new QPushButton(gridLayoutWidget);
        button_right_bracket->setObjectName(QString::fromUtf8("button_right_bracket"));

        gridLayout->addWidget(button_right_bracket, 0, 1, 1, 1);

        button_sub = new QPushButton(gridLayoutWidget);
        button_sub->setObjectName(QString::fromUtf8("button_sub"));

        gridLayout->addWidget(button_sub, 3, 3, 1, 1);

        button_9 = new QPushButton(gridLayoutWidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));

        gridLayout->addWidget(button_9, 4, 2, 1, 1);

        button_5 = new QPushButton(gridLayoutWidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));

        gridLayout->addWidget(button_5, 3, 1, 1, 1);

        button_1 = new QPushButton(gridLayoutWidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));

        gridLayout->addWidget(button_1, 2, 0, 1, 1);

        button_8 = new QPushButton(gridLayoutWidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));

        gridLayout->addWidget(button_8, 4, 1, 1, 1);

        button_3 = new QPushButton(gridLayoutWidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));

        gridLayout->addWidget(button_3, 2, 2, 1, 1);

        button_4 = new QPushButton(gridLayoutWidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));

        gridLayout->addWidget(button_4, 3, 0, 1, 1);

        button_add = new QPushButton(gridLayoutWidget);
        button_add->setObjectName(QString::fromUtf8("button_add"));

        gridLayout->addWidget(button_add, 2, 3, 1, 1);

        button_equal = new QPushButton(gridLayoutWidget);
        button_equal->setObjectName(QString::fromUtf8("button_equal"));

        gridLayout->addWidget(button_equal, 5, 2, 1, 1);

        button_7 = new QPushButton(gridLayoutWidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));

        gridLayout->addWidget(button_7, 4, 0, 1, 1);

        button_mult = new QPushButton(gridLayoutWidget);
        button_mult->setObjectName(QString::fromUtf8("button_mult"));

        gridLayout->addWidget(button_mult, 4, 3, 1, 1);

        button_back = new QPushButton(gridLayoutWidget);
        button_back->setObjectName(QString::fromUtf8("button_back"));

        gridLayout->addWidget(button_back, 0, 2, 1, 1);

        button_clear = new QPushButton(gridLayoutWidget);
        button_clear->setObjectName(QString::fromUtf8("button_clear"));

        gridLayout->addWidget(button_clear, 0, 3, 1, 1);

        button_2 = new QPushButton(gridLayoutWidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));

        gridLayout->addWidget(button_2, 2, 1, 1, 1);

        button_div = new QPushButton(gridLayoutWidget);
        button_div->setObjectName(QString::fromUtf8("button_div"));

        gridLayout->addWidget(button_div, 5, 3, 1, 1);

        button_0 = new QPushButton(gridLayoutWidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));

        gridLayout->addWidget(button_0, 5, 0, 1, 1);

        button_point = new QPushButton(gridLayoutWidget);
        button_point->setObjectName(QString::fromUtf8("button_point"));

        gridLayout->addWidget(button_point, 5, 1, 1, 1);

        button_6 = new QPushButton(gridLayoutWidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));

        gridLayout->addWidget(button_6, 3, 2, 1, 1);

        button_left_bracket = new QPushButton(gridLayoutWidget);
        button_left_bracket->setObjectName(QString::fromUtf8("button_left_bracket"));

        gridLayout->addWidget(button_left_bracket, 0, 0, 1, 1);


        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QDialog *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Calculator", nullptr));
        button_right_bracket->setText(QApplication::translate("Calculator", ")", nullptr));
        button_sub->setText(QApplication::translate("Calculator", "-", nullptr));
        button_9->setText(QApplication::translate("Calculator", "9", nullptr));
        button_5->setText(QApplication::translate("Calculator", "5", nullptr));
        button_1->setText(QApplication::translate("Calculator", "1", nullptr));
        button_8->setText(QApplication::translate("Calculator", "8", nullptr));
        button_3->setText(QApplication::translate("Calculator", "3", nullptr));
        button_4->setText(QApplication::translate("Calculator", "4", nullptr));
        button_add->setText(QApplication::translate("Calculator", "+", nullptr));
        button_equal->setText(QApplication::translate("Calculator", "=", nullptr));
        button_7->setText(QApplication::translate("Calculator", "7", nullptr));
        button_mult->setText(QApplication::translate("Calculator", "*", nullptr));
        button_back->setText(QApplication::translate("Calculator", "back", nullptr));
        button_clear->setText(QApplication::translate("Calculator", "C", nullptr));
        button_2->setText(QApplication::translate("Calculator", "2", nullptr));
        button_div->setText(QApplication::translate("Calculator", "/", nullptr));
        button_0->setText(QApplication::translate("Calculator", "0", nullptr));
        button_point->setText(QApplication::translate("Calculator", ".", nullptr));
        button_6->setText(QApplication::translate("Calculator", "6", nullptr));
        button_left_bracket->setText(QApplication::translate("Calculator", "(", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
