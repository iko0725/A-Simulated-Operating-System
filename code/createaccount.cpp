#include "createaccount.h"
#include "ui_createaccount.h"
#include "ui_deleteaccount.h"
#include <QMessageBox>
#include <QtCore/QCoreApplication>
#include <fstream>
#include <iostream>
#include "vector"
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
#include <QDebug>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "vector"
#include <iostream>
#include "h_gv.h"
#include <QTimer>
#include <QDateTime>
#include <QDir>


std::vector<std::string> username_create;
std::vector<std::string> password_create;
std::string input_path_username;
std::string input_path_password;


/*
 * Class: CreateAccount <QDialog>
 * -----------------------
 * This class implements account creation of the OS.
 */


CreateAccount::CreateAccount(QWidget *parent):

    QDialog(parent),
    ui(new Ui::CreateAccount){
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
    input_path_username = fu.toStdString();
    input_path_password = fp.toStdString();
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    allocate_memory[4].memory_size = 350 + (rand() % (100-0+1))+0;
    //Set window icon
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));
    thread_createaccount = new QTimer(this);
    thread_createaccount->setInterval (1000) ;
    connect(thread_createaccount,SIGNAL(timeout()),this,SLOT(showThread_createaccount()));
    thread_createaccount->start();
    initialize_account();
}

CreateAccount::~CreateAccount(){
    delete ui;
    thread_createaccount->stop();
    flags[4]=0;
    for(int i = 0;i<int(process.size());i++){
            if(process[i]==4){
                process.erase(process.begin()+i);
                break;
            }
    }
    allocate_memory[4].memory_size =0 + (rand() % (100-0+1))+0;
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Account setting closed.\t"+times);
}


/*
 * Function: initialize_account();
 * Usage: initialize_account();
 * ------------------------------------
 * Based on the username and password, the function could save the information
 * into c=related txt file for saving accounts. Then, the account is created
 * successfully and permanently.
 */
void CreateAccount::initialize_account(){
    allocate_memory[4].memory_size = 400 + (rand() % (100-0+1))+0;
    std::fstream file_username;
    std::string line_username;
    username_create.clear();
    password_create.clear();
    file_username.open(input_path_username.c_str());                    // open input file
    while (getline(file_username, line_username)){
        username_create.push_back(line_username);
    }
    file_username.close();

    std::fstream file_password;
    std::string line_password;
    file_password.open(input_path_password.c_str());                    // open input file
    while (getline(file_password, line_password)){
        password_create.push_back(line_password);
    }
    file_password.close();

}


/*
 * Function: on_create_clicked
 * Usage: on_create_clicked()
 * ------------------------------------
 * Click the create button. This implementation can create a new
 * acount for the OS based on the username and password that the user enters.
 * The function could save the information into c=related txt file for saving accounts.
 * Then, the account is created successfully and permanently.
 */
void CreateAccount::on_create_clicked(){
    allocate_memory[4].memory_size = 400 + (rand() % (100-0+1))+0;
    initialize_account();
    if (int(username_create.size()) >= 10){
         QMessageBox::warning(this, tr("Warning"),tr("There are already 10 accounts, please delete some accounts first!"), QMessageBox::Yes);
         return;
    }
    for (int i = 0; i < int(username_create.size()); i++){
        if(ui->createname->text() == QString::fromStdString(username_create[i]) && ui->createpass->text() == QString::fromStdString(password_create[i])){
            QMessageBox::warning(this, tr("Warning"),tr("User name and passward have existed!"), QMessageBox::Yes);
            ui->createname->clear();
            ui->createpass->clear();
            return;
        }
    }

    username_create.push_back(ui->createname->text().toStdString());
    password_create.push_back(ui->createpass->text().toStdString());
    std::ofstream update_username;
    update_username.open(input_path_username.c_str());
    std::ofstream update_password;
    update_password.open(input_path_password.c_str());
    for (int i = 0; i < int(username_create.size()); i++){
        update_username << username_create[i] << std::endl;
        update_password << password_create[i] << std::endl;
    }
    update_password.close();
    update_username.close();
    QMessageBox::information(this,"Success","The account is created.");
}



/*
 * Function: on_delete_button_clicked
 * Usage: on_delete_button_clicked()
 * ------------------------------------
 * Click the delete button. This implementation would show a new window
 * for deleting. Users can do delete operations on the new window.
 */
void CreateAccount::on_delete_button_clicked(){
    QDialog *dlg = new DeleteAccount(this);
    dlg->show();
}


/*
 * Function: showThread_createaccount
 * Usage: showThread_createaccount();
 * ------------------------------------
 *
 */
void CreateAccount::showThread_createaccount(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Account creation is running:" + t);
}



/*
 * Class: DeleteAccount <QDialog>
 * -----------------------
 * This class implements deleting accounts of the OS.
 */
DeleteAccount::DeleteAccount(QWidget *parent):
    QDialog(parent),
    ui(new Ui::DeleteAccount){
    ui->setupUi(this);
    initialize_delete_account();
}

DeleteAccount::~DeleteAccount(){
    delete ui;
}


/*
 * Function: initialize_delete_account
 * Usage: initialize_delete_account();
 * ------------------------------------
 * This implementation would read the acount informnation.
 * After that, refresh the account information on the window
 * for deleting accounts.
 */
