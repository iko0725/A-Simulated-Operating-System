#ifndef RECORDER_H
#define RECORDER_H

#include <QDialog>
class QAudioRecorder;

namespace Ui {
class Recorder;
}

/*
 * Class: Recorder <QDialog>
 * -----------------------
 * This class allows to record sound and save it in the computer.
 */
class Recorder : public QDialog{
    Q_OBJECT

public:
    explicit Recorder(QWidget *parent = nullptr);
    ~Recorder();
signals:
    void sendData(QString);   //用来传递数据的信号
    void sendData2(QString);
private slots:

    /*
     * Function: on_record_start_clicked
     * Usage: on_record_start_clicked()
     * ------------------------------------
     * Click the start button. Then the recorder begins to record
     * sounds until the stop button is clicked.
     */
    void on_record_start_clicked();

    /*
     * Function: on_record_stop_clicked
     * Usage: on_record_stop_clicked();
     * ------------------------------------
     * Click the stop button. Then the recorder that is recording sounds
     * would stop recording and the sound file would be saved into the address chosen by the user.
     */
    void on_record_stop_clicked();

    /*
     * Function: on_choose_clicked
     * Usage: on_choose_clicked()
     * ------------------------------------
     * Click the choose button. This implementation can allow users to
     * choose the path that the sound would be saved into.
     */
    void on_choose_clicked();

    /*
     * Function: updatePosition_video
     * Usage: updatePosition_video(qint64 duration)
     * ------------------------------------
     * Record the duration for the sound file. The recorder time is on the title of the
     * windows and increased with time.
     */
    void updateProgress(qint64 duration);

    /*
     * Function: showThread_recorder
     * Usage: showThread_recorder();
     * ------------------------------------
     *
     *
     */
    void showThread_recorder();

private:
    Ui::Recorder *ui;                   /* UI for recorder */
    QAudioRecorder *audioRecorder;      /* QAudioRecorder for recording */
    QTimer *thread_recorder;
};

#endif // RECORDER_H
