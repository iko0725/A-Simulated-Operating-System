#include "camera.h"
#include "ui_camera.h"
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QMediaRecorder>
#include <QAudioRecorder>
#include <QDragEnterEvent>
#include <QDateTime>
#include <QTimer>
#include "h_gv.h"


/*
 * Class: Camera <QDialog>
 * -----------------------
 * This class implements a camera that can take pictures and videos.
 */
Camera::Camera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Camera){
    ui->setupUi(this);
    allocate_memory[3].memory_size = 600 + (rand() % (100-0+1))+0;          // allocate memory
    this->setWindowTitle("Camera");
    camera = new QCamera;
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.count() > 0) {
        foreach (const QCameraInfo &cameraInfo, cameras) {
            qDebug() << cameraInfo.description();
        }
        camera = new QCamera(cameras.at(0));
    }

    viewfinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewfinder);
    viewfinder->resize(600, 350);

    imageCapture = new QCameraImageCapture(camera);

    camera->setCaptureMode(QCamera::CaptureVideo);
    video_recorder = new QMediaRecorder(camera);
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/pcm");
    audioSettings.setQuality(QMultimedia::HighQuality);
    video_recorder->setAudioSettings(audioSettings);

    connect(video_recorder, &QMediaRecorder::durationChanged, this,
            &Camera::updatePosition_video);
    camera->start();
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    thread_camera = new QTimer(this);
    thread_camera->setInterval (1000) ;
    connect(thread_camera,SIGNAL(timeout()),this,SLOT(showThread_camera()));
    thread_camera->start();

}

Camera::~Camera(){
    allocate_memory[3].memory_size = 0;
    camera->stop();
    delete ui;
    thread_camera->stop();
    flags[3]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==3){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Camera closed.\t"+times);
}


/*
 * Function: on_camera_shot_clicked
 * Usage: on_camera_shot_clicked()
 * ------------------------------------
 * Click the shot button. This implementation can save a picture
 * taken by the camera into the address chosen by the user.
 */
void Camera::on_camera_shot_clicked()
{
    allocate_memory[3].memory_size = 650 + (rand() % (100-0+1))+0;
    camera->setCaptureMode(QCamera::CaptureStillImage);
    if(ui->video_address->text() == "") {
        QMessageBox::warning(this, tr("Warning"),tr("Please enter the path first!"), QMessageBox::Yes);
        return;
    }
     QString fileName = QUrl::fromLocalFile(ui->video_address->text()).path();
    camera->searchAndLock();
    imageCapture->capture(fileName);
    camera->unlock();
}



/*
 * Function: on_video_start_clicked
 * Usage: on_video_start_clicked()
 * ------------------------------------
 * Click the start button. Then the camera begins to take a
 * video until the stop button is clicked.
 */
void Camera::on_video_start_clicked(){
    allocate_memory[3].memory_size = 650 + (rand() % (100-0+1))+0;
    if(ui->video_address->text() == "") {
        QMessageBox::warning(this, tr("Warning"),tr("Please enter the path first!"), QMessageBox::Yes);
        return;
    }
    video_recorder->setOutputLocation(QUrl::fromLocalFile(ui->video_address->text()));
    video_recorder->record();
}




/*
 * Function: on_video_stop_clicked
 * Usage: on_video_stop_clicked()
 * ------------------------------------
 * Click the stop button. Then the camera that is taking videos
 * would stop taking and the video would be saved into the address chosen by the user.
 */
void Camera::on_video_stop_clicked(){
    video_recorder->stop();
}



/*
 * Function: on_camera_choose_clicked
 * Usage: on_camera_choose_clicked()
 * ------------------------------------
 * Click the choose button. This implementation can allow users to
 * choose the path that the video or photo would be saved into.
 */
void Camera::on_camera_choose_clicked(){
    QString fileName = QFileDialog::getSaveFileName();
    ui->video_address->setText(fileName);
}



/*
 * Function: updatePosition_video
 * Usage: updatePosition_video(qint64 duration)
 * ------------------------------------
 * Record the time for taking videos. The video time is on the title of the
 * windows and increased with time.
 */
void Camera::updatePosition_video(qint64 duration){
    if (video_recorder->error() != QMediaRecorder::NoError || duration < 1000)
        return;
    setWindowTitle(tr("Recorded %1 sec").arg(duration / 1000));

}



/*
 * Function: showThread_camera
 * Usage: showThread_camera()
 * ------------------------------------
 *
 *
 */
void Camera::showThread_camera(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Camera is running:" + t);
}
