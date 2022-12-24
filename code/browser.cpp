#include "browser.h"
#include "ui_browser.h"
#include <QDesktopServices>
#include <QUrl>
#include <iostream>
#include <QTimer>
#include <QDateTime>
#include "h_gv.h"

/*
 * Function: Browser
 * Usage:Browser(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction functino of broswer, including some
 * initialization of the browser.
 */
Browser::Browser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Browser)
{
    ui->setupUi(this);
    allocate_memory[0].memory_size = 500 + (rand() % (100-0+1))+0;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    //Set window icon
    thread_browser = new QTimer(this);
    thread_browser->setInterval (1000) ;
    connect(thread_browser,SIGNAL(timeout()),this,SLOT(showThread_browser()));
    thread_browser->start();
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));
}

/*
 * Function: ~Browser
 * Usage:~Browser();
 * ------------------
 * This is a deconstruction functino of broswer, the deconstructor
 * frees any heap memory allocated by the browser.
 */
Browser::~Browser()
{
    delete ui;
    thread_browser->stop();
    allocate_memory[0].memory_size = 0;
    flags[0]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==0){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Brower closed.\t"+times);
}

/*
 * Function: on_pushButton_gp_clicked
 * Usage:on_pushButton_gp_clicked();
 * -----------------------------------
 * This is a slot for the action of clicking the pushbutton, it implements
 * the function to open the browser in users computer by inputing the url
 * address of the website.
 */
void Browser::on_pushButton_gp_clicked()
{
    QString url = ui->lineEdit->text();
    QDesktopServices::openUrl(QUrl(url));
    allocate_memory[0].memory_size = 1000 + (rand() % (100-0+1))+0;
}

/*
 * Function: showThread_browser
 * Usage:showThread_browser();
 * ----------------------------
 * This is a slot for the Qtimer, this implememtaion enables the signal can be
 * emitted every seconds.
 */
void Browser::showThread_browser(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Browser is running:" + t);
}
