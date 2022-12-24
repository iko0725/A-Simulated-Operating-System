#include "texteditor.h"
#include "ui_texteditor.h"
#include "ui_savewarn.h"
#include <QDragEnterEvent>
#include <QCloseEvent>
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
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QTimer>
#include "h_gv.h"
std::string text_content;
bool save_flag = false;
bool text_window_flag = true;
QString new_content;
QString original_content;
std::string input_path;
QString input_path_qstring;

/*
 * Class: TextEditor <QDialog>
 * -----------------------
 * This class allows to record sound and save it in the computer.
 */
TextEditor::TextEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextEditor){
    allocate_memory[13].memory_size = 350 + (rand() % (10-0+1))+0;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    ui->setupUi(this);

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
    input_path_qstring = nowps+"/CSC3002project/text_editor/test.txt";
    input_path = input_path_qstring.toStdString();

    thread_texteditor = new QTimer(this);
    thread_texteditor->setInterval (1000) ;
    connect(thread_texteditor,SIGNAL(timeout()),this,SLOT(showThread_texteditor()));
    thread_texteditor->start();
    //Set window icon
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));
    read_text();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatecontent()));// slotCountMessage
    timer->start(1000); // per second

}


/*
 * Function: ~TextEditor
 * Usage: ~TextEditor()
 * ------------------------------------
 * Close the window. If the user do not save the content, check whether the content
 * is changes or not. Ask user to decide whether the user want to save the change or not.
 */
TextEditor::~TextEditor(){
    allocate_memory[13].memory_size = 0;
    if ((save_flag == true)| (original_content == new_content)) {
        save_flag = false;
    }
    else{
        int answer = QMessageBox::question(this,
                                                   tr("Quit"),
                                                   tr("You do not save the file now. Are you sure to quit this application?"),
                                                    QMessageBox::Close,  QMessageBox::Save);
        if( answer == QMessageBox::Save){
            std::string update_content = new_content.toStdString();
            std::ofstream write_file;
            save_flag = false;
            write_file.open(input_path.c_str());
            write_file << update_content;
            write_file.close();
            accept();
        }else {
            accept();
        }
    }


    delete ui;
    flags[13]=0;
    for(int i = 0;i<int(process.size());i++){
            if(process[i]==13){
                process.erase(process.begin()+i);
                break;
            }
        }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Text eidtor closed.\t"+times);
}


/*
 * Function: updatecontent
 * Usage: updatecontent();
 * ------------------------------------
 * Read the content in the textEdit and save the content into a string.
 */
void TextEditor::updatecontent(){
    new_content = ui->textEdit->toPlainText();
}


/*
 * Function: on_save_clicked
 * Usage: on_save_clicked()
 * ------------------------------------
 * Click the save button. Then the content in the text editor
 * would be saved permanently.
 */
void TextEditor::on_save_clicked(){
    save_flag = true;
    new_content = ui->textEdit->toPlainText();
    std::string update_content = new_content.toStdString();
    std::ofstream write_file;
    write_file.open(input_path.c_str());
    write_file << update_content;
    write_file.close();
}


/*
 * Function: on_clear_clicked
 * Usage: on_clear_clicked()
 * ------------------------------------
 * Click the clear button. Then the content in the text editor
 * would be cleared.
 */
void TextEditor::on_clear_clicked(){
    ui->textEdit->setText("");
}


/*
 * Function: on_undo_clicked
 * Usage: on_undo_clicked()
 * ------------------------------------
 * Click the undo button. Then the text editor would undo the last step.
 */
void TextEditor::on_undo_clicked(){
    ui->textEdit->undo();
}


/*
 * Function: on_redo_clicked
 * Usage: on_redo_clicked()
 * ------------------------------------
 * Click the redo button. Then the text editor would redo the last step.
 */
void TextEditor::on_redo_clicked(){
    ui->textEdit->redo();
}


/*
 * Function: read_text
 * Usage: read_text()
 * ------------------------------------
 * According to the path chosen by user, read the content of text file.
 * Then, the text editor would show up the content.
 */
void TextEditor::read_text(){
    ui->textEdit->clear();
    std::fstream file;
    std::string line;
    QString total="";
    file.open(input_path.c_str());                    // open input file
    while (getline(file, line))  {
        total += (QString::fromStdString(line) + "<br/>");
    }
    ui->textEdit->setText(total);
    original_content = ui->textEdit->toPlainText();
    file.close();
}

/*
 * Function: on_findtext_clicked
 * Usage: on_findtext_clicked()
 * ------------------------------------
 * Click the finder button. Then the text editor would ask user to choose a
 * text file and open it in the text editor.
 */
void TextEditor::on_findtext_clicked(){
    allocate_memory[13].memory_size = 380 + (rand() % (10-0+1))+0;
    ui->textEdit->clear();
    QUrl file_path = QFileDialog::getOpenFileUrl(this, "Choose textfile",tr("Text (*.txt)"),tr("Text (*.txt)"));
    if (file_path.path().toStdString() != "")   input_path = file_path.path().toStdString();
    read_text();
}


/*
 * Class: SaveWarn <QDialog>
 * -----------------------
 * This class allows to check whether the user saves the file or not.
 */
SaveWarn::SaveWarn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveWarn){
    ui->setupUi(this);
}

SaveWarn::~SaveWarn(){
    delete ui;
}


/*
 * Function: on_on_save_yes_clicked()
 * Usage: on_save_yes_clicked();
 * ------------------------------------
 * Click the yes button. Save the content in the text editor into
 * related file permanently.
 */
void SaveWarn::on_save_yes_clicked(){
    std::string update_content = new_content.toStdString();
    std::string input_path = "/Users/apple/Desktop/1.txt";
    // /Users/apple/Desktop/1.txt
    std::ofstream write_file;
    write_file.open(input_path.c_str());
    write_file << update_content;
    write_file.close();
    close();
    text_window_flag = false;
}



/*
 * Function: on_on_save_no_clicked()
 * Usage: on_save_no_clicked();
 * ------------------------------------
 * Click the no button. Close the window and do not save the file.
 */
void SaveWarn::on_save_no_clicked(){
    close();
    text_window_flag = false;
}

void TextEditor::showThread_texteditor(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Text editor is running:" + t);
}
