#include "videoplayer.h"
#include "ui_videoplayer.h"
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QMimeData>
#include <QDebug>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "vector"
#include <iostream>
#include <QFileDialog>
#include <QDebug>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QVBoxLayout>
#include <QApplication>
#include <QGraphicsVideoItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMovie>
#include <QDragEnterEvent>
#include <QDateTime>
#include <QTimer>
#include "h_gv.h"

/*
 * Class: VideoPlayer <QDialog>
 * -----------------------
 * This class allows to play music and video.
 */
VideoPlayer::VideoPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoPlayer){
    ui->setupUi(this);
    this->setWindowTitle("Video Player");

    /* Initialize the Player and its Widget */
    Player= new QMediaPlayer(this);
    PlayerWidget = new QVideoWidget(this);
    PlayerWidget->resize(ui->playwidget->size());
    allocate_memory[14].memory_size = 1000 + (rand() % (100-0+1))+0;
    QVBoxLayout* layout_video = new QVBoxLayout;
    layout_video->addWidget(PlayerWidget);
    ui->playwidget->setLayout(layout_video);

    /* Coonect functions to update information timely */
    connect(Player, &QMediaPlayer::positionChanged,
            this, &VideoPlayer::updatePosition);
    connect(Player, &QMediaPlayer::stateChanged, this, &VideoPlayer::stateChanged);
    connect(Player, &QMediaPlayer::mediaStatusChanged,
            this, &VideoPlayer::mediaStatusChanged);
    connect(Player, static_cast<void(QMediaPlayer::*)(QMediaPlayer::Error)>
            (&QMediaPlayer::error), this, &VideoPlayer::showError);

    connect(Player, &QMediaPlayer::metaDataAvailableChanged,
            this, &VideoPlayer::metaDataAvailableChanged);

    /* Initialize the Player List */
    PlayerList = new QMediaPlaylist;
    #ifdef Q_OS_OSX
    PlayerList->addMedia(QUrl("qrc:/SE/video.mp4"));
    PlayerList->addMedia(QUrl("qrc:/SE/music.mp3"));
    #endif
    #ifdef Q_OS_WIN
    QDir nowp = QDir::current();
    nowp.cdUp();
    QString nowps = nowp.absolutePath();
    QString video_WMV=nowps+"/CSC3002project/music/video.WMV";
    QString music_MP3=nowps+"/CSC3002project/music/music.mp3";
    PlayerList->addMedia(QUrl::fromLocalFile(video_WMV));
    PlayerList->addMedia(QUrl::fromLocalFile(music_MP3));
    #endif
    PlayerList->setCurrentIndex(0);
    PlayerList->setPlaybackMode(QMediaPlaylist::Loop);
    Player->setPlaylist(PlayerList);

     /* Deal with the thread */
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    thread_videoplayer = new QTimer(this);
    thread_videoplayer->setInterval (1000) ;
    connect(thread_videoplayer,SIGNAL(timeout()),this,SLOT(showThread_videoplayer()));
    thread_videoplayer->start();

//    connect(PlayerList, &QMediaPlaylist::currentIndex, this, &VideoPlayer::CallMusicGif);
}


/*
 * Function: ~VideoPlayer
 * Usage: ~VideoPlayer()
 * ------------------------------------
 * Close the window and close the music or the video that is playing.
 */
VideoPlayer::~VideoPlayer(){
    allocate_memory[14].memory_size = 0;
    thread_videoplayer->stop();
    flags[14]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==14){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Video player closed.\t"+times);
    delete Player;
    delete ui;
}

/*
 * Function: on_previous_clicked
 * Usage: on_previous_clicked()
 * ------------------------------------
 * Click the previous button. Turn to the previous music or the video on the playing list.
 */
void VideoPlayer::on_previous_clicked(){
    PlayerList->previous();
}

/*
 * Function: on_next_clicked
 * Usage: on_next_clicked()
 * ------------------------------------
 * Click the next button. Turn to the next music or the video on the playing list.
 */
void VideoPlayer::on_next_clicked(){
    PlayerList->next();
}

/*
 * Function: on_play_clicked
 * Usage: on_play_clicked()
 * ------------------------------------
 * Click the play button. Start to play the music or the video on the playing list.
 */
void VideoPlayer::on_play_clicked(){
    allocate_memory[14].memory_size = 1000 + (rand() % (100-0+1))+0;
    Player->stateChanged(QMediaPlayer::PlayingState);
    Player->setVideoOutput(PlayerWidget);
    Player->play();
}


/*
 * Function: on_stopplay_clicked
 * Usage: on_stopplay_clicked()
 * ------------------------------------
 * Click the stop button. Stop playing the music or the video on the playing list
 */
void VideoPlayer::on_stopplay_clicked(){
    allocate_memory[14].memory_size = 800 + (rand() % (100-0+1))+0;
    Player->stateChanged(QMediaPlayer::StoppedState);
    Player->stop();
}


/*
 * Function: on_addnew_clicked
 * Usage: on_addnew_clicked()
 * ------------------------------------
 * Click the add new button. Ask user to choose a music or a video
 * and then add it into the playing list.
 */
void VideoPlayer:: on_addnew_clicked(){
    allocate_memory[14].memory_size = 600 + (rand() % (100-0+1))+0;
    QUrl new_media = QFileDialog::getOpenFileUrl(this);
    PlayerList->addMedia(new_media);
}


/*
 * Function: on_remove_clicked
 * Usage: on_remove_clicked()
 * ------------------------------------
 * Click the remove button. Remove current music or the video in the playing list.
 */
