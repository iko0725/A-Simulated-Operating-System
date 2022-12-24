#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include <QButtonGroup>
#include <QString>
#include <QStack>
#include <QTimer>
namespace Ui {
/*
 * Class: Calculator
 * -----------------
 * This class implements a calculator by using a QDialog.
 */
class Calculator;
}

class Calculator : public QDialog
{
    Q_OBJECT

public:
/*
 * Function: Calculator
 * Usage:Calculator(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction functino of calculator, including some
 * initialization of the calculator.
 */
    explicit Calculator(QWidget *parent = nullptr);

/*
 * Function: ~Calculator
 * Usage:~Calculator();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
    ~Calculator();
signals:
/*
 * Function: sendData
 * Usage:emit sendData(QString);
 * ----------------------------
 * Emit the signal of current status, this implementation
 * can transmit the status (the app is running) of this application
 * to the display board1 on the main window.
 */
    void sendData(QString);   //用来传递数据的信号
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
    Ui::Calculator *ui;                 /* Pointer to the ui of the application*/
    QButtonGroup *buttonGroup;          /* Pointer to the button group in the application*/
    QTimer *thread_caculator;           /* Pointer to the timer used for emit signal*/
/* Private method prototypes*/

/*
 * Function: Button_clicked
 * Usage: Button_clicked(QAbstractButton *ojbect_button);
 * -------------------------------------------------------
 * This implememtation allows different reaction with different
 * buttion clicked.
 */
    void Button_clicked(QAbstractButton *ojbect_button);

/*
 * Function: Button_clicked
 * Usage: Button_clicked(QAbstractButton *ojbect_button);
 * -------------------------------------------------------
 * This implememtation allows different reaction with different
 * buttion clicked.
 */
    bool is_number(char ch);

/*
 * Function: calc_string_to_rpn_string
 * Usage: calc_string_to_rpn_string(QString str_express);
 * ------------------------------------------------------
 * Turn the nifix expressionnifix expression to postfix Expressions
 */
    QString calc_string_to_rpn_string(QString str_express);

/*
 * Function: calc_rpn_string
 * Usage: calc_rpn_string(QString str_rpn_express);
 * -------------------------------------------------
 * Caluculate the result from the postfix Expressions.
 */
    QString  calc_rpn_string(QString str_rpn_express);



private slots:
/*
 * Function: showThread_calculator
 * Usage:showThread_calculator();
 * ----------------------------
 * This is a slot for the Qtimer, this implememtaion enables the signal can be
 * emitted every seconds.
 */
    void showThread_calculator();
};

#endif // CALCULATOR_H
