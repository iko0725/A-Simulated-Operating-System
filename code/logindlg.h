#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = nullptr);
    ~LoginDlg();
    void paintEvent(QPaintEvent *);

private slots:
    void on_loginBtn_clicked();


private:
    Ui::LoginDlg *ui;

};

#endif // LOGINDLG_H
