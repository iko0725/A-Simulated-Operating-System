#ifndef BROWSER_H
#define BROWSER_H

#include <QDialog>

namespace Ui {
/*
 * Class: Browser
 * --------------
 * This class implements a browser by using a QDialog.
 */
class Browser;
}

class Browser : public QDialog
{
    Q_OBJECT
signals:
/*
 * Function: sendData
 * Usage:emit sendData(QString);
 * ----------------------------
 * Emit the signal of current status, this implementation
 * can transmit the status (the app is running) of browser
 * to the display board1 on the main window.
 */
    void sendData(QString);

/*
 * Function: sendData2
 * Usage:emit sendData2(QString);
 * ----------------------------
 * Emit the signal of current status, this implementation
 * can transmit the status (open and close) of browser to
 * the display board2 on the main window.
 */
    void sendData2(QString);
public:
/*
 * Function: Browser
 * Usage:Browser(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction functino of broswer, including some
 * initialization of the browser.
 */
    explicit Browser(QWidget *parent = nullptr);

/*
 * Function: ~Browser
 * Usage:~Browser();
 * ------------------
 * This is a deconstruction functino of broswer, the deconstructor
 * frees any heap memory allocated by the browser.
 */
    ~Browser();

private slots:
/*
 * Function: on_pushButton_gp_clicked
 * Usage:on_pushButton_gp_clicked();
 * -----------------------------------
 * This is a slot for the action of clicking the pushbutton, it implements
 * the function to open the browser in users computer by inputing the url
 * address of the website.
 */
    void on_pushButton_gp_clicked();

/*
 * Function: showThread_browser
 * Usage:showThread_browser();
 * ----------------------------
 * This is a slot for the Qtimer, this implememtaion enables the signal can be
 * emitted every seconds.
 */
    void showThread_browser();

private:
/*instance variable*/
    Ui::Browser *ui;                /* Pointer to the ui of the browser*/
    QTimer *thread_browser;         /* Pointer to the timer used for emit signal*/
};

#endif // BROWSER_H
