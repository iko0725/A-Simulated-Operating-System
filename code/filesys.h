#ifndef FILESYS_H
#define FILESYS_H

#include <QDialog>
#include <QStyleOptionViewItem>
#include <QTimer>
namespace Ui {
/*
 * Class: Filesys
 * -----------------
 * This class implements a filesys by using a QDialog.
 */
class FileSys;
}

class FileSys : public QDialog
{
    Q_OBJECT

public:
/*
 * Function: Filesys
 * Usage:Filesys(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction functino of filesys, including some
 * initialization of the filesys.
 */
    explicit FileSys(QWidget *parent = nullptr);

/*
 * Function: ~Filesys
 * Usage:~Filesys();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
    ~FileSys();
private slots:
/*
 * Implementation notes: on_pushButton_finder_clicked, on_tableWidget_file_cellDoubleClicked
 * renamebtn, rename, deletefile
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
    void on_pushButton_finder_clicked();
    void on_tableWidget_file_cellDoubleClicked(int row, int column);
    void renamebtn();
    void rename();
    void deletefile();

/*
 * Implementation notes: showThread_filesysy
 * ----------------------------------------
 * This is a slot for the Qtimer.
 */
    void showThread_filesysy();

    void on_pushButton_refresh_clicked();

signals:
/*
 * Function: sendData
 * Usage:emit sendData(QString);
 * ----------------------------
 * Emit the signal of current status, this implementation
 * can transmit the status (the app is running) of this application
 * to the display board1 on the main window.
 */
    void sendData(QString);

/*
 * Function: sendData2
 * Usage:emit sendData2(QString);
 * ----------------------------
 * Emit the signal of current status, this implementation
 * can transmit the status (open and close) of this application
 * to the display board2 on the main window.
 */
    void sendData2(QString);

private:
/* Instance variable*/
    QDialog *filetool;          /* Pointer to a QDialog */
    QDialog *renametool;        /* Pointer to a QDialog */
    Ui::FileSys *ui;            /* Pointer to the ui */
    QTimer *thread_filesys;     /* Pointer to the timer used for emit signal*/
    QLineEdit *renamename;      /* Pointer to a QLineEdit */
    int row_num;                /* Row number of the table item*/
    int column_num;             /* Column number of the table item*/

/* Private method prototypes*/

/*
 * Function: FindFile
 * Usage:QString FindFile(const QString &path);
 * ----------------------------
 * Get the absolute path of a file. and show the information in the table.
 */
    QString FindFile(const QString &path);
};

#endif // FILESYS_H
