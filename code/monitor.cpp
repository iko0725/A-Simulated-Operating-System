#include "monitor.h"
#include "ui_monitor.h"
#include <QStandardItemModel>
#include <time.h>
#include <QTimer>
#include <QDateTime>
#include "h_gv.h"
#include <iostream>
#include <QMessageBox>
/*
 * Function: Monitor
 * Usage:Monitor(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction function of monitor, including some
 * initialization of the monitor.
 */
Monitor::Monitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Monitor)
{
    ui->setupUi(this);
    //Set title
    this->setWindowTitle("Monitor");
    allocate_memory[9].memory_size = 200 + (rand() % (100-0+1))+0;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    update_CPU_table();
    update_storage_table();
    updateTimer =new QTimer(this);
    updateTimer->setInterval (3000) ;
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(updateTable()));
    updateTimer->start();

    thread_monitor = new QTimer(this);
    thread_monitor->setInterval (1000) ;
    connect(thread_monitor,SIGNAL(timeout()),this,SLOT(showThread_monitor()));
    thread_monitor->start();

    QPalette pl = ui->textEdit_storage->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    ui->textEdit_storage->setPalette(pl);
    ui->progressBar_storage->setMaximum(100);
    ui->progressBar_storage->setValue(0);

}
/*
 * Function: ~Monitor
 * Usage:~Monitor();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
Monitor::~Monitor()
{
    delete ui;
    allocate_memory[9].memory_size = 0;
    updateTimer->stop();
    thread_monitor->stop();
    flags[9]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[9]==0){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Monitor closed.\t"+times);
}


/*
 * Implementation notes: on_pushButton_storage_clicked, on_pushButton_CPU_clicked
 * on_tableWidget_CPU_cellDoubleClicked
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
void Monitor::on_pushButton_storage_clicked()
{
    update_storage_table();
    allocate_memory[9].memory_size = 80 + (rand() % (100-0+1))+0;
    ui->stackedWidget->setCurrentIndex(1);

}

/*
 * Function: on_pushButton_CPU_clicked
 * Usage:on_pushButton_CPU_clicked()
 * ---------------------------------
 * Get the reaction when double click the CPU.
 */
void Monitor::on_pushButton_CPU_clicked()
{
    update_CPU_table();
    ui->stackedWidget->setCurrentIndex(0);

}

/*
 * Function: on_tableWidget_CPU_cellDoubleClicked
 * Usage:on_tableWidget_CPU_cellDoubleClicked(int row, int column)
 * ------------------
 * Get the reaction when double click the table.
 */
void Monitor::on_tableWidget_CPU_cellDoubleClicked(int row, int column)
{
    column++;
    QTableWidgetItem * item2 = new QTableWidgetItem;
    item2 = ui->tableWidget_CPU->item(row,1);
    QString cpu=item2->text();
    if(cpu!="0"){
        int ret1 = QMessageBox::question(this,QString("Qestion"),QString("Force this app to quit?"),QMessageBox::Yes,QMessageBox::No);
        if (ret1 == QMessageBox::Yes){
            QTableWidgetItem * item1 = new QTableWidgetItem;
            item1 = ui->tableWidget_CPU->item(row,0);
            QString appname=item1->text();
            for (int i=0;i<15;i++){
                if(allocate_memory[i].task_name == appname){
                    if(i==6) wids[0]->close();
                    else if(i==11) wids[1]->close();
                    else dlgs[i]->close();
                }
            }
        }
    }
}

/*
 * Function: update_CPU_table
 * Usage:update_CPU_table()
 * ------------------
 * update the information in the CPU table.
 */
void Monitor::update_CPU_table()
{
    allocate_memory[9].memory_size = 100 + (rand() % (100-0+1))+0;
    srand( (unsigned)time( NULL ) );
    ui->tableWidget_CPU->setColumnCount(5);
    ui->tableWidget_CPU->horizontalHeader()-> setSectionsClickable(false);
    QStringList header_CPU;
    header_CPU.append("process name");
    header_CPU.append("%CPU");
    header_CPU.append("thread");
    header_CPU.append("%GPU");
    header_CPU.append("user");
    ui->tableWidget_CPU->setHorizontalHeaderLabels(header_CPU);

    //set fromt
    QFont font = ui->tableWidget_CPU->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget_CPU->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_CPU->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_CPU->horizontalHeader()->setFont(font);
    ui->tableWidget_CPU->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget_CPU->setMouseTracking(true);
    ui->tableWidget_CPU->setStyleSheet("selection-background-color:rgb(255,209,128)");
    ui->tableWidget_CPU->verticalHeader()->setVisible(false);
    ui->tableWidget_CPU->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_CPU->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget_CPU->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget_CPU->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget_CPU->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget_CPU->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    ui->tableWidget_CPU->setRowCount(0);
    int openapp =0;
    QVector<int> openappnum;
    for (int i=0; i<15;i++){
        if (flags[i]==1){
            openapp++;
            openappnum.push_back(i);
        }
    }
    for(int i = 0; i < 15; ++i)
    {
        int rowCount = ui->tableWidget_CPU->rowCount();
        ui->tableWidget_CPU->insertRow(rowCount);

        QTableWidgetItem *item1 = new QTableWidgetItem;
        QTableWidgetItem *item2 = new QTableWidgetItem;
        QTableWidgetItem *item3 = new QTableWidgetItem;
        QTableWidgetItem *item4 = new QTableWidgetItem;
        QTableWidgetItem *item5 = new QTableWidgetItem;

        item1->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item2->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item3->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item4->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item5->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);


        QFont font;
        font.setPointSize(15);
        item1->setFont( font );
        item1->setText(allocate_memory[i].task_name);


        float i_2 = rand()%12;
        QString f_2;
        if(std::find(openappnum.begin(), openappnum.end(), i)==openappnum.end()){
            f_2 = QString("%1").arg(0);
        }else{
            if(i==14) f_2 = QString::number(rand()%24);
            else{
                f_2 = QString("%1").arg(i_2);
            }

        }
        item2->setText(f_2);

        float i_3 = rand()%24;
        QString f_3 = QString("%1").arg(i_3);
        item3->setText(f_3);

        float i_4 = rand()%3;
        QString f_4 = QString("%1").arg(i_4);
        item4->setText(f_4);

        item5->setText(login_username);

        ui->tableWidget_CPU->setItem(rowCount, 0, item1);
        ui->tableWidget_CPU->setItem(rowCount, 1, item2);
        ui->tableWidget_CPU->setItem(rowCount, 2, item3);
        ui->tableWidget_CPU->setItem(rowCount, 3, item4);
        ui->tableWidget_CPU->setItem(rowCount, 4, item5);
    }
    ui->tableWidget_CPU->sortItems(1,Qt::DescendingOrder);
}

