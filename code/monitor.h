#ifndef MONITOR_H
#define MONITOR_H

#include <QDialog>

namespace Ui {
/*
 * Class: Monitor
 * -----------------
 * This class implements a monitor by using a QDialog.
 */
class Monitor;
}

class Monitor : public QDialog
{
    Q_OBJECT

public:
/*
 * Function: Monitor
 * Usage:Monitor(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction functino of monitor, including some
 * initialization of the monitor.
 */
    explicit Monitor(QWidget *parent = nullptr);

/*
 * Function: ~Monitor
 * Usage:~Monitor();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
    ~Monitor();

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
 * Implementation notes: on_pushButton_storage_clicked, on_pushButton_CPU_clicked
 * on_tableWidget_CPU_cellDoubleClicked
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
    void on_pushButton_storage_clicked();
    void on_pushButton_CPU_clicked();
    void on_tableWidget_CPU_cellDoubleClicked(int row, int column);

/*
 * Implementation notes: update_CPU_table, update_storage_table,
 * updateTable,showThread_monitor
 * ----------------------------------------
 * These are slots for the Qtimer.
 */
    void update_CPU_table();
    void update_storage_table();
    void updateTable();
    void showThread_monitor();


private:
/* Instance variable*/
    Ui::Monitor *ui;            /* Pointer to the ui */
    QTimer *updateTimer;        /* Pointer to the timer*/
    QTimer *thread_monitor;     /* Pointer to the timer used for emit signal*/
};

#endif // MONITOR_H
