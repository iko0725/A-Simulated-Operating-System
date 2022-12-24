#include "painter.h"
#include "ui_painter.h"
#include <QPainter>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include "h_gv.h"
#include <QToolBar>
#include <QMainWindow>
#include <QColorDialog>
#include <iostream>
/*
 * Function: Painter
 * Usage:Painter(QWidget *parent = nullptr);
 * ----------------------------------------
 * This is a construction function of painter, including some
 * initialization of the painter.
 */
float scale;
Painter::Painter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Painter)
{
    ui->setupUi(this);
    //Set title
    this->setWindowTitle("Painter");
    allocate_memory[10].memory_size = 300 + (rand() % (10-0+1))+0;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    thread_painter = new QTimer(this);
    thread_painter->setInterval (1000) ;
    connect(thread_painter,SIGNAL(timeout()),this,SLOT(showThread_painter()));
    thread_painter->start();
    ui->spinBox_width->setValue(1);
    resize(600, 500);
    pix = QPixmap(400, 500);
    pix.fill(Qt::white);
    scale =1;
//    zoomin = new QPushButton(this);
//    zoomin->setText(tr("zoomIn"));
//    zoomin->move(450, 150);
//    zoomin->resize(112,32);
//    connect(zoomin, SIGNAL(clicked()), this, SLOT(zoomIn()));
}


/*
 * Function: ~Painter
 * Usage:~Painter();
 * ----------------------------------------
 * This is a deconstruction functino of this apllication,
 * the deconstructor frees any heap memory allocated by the
 * application.
 */
Painter::~Painter()
{
    delete ui;
    allocate_memory[10].memory_size = 0;
    thread_painter->stop();
    flags[10]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==10){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Painter closed.\t"+times);
}

void Painter::paintEvent(QPaintEvent *)
{

    allocate_memory[10].memory_size = 250 + (rand() % (10-0+1))+0;
    QPainter pp(&pix);
    pen.setWidth(wid);
    pen.setColor(color);
    pp.setPen(pen);
    pp.setBrush(br);
    pp.drawLine(lastPoint/scale, endPoint/scale);

    lastPoint = endPoint;
    QPainter painter(this);
    painter.scale(scale, scale);
    painter.drawPixmap(0, 0, pix);
}

void Painter::mousePressEvent(QMouseEvent *event)
{
    allocate_memory[10].memory_size = 250 + (rand() % (10-0+1))+0;
   if(event->button()==Qt::LeftButton)
   lastPoint = event->pos();
}

void Painter::mouseMoveEvent(QMouseEvent *event)
{
     if(event->buttons()&Qt::LeftButton) {
              endPoint = event->pos();
              update();
     }
}

void Painter::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
              endPoint = event->pos();
              update();
     }
}

/*
 * Implementation notes: zoomIn, on_pushButton_save_painter_clicked
 * on_pushButton_color_clicked
 * ----------------------------------------
 * Thease are slots for the action of clicking the pushbuttons.
 */
void Painter::zoomIn()
{
    scale *=2;
    update();
}

void Painter::zoomOut()
{
    scale /=2;
    update();
}

void Painter::on_pushButton_save_painter_clicked()
{
    allocate_memory[10].memory_size = 250 + (rand() % (10-0+1))+0;
    QString* imageName=new QString();
    *imageName=QFileDialog::getSaveFileName(this,tr("Save Image"), "./untitle.png", tr("Image Files (*.png)"));
    if(imageName->size()>0){
         if(pix.save(*imageName,"PNG")){
             QMessageBox::information(this,"Success","File is saved.");
         }else{
             QMessageBox::information(this,"Fail","File cannot be saved");
         }
    }
    this->raise();
}

/*
 * Implementation notes: showThread_painter
 * ----------------------------------------
 * This is a slot for the Qtimer.
 */

void Painter::showThread_painter(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Painter is running:" + t);
}

/*
 * Function: on_spinBox_width_valueChanged
 * Usage:on_spinBox_width_valueChanged(int arg1)
 * ---------------------------------------------
 * Get the reaction when change the value of the spin box.
 */
void Painter::on_spinBox_width_valueChanged(int arg1)
{
    wid = arg1;
}

/*
 * Function: on_pushButton_color_clicked
 * Usage:on_pushButton_color_clicked()
 * -----------------------------------
 * Get the reaction when click button.
 */
void Painter::on_pushButton_color_clicked()
{
    QColor newColor = QColorDialog::getColor();
     if (newColor.isValid()){
         color = newColor;
         QPalette palette = ui->textBrowser_color->palette();
          palette.setColor(QPalette::Base,color);
          ui->textBrowser_color->setPalette(palette);
          update();
          this->raise();
     }
}



void Painter::on_pushButton_zoomin_clicked()
{
    zoomIn();
}

void Painter::on_pushButton_zoomout_clicked()
{
    zoomOut();
}
