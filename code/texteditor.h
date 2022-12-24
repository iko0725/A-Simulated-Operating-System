#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QDialog>


namespace Ui {
class TextEditor;
}

/*
 * Class: TextEditor <QDialog>
 * -----------------------
 * This class allows to record sound and save it in the computer.
 */
class TextEditor : public QDialog
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = nullptr);

    /*
     * Function: ~TextEditor
     * Usage: ~TextEditor()
     * ------------------------------------
     * Close the window. If the user do not save the content, check whether the content
     * is changes or not. Ask user to decide whether the user want to save the change or not.
     */
    ~TextEditor();
signals:
    void sendData(QString);   //用来传递数据的信号
    void sendData2(QString);
private slots:

    /*
     * Function: on_save_clicked
     * Usage: on_save_clicked()
     * ------------------------------------
     * Click the save button. Then the content in the text editor
     * would be saved permanently.
     */
    void on_save_clicked();

    /*
     * Function: on_clear_clicked
     * Usage: on_clear_clicked()
     * ------------------------------------
     * Click the clear button. Then the content in the text editor
     * would be cleared.
     */
    void on_clear_clicked();


    /*
     * Function: on_undo_clicked
     * Usage: on_undo_clicked()
     * ------------------------------------
     * Click the undo button. Then the text editor would undo the last step.
     */
    void on_undo_clicked();


    /*
     * Function: on_redo_clicked
     * Usage: on_redo_clicked()
     * ------------------------------------
     * Click the redo button. Then the text editor would redo the last step.
     */
    void on_redo_clicked();


    /*
     * Function: on_findtext_clicked
     * Usage: on_findtext_clicked()
     * ------------------------------------
     * Click the finder button. Then the text editor would ask user to choose a
     * text file and open it in the text editor.
     */
    void on_findtext_clicked();

    /*
     * Function: updatecontent
     * Usage: updatecontent();
     * ------------------------------------
     * Read the content in the textEdit and save the content into a string.
     */
    void updatecontent();


    /*
     * Function: showThread_texteditor
     * Usage: showThread_texteditor()
     * ------------------------------------
     *
     *
     *
     */
    void showThread_texteditor();

private:
    Ui::TextEditor *ui;

    /*
     * Function: read_text
     * Usage: read_text()
     * ------------------------------------
     * According to the path chosen by user, read the content of text file.
     * Then, the text editor would show up the content.
     */
    void read_text();
    QTimer *thread_texteditor;
};


/*
 * Class: SaveWarn <QDialog>
 * -----------------------
 * This class allows to check whether the user saves the file or not.
 */
namespace Ui {
class SaveWarn;
}
class SaveWarn: public QDialog
{
    Q_OBJECT

public:
    explicit SaveWarn(QWidget *parent = nullptr);
    ~SaveWarn();


private slots:
    /*
     * Function: on_on_save_yes_clicked()
     * Usage: on_save_yes_clicked();
     * ------------------------------------
     * Click the yes button. Save the content in the text editor into
     * related file permanently.
     */
    void on_save_yes_clicked();

    /*
     * Function: on_on_save_no_clicked()
     * Usage: on_save_no_clicked();
     * ------------------------------------
     * Click the no button. Close the window and do not save the file.
     */
    void on_save_no_clicked();

private:
    Ui::SaveWarn *ui;
};


#endif // TEXTEDITOR_H
