#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindlg.h"
#include "ui_logindlg.h"
#include "filesys.h"
#include "ui_filesys.h"
#include "calendar.h"
#include "ui_calendar.h"
#include "calculator.h"
#include "ui_calculator.h"
#include "texteditor.h"
#include "ui_texteditor.h"
#include "createaccount.h"
#include "ui_createaccount.h"
#include "browser.h"
#include "ui_browser.h"
#include "memoset.h"
#include "ui_memoset.h"
#include "monitor.h"
#include "ui_monitor.h"
#include "videoplayer.h"
#include "ui_videoplayer.h"
#include "recorder.h"
#include "ui_recorder.h"
#include "camera.h"
#include "ui_camera.h"
#include "photo.h"
#include "ui_photo.h"
#include "MyPushButton.h"
#include "gluttonous_snake.h"
#include "painter.h"
#include "h_gv.h"
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QIcon>
#include <QSound>
#include <QNetworkConfigurationManager>
#include <QLibrary>
#include <iostream>
int battery = 100;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dlgs.resize(15);
    flags = {15*0};
    QPixmap *pixmap = new QPixmap(":/icon/battery_100.png");
    pixmap->scaled(ui->battery_label->size(), Qt::KeepAspectRatio);
    ui->battery_label->setScaledContents(true);
    ui->battery_label->setPixmap(*pixmap);

    QPixmap *mainlogo = new QPixmap(":/icon/orange_new.png");
    mainlogo->scaled(ui->battery_label->size(), Qt::KeepAspectRatio);
    ui->logo->setScaledContents(true);
    ui->logo->setPixmap(*mainlogo);

    ui->username->setText(login_username);
    ui->username->setStyleSheet("color:white;");

    ui->battery_amount->setText(QString::number(battery) + "%");
    ui->battery_amount->setStyleSheet("color:white;");

    update_battery_Time =new QTimer(this);
    update_battery_Time->setInterval (30*1000) ;
    connect(update_battery_Time,SIGNAL(timeout()),this,SLOT(updateBattery()));
    update_battery_Time->start();
    
    #ifdef Q_OS_WIN
    QLibrary lib("Wininet.dll");
    typedef bool (*ConnectFun)(int* lpdwFlags,int  dwReserved);
    if(lib.load()){
        bool bOnline=false;
        int  online_flag;
        ConnectFun  myConnectFun=(ConnectFun)lib.resolve("InternetGetConnectedState");
        bOnline=myConnectFun(&online_flag,0);
        if(bOnline){
            QPixmap *wifi = new QPixmap(":/icon/wifi_logo.png");
            wifi->scaled(ui->wifi_label->size(), Qt::KeepAspectRatio);
            ui->wifi_label->setScaledContents(true);
            ui->wifi_label->setPixmap(*wifi);}
        else{
            QPixmap *wifi = new QPixmap(":/icon/nowifi_logo.png");
            wifi->scaled(ui->wifi_label->size(), Qt::KeepAspectRatio);
            ui->wifi_label->setScaledContents(true);
            ui->wifi_label->setPixmap(*wifi);
        }
    }
    #endif
    update_Time =new QTimer(this);
    update_Time->setInterval (1000) ;
    connect(update_Time,SIGNAL(timeout()),this,SLOT(show_maintime()));
    update_Time->start();

    ui->time_main->setStyleSheet("color:white;");
    ui->battery_label->move(this->width()*0.618-ui->battery_label->width()*0.01,this->height()*0.0025);

    #ifdef Q_OS_OSX
    QPixmap *wifi = new QPixmap(":/icon/wifi_logo.png");
    wifi->scaled(ui->wifi_label->size(), Qt::KeepAspectRatio);
    ui->wifi_label->setScaledContents(true);
    ui->wifi_label->setPixmap(*wifi);
    ui->battery_label->move(this->width()*0.618-ui->battery_label->width()*0.01,this->height()*0.0025);
    ui->battery_amount->move(this->width()*0.60-ui->battery_amount->width()*0.01,this->height()*0.0025);
    ui->wifi_label->move(this->width()*0.588-ui->wifi_label->width()*0.01,this->height()*0.003);
    ui->time_main->move(this->width()*0.52-ui->time_main->width()*0.01,this->height()*0.0008);
    #endif
    #ifdef Q_OS_WIN
    ui->battery_label->move(this->width()*0.618-ui->battery_label->width()*0.01,this->height()*0.0025);
    ui->battery_amount->move(this->width()*0.60-ui->battery_amount->width()*0.01,this->height()*0.0025);
    ui->wifi_label->move(this->width()*0.588-ui->wifi_label->width()*0.01,this->height()*0.003);
    ui->time_main->move(this->width()*0.51-ui->time_main->width()*0.01,this->height()*0.0018);
    #endif

    setAcceptDrops(true);

    //Set frame size
    //this->setFixedSize(1920,1080);
    this->setFixedSize(1280,720);
    //Set title
    this->setWindowTitle("CSC3002 Project");

    //Set window icon
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));

    QCursor *myCursor = new QCursor(QPixmap(":/cursor/cursor.png"),0,0);
    this->setCursor(*myCursor);

    //Set SE: mouse click
    QSound *click  = new QSound(":/SE/mouse.wav");

    QString tips_calendar = "--Calendar & Time--\nInclude a calender\nProvide timer\nThe current time";
    QString tips_file = "----File System----\nOpen file folder\nList files information\nDelete and Rename";
    QString tips_calculator = "----Calculator----\nA simple calculator";
    QString tips_login = "----Login Interface----\nLogin\nUser can use this task\nto change account\n";
    QString tips_text = "----Text Editor----\nA tool to edit text\n\n\n";
    QString tips_browser = "----Net Browser----\nEnter Url\nvist the website";
    QString tips_memo = "-------Memo-------\nSet memos\nSearch memos";
    QString tips_account = "--Create Account--\ncreate or delete accounts\n\n\n";
    QString tips_game = "-Gluttonous Snake-\nUse WASD to control direction\ngameover when the\nsnake hits itself or the wall";
    QString tips_photo = "---Photo Viewer---\nPreview photos and\nmake adjustments.   \nSupport png/xpm/jpg.\n";
    QString tips_media = "-Multimedia Player-\nSupport MP4,MP3 and WAV\nPlay media\n\n";
    QString tips_monitor = "-----Monitor-----\nShow every tasks\nCPU\nInternal Storage";
    QString tips_camera = "------Camera------\nTake pictures or videos\nsaved in the computer\n\n";
    QString tips_recorder = "-----Recorder-----\nrecord sound\nuse the microphone\nsaved in the computert\n";
    QString tips_painter = "-----Painter-----\nPaint tool\nwith save function";

    //Customized PushButton: Login
    MyPushButton *loginBtn = new MyPushButton(this,":/button/login_button.png","",true,tips_login);
    loginBtn->setParent(this);
    loginBtn->move(this->width()*0.52-loginBtn->width()*0.5,this->height()*0.03);
    connect(loginBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        loginBtn->Down();
        loginBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        QDialog *dlg = new LoginDlg(this);
        connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
        connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
        dlg->show();
        });
            });

    //Customized PushButton: Calculator
    MyPushButton *calculatorBtn = new MyPushButton(this,":/button/calculator_button.png","",true,tips_calculator);
    calculatorBtn->setParent(this);
    calculatorBtn->move(this->width()*0.38-calculatorBtn->width()*0.5,this->height()*0.03);
    connect(calculatorBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        calculatorBtn->Down();
        calculatorBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[1]==0){
            process.push_back(1);
            QDialog *dlg = new Calculator(this);
            dlgs[1] = dlg;
            flags[1] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open caculator.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[1]->raise();
        }
        });
            });

    //Customized PushButton: File
    MyPushButton *fileBtn = new MyPushButton(this,":/button/file_button.png","",true,tips_file);
    fileBtn->setParent(this);
    fileBtn->move(this->width()*0.24-fileBtn->width()*0.5,this->height()*0.03);
    connect(fileBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        fileBtn->Down();
        fileBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[5]==0){
            process.push_back(5);
            QDialog *dlg = new FileSys(this);
            dlgs[5] = dlg;
            flags[5] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open file system.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[5]->raise();
        }
        });
            });

    //Customized PushButton: Calendar & Time
    MyPushButton *calendarBtn = new MyPushButton(this,":/button/calendar_button.png","",true,tips_calendar);
    calendarBtn->setParent(this);
    calendarBtn->move(this->width()*0.10-calendarBtn->width()*0.5,this->height()*0.03);
    connect(calendarBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        calendarBtn->Down();
        calendarBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[2]==0){
            process.push_back(2);
            QDialog *dlg = new Calendar(this);
            dlgs[2] = dlg;
            flags[2] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open calendar.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[2]->raise();
        }
        });
            });

    //Customized PushButton: CreateAccount
    MyPushButton *createBtn = new MyPushButton(this,":/button/account_button.png","",true,tips_account);
    createBtn->setParent(this);
    createBtn->move(this->width()*0.52-createBtn->width()*0.5,this->height()*0.26);
    connect(createBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        createBtn->Down();
        createBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[4]==0){
            process.push_back(4);
            QDialog *dlg = new CreateAccount(this);
            dlgs[4] = dlg;
            flags[4] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open account setting.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[4]->raise();
        }
        });
            });

    //Customized PushButton: Memo
    MyPushButton *memoBtn = new MyPushButton(this,":/button/memo_button.png","",true,tips_memo);
    memoBtn->setParent(this);
    memoBtn->move(this->width()*0.38-memoBtn->width()*0.5,this->height()*0.26);
    connect(memoBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        memoBtn->Down();
        memoBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[8]==0){
            process.push_back(8);
            QDialog *dlg = new Memoset(this);
            dlgs[8] = dlg;
            flags[8] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open the memo.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[8]->raise();
        }
        });
            });

    //Customized PushButton: Browser
    MyPushButton *browserBtn = new MyPushButton(this,":/button/browser_button.png","",true,tips_browser);
    browserBtn->setParent(this);
    browserBtn->move(this->width()*0.24-browserBtn->width()*0.5,this->height()*0.26);
    connect(browserBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        browserBtn->Down();
        browserBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[0]==0){
            process.push_back(0);
            QDialog *dlg = new Browser(this);
            dlgs[0] = dlg;
            flags[0] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open browser.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();

        }else{
            dlgs[0]->raise();
        }
        });
            });

    //Customized PushButton: Text Editor
    MyPushButton *editorBtn = new MyPushButton(this,":/button/editor_button.png","",true,tips_text);
    editorBtn->setParent(this);
    editorBtn->move(this->width()*0.10-editorBtn->width()*0.5,this->height()*0.26);
    connect(editorBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        editorBtn->Down();
        editorBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[13]==0){
            process.push_back(13);
            QDialog *dlg = new TextEditor(this);
            dlgs[13] = dlg;
            flags[13] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open text editor.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[13]->raise();
        }

        });
            });

    //Customized PushButton: Monitor
    MyPushButton *monitorBtn = new MyPushButton(this,":/button/monitor_button.png","",true,tips_monitor);
    monitorBtn->setParent(this);
    monitorBtn->move(this->width()*0.52-monitorBtn->width()*0.5,this->height()*0.50);
    connect(monitorBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        monitorBtn->Down();
        monitorBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[9]==0){
            process.push_back(9);
            QDialog *dlg = new Monitor(this);
            dlgs[9] = dlg;
            flags[9] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open monitor.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[9]->raise();
        }

        });
            });

    //Customized PushButton: Media
    MyPushButton *mediaBtn = new MyPushButton(this,":/button/media_button.png","",true,tips_media);
    mediaBtn->setParent(this);
    mediaBtn->move(this->width()*0.38-mediaBtn->width()*0.5,this->height()*0.50);
    connect(mediaBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        mediaBtn->Down();
        mediaBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[14]==0){
            process.push_back(14);
            QDialog *dlg = new VideoPlayer(this);
            dlgs[14] = dlg;
            flags[14] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open media player.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[14]->raise();
        }

        });
            });

    //Customized PushButton: Photo
    MyPushButton *photoBtn = new MyPushButton(this,":/button/photo_button.png","",true,tips_photo);
    photoBtn->setParent(this);
    photoBtn->move(this->width()*0.24-photoBtn->width()*0.5,this->height()*0.50);
    connect(photoBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        photoBtn->Down();
        photoBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[11]==0){
            process.push_back(11);
            QWidget* wid = new Photo(this);
            wids[1] = wid;
            flags[11] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open photo.\t\t"+times);
            connect(wid, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(wid, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            wid->show();
        }else{
            wids[1]->raise();
        }
        });
            });


    //Customized PushButton: Game
    MyPushButton *gameBtn = new MyPushButton(this,":/button/game_button.png","",true,tips_game);
    gameBtn->setParent(this);
    gameBtn->move(this->width()*0.10-gameBtn->width()*0.5,this->height()*0.50);
    connect(gameBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        gameBtn->Down();
        gameBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[6]==0){
            process.push_back(6);
            Widget *wid = new Widget();
            wids[0] = wid;
            flags[6] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open video game: snake.\t"+times);
            connect(wid, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(wid, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            wid->show();
        }else{
            wids[0]->raise();
        }
        });
            });

    //Customized PushButton: Painter
    MyPushButton *painterBtn = new MyPushButton(this,":/button/painter_button.png","",true,tips_painter);
    painterBtn->setParent(this);
    painterBtn->move(this->width()*0.38-painterBtn->width()*0.5,this->height()*0.74);
    connect(painterBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        painterBtn->Down();
        painterBtn->Up();
        //Play SE: mouse click
        click->play();

        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[10]==0){
            process.push_back(10);
            QDialog *dlg = new Painter(this);
            dlgs[10] = dlg;
            flags[10] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open painter.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[10]->raise();
        }
        });
            });


    //Customized PushButton: Recorder
    MyPushButton *recordBtn = new MyPushButton(this,":/button/record_button.png","",true,tips_recorder);
    recordBtn->setParent(this);
    recordBtn->move(this->width()*0.24-recordBtn->width()*0.5,this->height()*0.74);
    connect(recordBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        recordBtn->Down();
        recordBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[12]==0){
            process.push_back(12);
            QDialog *dlg = new Recorder(this);
            dlgs[12] = dlg;
            flags[12] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open recorder.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[12]->raise();
        }
        });
            });

    //Customized PushButton: Camera
    MyPushButton *cameraBtn = new MyPushButton(this,":/button/camera_button.png","",true,tips_camera);
    cameraBtn->setParent(this);
    cameraBtn->move(this->width()*0.10-cameraBtn->width()*0.5,this->height()*0.74);
    connect(cameraBtn, &MyPushButton::clicked, [=](){
        // Show animation when clicked
        cameraBtn->Down();
        cameraBtn->Up();
        //Play SE: mouse click
        click->play();
        // Delay executing function, after animation has finished.
        QTimer::singleShot(120, this, [=](){
        if(flags[3]==0){
            process.push_back(3);
            QDialog *dlg = new Camera(this);
            dlgs[3] = dlg;
            flags[3] = 1;
            QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            ui->textBrowser_2->append("Open camera.\t"+times);
            connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
            connect(dlg, SIGNAL(sendData2(QString)), this, SLOT(receiveData2(QString)));
            dlg->show();
        }else{
            dlgs[3]->raise();
        }
        });
            });