void VideoPlayer:: on_remove_clicked(){
    allocate_memory[14].memory_size = 600 + (rand() % (100-0+1))+0;
    int current_media_index = PlayerList->currentIndex();
    PlayerList->removeMedia(current_media_index);
}


/*
 * Function: on_pause_clicked
 * Usage: on_pause_clicked()
 * ------------------------------------
 * Click the pause button. Pause playing the music or the video on the playing list.
 */
void VideoPlayer::on_pause_clicked(){
    Player->stateChanged(QMediaPlayer::PausedState);
    Player->pause();
}


/*
 * Function: on_videoslider_sliderMoved
 * Usage: on_videoslider_sliderMoved(int position)
 * ------------------------------------
 * Show the video and music slider. Users can move the slider to change the pace of
 * current media
 */
void VideoPlayer::on_videoslider_sliderMoved(int position){
    Player->setPosition(position*1000);
}


/*
 * Function: updatePosition_video
 * Usage: updatePosition_video(qint64 duration)
 * ------------------------------------
 * Record the duration for the sound file. The recorder time is on the title of the
 * windows and increased with time.
 */
void VideoPlayer::updatePosition(qint64 position){
    ui->videoslider->setMaximum(Player->duration() /1000);
    ui->videoslider->setValue(position/1000);
}


/*
 * Function: mediaStatusChanged
 * Usage: mediaStatusChanged(QMediaPlayer::MediaStatus status)
 * ------------------------------------
 * Change the current media state.
 */
void VideoPlayer::mediaStatusChanged(QMediaPlayer::MediaStatus status){
    if ((PlayerList->currentMedia().canonicalUrl().fileName().toStdString().find("mp3")) != std::string::npos){
        movie = new QMovie(":/SE/musicsign.gif");
        ui->movielabel->setMovie(movie);
        movie->start();
        PlayerWidget->setVisible(false);
    }else if ((PlayerList->currentMedia().canonicalUrl().fileName().toStdString().find("MP3")) != std::string::npos){
        movie = new QMovie(":/SE/musicsign.gif");
        ui->movielabel->setMovie(movie);
        movie->start();
        PlayerWidget->setVisible(false);
    }else{
        PlayerWidget->setVisible(true);
        ui->movielabel->clear();
    }
    switch (status) {
    case QMediaPlayer::UnknownMediaStatus:
        ui->label->setText(tr("Unknown Error！"));
        break;
    case QMediaPlayer::NoMedia:
        ui->label->setText(tr("NO Media！"));
        PlayerList->next();
        break;
    case QMediaPlayer::BufferingMedia:
        ui->label->setText(tr("Buffering！"));
        break;
    case QMediaPlayer::BufferedMedia:
        ui->label->setText(tr("Finish Buffering！"));
        break;
    case QMediaPlayer::LoadingMedia:
        ui->label->setText(tr("Loading！"));
        break;
    case QMediaPlayer::StalledMedia:
        ui->label->setText(tr("Stop Playing！"));
        break;
    case QMediaPlayer::EndOfMedia:
        ui->label->setText(tr("End of the Play！"));
        break;
    case QMediaPlayer::LoadedMedia:
        ui->label->setText(tr("Finish Loading！"));
        break;
    case QMediaPlayer::InvalidMedia:
        ui->label->setText(tr("No Availabel Media！"));
        break;
    default: break;
    }
}



/*
 * Function: stateChanged
 * Usage: stateChanged(QMediaPlayer::State state)
 * ------------------------------------
 * Check the current media state.
 */
void VideoPlayer::stateChanged(QMediaPlayer::State state){
    switch (state) {
    case QMediaPlayer::StoppedState:
        ui->label_2->setText(tr("State:Stopped！"));
        break;
    case QMediaPlayer::PlayingState:
        ui->label_2->setText(tr("State:Playing！"));
        break;
    case QMediaPlayer::PausedState:
        ui->label_2->setText(tr("State:Paused！"));
        break;
    default: break;
    }
}


/*
 * Function: showError
 * Usage: showError(QMediaPlayer::Error error)
 * ------------------------------------
 * Dispaly the errors that occur in the playing progress.
 */
void VideoPlayer::showError(QMediaPlayer::Error error){
    switch (error) {
    case QMediaPlayer::NoError:
        ui->label_3->setText(tr("No Error！"));
        break;
    case QMediaPlayer::ResourceError:
        ui->label_3->setText(tr("Resource Error！"));
        break;
    case QMediaPlayer::FormatError:
        ui->label_3->setText(tr("Format Error！"));
        break;
    case QMediaPlayer::NetworkError:
        ui->label_3->setText(tr("Network Error！"));
        break;
    case QMediaPlayer::AccessDeniedError:
        ui->label_3->setText(tr("Access Denied Error！"));
        break;
    case QMediaPlayer::ServiceMissingError:
        ui->label_3->setText(tr("Service Missing Error！"));
        break;
    default: break;
    }
}

/*
 * Function: metaDataAvailableChanged
 * Usage: metaDataAvailableChanged(bool available)
 * ------------------------------------
 * Gain information of current media
 */
void VideoPlayer::metaDataAvailableChanged(bool available){
    if(available) {
        QString title = Player->metaData("Title").toString();
        QString author = Player->metaData("Author").toString();
        if (title == "" ) title= "Media";
        if (author == "") author = "Anonymous";
        setWindowTitle(title + "-" + author);
    }
}

/*
 * Function: showThread_videoplayer
 * Usage: showThread_videoplayer();
 * ------------------------------------
 *
 *
 */
void VideoPlayer::showThread_videoplayer(){
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Video player is running:" + t);
}
