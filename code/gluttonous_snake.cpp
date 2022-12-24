#include "gluttonous_snake.h"
#include "h_gv.h"
#include <QDateTime>
#include <QTimer>
using namespace std;

/*
 * Function: Widget
 * Usage:Widget(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction function of the game Gluttonous Snake.
 */

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //Set title
    this->setWindowTitle("Gluttonous Snake");
    //Set window icon
    this->setWindowIcon(QIcon(":/icon/general_icon.png"));
    //Initialize the game interface
    resize(MARGIN*4+(COL+6)*BLOCK_SIZE,MARGIN*2+ROW*BLOCK_SIZE);
    this->setAttribute(Qt::WA_DeleteOnClose);
    allocate_memory[6].memory_size = 900 + (rand() % (100-0+1))+0;
    this->show();
    //Message to satrt the game
    int ret1 = QMessageBox::information(NULL, "Title", "Welcome to Gluttonous Snake!\nDo you want to start?",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//    QPushButton *startbtn = new QPushButton(QString::fromLocal8Bit("Start the game!"));
//    promptBox = new QMessageBox;
//    promptBox->setIcon(QMessageBox::Information);
//    promptBox->setWindowTitle(QString::fromLocal8Bit("Prompt"));
//    promptBox->setText("Welcome to Gluttonous Snake!");
//    promptBox->addButton(startbtn, QMessageBox::AcceptRole);
//    //promptBox->addButton(quitbtn, QMessageBox::RejectRole);
//    promptBox->show();
//    promptBox->exec();
    if (ret1==QMessageBox::Yes){
         gameInit();
    }else{
        this->close();
    };
    thread_snake = new QTimer(this);
    thread_snake->setInterval (1000) ;
    connect(thread_snake,SIGNAL(timeout()),this,SLOT(showThread_snake()));
    thread_snake->start();

}

Widget::~Widget(){
    allocate_memory[6].memory_size = 0;
    flags[6]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==6){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Video game:snake closed.\t"+times);
}

/*
 * Function: randomFood
 * Usage:randomFood(QVector<QPoint> coordinate);
 * ----------------------------------------
 * This is the function to randomly choose the food position.
 */

void Widget::randomFood(QVector<QPoint> coordinate){

    foodPosition.setX(rand()%COL);
    foodPosition.setY(rand()%ROW);

    if(coordinate.contains(foodPosition))
       randomFood(coordinate);

};

/*
 * Function: getFoodPosition
 * Usage: QPoint p = getFoodPosition();
 * ----------------------------------------
 * This is the function to get the food position at certain time.
 */

QPoint Widget::getFoodPosition(){
        return foodPosition;
    };

/*
 * Function: keyPressEvent
 * ----------------------------------------
 * This is a overide function to use each time a keyboard input happens.
 */

void Widget::keyPressEvent(QKeyEvent *event){
        allocate_memory[6].memory_size = 1200 + (rand() % (100-0+1))+0;
                switch (event->key())
                {
                case Qt::Key_W:
                    if (this->direction == DOWN)
                        break;
                    this->direction = UP;
                    break;
                case Qt::Key_S:
                    if (this->direction == UP)
                        break;
                    this->direction = DOWN;
                    break;
                case Qt::Key_A:
                    if (this->direction == RIGHT)
                        break;
                    this->direction = LEFT;
                    break;
                case Qt::Key_D:
                    if (this->direction == LEFT)
                        break;
                    this->direction = RIGHT;
                    break;
                case Qt::Key_P:
                    pauseResumeGame();
                    break;
                default:
                    break;
                }

    };

/*
 * Function: snakeAction
 * ----------------------------------------
 * This is the function to move the snake at set intervals.
 */

void Widget::snakeAction(){
        QPoint newHead = coordinate[0];

        switch(this->direction){
        case UP:
            newHead.ry()--;
            break;
        case LEFT:
            newHead.rx()--;
            break;
        case DOWN:
            newHead.ry()++;
            break;
        case RIGHT:
            newHead.rx()++;
            break;
        default:
            break;
        }

        coordinate.insert(coordinate.begin(), newHead);

        if (coordinate[0] == foodPosition){
            score++;
            randomFood(coordinate);
            return;
        }else{

            coordinate.pop_back();
        }
        if (snakeAlive() == false){
            gameOver();
            return;
        }
        update();
    };

/*
 * Function: snakeAlive
 * ----------------------------------------
 * This is the function to check whether the snake is still alive after each movement.
 */

bool Widget::snakeAlive(){
        //check whether the snack reach the boundary
        if(coordinate[0].x()<0||coordinate[0].x()>COL-1||coordinate[0].y()<0||coordinate[0].y()>ROW-1)
        {
          return false;
        }

        //check whether the snack crash itself
        for(int i=3;i<coordinate.size();i++){
                if(coordinate[i]==coordinate[0])
            {
                return false;
            }
        }
        return true;
    };


