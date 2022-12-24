#include "opening.h"
#include "ui_opening.h"
#include "MyPushButton.h"
#include "logindlg.h"
#include <QMessageBox>
#include <QPainter>
#include <QtCore/QCoreApplication>
#include <QMediaPlayer>
#include <QDir>
#include <QIcon>
#include <QTimer>
#include "h_gv.h"

/*
 * Function: Opening(QWidget *parent = nullptr)
 * Usage: QDialog *dlg = new Opening()
 * --------------------------------------------
 * Construct a Opening class QDialog
*/
Opening::Opening(QWidget *parent)
{
    ui->setupUi(this);

    //Set frame size
    this->setFixedSize(1280,720);

    //Set title
    this->setWindowTitle(" ");

    QCursor *myCursor = new QCursor(Qt::BlankCursor);
    this->setCursor(*myCursor);

    //Set window icon
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));

    MyPushButton *banner = new MyPushButton(this,":/banner/booting_banner.png","",false);
    banner->setParent(this);
    banner->move(this->width()*0.53-banner->width()*0.5,this->height()*0.15);

    MyPushButton *l_b = new MyPushButton(this,":/icon/l_bracket.png","",false);
    l_b->setParent(this);
    l_b->move(this->width()*0.28-l_b->width()*0.5,this->height()*0.45);

    MyPushButton *load1 = new MyPushButton(this,":/icon/load.png","",false);
    load1->setParent(this);
    load1->move(this->width()*0.32-load1->width()*0.5,this->height()*0.48);

    MyPushButton *load2 = new MyPushButton(this,":/icon/load.png","",false);
    load2->setParent(this);
    load2->move(this->width()*0.38-load1->width()*0.5,this->height()*0.48);

    MyPushButton *load3 = new MyPushButton(this,":/icon/load.png","",false);
    load3->setParent(this);
    load3->move(this->width()*0.44-load1->width()*0.5,this->height()*0.48);

    MyPushButton *load4 = new MyPushButton(this,":/icon/load.png","",false);
    load4->setParent(this);
    load4->move(this->width()*0.50-load1->width()*0.5,this->height()*0.48);

    MyPushButton *load5 = new MyPushButton(this,":/icon/load.png","",false);
    load5->setParent(this);
    load5->move(this->width()*0.56-load1->width()*0.5,this->height()*0.48);

    MyPushButton *load6 = new MyPushButton(this,":/icon/load.png","",false);
    load6->setParent(this);
    load6->move(this->width()*0.62-load1->width()*0.5,this->height()*0.48);

    MyPushButton *load7 = new MyPushButton(this,":/icon/load.png","",false);
    load7->setParent(this);
    load7->move(this->width()*0.68-load1->width()*0.5,this->height()*0.48);

    MyPushButton *r_b = new MyPushButton(this,":/icon/r_bracket.png","",false);
    r_b->setParent(this);
    r_b->move(this->width()*0.72-l_b->width()*0.5,this->height()*0.45);

    QTimer::singleShot(10, this, [=](){
        banner->Shimmer();
        banner->startShimmerAnimation();
        for (int loopAmount = 0; loopAmount <= 3; loopAmount++){
            QTimer::singleShot(300+loopAmount*2100, this, [=](){
                load1->Down();
                load1->Up();
                });
            QTimer::singleShot(600+loopAmount*2100, this, [=](){
                load2->Down();
                load2->Up();
                });
            QTimer::singleShot(900+loopAmount*2100, this, [=](){
                load3->Down();
                load3->Up();
                });
            QTimer::singleShot(1200+loopAmount*2100, this, [=](){
                load4->Down();
                load4->Up();
                });
            QTimer::singleShot(1500+loopAmount*2100, this, [=](){
                load5->Down();
                load5->Up();
                });
            QTimer::singleShot(1800+loopAmount*2100, this, [=](){
                load6->Down();
                load6->Up();
                });
            QTimer::singleShot(2100+loopAmount*2100, this, [=](){
                load7->Down();
                load7->Up();
                });
        }
        QTimer::singleShot(8400, this, [=](){
            this->close();
            });
        });


}

/*
 * Function: ~Opening
 * Usage: Usually implicit
 * --------------------------------------------
 * Dextruct the object and all memories it allocated.
*/
Opening::~Opening()
{
}

/*
     * Function: paintEvent(QPaintEvent *)
     * Usage: Implicit
     * --------------------------------------------
     * Draw the background for the Opening object.
*/
void Opening::paintEvent(QPaintEvent *){
        //Set background
        QPainter painter (this);
        QPixmap pix;
        pix.load(":/bg/bg_login.png");
        painter.drawPixmap(0,0,1280,720,pix);
//        painter.drawPixmap(0,0,1920,1080,pix);
}
