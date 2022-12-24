#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *keyset);




private slots:
    void receiveData(QString data);
    void receiveData2(QString data);
    void updateBattery();
    void show_maintime();
private:
    Ui::MainWindow *ui;
    QTimer *update_battery_Time;
    QTimer *update_Time;
//    std::vector<QDialog*> dlgs;

};
#endif // MAINWINDOW_H
