/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QPushButton *camera_shot;
    QPushButton *video_start;
    QPushButton *video_stop;
    QPushButton *camera_choose;
    QLineEdit *video_address;
    QLabel *label;

    void setupUi(QDialog *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QString::fromUtf8("Camera"));
        Camera->resize(600, 466);
        camera_shot = new QPushButton(Camera);
        camera_shot->setObjectName(QString::fromUtf8("camera_shot"));
        camera_shot->setGeometry(QRect(380, 390, 112, 32));
        video_start = new QPushButton(Camera);
        video_start->setObjectName(QString::fromUtf8("video_start"));
        video_start->setGeometry(QRect(80, 390, 112, 32));
        video_stop = new QPushButton(Camera);
        video_stop->setObjectName(QString::fromUtf8("video_stop"));
        video_stop->setGeometry(QRect(230, 390, 112, 32));
        camera_choose = new QPushButton(Camera);
        camera_choose->setObjectName(QString::fromUtf8("camera_choose"));
        camera_choose->setGeometry(QRect(420, 426, 112, 32));
        video_address = new QLineEdit(Camera);
        video_address->setObjectName(QString::fromUtf8("video_address"));
        video_address->setGeometry(QRect(190, 430, 211, 21));
        label = new QLabel(Camera);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 430, 111, 16));

        retranslateUi(Camera);

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QDialog *Camera)
    {
        Camera->setWindowTitle(QApplication::translate("Camera", "Dialog", nullptr));
        camera_shot->setText(QApplication::translate("Camera", "Shot", nullptr));
        video_start->setText(QApplication::translate("Camera", "Start", nullptr));
        video_stop->setText(QApplication::translate("Camera", "Stop", nullptr));
        camera_choose->setText(QApplication::translate("Camera", "Choose", nullptr));
        label->setText(QApplication::translate("Camera", "Store Address", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
