#include "filesys.h"
#include "ui_filesys.h"
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
#include <QDebug>
#include<fstream>
#include "mainwindow.h"
#include "h_gv.h"
#include <stdlib.h>
#include <time.h>
#include "vector"
#include <iostream>
#include <QFileDialog>
#include <QDateTime>
#include <QMenu>
#include <QMessageBox>
#include <QLabel>
#include "h_gv.h"
#include <QLineEdit>
std::vector<std::string> vec_size;
std::vector<std::string> vec_path;
std::vector<std::string> vec_time;
std::vector<std::string> vec_type;
std::vector<std::string> vec_pocition;
std::vector<std::string> vec_content;
QString filepath;

/*
 * Function: Filesys
 * Usage:Filesys(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction function of filesys, including some
 * initialization of the filesys.
 */
FileSys::FileSys(QWidget *parent) :

    QDialog(parent),

    ui(new Ui::FileSys)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    ui->setupUi(this);
    allocate_memory[5].memory_size = 700 + (rand() % (100-0+1))+0;
    thread_filesys = new QTimer(this);
    thread_filesys->setInterval (1000) ;
    connect(thread_filesys,SIGNAL(timeout()),this,SLOT(showThread_filesysy()));
    thread_filesys->start();
}

/*
 * Function: ~Filesys
 * Usage:~Filesys();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
FileSys::~FileSys()
{
    delete ui;
    allocate_memory[5].memory_size = 0;
    thread_filesys->stop();
    flags[5]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==5){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    emit sendData2("File system closed.\t"+times);
}



/*
 * Function: FindFile
 * Usage:QString FindFile(const QString &path);
 * ----------------------------
 * Get the absolute path of a file.
 */
QString FileSys::FindFile(const QString &path) {
    ui->tableWidget_file->setColumnCount(4);
    ui->tableWidget_file->horizontalHeader()-> setSectionsClickable(false);
    QStringList header_file;
    header_file.append("file name");
    header_file.append("file path");
    header_file.append("create time");
    header_file.append("size");
    ui->tableWidget_file->setHorizontalHeaderLabels(header_file);
    QFont font = ui->tableWidget_file->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget_file->horizontalHeader()->setFont(font);
    ui->tableWidget_file->verticalHeader()->setDefaultSectionSize(40);
    //select row
    ui->tableWidget_file->setMouseTracking(true);
    ui->tableWidget_file->setStyleSheet("selection-background-color:rgb(255,209,128)");
    ui->tableWidget_file->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_file->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_file->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_file->verticalHeader()->setVisible(false);
    ui->tableWidget_file->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_file->setColumnWidth(1,530);
    ui->tableWidget_file->setColumnWidth(2,150);

    QString total="";
    QDir dir(path);
    if (!dir.exists()) {
        return "not exist";
    }
    dir.setFilter(QDir::Dirs | QDir::Files);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList list = dir.entryInfoList();
    int i = 0;
    do {

        QFileInfo fileInfo = list.at(i);
        if (fileInfo.fileName() == "." | fileInfo.fileName() == "..") {
            i++;
            continue;
        }
        bool bisDir = fileInfo.isDir();
        if (bisDir) {
            QString subcontent = FindFile(fileInfo.filePath());
            total += subcontent;
        } else {
            QString path = fileInfo.filePath();
            QString filename = fileInfo.fileName();
            qint64 filesize = fileInfo.size();
            QDateTime dt1 = fileInfo.birthTime();
            QString create_time = tr("%1").arg(dt1.toString("yyyy-MM-dd hh:mm:ss"));
            create_time="Create Time: "+create_time;
            char unit ='B';
            if(filesize>1024){
                filesize/=1024;
                unit ='K';
                if(filesize>1024){
                    filesize/=1024;
                    unit ='M';
                    if(filesize>1024){
                        filesize/=1024;
                        unit ='G';
                    }
                }
            }
            QString size = QString::number(filesize)+unit;
            size = "Size: "+size;
            QString line = "filepath: "+path +  "<br/>"+\
                    "filename: "+ filename +  "<br/>"+\
                    "file size: "+size+ "<br/>" +\
                    "create time: "+create_time +"<br/>"+\
                    "-----------------------------------------------------------"+"<br/>";
            total += line;
            int rowCount =ui->tableWidget_file->rowCount();
            ui->tableWidget_file->insertRow(rowCount);
            QTableWidgetItem *item1 = new QTableWidgetItem;
            QTableWidgetItem *item2 = new QTableWidgetItem;
            QTableWidgetItem *item3 = new QTableWidgetItem;
            QTableWidgetItem *item4 = new QTableWidgetItem;

            item1->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
            item2->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
            item3->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);
            item4->setTextAlignment(Qt::AlignHCenter |  Qt::AlignVCenter);

            item1->setText(filename);
            item2->setText(path);
            item3->setText(create_time);
            item4->setText(size);

            ui->tableWidget_file->setItem(rowCount, 0, item1);
            ui->tableWidget_file->setItem(rowCount, 1, item2);
            ui->tableWidget_file->setItem(rowCount, 2, item3);
            ui->tableWidget_file->setItem(rowCount, 3, item4);
        }
        i++;
    } while (i < list.size());


    return total;
}

