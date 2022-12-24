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
#ifndef CALENDARPUSHBUTTON_H
#define CALENDARPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QGridLayout>
#include <QApplication>
#include <QMouseEvent>

class QGraphicsOpacityEffect;

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    /*
     * Function: MyPushButton(QWidget *Parent, QString normalImg, QString pressImg = "",bool AsButton = true, QString tips = "");
     * Usage: MyPushButton(this, "", "",true, "")
     * ------------------------------------------
     * Construct a MyPushButton object.
*/
    MyPushButton(QWidget *Parent, QString normalImg, QString pressImg = "",bool AsButton = true, QString tips = "");
    QString normalImgPath;
    QString pressImgPath;

    /* Button initialization */

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
    void init(QWidget *Parent);

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
    void move(int x, int y);

    /* Animation Effects */

    // Button go down for 10 mm.
    /*
     * Function: Down()
     * Usage: Btn->Down();
     * -------------------
     * Animate the push button making it
     * bounce down a little bit.
    */
    void Down();

    // Button go up for 10 mm.
    /*
     * Function: Up()
     * Usage: Btn->Up();
     * -------------------
     * Animate the push button making it
     * bounce up a little bit.
    */
    void Up();  

    // Button shifts alpha level.
    /*
     * Function: Shimmer
     * Usage: implicit
     * ---------------
     * When ever m_pTimer is timed up,
     * change the opacity value of button by 0.05,
     * creating a shimmering effect
    */
    void Shimmer();

    /*
     * Function: startShimmerAnimation()
     * Usage: startShimmerAnimation()
     * ---------------------------------
     * Set m_pTimer to 50 misc a cycle and
     * trigger the shimmer function.
    */
    void startShimmerAnimation();

    /*
     * Function: stopShimmerAnimation()
     * Usage: stopShimmerAnimation()
     * --------------------------------
     * Stop m_pTimer and thus stop the shimmer function.
    */
    void stopShimmerAnimation();

    /*
     * Function: isActive() const
     * Usage: if(isActive())
     * --------------------------
     * Detect whether shimmer effect is on.
    */
    bool isActive() const;

    /* Tips Widget */

    // Detect cursor hover & left
    /*
     * Function: enterEvent(QEvent * )
     * Usage: Implicit
     * -------------------------------
     * Emit a signal when detecting
     * cursor entering the button.
    */
    void enterEvent(QEvent * ev);

    /*
    * Function: leaveEvent(QEvent * )
    * Usage: Implicit
    * -------------------------------
    * Hide the tips window when detecting
    * cursor leaving the button.
    */
    void leaveEvent(QEvent * ev);

    // Show tips widget
    /*
     * Function: slot_showWgt(QPoint oPoint)
     * Usage: connect(this, &MyPushButton::sig_showWgt, this, &MyPushButton::slot_showWgt);
     * ------------------------------------------------------------------------------------
     * Show tips window and moves it to the position given by oPoint.
    */
    void slot_showWgt(QPoint oPoint);



signals:
    void sigTimeout();
    void sig_showWgt(QPoint);     //Send signal to the widget to be displayed
    void sig_hideWgt();           //Send signal to the widget to be hidden

private:
    /* Animation Effects */
    QGraphicsOpacityEffect *m_pOpacityEffect = Q_NULLPTR;
    QTimer *m_pTimer = Q_NULLPTR;
    bool m_bStatus = false;
    float m_opacityVal = 1.0;

    /* Tips Widget */
    QLabel *TipsLbl;
    QWidget *TipsWgt;
    QGridLayout *TipsLyt;
    int waitingTime = 2000;
    QTimer *w_Timer = Q_NULLPTR;  

    bool IsButton = true;

    QPoint *posi = new QPoint;


};

#endif // CALENDARPUSHBUTTON_H
