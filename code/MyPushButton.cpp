/*
 * Class: MyPushButton(QWidget *Parent, QString normalImg, QString pressImg,bool AsButton, QString tips)
 * ------------------
 * Inherited from QPushButton class,
 * can generate customized button with following features:
 *
 * - Customized outlook
 *
 * - Color change when cursor hovers
 * - bounce effect when clicked
 * - Shimmer effect
 * - Tip window when cursor enters
 *
 * This class can also be used as an animation unit
 * by changing the bool input AsButton to 'false'.
 * For animation units, some functions would be disabled.
*/
#include "MyPushButton.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QMouseEvent>
#include "iostream"

/*
 * Function: MyPushButton(QWidget *Parent, QString normalImg, QString pressImg = "",bool AsButton = true, QString tips = "");
 * Usage: MyPushButton(this, "", "",true, "")
 * ------------------------------------------
 * Construct a MyPushButton object.
*/
MyPushButton::MyPushButton(QWidget *Parent, QString normalImg, QString pressImg, bool AsButton, QString tips)
{
    init(Parent);

    this->setParent(Parent);
    this->setMouseTracking(true);

    //Save path for button image
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;
    IsButton = AsButton;
    TipsLbl->setText(tips);

    QPixmap pix;
    bool ret = pix.load(this->normalImgPath);
    if (!ret){
        QString str = QString("Failed to load image at %1").arg(this->normalImgPath);
        qDebug() << str;
        return;
    }

    /* Style setup for push buttons */
    if (IsButton){
        //Set size of button
        this->setFixedSize(pix.width()*0.72,pix.height()*0.72);

        //Set irregular shape button
        this->setStyleSheet("QPushButton{border:0px;}");

        //Set icon
        this->setIcon(pix);

        //Set size of image
        this->setIconSize(QSize(pix.width(),pix.height()));

        //Set hover cursor
        QCursor *myCursor = new QCursor(QPixmap(":/cursor/cursor_hover.png"),0,0);
        this->setCursor(*myCursor);
        //Set background color
        this->setStyleSheet("QPushButton{background-color: rgba(0, 0, 0, 0);}"
                            "QPushButton:hover{background-color: rgba(219, 247, 255, 50);}");
    }

    /* Style setup for animation unit */
    else if(!IsButton){
        //Set size of button
        this->setFixedSize(pix.width(),pix.height());

        //Set irregular shape button
        this->setStyleSheet("QPushButton{border:0px;}");

        //Set icon
        this->setIcon(pix);

        //Set size of image
        this->setIconSize(QSize(pix.width(),pix.height()));

        QCursor *myCursor = new QCursor(Qt::BlankCursor);
        this->setCursor(*myCursor);
    }

    }

/*
 * Function: Down()
 * Usage: Btn->Down();
 * -------------------
 * Animate the push button making it
 * bounce down a little bit.
*/
void MyPushButton::Down()
{
    QPropertyAnimation * animation = new QPropertyAnimation (this, "geometry");
    // Set duration
    animation->setDuration(200);
    animation->setStartValue(QRect( this ->x(), this->y(), this->width(), this->height() ));
    animation->setEndValue(QRect( this ->x(), this->y()+10, this->width(), this->height() ));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // Execute animation
    animation->start();
}

/*
 * Function: Up()
 * Usage: Btn->Up();
 * -------------------
 * Animate the push button making it
 * bounce up a little bit.
*/
void MyPushButton::Up()
{
    QPropertyAnimation * animation = new QPropertyAnimation (this, "geometry");
    // Set duration
    animation->setDuration(200);
    animation->setStartValue(QRect( this ->x(), this->y()+10, this->width(), this->height() ));
    animation->setEndValue(QRect( this ->x(), this->y(), this->width(), this->height() ));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // Execute animation
    animation->start();
}

