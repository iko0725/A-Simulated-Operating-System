#ifndef CAMERA_H
#define CAMERA_H
#include <QDialog>

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QMediaRecorder;

namespace Ui {
class Camera;
}

/*
 * Class: Camera <QDialog>
 * -----------------------
 * This class implements a camera that can take pictures and videos.
 */
class Camera : public QDialog
{
    Q_OBJECT
signals:
    void sendData(QString);   //用来传递数据的信号
    void sendData2(QString);
public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

private slots:

    /*
     * Function: on_camera_shot_clicked
     * Usage: on_camera_shot_clicked()
     * ------------------------------------
     * Click the shot button. This implementation can save a picture
     * taken by the camera into the address chosen by the user.
     */
    void on_camera_shot_clicked();


    /*
     * Function: on_video_start_clicked
     * Usage: on_video_start_clicked()
     * ------------------------------------
     * Click the start button. Then the camera begins to take a
     * video until the stop button is clicked.
     */
    void on_video_start_clicked();


    /*
     * Function: on_video_stop_clicked
     * Usage: on_video_stop_clicked()
     * ------------------------------------
     * Click the stop button. Then the camera that is taking videos
     * would stop taking and the video would be saved into the address chosen by the user.
     */
    void on_video_stop_clicked();

    /*
     * Function: on_camera_choose_clicked
     * Usage: on_camera_choose_clicked()
     * ------------------------------------
     * Click the choose button. This implementation can allow users to
     * choose the path that the video or photo would be saved into.
     */
    void on_camera_choose_clicked();

    /*
     * Function: updatePosition_video
     * Usage: updatePosition_video(qint64 duration)
     * ------------------------------------
     * Record the duration for taking videos. The video time is on the title of the
     * windows and increased with time.
     */
    void updatePosition_video(qint64 duration);


    /*
     * Function: showThread_camera
     * Usage: showThread_camera()
     * ------------------------------------
     *
     *
     */
    void showThread_camera();

private:
    Ui::Camera *ui;

    QCamera *camera;                        /* QCamera for Computer Camera */
    QCameraViewfinder *viewfinder;          /* QCameraViewfinder for camera */
    QCameraImageCapture *imageCapture;      /* QCameraImageCapture for shotting */
    QMediaRecorder *video_recorder;         /* QMediaRecorder for taking videos */
    QTimer *thread_camera;
};

#endif // CAMERA_H