//    showFullScreen();
}




//Set background
void MainWindow::paintEvent(QPaintEvent *)
{
        QPainter painter (this);
        QPixmap pix;
        pix.load(":/bg/bg.png");
//        painter.drawPixmap(0,0,1920,1080,pix);
        painter.drawPixmap(0,0,1280,720,pix);
}

void MainWindow::keyPressEvent(QKeyEvent *keyset)
    {
     if(keyset->key()==Qt::Key_Escape){
          this->showNormal ();
    }

}

void MainWindow::receiveData(QString data)
{
//    QTextDocument *td = ui->textBrowser->document();
    ui->textBrowser->document()->setMaximumBlockCount (20);
    ui->textBrowser->append(data);
}
void MainWindow::receiveData2(QString data)
{
//    QTextDocument *td = ui->textBrowser->document();
    ui->textBrowser_2->document()->setMaximumBlockCount (10);
    ui->textBrowser_2->append(data);
}
MainWindow::~MainWindow()
{
    delete ui;
    update_battery_Time->stop();
}


void MainWindow::updateBattery(){
    battery -= 1;
    ui->battery_amount->setText(QString::number(battery) + "%");
    ui->battery_amount->setStyleSheet("color:white;");
    if (battery == 80){
        QPixmap *pixmap = new QPixmap(":/icon/battery_80.png");
        pixmap->scaled(ui->battery_label->size(), Qt::KeepAspectRatio);
        ui->battery_label->setScaledContents(true);
        ui->battery_label->setPixmap(*pixmap);
    }
    if (battery == 30){
        QPixmap *pixmap = new QPixmap(":/icon/battery_30.png");
        pixmap->scaled(ui->battery_label->size(), Qt::KeepAspectRatio);
        ui->battery_label->setScaledContents(true);
        ui->battery_label->setPixmap(*pixmap);
    }
    if (battery == 10){
        QPixmap *pixmap = new QPixmap(":/icon/battery_10.png");
        pixmap->scaled(ui->battery_label->size(), Qt::KeepAspectRatio);
        ui->battery_label->setScaledContents(true);
        ui->battery_label->setPixmap(*pixmap);
    }
    if (battery == 0) {
        this->close();
    }
}
void MainWindow::show_maintime(){        
    #ifdef Q_OS_WIN
    QLibrary lib("Wininet.dll");
    typedef bool (*ConnectFun)(int* lpdwFlags,int  dwReserved);
    if(lib.load()){
        bool bOnline=false;
        int  online_flag;
        ConnectFun  myConnectFun=(ConnectFun)lib.resolve("InternetGetConnectedState");
        bOnline=myConnectFun(&online_flag,0);
        if(bOnline){
            QPixmap *wifi = new QPixmap(":/icon/wifi_logo.png");
            wifi->scaled(ui->wifi_label->size(), Qt::KeepAspectRatio);
            ui->wifi_label->setScaledContents(true);
            ui->wifi_label->setPixmap(*wifi);}
        else{
            QPixmap *wifi = new QPixmap(":/icon/nowifi_logo.png");
            wifi->scaled(ui->wifi_label->size(), Qt::KeepAspectRatio);
            ui->wifi_label->setScaledContents(true);
            ui->wifi_label->setPixmap(*wifi);
        }
    }
    #endif
    QDateTime time = QDateTime::currentDateTime();
    ui->username->setText(login_username);
    ui->time_main->clear();
    ui->time_main->setText(time.toString("yyyy-MM-dd hh:mm:ss"));
    ui->time_main->update();
    int memory_total = 0;
    for (int i=0; i<15;i++){
        memory_total += allocate_memory[i].memory_size;
    }
//    if(process.size()>0) std::cout<<allocate_memory[process[0]].task_name.toStdString()<<std::endl;
    memory_percent = memory_total*100/4096;
    if(memory_percent>100) memory_percent=100;
    if(memory_percent>=90){
        int apptoremove = process[0];
        process.erase(process.begin());
        if(apptoremove==6) wids[0]->close();
        else if(apptoremove==11) wids[1]->close();
        else dlgs[apptoremove]->close();
        QMessageBox::warning(NULL, "warning", "The memory is nearlly full. \nThe earliest open program is closed");

    }
}