/*
 * Function: update_storage_table
 * Usage:update_storage_table()
 * ----------------------------
 * update the information in the storage table.
 */
void Monitor::update_storage_table()
{
    allocate_memory[9].memory_size = 100 + (rand() % (100-0+1))+0;
    srand( (unsigned)time( NULL ) );
    QFont font = ui->tableWidget_CPU->horizontalHeader()->font();
    font.setBold(true);
    QStringList cpu_process_name = {"kernal_task","WindowServer","Browser","Calendar","Text Editor","Photo","Media","Sysmond","Monitor","File"};
    QStringList cpu_user_name = {"root","windowserver_",login_username,login_username,login_username,login_username,login_username,login_username,login_username,login_username};
    ui->tableWidget_storage->setColumnCount(4);

    ui->tableWidget_storage->horizontalHeader()-> setSectionsClickable(false);


    QStringList header;
    header.append("process name");
    header.append("internal storage");
    header.append("thread");
    header.append(login_username);
    ui->tableWidget_storage->setHorizontalHeaderLabels(header);


    ui->tableWidget_storage->horizontalHeader()->setFont(font);

    ui->tableWidget_storage->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget_storage->verticalHeader()->setVisible(false);
    ui->tableWidget_storage->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget_storage->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_storage->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget_storage->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget_storage->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget_storage->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

    ui->tableWidget_storage->setRowCount(0);
    for(int i = 0; i < 15; ++i)
    {
        int rowCount = ui->tableWidget_storage->rowCount();
        ui->tableWidget_storage->insertRow(rowCount);

        QTableWidgetItem *item1 = new QTableWidgetItem;
        QTableWidgetItem *item2 = new QTableWidgetItem;
        QTableWidgetItem *item3 = new QTableWidgetItem;
        QTableWidgetItem *item4 = new QTableWidgetItem;

        item1->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item2->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item3->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
        item4->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);

        QFont font;
        font.setPointSize(15);
        item1->setFont( font );
        item1->setText(allocate_memory[i].task_name);

        item2->setData(Qt::DisplayRole, allocate_memory[i].memory_size+rand()%24);

        float i_3 = rand()%24;
        QString f_3 = QString("%1").arg(i_3);
        item3->setText(f_3);

        item4->setText(login_username);

        ui->tableWidget_storage->setItem(rowCount, 0, item1);
        ui->tableWidget_storage->setItem(rowCount, 1, item2);
        ui->tableWidget_storage->setItem(rowCount, 2, item3);
        ui->tableWidget_storage->setItem(rowCount, 3, item4);
    }
    ui->tableWidget_storage->sortItems(1,Qt::DescendingOrder);
}



void Monitor::updateTable()
{
    update_CPU_table();
    update_storage_table();
    //storage
//    int memory_total = 0;
//    for (int i=0; i<15;i++){
//        memory_total += allocate_memory[i].memory_size;
//    }
//    if(memory_percent>100) memory_percent=100;
//    if(memory_percent>=30){
//        QMessageBox::warning(NULL, "warning", "The memory is nearlly full.");
//        int apptoremove = process[0];
//        process.erase(process.begin());
//        if(apptoremove==6) wids[0]->close();
//        else if(apptoremove==11) wids[1]->close();
//        else dlgs[apptoremove]->close();
//    }
    ui->textEdit_storage->clear();
    ui->textEdit_storage->setText(QString::number(memory_percent) + "%");
    ui->textEdit_storage->update();
    ui->progressBar_storage->setValue(memory_percent);
    ui->progressBar_storage->update();

}

void Monitor::showThread_monitor(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Monitor is running:" + t);
}




