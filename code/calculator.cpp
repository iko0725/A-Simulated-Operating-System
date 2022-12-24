#include "calculator.h"
#include "ui_calculator.h"
#include <QDateTime>
#include "h_gv.h"

/*
 * Function: Calculator
 * Usage:Calculator(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction function of broswer, including some
 * initialization of the calculator.
 */
Calculator::Calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    allocate_memory[1].memory_size = 300 + (rand() % (100-0+1))+0;

    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    thread_caculator = new QTimer(this);
    thread_caculator->setInterval (1000) ;
    connect(thread_caculator,SIGNAL(timeout()),this,SLOT(showThread_calculator()));
    thread_caculator->start();
    //Set window icon
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));

    buttonGroup = new QButtonGroup;
    buttonGroup->addButton(ui->button_0,1);
    buttonGroup->addButton(ui->button_1,2);
    buttonGroup->addButton(ui->button_2,3);
    buttonGroup->addButton(ui->button_3,4);
    buttonGroup->addButton(ui->button_4,5);
    buttonGroup->addButton(ui->button_5,6);
    buttonGroup->addButton(ui->button_6,7);
    buttonGroup->addButton(ui->button_7,8);
    buttonGroup->addButton(ui->button_8,9);
    buttonGroup->addButton(ui->button_9,10);
    buttonGroup->addButton(ui->button_add,11);
    buttonGroup->addButton(ui->button_sub,12);
    buttonGroup->addButton(ui->button_mult,13);
    buttonGroup->addButton(ui->button_div,14);
    buttonGroup->addButton(ui->button_left_bracket,15);
    buttonGroup->addButton(ui->button_right_bracket,16);
    buttonGroup->addButton(ui->button_point,17);
    buttonGroup->addButton(ui->button_clear,18);
    buttonGroup->addButton(ui->button_equal,19);
    buttonGroup->addButton(ui->button_back,20);
    QObject::connect(buttonGroup,
                     (void (QButtonGroup::*)(QAbstractButton *))&QButtonGroup::buttonClicked
                     , this
                     , &Calculator::Button_clicked);

}

/*
 * Function: ~Calculator
 * Usage:~Calculator();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
Calculator::~Calculator()
{
    allocate_memory[1].memory_size = 0;
    delete ui;
    thread_caculator->stop();
    flags[1] = 0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==1){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Calculator closed.\t"+times);
}

/*
 * Function: Button_clicked
 * Usage: Button_clicked(QAbstractButton *ojbect_button);
 * -------------------------------------------------------
 * This implememtation allows different reaction with different
 * buttion clicked.
 */
void Calculator::Button_clicked(QAbstractButton *ojbect_button)
{
    allocate_memory[1].memory_size = 500 + (rand() % (100-0+1))+0;
    QString button_text=ojbect_button->text();
    QString display_text=ui->textEdit->toPlainText();
    if(display_text.length()>20)
    {
        ui->textEdit->clear();
        ui->textEdit->update();
        ui->textEdit->setText("ERROR");
        ui->textEdit->update();
        ui->textEdit->show();
        return;
    }
    if(display_text=="ERROR")
    {
        ui->textEdit->clear();
        ui->textEdit->update();
        ui->textEdit->setText("");
        ui->textEdit->update();
        ui->textEdit->show();
        display_text.clear();
    }
    if(button_text == "C")
    {
        ui->textEdit->clear();
        ui->textEdit->update();
        ui->textEdit->setText("");
        ui->textEdit->update();
        ui->textEdit->show();
    }
    else if(button_text == "back")
    {
        display_text.remove(display_text.length()-1,display_text.length());
        ui->textEdit->setText(display_text);
        ui->textEdit->show();
    }
    else if(button_text == "=")
    {
        QString str_rpn_exp=calc_string_to_rpn_string(display_text);
        QString str_display=calc_rpn_string(str_rpn_exp);
        ui->textEdit->setText(str_display);
        ui->textEdit->show();
    }
    else
    {
        display_text+=button_text;
        ui->textEdit->setText(display_text);
        ui->textEdit->show();
    }
}

/*
 * Function: Button_clicked
 * Usage: Button_clicked(QAbstractButton *ojbect_button);
 * -------------------------------------------------------
 * This implememtation allows different reaction with different
 * buttion clicked.
 */
