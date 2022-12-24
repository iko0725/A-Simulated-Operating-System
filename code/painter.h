#ifndef PAINTER_H
#define PAINTER_H

#include <QDialog>
#include <QMouseEvent>
#include <QPushButton>
#include <QAction>
#include <QPainter>
#include <QColor>
namespace Ui {
/*
 * Class: Painter
 * -----------------
 * This class implements a painter by using a QDialog.
 */
class Painter;
}

class Painter : public QDialog
{
    Q_OBJECT

public:
/*
 * Function: Painter
 * Usage:Painter(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction functino of painter, including some
 * initialization of the painter.
 */
    explicit Painter(QWidget *parent = nullptr);

/*
 * Function: ~Painter
 * Usage:~Painter();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
    ~Painter();
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
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
private:
/* Instance variable*/
    Ui::Painter *ui;        /* Pointer to the ui */
    QPixmap pix;            /* Pointer to a QPixmap */
    QPoint lastPoint;       /* Pointer to a QPoint */
    QPoint endPoint;        /* Pointer to a QPoint */
    qreal scale;
    QPushButton *zoomin;    /* Pointer to a Qpushbutton */
    QPushButton *zoomout;   /* Pointer to a Qpushbutton */
    QTimer *thread_painter; /* Pointer to the timer used for emit signal*/
    QPen pen;
    QPainter pp;
    QBrush br;
    int wid;
    QColor color;
private slots:
/*
 * Implementation notes: zoomIn, on_pushButton_save_painter_clicked
 * on_pushButton_color_clicked
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
    void zoomIn();
    void zoomOut();
    void on_pushButton_save_painter_clicked();
    void on_spinBox_width_valueChanged(int arg1);
    void on_pushButton_color_clicked();

/*
 * Implementation notes: showThread_painter
 * ----------------------------------------
 * This is a slot for the Qtimer.
 */
     void showThread_painter();
     void on_pushButton_zoomin_clicked();
     void on_pushButton_zoomout_clicked();
};

#endif // PAINTER_H
