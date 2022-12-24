#ifndef GLUTTONOUS_SNAKE_H
#define GLUTTONOUS_SNAKE_H

#include <QVector>
#include <QPoint>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QMessageBox>
#include <QTimer>
#include <QPushButton>

using namespace std;

/*
 * Class: Widget
 * -----------------
 * This class implements a game named Gluttonous Snake.
 */

static const int BLOCK_SIZE = 25;
static const int MARGIN = 10;
static const int ROW = 20;
static const int COL = 20;
static const int TIME_INTERVAL=500;


enum{UP = 1, LEFT, DOWN, RIGHT};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void paintEvent(QPaintEvent *);
signals:
    void sendData(QString);
    void sendData2(QString);
public:
    void gameInit();
    void pauseResumeGame(); //pause the game
    void gameOver(); //give prompt when game is over
    void randomFood(QVector<QPoint> coordinate);
    bool snakeAlive();
    QPoint getFoodPosition();
    QVector<QPoint> getSnake();
    QMessageBox *promptBox;

private slots:
    void snakeAction();
    void showThread_snake();

private:
    QTimer *gameTimer;
    bool isPause;
    QPoint foodPosition;
    QVector<QPoint> coordinate;
    int direction;
    bool isAlive;
    int score;
    QTimer *thread_snake;
};


#endif // GLUTTONOUS_SNAKE_H
