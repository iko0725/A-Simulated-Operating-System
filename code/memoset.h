#ifndef MEMOSET_H
#define MEMOSET_H

#include <QDialog>
#include <QTimer>
#include <QDateTime>
namespace Ui {
/*
 * Class: Memoset
 * -----------------
 * This class implements a memoset by using a QDialog.
 */
class Memoset;
}

class Memoset : public QDialog
{
    Q_OBJECT

public:
/*
 * Function: Memoset
 * Usage:Memoset(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction functino of memoset, including some
 * initialization of the memoset.
 */
    explicit Memoset(QWidget *parent = nullptr);

/*
 * Function: ~Memoset
 * Usage:~Memoset();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
    ~Memoset();
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

private slots:
/*
 * Implementation notes: on_pushButton_memoset_clicked, on_pushButton_showall_clicked
 * on_pushButton_search_clicked
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
    void on_pushButton_memoset_clicked();
    void on_pushButton_showall_clicked();
    void on_pushButton_search_clicked();

/*
 * Implementation notes: showThread_memo
 * ----------------------------------------
 * This is a slot for the Qtimer.
 */
    void showThread_memo();

    void on_pushButton_delete_clicked();

private:
/* Instance variable*/
    Ui::Memoset *ui;            /* Pointer to the ui */
    QTimer *thread_memo;        /* Pointer to the timer used for emit signal*/
};

#endif // MEMOSET_H