QVector<QPoint> Widget::getSnake(){
        return coordinate;
    };


/*
 * Function: gameInit
 * Usage: gameInit();
 * ----------------------------------------
 * This is the function to initialize a new game.
 */
void Widget::gameInit(){
    for(int j=3;j>=0;j--){
        coordinate.push_back(QPoint(j,0));
    }
    direction=RIGHT;
    srand(time(0));
    randomFood(coordinate);
    score=0;
    isPause=false;
    gameTimer=new QTimer(this);
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(snakeAction()));
    gameTimer->start(TIME_INTERVAL);
};


/*
 * Function: paintEvent
 * Usage: paintEvent(QPaintEvent *)
 * ----------------------------------------
 * This is the function to draw the game interface.
 */
void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //the scene
    painter.setBrush(Qt::white);
    painter.setPen(Qt::white);
    painter.drawRect(MARGIN,MARGIN,COL*BLOCK_SIZE,ROW*BLOCK_SIZE);
    //the snake
    painter.setBrush(Qt::red);
    painter.setPen(Qt::blue);
    for(int i=0;i < coordinate.size();i++)
        if(coordinate[i].x()>=0 && coordinate[i].x()<=COL-1 && coordinate[i].y()>=0 && coordinate[i].y()<=ROW-1)
           painter.drawRect(MARGIN+coordinate[i].x()*BLOCK_SIZE,MARGIN+coordinate[i].y()*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
    //the food
    painter.setBrush(Qt::green);
    painter.drawEllipse(MARGIN+foodPosition.x()*BLOCK_SIZE,MARGIN+foodPosition.y()*BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
    //the score
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial",10));
    painter.drawText(MARGIN*3+COL*BLOCK_SIZE,MARGIN+2*BLOCK_SIZE,"score: " + QString::number(score));
    painter.drawText(MARGIN*3+COL*BLOCK_SIZE,MARGIN+4*BLOCK_SIZE,"Instructions: ");
    painter.drawText(MARGIN*3+COL*BLOCK_SIZE,MARGIN+5*BLOCK_SIZE,"W: up");
    painter.drawText(MARGIN*3+COL*BLOCK_SIZE,MARGIN+6*BLOCK_SIZE,"S: down");
    painter.drawText(MARGIN*3+COL*BLOCK_SIZE,MARGIN+7*BLOCK_SIZE,"A: left");
    painter.drawText(MARGIN*3+COL*BLOCK_SIZE,MARGIN+8*BLOCK_SIZE,"D: right");
    painter.drawText(MARGIN*3+COL*BLOCK_SIZE,MARGIN+9*BLOCK_SIZE,"P: pause");

};

/*
 * Function: gameOver;
 * Usage: gameOver();
 * ----------------------------------------
 * This is the function to show the screen at the end of the game.
 */

void Widget::gameOver(){
    allocate_memory[6].memory_size = 800 + (rand() % (100-0+1))+0;
    gameTimer->stop();
    //QMessageBox::information(this,"Failed","Game Over! Your score is: " + QString::number(score), QMessageBox::Yes);
    QPushButton *okbtn = new QPushButton(QString::fromLocal8Bit("Start new"));
    QPushButton *cancelbtn = new QPushButton(QString::fromLocal8Bit("Quit"));
    QMessageBox *mymsgbox = new QMessageBox;
    mymsgbox->setIcon(QMessageBox::Warning);
    mymsgbox->setWindowTitle(QString::fromLocal8Bit("Prompt"));
    mymsgbox->setText("Game Over! Your score is: " + QString::number(score));
    mymsgbox->addButton(okbtn, QMessageBox::AcceptRole);
    mymsgbox->addButton(cancelbtn, QMessageBox::RejectRole);
    mymsgbox->show();
    mymsgbox->exec();
    if (mymsgbox->clickedButton()==okbtn){
       coordinate.clear();
       for(int j=3;j>=0;j--){
           coordinate.push_back(QPoint(j,0));
       }
       direction=RIGHT;
       srand(time(0));
       randomFood(coordinate);
       score=0;
       isPause=false;
       gameTimer->start(TIME_INTERVAL);
    }else{
        this->close();
    }
};

/*
 * Function: pauseResumeGame;
 * Usage: pauseResumeGame();
 * ----------------------------------------
 * This is the function to pause the game.
 */

void Widget::pauseResumeGame()
{
    if(!isPause)
    {
        isPause=!isPause;
        gameTimer->stop();
    }
    else
    {
        isPause=!isPause;
        gameTimer->start(TIME_INTERVAL);
    }
}


void Widget::showThread_snake(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Video game snake is running:" + t);
}