/*
 * Function: Shimmer
 * Usage: implicit
 * ---------------
 * When ever m_pTimer is timed up,
 * change the opacity value of button by 0.05,
 * creating a shimmering effect
*/
void MyPushButton::Shimmer()
{
    m_pOpacityEffect = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(m_pOpacityEffect);
    m_pTimer = new QTimer(this);
    //QTimer need to be precise
    m_pTimer->setTimerType(Qt::PreciseTimer);
    connect(m_pTimer, &QTimer::timeout, this, [=](){
        emit sigTimeout();
        m_pOpacityEffect->setOpacity(m_opacityVal);
        if(m_bStatus)
        {
            m_opacityVal -= 0.05;
        }
        else
        {
            m_opacityVal += 0.05;
        }
        if(m_opacityVal > 0.9)
        {
            m_bStatus = true;
        }
        else if(m_opacityVal < 0.1)
        {
            m_bStatus = false;
        }
    });
}

/*
 * Function: startShimmerAnimation()
 * Usage: startShimmerAnimation()
 * ---------------------------------
 * Set m_pTimer to 50 misc a cycle and
 * trigger the shimmer function.
*/
void MyPushButton::startShimmerAnimation(){
    m_pTimer->start(50);
}

/*
 * Function: stopShimmerAnimation()
 * Usage: stopShimmerAnimation()
 * --------------------------------
 * Stop m_pTimer and thus stop the shimmer function.
*/
void MyPushButton::stopShimmerAnimation(){
    m_pTimer->stop();
    m_pOpacityEffect->setOpacity(1.0);
}

/*
 * Function: isActive() const
 * Usage: if(isActive())
 * --------------------------
 * Detect whether shimmer effect is on.
*/
bool MyPushButton::isActive() const{
    return m_pTimer->isActive();
}

/*
 * Function: enterEvent(QEvent * )
 * Usage: Implicit
 * -------------------------------
 * Emit a signal when detecting
 * cursor entering the button.
*/
void MyPushButton::enterEvent(QEvent *){
    if(IsButton){
        //w_Timer = new QTimer;
        //w_Timer->start(waitingTime);
        //connect(w_Timer, &QTimer::timeout, this, [=](){
            emit sigTimeout();
            //QPoint oPoint = this->mapToGlobal(*posi);
            emit sig_showWgt(*posi);
        //});
    }
}

/*
* Function: leaveEvent(QEvent * )
* Usage: Implicit
* -------------------------------
* Hide the tips window when detecting
* cursor leaving the button.
*/
void MyPushButton::leaveEvent(QEvent *){
    if(IsButton){
        //w_Timer->stop();
        TipsWgt->hide();
    }
}

/*
 * Function: init()
 * Usage: init()
 * ----------------
 * Initialize the widgets & labels used for
 * displaying tips.
 * The widget would be closed initially.
 * If the object is set to be an animation unit,
 * this would generate an empty widget.
*/
void MyPushButton::init(QWidget *Parent)
{
    if(IsButton){
        TipsWgt = new QWidget;
        TipsWgt->setParent(Parent);
        TipsWgt->close();
        TipsLbl = new QLabel(TipsWgt);
        TipsLyt = new QGridLayout(TipsWgt);
        TipsLyt->addWidget(TipsLbl);

        TipsWgt->setWindowFlags(Qt::FramelessWindowHint);
        TipsWgt->setStyleSheet("background-color: transparent");
        TipsWgt->setAutoFillBackground(false);
        TipsWgt->setAttribute(Qt::WA_TranslucentBackground);
        TipsWgt->resize(250, 188);

        TipsLbl->setStyleSheet("QLabel{border-image: url(:/bg/bg_tips.png);color:white;}");
        TipsLbl->resize(250, 188);
        TipsLbl->setAlignment(Qt::AlignCenter);

        connect(this, &MyPushButton::sig_showWgt, this, &MyPushButton::slot_showWgt);
    }
}

void MyPushButton::slot_showWgt(QPoint oPoint)
{
    TipsWgt->move(oPoint);
    TipsWgt->show();
}

/*
 * Function: move(int x, int y)
 * Usage: Btn->move(0,0)
 * ----------------------------
 * This function first conduct
 * move function of QPushButton class,
 * then save the target location for
 * tips window such that tips window
 * can be generated aside the push button.
*/
void MyPushButton::move(int x, int y){
    QPushButton::move(x,y);
    posi->setX(x+150);
    posi->setY(y-10);
}
