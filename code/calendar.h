#ifndef CALENDER_H
#define CALENDER_H

#include <QDialog>
#include <QTime>
#include <QElapsedTimer>
#include <QTimer>
namespace Ui {
/*
 * Class: Calendar
 * -----------------
 * This class implements a calendar by using a QDialog.
 */
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
/*
 * Function: Calendar
 * Usage:Calendar(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction functino of calendar, including some
 * initialization of the calendar.
 */
    explicit Calendar(QWidget *parent = nullptr);

/*
 * Function: ~Calendar
 * Usage:~Calendar();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
    ~Calendar();

private slots:
/*
 * Implementation notes: on_updtimebtnte_clicked, on_startBtn_clicked, on_stopBtn_clicked
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
    void on_updtimebtnte_clicked();    
    void on_startBtn_clicked();
    void on_stopBtn_clicked();

/*
 * Implementation notes: showThread_calendar, show_time, on_timer_timeout
 * ----------------------------------------
 * Thease are slots for the Qtimer.
 */
    void showThread_calendar();
    void show_time();
    void on_timer_timeout();

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
    Ui::Calendar *ui;           /* Pointer to the ui of the application*/
    QTimer *fTimer;             /* Pointer to the timer*/
    QTimer *showTimer;          /* Pointer to the timer*/
    QTimer *thread_calendar;    /* Pointer to the timer used for emit signal*/
    QElapsedTimer fTimeCounter; /* Pointer to the QElapsedTimer*/
};

#endif // CALENDER_H