/*
 * Function: on_pushButton_finder_clicked
 * Usage:on_pushButton_finder_clicked()
 * -----------------------------------
 * Get the reaction when click the pushbutton finder.
 */
void FileSys::on_pushButton_finder_clicked()
{
    allocate_memory[5].memory_size = 750 + (rand() % (100-0+1))+0;
    emit sendData("click_finder.");
    ui->tableWidget_file->clear();
    ui->tableWidget_file->update();
    ui->tableWidget_file->setRowCount(0);
    QString file_path = QFileDialog::getExistingDirectory(this, "Choose filepath…", "./");
    if(file_path !=""){
        filepath = file_path;
    }
    QString total = FindFile(filepath);
}

/*
 * Function: on_tableWidget_file_cellDoubleClicked
 * Usage:on_tableWidget_file_cellDoubleClicked(int row, int column)
 * ----------------------------------------------------------------
 * Get the reaction when double click the table.
 */
void FileSys::on_tableWidget_file_cellDoubleClicked(int row, int column)
{
    row_num = row;
    column_num=column;
    filetool = new QDialog(this);
    QPushButton * btnrename = new QPushButton("rename", filetool);
    QPushButton * btndelete = new QPushButton("delete", filetool);
    filetool->resize(300,100);
    btnrename->move(filetool->width()*0.1,filetool->height()*0.1);
    btndelete->move(filetool->width()*0.4,filetool->height()*0.1);
    connect(btnrename, SIGNAL(clicked(bool)), this, SLOT(renamebtn()));
    connect(btndelete, SIGNAL(clicked(bool)), this, SLOT(deletefile()));

    filetool->show();
    filetool->raise();
    allocate_memory[5].memory_size = 400 + (rand() % (100-0+1))+0;
}

/*
 * Function: renamebtn
 * Usage:renamebtn()
 * -----------------
 * Get the reaction when double click the rename button.
 */
void FileSys::renamebtn(){
    renametool = new QDialog(this);
    QPushButton * rename = new QPushButton("rename", renametool);
    QLabel *l = new QLabel(renametool);
    renamename = new QLineEdit(renametool);
    l->setText("Please enter the new file name (no need to include the suffix):");
    connect(rename, SIGNAL(clicked(bool)), this, SLOT(rename()));
    renametool->resize(500,200);
    rename->move(renametool->width()*0.1,renametool->height()*0.55);
    l->move(renametool->width()*0.1,renametool->height()*0.25);
    renamename->move(renametool->width()*0.1,renametool->height()*0.4);
    renametool->show();
    renametool->raise();
}

/*
 * Function: rename
 * Usage:rename()
 * -----------------
 * Get the reaction when double click the rename button.
 */
void FileSys::rename(){
    QString renameName = renamename->text();
    QString filePath = ui->tableWidget_file->item(row_num,1)->text();
    QString prenamename = filePath;
    int index = filePath.lastIndexOf('/');
    int indexdot = filePath.lastIndexOf('.');
    QString file_suffix = filePath.mid(indexdot,filePath.length()-indexdot);
    filePath = filePath.mid(0,index+1);
    renameName = filePath+renameName+file_suffix;
    if(QFile::rename(prenamename,renameName)){
        QMessageBox::information(this,"Success","File is renamed.");
    }else{
        QMessageBox::information(this,"Fail","File cannot be renamed");
    }
}

/*
 * Function: deletefile()
 * Usage:deletefile()
 * -----------------
 * Get the reaction when double click the delete button.
 */
void FileSys::deletefile(){
    int ret1 = QMessageBox::question(this,QString("Qestion"),QString("ARE YOU SURE TO DELETE THIS FILE? (permanent)"),QMessageBox::Yes,QMessageBox::No);
    if (ret1 == QMessageBox::Yes) {
       QTableWidgetItem * item1 = new QTableWidgetItem;
       item1 = ui->tableWidget_file->item(row_num,1);
       QString filePath = item1->text();
       if (QFile::remove(filePath)){
           QMessageBox::information(this,"Success","File is removing.");
       }else{
           QMessageBox::information(this,"Fail","File is not exists.");
       }
    }
}

/*
 * Implementation notes: showThread_filesysy
 * ----------------------------------------
 * This is a slot for the Qtimer.
 */
void FileSys::showThread_filesysy(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("File system is running:" + t);
}



void FileSys::on_pushButton_refresh_clicked()
{
    ui->tableWidget_file->clear();
    ui->tableWidget_file->update();
    ui->tableWidget_file->setRowCount(0);
    QString total = FindFile(filepath);
}
