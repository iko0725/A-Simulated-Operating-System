#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QResizeEvent>
#include <QMovie>
namespace Ui {
class VideoPlayer;
}

/*
 * Class: VideoPlayer <QDialog>
 * -----------------------
 * This class allows to play music and video.
 */
class VideoPlayer: public QDialog
{
    Q_OBJECT

signals:
    void sendData(QString);   //用来传递数据的信号
    void sendData2(QString);

public:
    explicit VideoPlayer(QWidget *parent = nullptr);

    /*
     * Function: ~VideoPlayer
     * Usage: ~VideoPlayer()
     * ------------------------------------
     * Close the window and close the music or the video that is playing.
     */
    ~VideoPlayer();

private slots:
    /*
     * Function: on_play_clicked
     * Usage: on_play_clicked()
     * ------------------------------------
     * Click the play button. Start to play the music or the video on the playing list.
     */
    void on_play_clicked();

    /*
     * Function: on_stopplay_clicked
     * Usage: on_stopplay_clicked()
     * ------------------------------------
     * Click the stop button. Stop playing the music or the video on the playing list
     */
    void on_stopplay_clicked();

    /*
     * Function: on_pause_clicked
     * Usage: on_pause_clicked()
     * ------------------------------------
     * Click the pause button. Pause playing the music or the video on the playing list.
     */
    void on_pause_clicked();


    /*
     * Function: on_previous_clicked
     * Usage: on_previous_clicked()
     * ------------------------------------
     * Click the previous button. Turn to the previous music or the video on the playing list.
     */
    void on_previous_clicked();

    /*
     * Function: on_next_clicked
     * Usage: on_next_clicked()
     * ------------------------------------
     * Click the next button. Turn to the next music or the video on the playing list.
     */
    void on_next_clicked();

    /*
     * Function: on_addnew_clicked
     * Usage: on_addnew_clicked()
     * ------------------------------------
     * Click the add new button. Ask user to choose a music or a video
     * and then add it into the playing list.
     */
    void on_addnew_clicked();

    /*
     * Function: on_remove_clicked
     * Usage: on_remove_clicked()
     * ------------------------------------
     * Click the remove button. Remove current music or the video in the playing list.
     */
    void on_remove_clicked();


    /*
     * Function: on_videoslider_sliderMoved
     * Usage: on_videoslider_sliderMoved(int position)
     * ------------------------------------
     * Show the video and music slider. Users can move the slider to change the pace of
     * current media
     */
    void on_videoslider_sliderMoved(int position);

    /*
     * Function: updatePosition_video
     * Usage: updatePosition_video(qint64 duration)
     * ------------------------------------
     * Record the duration for the sound file. The recorder time is on the title of the
     * windows and increased with time.
     */
    void updatePosition(qint64 position);

    /*
     * Function: stateChanged
     * Usage: stateChanged(QMediaPlayer::State state)
     * ------------------------------------
     * Check the current media state.
     */
    void stateChanged(QMediaPlayer::State state);

    /*
     * Function: mediaStatusChanged
     * Usage: mediaStatusChanged(QMediaPlayer::MediaStatus status)
     * ------------------------------------
     * Change the current media state.
     */
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

    /*
     * Function: showError
     * Usage: showError(QMediaPlayer::Error error)
     * ------------------------------------
     * Dispaly the errors that occur in the playing progress.
     */
    void showError(QMediaPlayer::Error error);

    /*
     * Function: metaDataAvailableChanged
     * Usage: metaDataAvailableChanged(bool available)
     * ------------------------------------
     * Gain information of current media
     */
    void metaDataAvailableChanged(bool available);

    /*
     * Function: showThread_videoplayer
     * Usage: showThread_videoplayer();
     * ------------------------------------
     *
     *
     */
    void showThread_videoplayer();

private:
    Ui::VideoPlayer *ui;                /* Ui for Media Player */
    QVideoWidget * PlayerWidget;        /* Widget for Media Player */
    QMediaPlayer * Player;              /* Player for Media Player */
    QMediaPlaylist * PlayerList;        /* Playlist for Media Player */
    QMovie * movie;                     /* Movie for Media Player */
    QTimer *thread_videoplayer;
};

#endif // VIDEOPLAYER_H
