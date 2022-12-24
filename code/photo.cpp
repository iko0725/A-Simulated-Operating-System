/*
 * Class: Photo
 * --------------
 * Generates a QWidget that allow user to load and
 * preview images with brightness and saturation adjusment.
 * User can choose to save adjusted photos.
*/
#include "photo.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QStyleOption>
#include <QPainter>
#include <QFileDialog>
#include <QColor>
#include "h_gv.h"

/*
 * Function: Photo(QWidget *parent = nullptr)
 * Usage: QWidget *w = new Photo(this);
 * ------------------------------------
 * Construct a Photo class widget.
*/
Photo::Photo(QWidget *parent)
{
    //Set title
    this->setWindowTitle("Photo Viewer");
    allocate_memory[11].memory_size = 300 + (rand() % (30-0+1))+0;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    thread_photo = new QTimer(this);
    thread_photo->setInterval (1000) ;
    connect(thread_photo,SIGNAL(timeout()),this,SLOT(showThread_photo()));
    thread_photo->start();
    this->show();
    QMessageBox::information(this,"Prompt","Right-click to view the function list.");
}

/*
 * Function: ~Photo()
 * Usage: Usually implicit
 * -----------------------
 * Delete the widget and all storage allocated by it.
*/
Photo::~Photo()
{
    thread_photo->stop();
    allocate_memory[11].memory_size = 0;
    flags[11]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==11){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Photo closed.\t"+times);
}

// Set context menu with 9 bars.

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
void Photo::contextMenuEvent(QContextMenuEvent *event)
{
    QPoint pos = event->pos();
    pos = this->mapToGlobal(pos);
    QMenu *menu = new QMenu(this);

    QAction *loadImage = new QAction(tr("Load Image"));
    QObject::connect(loadImage, &QAction::triggered, this, &Photo::onLoadImage);
    menu->addAction(loadImage);
    menu->addSeparator();

    QAction *zoomInAction = new QAction(tr("Zoom +"));
    QObject::connect(zoomInAction, &QAction::triggered, this, &Photo::onZoomInImage);
    menu->addAction(zoomInAction);

    QAction *zoomOutAction = new QAction(tr("Zoom -"));
    QObject::connect(zoomOutAction, &QAction::triggered, this, &Photo::onZoomOutImage);
    menu->addAction(zoomOutAction);

    QAction *BrightAction = new QAction(tr("Brightness +"));
    QObject::connect(BrightAction, &QAction::triggered, this, &Photo::onBrighter);
    menu->addAction(BrightAction);

    QAction *DarkAction = new QAction(tr("Brightness -"));
    QObject::connect(DarkAction, &QAction::triggered, this, &Photo::onDarker);
    menu->addAction(DarkAction);

    QAction *VividAction = new QAction(tr("Saturation +"));
    QObject::connect(VividAction, &QAction::triggered, this, &Photo::onVivid);
    menu->addAction(VividAction);

    QAction *GreyAction = new QAction(tr("Saturation -"));
    QObject::connect(GreyAction, &QAction::triggered, this, &Photo::onGrey);
    menu->addAction(GreyAction);

    QAction *presetAction = new QAction(tr("Preset"));
    QObject::connect(presetAction, &QAction::triggered, this, &Photo::onPresetImage);
    menu->addAction(presetAction);

    QAction *SaveAction = new QAction(tr("Save"));
    QObject::connect(SaveAction, &QAction::triggered, this, &Photo::onSave);
    menu->addAction(SaveAction);
    menu->exec(pos);


}

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
void Photo::paintEvent(QPaintEvent *event)
{
    // Draw Widget
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);


    if (m_Image.isNull()){
        return QWidget::paintEvent(event);
    }

    // Size image to the minimum value of its original size and the window's size
    int width = qMin(m_Image.width(), this->width());
    int height = width * 1.0 / (m_Image.width() * 1.0 / m_Image.height());
    height = qMin(height, this->height());
    width = height * 1.0 * (m_Image.width() * 1.0 / m_Image.height());

    // Translate the image
    painter.translate(this->width() / 2 + m_XPtInterval, this->height() / 2 + m_YPtInterval);

    // Scale the image
    painter.scale(m_ZoomValue, m_ZoomValue);

    // Draw image
    QRect picRect(-width / 2, -height / 2, width, height);
    painter.drawImage(picRect, m_Image);
}

// Use mouse wheel to scale the image

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
void Photo::wheelEvent(QWheelEvent *event)
{
    int value = event->delta();
    if (value > 0)
        onZoomInImage();
    else
        onZoomOutImage();

    this->update();
}

