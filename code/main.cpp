#include "mainwindow.h"
#include "opening.h"
#include "logindlg.h"
#include <ctime>
#include <QApplication>
#include <QSound>
#include <QTimer>
#include "h_gv.h"

void  initialize_memory();

int main(int argc, char *argv[])
{
    initialize_memory();
    flag_login = false;
    login_username = "user";
    for( int i = 0; i < 15; i = i + 1 )  flags.push_back(0);
    for( int i = 0; i < 15; i = i + 1 )  dlgs.push_back(NULL);
    for( int i = 0; i < 2 ; i = i + 1 )  wids.push_back(NULL);
    QApplication a(argc, argv);
    LoginDlg dlg;
    //Set SE: opening up
    QSound opening (":/SE/open.wav");
    //Play SE: opening up
    opening.play();

    if(dlg.exec() == QDialog::Accepted){
        flag_login = true;
        MainWindow w;
        w.show();
        return a.exec();
    }
    else return 0;
}

void initialize_memory(){

    //index = 0
    Task task_Browser;
    task_Browser.task_name = "Browser";
    task_Browser.memory_size = 0;
    allocate_memory.push_back(task_Browser);

    //index = 1
    Task task_Calculator;
    task_Calculator.task_name = "Calculator";
    task_Calculator.memory_size = 0;
    allocate_memory.push_back(task_Calculator);

    //index = 2
    Task task_Calendar;
    task_Calendar.task_name = "Calendar";
    task_Calendar.memory_size = 0;
    allocate_memory.push_back(task_Calendar);

    //index = 3
    Task task_Camera;
    task_Camera.task_name = "Camera";
    task_Camera.memory_size = 0;
    allocate_memory.push_back(task_Camera);

    //index = 4
    Task task_Account;
    task_Account.task_name = "Account";
    task_Account.memory_size = 0;
    allocate_memory.push_back(task_Account);

    //index = 5
    Task task_filesys;
    task_filesys.task_name = "File System";
    task_filesys.memory_size = 0;
    allocate_memory.push_back(task_filesys);

    //index = 6
    Task task_Snake;
    task_Snake.task_name = "Gluttonous Snake Game";
    task_Snake.memory_size = 0;
    allocate_memory.push_back(task_Snake);

    //index = 7
    Task task_Login;
    task_Login.task_name = "Login";
    task_Login.memory_size = 0;
    allocate_memory.push_back(task_Login);

    //index = 8
    Task task_Memoset;
    task_Memoset.task_name = "Memoset";
    task_Memoset.memory_size = 0;
    allocate_memory.push_back(task_Memoset);

    //index = 9
    Task task_Monitor;
    task_Monitor.task_name = "Monitor";
    task_Monitor.memory_size = 0;
    allocate_memory.push_back(task_Monitor);

    //index = 10
    Task task_Painter;
    task_Painter.task_name = "Painter";
    task_Painter.memory_size = 0;
    allocate_memory.push_back(task_Painter);

    //index = 11
    Task task_Photo;
    task_Photo.task_name = "Photo Editor";
    task_Photo.memory_size = 0;
    allocate_memory.push_back(task_Photo);

    //index = 12
    Task task_Recorder;
    task_Recorder.task_name = "Recorder";
    task_Recorder.memory_size = 0;
    allocate_memory.push_back(task_Recorder);

    //index = 13
    Task task_texteditor;
    task_texteditor.task_name = "Text Editor";
    task_texteditor.memory_size = 0;
    allocate_memory.push_back(task_texteditor);

    //index = 14
    Task task_Videoplayer;
    task_Videoplayer.task_name = "Video Player";
    task_Videoplayer.memory_size = 0;
    allocate_memory.push_back(task_Videoplayer);
}
