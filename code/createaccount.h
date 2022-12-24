#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>

namespace Ui {
class CreateAccount;
}

/*
 * Class: CreateAccount <QDialog>
 * -----------------------
 * This class implements account creation of the OS.
 */
class CreateAccount : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = nullptr);
    ~CreateAccount();
signals:
    void sendData(QString);   //用来传递数据的信号
    void sendData2(QString);

private slots:

    /*
     * Function: on_create_clicked
     * Usage: on_create_clicked()
     * ------------------------------------
     * Click the create button. This implementation can create a new
     * acount for the OS based on the username and password that the user enters.
     * The function could save the information into c=related txt file for saving accounts.
     * Then, the account is created successfully and permanently.
     */
    void on_create_clicked();

    /*
     * Function: on_delete_button_clicked
     * Usage: on_delete_button_clicked()
     * ------------------------------------
     * Click the delete button. This implementation would show a new window
     * for deleting. Users can do delete operations on the new window.
     */
    void on_delete_button_clicked();

    /*
     * Function: showThread_createaccount
     * Usage: showThread_createaccount();
     * ------------------------------------
     *
     */
    void showThread_createaccount();
private:
    Ui::CreateAccount *ui;

    /*
     * Function: initialize_account();
     * Usage: initialize_account();
     * ------------------------------------
     * Based on the username and password, the function could save the information
     * into c=related txt file for saving accounts. Then, the account is created
     * successfully and permanently.
     */
    void initialize_account();

    QTimer *thread_createaccount;
};



namespace Ui {
class DeleteAccount;
}

/*
 * Class: DeleteAccount <QDialog>
 * -----------------------
 * This class implements deleting accounts of the OS.
 */
class DeleteAccount: public QDialog
{
    Q_OBJECT

public:
    explicit DeleteAccount(QWidget *parent = nullptr);
    ~DeleteAccount();
private slots:

    /*
     * Function:  on_deleteconfirm_clicked
     * Usage:  on_deleteconfirm_clicked();
     * ------------------------------------
     * Click the confirm button. This implementation can delete the account
     * information in related txt file. Therefore, the account is deleted permanently.
     */
    void on_deleteconfirm_clicked();

    /*
     * Function: on_refresh_clicked
     * Usage: on_refresh_clicked()
     * ------------------------------------
     * Click the refresh button. This implementation refresh the account information
     * on the window. Then, the account that is deleted before would disappear.
     */
    void on_refresh_clicked();

private:
    Ui::DeleteAccount *ui;

    /*
     * Function: initialize_delete_account
     * Usage: initialize_delete_account();
     * ------------------------------------
     * This implementation would read the acount informnation.
     * After that, refresh the account information on the window
     * for deleting accounts.
     */
    void initialize_delete_account();
};

#endif // CREATEACCOUNT_H
