#include "memoset.h"
#include "ui_memoset.h"
#include <iostream>
#include<fstream>
#include<QDir>
#include "h_gv.h"
/*
 * Function: Memoset
 * Usage:Memoset(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction function of memoset, including some
 * initialization of the memoset.
 */
Memoset::Memoset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Memoset)
{
    ui->setupUi(this);
    //Set title
    this->setWindowTitle("Memo");
    allocate_memory[8].memory_size = 300 + (rand() % (50-0+1))+0;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    thread_memo = new QTimer(this);
    thread_memo->setInterval (1000) ;
    connect(thread_memo,SIGNAL(timeout()),this,SLOT(showThread_memo()));
    thread_memo->start();
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->dateTimeEdit_memo->setDateTime(curDateTime);
    ui->dateEdit_searchmemo->setDate(curDateTime.date());

}

/*
 * Function: ~Memoset
 * Usage:~Memoset();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
Memoset::~Memoset()
{
    delete ui;
    allocate_memory[8].memory_size = 0;
    thread_memo->stop();
    flags[8]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==8){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Memo closed.\t"+times);
}

/*
 * Implementation notes: on_pushButton_memoset_clicked, on_pushButton_showall_clicked
 * on_pushButton_search_clicked
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
void Memoset::on_pushButton_memoset_clicked()
{
    allocate_memory[8].memory_size = 400 + (rand() % (50-0+1))+0;
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

    QString time=ui->dateTimeEdit_memo->text();
    QString matter = ui->lineEdit_matter->text();

    QString fm=nowps+"/CSC3002project/memo/matter.txt";

    std::string memo_path = fm.toStdString();
//    std::cout<<memo_path<<std::endl;
    std::ofstream write_file;
    write_file.open(memo_path.c_str(),std::ios::app);
    if(!write_file.is_open()){
        std::cout<<"not open"<<std::endl;
    }
    std::string time_s = time.toStdString();
    write_file <<time_s<<"\n";
    std::string matter_s = matter.toStdString();
    write_file <<matter_s<<"\n";
    write_file.close();
}

/*
 * Function:on_pushButton_showall_clicked
 * Usage:on_pushButton_showall_clicked()
 * ----------------------------------------
 * Get the reaction when clicked the pushButton showall.
 */
void Memoset::on_pushButton_showall_clicked()
{
    allocate_memory[8].memory_size = 420 + (rand() % (50-0+1))+0;
    //ingore the matters with time before now.
    ui->textEdit_matter->clear();
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
    QString fm=nowps+"/CSC3002project/memo/matter.txt";
    std::string memo_path = fm.toStdString();
    std::fstream file;
    std::string line;
    QString total="";
    file.open(memo_path.c_str());                    // open input file
    while (getline(file, line))  {
        QString ori_line = QString::fromStdString(line);
        line = line.substr(0,(line.find("上午")-1));
        line = line.substr(0,(line.find("下午")-1));
        QString lineq = QString::fromStdString(line);
        QDateTime timenow = QDateTime::currentDateTime();
        QString timenowq = timenow.toString("yyyy/MM/dd");

        int p1 = line.find_first_of('/');
        int p2 = line.find_last_of('/');
        int l = line.length();
        timenowq = timenowq.remove(QString("/"), Qt::CaseInsensitive);
        lineq = lineq.remove(QString("/"),Qt::CaseInsensitive);
        if(p2-p1 == 2){
            lineq = lineq.insert(4,'0');
        }
        if(l-p2 == 2){
            lineq = lineq.insert(6,'0');
        }
        int timemem = lineq.toInt();
        int timenownum = timenowq.toInt();
        int i = timemem-timenownum;
        if(i >=0){
            total += (ori_line + "<br/>");
            getline(file, line);
            total += (QString::fromStdString(line) + "<br/>");
        }else{
            getline(file, line);
        }
    }
    ui->textEdit_matter->setText(total);
    ui->textEdit_matter->update();
    file.close();
}

/*
 * Function:on_pushButton_search_clicked
 * Usage:on_pushButton_search_clicked()
 * ----------------------------------------
 * Get the reaction when clicked the pushButton search.
 */
void Memoset::on_pushButton_search_clicked()
{
    allocate_memory[8].memory_size = 420 + (rand() % (50-0+1))+0;
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
    QString time_forsearch = ui->dateEdit_searchmemo->text();
    ui->textEdit_matter->clear();
    QString fm=nowps+"/CSC3002project/memo/matter.txt";
    std::string memo_path = fm.toStdString();
    std::fstream file;
    std::string line;
    QString total="";
    file.open(memo_path.c_str());
    while (getline(file, line)) {
        QString ori_line = QString::fromStdString(line);
        line = line.substr(0,(line.find("上午")-1));
        line = line.substr(0,(line.find("下午")-1));
        if(line == time_forsearch.toStdString()){
            total += (ori_line + "<br/>");
            getline(file, line);
            total += (QString::fromStdString(line) + "<br/>");
        }else{
            getline(file, line);
        }
    }
    ui->textEdit_matter->setText(total);
    ui->textEdit_matter->update();
    file.close();
}

/*
 * Implementation notes: showThread_memo
 * ----------------------------------------
 * This is a slot for the Qtimer.
 */
void Memoset::showThread_memo(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Memo is running:" + t);
}

void Memoset::on_pushButton_delete_clicked()
{
    allocate_memory[8].memory_size = 420 + (rand() % (50-0+1))+0;
    //ingore the matters with time before now.
    ui->textEdit_matter->clear();
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
    QString fm=nowps+"/CSC3002project/memo/matter.txt";
    std::string memo_path = fm.toStdString();
    std::fstream file;
    std::string line;
    QString total="";
    std::cout<<memo_path<<std::endl;
    file.open(memo_path.c_str(),std::ios::in|std::ios::out);                    // open input file
    while (getline(file, line))  {
        QString ori_line = QString::fromStdString(line);
        line = line.substr(0,(line.find("上午")-1));
        line = line.substr(0,(line.find("下午")-1));
        QString lineq = QString::fromStdString(line);
        QDateTime timenow = QDateTime::currentDateTime();
        QString timenowq = timenow.toString("yyyy/MM/dd");

        int p1 = line.find_first_of('/');
        int p2 = line.find_last_of('/');
        int l = line.length();
        timenowq = timenowq.remove(QString("/"), Qt::CaseInsensitive);
        lineq = lineq.remove(QString("/"),Qt::CaseInsensitive);
        if(p2-p1 == 2){
            lineq = lineq.insert(4,'0');
        }
        if(l-p2 == 2){
            lineq = lineq.insert(6,'0');
        }
        int timemem = lineq.toInt();
        int timenownum = timenowq.toInt();
        int i = timemem-timenownum;
        if(i >=0){
            total += (ori_line + "\n");
            getline(file, line);
            total += (QString::fromStdString(line) + "\n");
        }else{
            getline(file, line);
        }
    }
    total = total.mid(0,total.length()-1);
    file.close();
    std::ofstream out;
    out.open(memo_path,std::ios::trunc);
    std::cout<<total.toStdString()<<std::endl;
    out<<total.toStdString()<<std::endl;
    out.close();
}
