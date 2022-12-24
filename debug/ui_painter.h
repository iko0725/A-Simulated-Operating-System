/********************************************************************************
** Form generated from reading UI file 'painter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTER_H
#define UI_PAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Painter
{
public:
    QPushButton *pushButton_save_painter;
    QLabel *label_2;
    QSpinBox *spinBox_width;
    QPushButton *pushButton_color;
    QTextBrowser *textBrowser_color;
    QPushButton *pushButton_zoomin;
    QPushButton *pushButton_zoomout;
    QLabel *label_attr;
    QLabel *label_3;

    void setupUi(QDialog *Painter)
    {
        if (Painter->objectName().isEmpty())
            Painter->setObjectName(QString::fromUtf8("Painter"));
        Painter->resize(591, 352);
        pushButton_save_painter = new QPushButton(Painter);
        pushButton_save_painter->setObjectName(QString::fromUtf8("pushButton_save_painter"));
        pushButton_save_painter->setGeometry(QRect(460, 260, 101, 31));
        label_2 = new QLabel(Painter);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(460, 40, 71, 21));
        spinBox_width = new QSpinBox(Painter);
        spinBox_width->setObjectName(QString::fromUtf8("spinBox_width"));
        spinBox_width->setGeometry(QRect(460, 60, 42, 22));
        pushButton_color = new QPushButton(Painter);
        pushButton_color->setObjectName(QString::fromUtf8("pushButton_color"));
        pushButton_color->setGeometry(QRect(460, 140, 101, 31));
        textBrowser_color = new QTextBrowser(Painter);
        textBrowser_color->setObjectName(QString::fromUtf8("textBrowser_color"));
        textBrowser_color->setGeometry(QRect(530, 60, 31, 21));
        pushButton_zoomin = new QPushButton(Painter);
        pushButton_zoomin->setObjectName(QString::fromUtf8("pushButton_zoomin"));
        pushButton_zoomin->setGeometry(QRect(460, 180, 101, 31));
        pushButton_zoomout = new QPushButton(Painter);
        pushButton_zoomout->setObjectName(QString::fromUtf8("pushButton_zoomout"));
        pushButton_zoomout->setGeometry(QRect(460, 220, 101, 31));
        label_attr = new QLabel(Painter);
        label_attr->setObjectName(QString::fromUtf8("label_attr"));
        label_attr->setGeometry(QRect(460, 20, 101, 21));
        label_3 = new QLabel(Painter);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 40, 71, 21));

        retranslateUi(Painter);

        QMetaObject::connectSlotsByName(Painter);
    } // setupUi

    void retranslateUi(QDialog *Painter)
    {
        Painter->setWindowTitle(QApplication::translate("Painter", "Dialog", nullptr));
        pushButton_save_painter->setText(QApplication::translate("Painter", "save", nullptr));
        label_2->setText(QApplication::translate("Painter", "line width\357\274\232", nullptr));
        pushButton_color->setText(QApplication::translate("Painter", "change color", nullptr));
        pushButton_zoomin->setText(QApplication::translate("Painter", "zoom in ", nullptr));
        pushButton_zoomout->setText(QApplication::translate("Painter", "zoom out", nullptr));
        label_attr->setText(QApplication::translate("Painter", "Pen attributes", nullptr));
        label_3->setText(QApplication::translate("Painter", "color:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Painter: public Ui_Painter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTER_H
