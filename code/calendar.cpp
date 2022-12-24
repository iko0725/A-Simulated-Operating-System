#include "calendar.h"
#include "ui_calendar.h"
#include <QDateTime>
#include <QTimer>
#include "h_gv.h"
#include <iostream>

/*
 * Function: Calendar
 * Usage:Calendar(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction function of calendar, including some
 * initialization of the calendar.
 */
Calendar::Calendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    allocate_memory[2].memory_size = 500 + (rand() % (100-0+1))+0;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    //Set window icon
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));

    fTimer=new QTimer(this);
    fTimer->stop();
    fTimer->setInterval (1000) ;
    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));

    show_time();
    showTimer =new QTimer(this);
    showTimer->setInterval (1000) ;
    connect(showTimer,SIGNAL(timeout()),this,SLOT(show_time()));
    showTimer->start();

    thread_calendar = new QTimer(this);
    thread_calendar->setInterval (1000) ;
    connect(thread_calendar,SIGNAL(timeout()),this,SLOT(showThread_calendar()));
    thread_calendar->start();

    ui->progressBar->setValue(0);
}

/*
 * Function: ~Calendar
 * Usage:~Calendar();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
Calendar::~Calendar(){
    allocate_memory[2].memory_size = 0;
    delete ui;
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Calendar closed.\t"+times);
    flags[2]=0;
    thread_calendar->stop();
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==2){
            process.erase(process.begin()+i);
            break;
        }
    }
    showTimer->stop();
}

/*
 * Implementation notes: on_updtimebtnte_clicked, on_startBtn_clicked, on_stopBtn_clicked
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
void Calendar::on_updtimebtnte_clicked()
{
    allocate_memory[2].memory_size = 30 + (rand() % (10-0+1))+0;
    QDateTime curDateTime=QDateTime::currentDateTime();
    ui->le_time ->setText (curDateTime.toString ("hh:mm: ss"));
    ui->le_date->setText(curDateTime.toString("yyyy-MM-dd"));
    ui->le_td->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

void Calendar::on_startBtn_clicked()
{
    allocate_memory[2].memory_size = 35 + (rand() % (100-0+1))+0;
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    fTimer->start () ;// Timer srat to work
    fTimeCounter.start() ;
    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);
}

void Calendar::on_stopBtn_clicked()
{
    fTimer->stop () ; //Timer stop
    int tmMsec=fTimeCounter.elapsed() ;//ms
    int ms=tmMsec%1000;
    int sec=tmMsec/1000;
    QString mss,secs;
    mss = QString::number(ms);
    secs = QString::number(sec);
    ui->label_elapsed->clear();
    ui->label_elapsed->update();
    QString str= "Eclapsed time: "+secs+ "s";
    std::cout<<str.toStdString()<<std::endl;
    ui->label_elapsed->setText(str);
    ui->label_elapsed->show();
    ui->label_elapsed->update();
    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);
}

/*
 * Implementation notes: showThread_calendar, show_time, on_timer_timeout
 * ----------------------------------------
 * Thease are slots for the Qtimer.
 */
void Calendar::on_timer_timeout(){
        QTime curTime=QTime::currentTime(); //get current tme
        ui->lcdHour->setPalette(Qt::black);
        ui->lcdMin->setPalette(Qt::black);
        ui->lcdSec->setPalette(Qt::black);
        ui->lcdHour->display (curTime.hour()); //show hour
        ui->lcdMin->display (curTime.minute()); //show minutes
        ui->lcdSec->display(curTime.second()); //show seconds
        int va=ui->progressBar->value();
        va++;
        if (va>100)
            va=0;
        ui->progressBar->setValue(va);
        QString str= "Eclapsed time: "+QString::number(va)+ "s";
        ui->label_elapsed->setText(str);
        ui->label_elapsed->show();
        update();
}


void Calendar::show_time(){
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->le_time ->setText (curDateTime.toString ("hh:mm: ss"));
    ui->le_date->setText(curDateTime.toString("yyyy-MM-dd"));
    ui->le_td->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

void Calendar::showThread_calendar(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Calendar is running:" + t);
}