/*
 * The three functions below together updates
 * the m_XPtInterval and m_YPtInterval when
 * user drags the image. The updated value would then
 * be reflected to the translate function and move the image.
*/

// Update m_OldPos when mouse is pressed.
// Flag m_Pressed.

/*
 * Function: mousePressEvent(QMouseEvent *event)
 * Usage: Implicit
 * ---------------------------------------------
 * Overide the mousePressEvent such that it saves
 * the cursor position beofre pressing and the status of 'being pressed'.
*/
void Photo::mousePressEvent(QMouseEvent *event)
{
    m_OldPos = event->pos();
    m_Pressed = true;
}

// Update m_XPtInterval m_YPtInterval when mouse is pressed & dragged.

/*
 * Function: mouseMoveEvent(QMouseEvent *event)
 * Usage: Implicit
 * --------------------------------------------
 * Overide mouseMoveEvent function. It only returns
 * when mouse stopped being pressed. It updates the
 * cursor position and save the x and y interval
 * moved during pressing.
*/
void Photo::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_Pressed)
        return QWidget::mouseMoveEvent(event);

    this->setCursor(Qt::SizeAllCursor);
    QPoint pos = event->pos();
    int xPtInterval = pos.x() - m_OldPos.x();
    int yPtInterval = pos.y() - m_OldPos.y();

    m_XPtInterval += xPtInterval;
    m_YPtInterval += yPtInterval;

    m_OldPos = pos;
    this->update();
}

// Deflag m_Press when mouse is released.

/*
 * Function: mouseReleaseEvent(QMouseEvent *)
 * Usage: Implicit
 * ------------------------------------------
 * Overide of the mouseReleaseEvent function.
 * It change the pressing status m_Pressed into false
 * and change the cursor image back to arrow cursor.
*/
void Photo::mouseReleaseEvent(QMouseEvent *)
{
    m_Pressed = false;
    this->setCursor(Qt::ArrowCursor);
}

/* Load .png, .xpm, .jpg images from the users computer.*/

/*
 * Function: onLoadImage(void)
 * Usage: QObject::connect(loadImage, &QAction::triggered, this, &Photo::onLoadImage);
 * -----------------------------------------------------------------------------------
 * Load png, xpm or jpg files from the computer storage.
 * It actually load the image twice and save a backup copy.
*/
void Photo::onLoadImage(void)
{
    QString imageFile = QFileDialog::getOpenFileName(this, "Open Image", "./", tr("Images (*.png *.xpm *.jpg)"));

    QFile file(imageFile);
    if (!file.exists()){
        QMessageBox::warning(this,"Warning","Failed to load the image!");
        return;
    }

    m_Image.load(imageFile);
    backup.load(imageFile);
}

/*
 * Function: onZoomInImage
 * Usage: QObject::connect(zoomInAction, &QAction::triggered, this, &Photo::onZoomInImage);
 * ----------------------------------------------------------------------------------------
 * Increase the m_ZoomValue by 0.1, which in paintEvent function
 * rescale the image to 1.1 of its present size.
*/
void Photo::onZoomInImage(void)
{
    m_ZoomValue += 0.1;
    this->update();
}

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
void Photo::onZoomOutImage(void)
{
    m_ZoomValue -= 0.1;
    // Prevent the image to be zoomed smaller than 10% of its original size.
    if (m_ZoomValue <= 0)
    {
        m_ZoomValue += 0.1;
        return;
    }

    this->update();
}

// Set default value of the image.

/*
 * Function: onPresetImage(void)
 * Usage: QObject::connect(presetAction, &QAction::triggered, this, &Photo::onPresetImage);
 * ----------------------------------------------------------------------------------------
 * Replace the changed image with its backup and
 * change all moving & scaling variavles to its original state.
*/
void Photo::onPresetImage(void)
{
    m_ZoomValue = 1.0;
    m_XPtInterval = 0;
    m_YPtInterval = 0;
    m_Image = backup;
    this->update();
}

/*
 * Function: onBrighter(void)
 * Usage: QObject::connect(BrightAction, &QAction::triggered, this, &Photo::onBrighter);
 * -------------------------------------------------------------------------------------
 * Repaint the QImage using QColor, during which adds 30 to
 * both r, g and b of the RGB status, resulting a increasement
 * of brightness of the entire image. If any of the RGB status
 * reached its maximum of 255, it would be bounded to that value.
*/
void Photo::onBrighter(void)
{
        QImage *newImage = new QImage(m_Image.width(), m_Image.height(), QImage::Format_ARGB32);
        QColor oldColor;    int r,g,b;
        for(int x=0; x<newImage->width(); x++)
        {

            for(int y=0; y<newImage->height(); y++)
            {
                oldColor = QColor(m_Image.pixel(x,y));
                r = oldColor.red() + 30;
                g = oldColor.green() +30;
                b = oldColor.blue() +30;
                //Check if the new values are between 0 and 255
                r = qBound(0, r, 255);
                g = qBound(0, g, 255);
                b = qBound(0, b, 255);
                newImage->setPixel(x,y, qRgb(r,g,b));
            }
        }
        m_Image = *newImage;
        this->update();
    }