void DeleteAccount::initialize_delete_account(){
    std::fstream file_username;
    std::string line_username;
    username_create.clear();
    password_create.clear();
    file_username.open(input_path_username.c_str());                    // open input file
    while (getline(file_username, line_username)){
        username_create.push_back(line_username);
    }
    file_username.close();

    std::fstream file_password;
    std::string line_password;
    file_password.open(input_path_password.c_str());                    // open input file
    while (getline(file_password, line_password)){
        password_create.push_back(line_password);
    }
    file_password.close();
    allocate_memory[4].memory_size = 380 + (rand() % (100-0+1))+0;
    ui->checkBox_1->setText(QString::fromStdString(""));
    ui->checkBox_2->setText(QString::fromStdString(""));
    ui->checkBox_3->setText(QString::fromStdString(""));
    ui->checkBox_4->setText(QString::fromStdString(""));
    ui->checkBox_5->setText(QString::fromStdString(""));
    ui->checkBox_6->setText(QString::fromStdString(""));
    ui->checkBox_7->setText(QString::fromStdString(""));
    ui->checkBox_8->setText(QString::fromStdString(""));
    ui->checkBox_9->setText(QString::fromStdString(""));
    ui->checkBox_10->setText(QString::fromStdString(""));
    if (int(username_create.size() >= 1)) ui->checkBox_1->setText(QString::fromStdString(username_create[0]));
    if (int(username_create.size() >= 2)) ui->checkBox_2->setText(QString::fromStdString(username_create[1]));
    if (int(username_create.size() >= 3)) ui->checkBox_3->setText(QString::fromStdString(username_create[2]));
    if (int(username_create.size() >= 4)) ui->checkBox_4->setText(QString::fromStdString(username_create[3]));
    if (int(username_create.size() >= 5)) ui->checkBox_5->setText(QString::fromStdString(username_create[4]));
    if (int(username_create.size() >= 6)) ui->checkBox_6->setText(QString::fromStdString(username_create[5]));
    if (int(username_create.size() >= 7)) ui->checkBox_7->setText(QString::fromStdString(username_create[6]));
    if (int(username_create.size() >= 8)) ui->checkBox_8->setText(QString::fromStdString(username_create[7]));
    if (int(username_create.size() >= 9)) ui->checkBox_9->setText(QString::fromStdString(username_create[8]));
    if (int(username_create.size() >= 10)) ui->checkBox_10->setText(QString::fromStdString(username_create[9]));
}



/*
 * Function:  on_deleteconfirm_clicked
 * Usage:  on_deleteconfirm_clicked();
 * ------------------------------------
 * Click the confirm button. This implementation can delete the account
 * information in related txt file. Therefore, the account is deleted permanently.
 */
void DeleteAccount::on_deleteconfirm_clicked(){
    allocate_memory[4].memory_size = 380 + (rand() % (100-0+1))+0;
    if(ui->secretepsw->text() != tr("3002")){
        QMessageBox::warning(this, tr("Warning"),tr("Please enter the correct secrete password!"), QMessageBox::Yes);
        return;
    }
    ui->secretepsw->clear();
    std::vector<int> delete_index;
    if(ui->checkBox_1->isChecked() == true){
        delete_index.push_back(0);
    }
    if(ui->checkBox_2->isChecked() == true){
        delete_index.push_back(1);
    }
    if(ui->checkBox_3->isChecked() == true){
        delete_index.push_back(2);
    }
    if(ui->checkBox_4->isChecked() == true){
        delete_index.push_back(3);
    }
    if(ui->checkBox_5->isChecked() == true){
        delete_index.push_back(4);
    }
    if(ui->checkBox_6->isChecked() == true){
        delete_index.push_back(5);
    }
    if(ui->checkBox_7->isChecked() == true){
        delete_index.push_back(6);
    }
    if(ui->checkBox_8->isChecked() == true){
        delete_index.push_back(7);
    }
    if(ui->checkBox_9->isChecked() == true){
        delete_index.push_back(8);
    }
    if(ui->checkBox_10->isChecked() == true){
        delete_index.push_back(9);
    }

    int i = 0;
    for (auto it = username_create.begin(); it != username_create.end();)	{
        for (int j = 0; j <= int(delete_index.size());j++){
            if (i == delete_index[j]){
                it = username_create.erase(it);
                --it;
            }
        }
        ++it;
        i++;
    }

    int m = 0;
    for (auto it_psw = password_create.begin(); it_psw != password_create.end();)	{
        for (int n = 0; n <= int(delete_index.size());n++){
            if (m == delete_index[n]){
                it_psw = password_create.erase(it_psw);
                --it_psw;
            }
        }
        ++it_psw;
        m++;
    }

    std::ofstream delete_update_username;
    delete_update_username.open(input_path_username.c_str());
    std::ofstream delete_update_password;
    delete_update_password.open(input_path_password.c_str());
    for (int i = 0; i < int(username_create.size()); i++){
        delete_update_username << username_create[i] << std::endl;
        delete_update_password << password_create[i] << std::endl;
    }
    delete_update_password.close();
    delete_update_username.close();
}


/*
 * Function: on_refresh_clicked
 * Usage: on_refresh_clicked()
 * ------------------------------------
 * Click the refresh button. This implementation refresh the account information
 * on the window. Then, the account that is deleted before would disappear.
 */
void DeleteAccount::on_refresh_clicked(){
    initialize_delete_account();

}

