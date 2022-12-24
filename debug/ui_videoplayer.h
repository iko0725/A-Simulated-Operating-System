/********************************************************************************
** Form generated from reading UI file 'videoplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPlayer
{
public:
    QPushButton *play;
    QPushButton *stopplay;
    QWidget *playwidget;
    QLabel *movielabel;
    QSlider *videoslider;
    QPushButton *pause;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *next;
    QPushButton *previous;
    QPushButton *addnew;
    QPushButton *remove;

    void setupUi(QDialog *VideoPlayer)
    {
        if (VideoPlayer->objectName().isEmpty())
            VideoPlayer->setObjectName(QString::fromUtf8("VideoPlayer"));
        VideoPlayer->resize(488, 386);
        play = new QPushButton(VideoPlayer);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(220, 320, 81, 32));
        stopplay = new QPushButton(VideoPlayer);
        stopplay->setObjectName(QString::fromUtf8("stopplay"));
        stopplay->setGeometry(QRect(300, 320, 81, 32));
        playwidget = new QWidget(VideoPlayer);
        playwidget->setObjectName(QString::fromUtf8("playwidget"));
        playwidget->setGeometry(QRect(50, 10, 391, 251));
        movielabel = new QLabel(playwidget);
        movielabel->setObjectName(QString::fromUtf8("movielabel"));
        movielabel->setGeometry(QRect(20, 20, 351, 211));
        videoslider = new QSlider(VideoPlayer);
        videoslider->setObjectName(QString::fromUtf8("videoslider"));
        videoslider->setGeometry(QRect(50, 290, 391, 22));
        videoslider->setOrientation(Qt::Horizontal);
        pause = new QPushButton(VideoPlayer);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(390, 320, 81, 32));
        label = new QLabel(VideoPlayer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 270, 101, 16));
        label_2 = new QLabel(VideoPlayer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 270, 111, 16));
        label_3 = new QLabel(VideoPlayer);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 270, 111, 16));
        next = new QPushButton(VideoPlayer);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(100, 320, 81, 32));
        next->setFlat(false);
        previous = new QPushButton(VideoPlayer);
        previous->setObjectName(QString::fromUtf8("previous"));
        previous->setGeometry(QRect(10, 320, 81, 32));
        previous->setFlat(false);
        addnew = new QPushButton(VideoPlayer);
        addnew->setObjectName(QString::fromUtf8("addnew"));
        addnew->setGeometry(QRect(50, 350, 131, 32));
        remove = new QPushButton(VideoPlayer);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(260, 350, 161, 32));

        retranslateUi(VideoPlayer);

        next->setDefault(false);
        previous->setDefault(false);


        QMetaObject::connectSlotsByName(VideoPlayer);
    } // setupUi

    void retranslateUi(QDialog *VideoPlayer)
    {
        VideoPlayer->setWindowTitle(QApplication::translate("VideoPlayer", "Dialog", nullptr));
        play->setText(QApplication::translate("VideoPlayer", "Play", nullptr));
        stopplay->setText(QApplication::translate("VideoPlayer", "Stop", nullptr));
        movielabel->setText(QApplication::translate("VideoPlayer", "\\", nullptr));
        pause->setText(QApplication::translate("VideoPlayer", "Pause", nullptr));
        label->setText(QApplication::translate("VideoPlayer", "Information", nullptr));
        label_2->setText(QApplication::translate("VideoPlayer", "State", nullptr));
        label_3->setText(QString());
        next->setText(QApplication::translate("VideoPlayer", "Next", nullptr));
        previous->setText(QApplication::translate("VideoPlayer", "Previous", nullptr));
        addnew->setText(QApplication::translate("VideoPlayer", "Add New Media", nullptr));
        remove->setText(QApplication::translate("VideoPlayer", "Remove current Media", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoPlayer: public Ui_VideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
