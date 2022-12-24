/*
 * Class: Photo
 * --------------
 * Generates a QWidget that allow user to load and
 * preview images with brightness and saturation adjusment.
 * User can choose to save adjusted photos.
*/
#ifndef IMAGE_VIEW_H
#define IMAGE_VIEW_H

#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class Photo;
}
class Photo : public QWidget
{
    Q_OBJECT

public:
    /*
     * Function: Photo(QWidget *parent = nullptr)
     * Usage: QWidget *w = new Photo(this);
     * ------------------------------------
     * Construct a Photo class widget.
*/
    explicit Photo(QWidget *parent = nullptr);
    /*
     * Function: ~Photo()
     * Usage: Usually implicit
     * -----------------------
     * Delete the widget and all storage allocated by it.
*/
    ~Photo();
signals:
    void sendData(QString);
    void sendData2(QString);
protected:
    /*
     * Function: contextMenuEvent(QContextMenuEvent *event)
     * Usage: Implicit
     * ----------------------------------------------------
     * Override the context menu event. By right clicking the cursor
     * a context menu with 8 bars would appear. The bars are:
     * - Load Image, which ask the user to load a image from computer.
     * - Zoom +, which expands the loaded image slightly.
     * - Zoom -, which shrinks the loaded image slightly.
     * - Brightness +, which set the loaded photo to be brighter.
     * - Brightness -, which set the loaded photo to be dimmer.
     * - Saturation +, which set the loaded photo to be more vivid.
     * - Saturation -, which set the loaded photo to be more greish.
    */
    void contextMenuEvent(QContextMenuEvent *event) override;

    /*
     * Function: paintEvent(QPaintEvent *event)
     * Usage: implicit
     * ----------------------------------------
     * Draw the loaded photo onto the QWidget.
     * The photo would be scaled such that
     * its width is the minimum of its original width
     * and the frame size of the widget.
     * If anychange (of brightness, of saturation, of scale)
     * has occured to the image it would translate and rescale it.
     * (repaint called by update() function in other functions)
    */
    void paintEvent(QPaintEvent *event) override;

    /*
     * Function: wheelEvent(QWheelEvent *event)
     * Usage: Implicit
     * ---------------------------------------
     * Overide the wheelEvent function such that it
     * detects wheel movement of mouse and preform zoom functions.
     * If the wheel value is positive, zoom in function
     * would be called. If the value is negative, zoom out function
     * would be called. This would result in re-scaling the image.
    */
    void wheelEvent(QWheelEvent *event) override;

    /*
     * Function: mousePressEvent(QMouseEvent *event)
     * Usage: Implicit
     * ---------------------------------------------
     * Overide the mousePressEvent such that it saves
     * the cursor position beofre pressing and the status of 'being pressed'.
    */
    void mousePressEvent(QMouseEvent *event) override;

    /*
     * Function: mouseMoveEvent(QMouseEvent *event)
     * Usage: Implicit
     * --------------------------------------------
     * Overide mouseMoveEvent function. It only returns
     * when mouse stopped being pressed. It updates the
     * cursor position and save the x and y interval
     * moved during pressing.
    */
    void mouseMoveEvent(QMouseEvent *event) override;

    /*
     * Function: mouseReleaseEvent(QMouseEvent *)
     * Usage: Implicit
     * ------------------------------------------
     * Overide of the mouseReleaseEvent function.
     * It change the pressing status m_Pressed into false
     * and change the cursor image back to arrow cursor.
    */
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Photo *ui;
    QImage m_Image;
    QImage backup;
    qreal m_ZoomValue = 1.0;
    int m_XPtInterval = 0;
    int m_YPtInterval = 0;
    QPoint m_OldPos;
    bool m_Pressed = false;
    QTimer *thread_photo;

private slots:

    /*
     * Function: onLoadImage(void)
     * Usage: QObject::connect(loadImage, &QAction::triggered, this, &Photo::onLoadImage);
     * -----------------------------------------------------------------------------------
     * Load png, xpm or jpg files from the computer storage.
     * It actually load the image twice and save a backup copy.
    */
    void onLoadImage(void);

    /*
     * Function: onZoomInImage
     * Usage: QObject::connect(zoomInAction, &QAction::triggered, this, &Photo::onZoomInImage);
     * ----------------------------------------------------------------------------------------
     * Increase the m_ZoomValue by 0.1, which in paintEvent function
     * rescale the image to 1.1 of its present size.
    */
    void onZoomInImage(void);

    /*
     * Function: onZoomInImage
     * Usage: QObject::connect(zoomOutAction, &QAction::triggered, this, &Photo::onZoomOutImage);
     * ----------------------------------------------------------------------------------------
     * Decrease the m_ZoomValue by 0.1, which in paintEvent function
     * rescale the image to 1.1 of its present size.
     * If m_ZoomValue becomes zero or negative after the operation,
     * an extra 0.1 would be added to it to make it positive. This means
     * loaded images can not be scaled to less than 10% of its original size.
    */
    void onZoomOutImage(void);

    /*
     * Function: onPresetImage(void)
     * Usage: QObject::connect(presetAction, &QAction::triggered, this, &Photo::onPresetImage);
     * ----------------------------------------------------------------------------------------
     * Replace the changed image with its backup and
     * change all moving & scaling variavles to its original state.
    */
    void onPresetImage(void);

    /*
     * Function: onBrighter(void)
     * Usage: QObject::connect(BrightAction, &QAction::triggered, this, &Photo::onBrighter);
     * -------------------------------------------------------------------------------------
     * Repaint the QImage using QColor, during which adds 30 to
     * both r, g and b of the RGB status, resulting a increasement
     * of brightness of the entire image. If any of the RGB status
     * reached its maximum of 255, it would be bounded to that value.
    */
    void onBrighter(void);

    /*
     * Function: onDarker(void)
     * Usage: QObject::connect(DarkAction, &QAction::triggered, this, &Photo::onDarker);
     * ---------------------------------------------------------------------------------
     * Repaint the QImage using QColor, during which substracts 30 to
     * both r, g and b of the RGB status, resulting a increasement
     * of brightness of the entire image. If any of the RGB status
     * reached its minimum of 0, it would be bounded to that value.
    */
    void onDarker(void);

    /*
     * Function: onVivid(void)
     * Usage: QObject::connect(VividAction, &QAction::triggered, this, &Photo::onVivid);
     * ---------------------------------------------------------------------------------
     * Repaint the QImage using QColor, during which adds 10 to
     * s(saturation) of the HSL status, resulting a increasement
     * of vividness of the entire image. If the saturation status
     * reached its maximum of 255, it would be bounded to that value.
    */
    void onVivid(void);

    /*
     * Function: onGrey(void)
     * Usage: QObject::connect(GreyAction, &QAction::triggered, this, &Photo::onGrey);
     * -------------------------------------------------------------------------------
     * Repaint the QImage using QColor, during which substracts 10 to
     * s(saturation) of the HSL status, resulting a decreasement
     * of vividness of the entire image. If the saturation status
     * reached its minimum of 0, it would be bounded to that value.
    */
    void onGrey(void);
    void showThread_photo();
    void onSave();
};
#endif // IMAGE_VIEW_H