/*
 * Function: onDarker(void)
 * Usage: QObject::connect(DarkAction, &QAction::triggered, this, &Photo::onDarker);
 * ---------------------------------------------------------------------------------
 * Repaint the QImage using QColor, during which substracts 30 to
 * both r, g and b of the RGB status, resulting a increasement
 * of brightness of the entire image. If any of the RGB status
 * reached its minimum of 0, it would be bounded to that value.
*/
void Photo::onDarker(void)
{
        QImage *newImage = new QImage(m_Image.width(), m_Image.height(), QImage::Format_ARGB32);
        QColor oldColor;    int r,g,b;
        for(int x=0; x<newImage->width(); x++)
        {

            for(int y=0; y<newImage->height(); y++)
            {
                oldColor = QColor(m_Image.pixel(x,y));
                r = oldColor.red() - 30;
                g = oldColor.green() - 30;
                b = oldColor.blue() - 30;
                //Check if the new values are between 0 and 255
                r = qBound(0, r, 255);
                g = qBound(0, g, 255);
                b = qBound(0, b, 255);
                newImage->setPixel(x,y, qRgb(r,g,b));
            }
        }
        m_Image = *newImage;
        this->update();
    }

/*
 * Function: onVivid(void)
 * Usage: QObject::connect(VividAction, &QAction::triggered, this, &Photo::onVivid);
 * ---------------------------------------------------------------------------------
 * Repaint the QImage using QColor, during which adds 10 to
 * s(saturation) of the HSL status, resulting a increasement
 * of vividness of the entire image. If the saturation status
 * reached its maximum of 255, it would be bounded to that value.
*/
void Photo::onVivid(void)
{
        QImage *newImage = new QImage(m_Image.width(), m_Image.height(), QImage::Format_ARGB32);
        QColor oldColor;
        QColor newColor;
        int h,s,l;
        for(int x=0; x<newImage->width(); x++)
        {

            for(int y=0; y<newImage->height(); y++)
            {
                oldColor = QColor(m_Image.pixel(x,y));
                h = oldColor.hue();
                s = oldColor.saturation() + 10;
                l = oldColor.lightness();
                //Check if the new values are between 0 and 255
                s = qBound(0, s, 255);
                newColor.setHsl(h, s, l);
                newImage->setPixel(x, y, qRgb(newColor.red(), newColor.green(), newColor.blue()));

            }
        }
        m_Image = *newImage;
        this->update();
    }

/*
 * Function: onGrey(void)
 * Usage: QObject::connect(GreyAction, &QAction::triggered, this, &Photo::onGrey);
 * -------------------------------------------------------------------------------
 * Repaint the QImage using QColor, during which substracts 10 to
 * s(saturation) of the HSL status, resulting a decreasement
 * of vividness of the entire image. If the saturation status
 * reached its minimum of 0, it would be bounded to that value.
*/
void Photo::onGrey(void)
{
        QImage *newImage = new QImage(m_Image.width(), m_Image.height(), QImage::Format_ARGB32);
        QColor oldColor;
        QColor newColor;
        int h,s,l;
        for(int x=0; x<newImage->width(); x++)
        {

            for(int y=0; y<newImage->height(); y++)
            {
                oldColor = QColor(m_Image.pixel(x,y));
                h = oldColor.hue();
                s = oldColor.saturation() - 10;
                l = oldColor.lightness();
                //Check if the new values are between 0 and 255
                s = qBound(0, s, 255);
                newColor.setHsl(h, s, l);
                newImage->setPixel(x, y, qRgb(newColor.red(), newColor.green(), newColor.blue()));

            }
        }
        m_Image = *newImage;
        this->update();
    }

void Photo::showThread_photo(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Photo is running:" + t);
}

void Photo::onSave(void){
    QString imageName = QFileDialog::getSaveFileName(this, "Save Image", "./untitle.png", tr("Images (*.png)"));
    bool judge = m_Image.save(imageName, "PNG", 100);
    if (!judge){
        QMessageBox::warning(this,"Warning","Failed to save the image!");
    }

};






