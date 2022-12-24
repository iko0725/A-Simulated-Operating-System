#include "logindlg.h"
#include "ui_logindlg.h"
#include "opening.h"
#include <QMessageBox>
#include <QPainter>
#include <QtCore/QCoreApplication>
#include <QMediaPlayer>
#include <fstream>
#include <iostream>
#include <QKeyEvent>
#include <QDir>
#include "vector"
#include "h_gv.h"
#include <QTimer>
#include <QDateTime>
std::vector<std::string> username_login;
std::vector<std::string> password_login;
bool openingFlag = true;

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);

    //Set frame size
//    this->setFixedSize(1920,1080);
    this->setFixedSize(1280,720);
    //Set title
    this->setWindowTitle("Login");
//    setAttribute(Qt::WA_DeleteOnClose);
    QCursor *myCursor = new QCursor(QPixmap(":/cursor/cursor.png"),0,0);
    this->setCursor(*myCursor);

    //Set window icon
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));

    allocate_memory[7].memory_size = 0 + (rand() % (50-0+1))+0;
//    if(flag_login){
//        thread_login = new QTimer(this);
//        thread_login->setInterval (1000) ;
//        connect(thread_login,SIGNAL(timeout()),this,SLOT(showthread_login()));
//        thread_login->start();
//    }
    //Dsiplay it in full screen
    //showFullScreen();

    if (openingFlag){
        ui->userlineEdit->hide();
        ui->pswlineEdit->hide();
        QWidget* BootWid = new Opening(this);
        BootWid->setParent(this);
        BootWid->move(0,0);
        //this->hide();
        BootWid->show();
        openingFlag = false;
        QTimer::singleShot(4000, this, [=](){
        ui->userlineEdit->show();
        ui->pswlineEdit->show();
        });
    }

}

LoginDlg::~LoginDlg()
{
    delete ui;
    allocate_memory[7].memory_size = 0;
//    if(flag_login){
//        thread_login->stop();
//        sendData2("Login closed.");
//    }
}


void LoginDlg::paintEvent(QPaintEvent *)
{
        //Set background
        QPainter painter (this);
        QPixmap pix;
        pix.load(":/bg/bg_login.png");
        painter.drawPixmap(0,0,1280,720,pix);
//        painter.drawPixmap(0,0,1920,1080,pix);
        //Set banner
        pix.load(":/banner/login_banner.png");
        painter.drawPixmap(480, 87, 322,115,pix);
//        painter.drawPixmap(720, 130, 482,173,pix);

}

void LoginDlg::on_loginBtn_clicked()
{

    QDir nowp = QDir::current();
    #ifdef Q_OS_OSX
    nowp.cdUp();
    nowp.cdUp();
    nowp.cdUp();
    nowp.cdUp();
    #endif
    #ifdef Q_OS_WIN
    nowp.cdUp();
    #endif
    QString nowps = nowp.absolutePath();
    QString fp=nowps+"/CSC3002project/account/password.txt";
    QString fu=nowps+"/CSC3002project/account/username.txt";
    std::cout<<fp.toStdString()<<std::endl;
    std::string input_path_username = fu.toStdString();
    std::fstream file_username_login;
    std::string username;
    file_username_login.open(input_path_username.c_str());                    // open input file
    while (getline(file_username_login, username)){
        username_login.push_back(username);
    }
    file_username_login.close();
    std::string input_path_password = fp.toStdString();
    std::fstream file_password_login;
    std::string password;
    file_password_login.open(input_path_password.c_str());                    // open input file
    while (getline(file_password_login, password)){
        password_login.push_back(password);
    }
    file_password_login.close();

    for (int i = 0; i < int(username_login.size()); i++){
        if(ui->userlineEdit->text() == QString::fromStdString(username_login[i]) && ui->pswlineEdit->text() == QString::fromStdString(password_login[i])){
            login_username = "user: " + ui->userlineEdit->text();
            accept();
            return;
        }
    }

    QMessageBox::warning(this, tr("Warning"),tr("user name or passward error!"), QMessageBox::Yes);
    //clear and update index
    ui->userlineEdit->clear();
    ui->pswlineEdit->clear();
    ui->userlineEdit->setFocus();

}