bool Calculator::is_number(char ch)
{
    if(ch >= '0' && ch <= '9')
        return true;
    if(ch == '.')
        return true;
    return false;
}

/*
 * Function: calc_string_to_rpn_string
 * Usage: calc_string_to_rpn_string(QString str_express);
 * ------------------------------------------------------
 * Turn the nifix expressionnifix expression to postfix Expressions
 */
QString Calculator::calc_string_to_rpn_string(QString str_express)
{
    QStack<char> stack_symbol;
    QString str_rpnexp = "";
    for(int npos = 0; npos < str_express.length(); npos++){
        char ch = str_express[npos].toLatin1();
        if(is_number(ch) == true){
            str_rpnexp += ch;
            npos++;
            while(npos < str_express.length()){
                ch = str_express[npos].toLatin1();
                if(is_number(ch) == true){
                    str_rpnexp += ch;
                    npos++;
                }
                else{
                    break;
                }
            }
            str_rpnexp += '#';
        }
        //other symbool
        if(ch == '+' || ch == '-'){
            if(stack_symbol.isEmpty() != true && stack_symbol.top() != '('){
                do{
                    str_rpnexp += stack_symbol.pop();
                }
                while(stack_symbol.isEmpty() != true && stack_symbol.top() != '(');
            }
            stack_symbol.push(ch);
        }
        else if(ch == '*' || ch == '/'){
            if(stack_symbol.isEmpty() != true
                    && (stack_symbol.top() == '*' || stack_symbol.top() == '/')
              )
            {
                do{
                    str_rpnexp += stack_symbol.pop();
                }
                while(stack_symbol.isEmpty() != true && stack_symbol.top() != '(');
                str_rpnexp += ch;
            }
            stack_symbol.push(ch);
        }
        else if(ch == '('){
            stack_symbol.push(ch);
        }
        else if(ch == ')'){
            while(stack_symbol.isEmpty() != true){
                ch = stack_symbol.pop();
                if(ch != '('){
                    str_rpnexp += ch;
                }
            }
        }
    }
    while(stack_symbol.isEmpty() != true){
        char ch = stack_symbol.pop();
        if(ch != '('){
            str_rpnexp += ch;
        }
    }
    return str_rpnexp;
}

/*
 * Function: calc_rpn_string
 * Usage: calc_rpn_string(QString str_rpn_express);
 * -------------------------------------------------
 * Caluculate the result from the postfix Expressions.
 */
QString Calculator:: calc_rpn_string(QString str_rpn_express)
{
    QStack<double> stack_num;
    for(int npos = 0; npos < str_rpn_express.length(); npos++){
        char ch = str_rpn_express[npos].toLatin1();
        if(is_number(ch) == true){
            QString str_num;
            str_num += ch;
            npos++;
            while(npos < str_rpn_express.length()){
                ch = str_rpn_express[npos].toLatin1();
                if(is_number(ch) == true){
                    str_num += ch;
                    npos++;
                }
                else{
                    break;
                }
            }
            bool b_conversion = false;
            double do_num = str_num.toDouble(&b_conversion);
            if(b_conversion == false){
                return "ERROR";
            }
            stack_num.push(do_num);
        }
        if(ch == '#'){
            continue;
        }
        else{
            if(stack_num.length() < 2){
                return "ERROR";
            }
            double b = stack_num.pop();
            double a = stack_num.pop();
            switch(ch){
            case '+':
                stack_num.push(a + b);
                break;
            case '-':
                stack_num.push(a - b);
                break;
            case '*':
                stack_num.push(a * b);
                break;
            case '/':
                if(b==0) return "Devided By Zero";
                stack_num.push(a / b);
                break;
            default:
                return "ERROR";
            }
        }
    }
    if(stack_num.isEmpty() == true){
        return "ERROR";
    }
    double calc = stack_num.pop();
    return QString("").setNum(calc);
    update();
}

/*
 * Function: showThread_calculator
 * Usage:showThread_calculator();
 * ----------------------------
 * This is a slot for the Qtimer, this implememtaion enables the signal can be
 * emitted every seconds.
 */
void Calculator::showThread_calculator(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Calculator is running:" + t);
}





