#include "recorder.h"
#include "ui_recorder.h"
#include <QAudioRecorder>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QDragEnterEvent>
#include <QTimer>
#include <QDateTime>
#include "h_gv.h"

/*
 * Class: Recorder <QDialog>
 * -----------------------
 * This class allows to record sound and save it in the computer.
 */
Recorder::Recorder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recorder){
    ui->setupUi(this);
    this->setWindowTitle("Recorder");
    allocate_memory[12].memory_size = 500 + (rand() % (10-0+1))+0;

    audioRecorder = new QAudioRecorder;

    QStringList inputs = audioRecorder->audioInputs();

    connect(audioRecorder, &QAudioRecorder::durationChanged, this,
            &Recorder::updateProgress);

    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/pcm");
    audioSettings.setQuality(QMultimedia::HighQuality);
    audioRecorder->setAudioSettings(audioSettings);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() | Qt::Tool);
    thread_recorder = new QTimer(this);
    thread_recorder->setInterval (1000) ;
    connect(thread_recorder,SIGNAL(timeout()),this,SLOT(showThread_recorder()));
    thread_recorder->start();

}

Recorder::~Recorder(){
    allocate_memory[12].memory_size = 0;
    audioRecorder->stop();
    delete ui;
    thread_recorder->stop();
    flags[12]=0;
    for(int i = 0;i<int(process.size());i++){
        if(process[i]==12){
            process.erase(process.begin()+i);
            break;
        }
    }
    QString times = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    sendData2("Recorder closed.\t"+times);
}


/*
 * Function: on_choose_clicked
 * Usage: on_choose_clicked()
 * ------------------------------------
 * Click the choose button. This implementation can allow users to
 * choose the path that the sound would be saved into.
 */
void Recorder::on_choose_clicked()
{
    QString fileName = QFileDialog::getSaveFileName();
    ui->Address->setText(fileName);
}



/*
 * Function: on_record_start_clicked
 * Usage: on_record_start_clicked()
 * ------------------------------------
 * Click the start button. Then the recorder begins to record
 * sounds until the stop button is clicked.
 */
void Recorder::on_record_start_clicked()
{
    allocate_memory[12].memory_size = 500 + (rand() % (10-0+1))+0;
    if(ui->Address->text() == "") {
        QMessageBox::warning(this, tr("Warning"),tr("Please enter the path first!"), QMessageBox::Yes);
        return;
    }
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(ui->Address->text()));
    audioRecorder->record();
}



/*
 * Function: on_record_stop_clicked
 * Usage: on_record_stop_clicked();
 * ------------------------------------
 * Click the stop button. Then the recorder that is recording sounds
 * would stop recording and the sound file would be saved into the address chosen by the user.
 */
void Recorder::on_record_stop_clicked()
{
    allocate_memory[12].memory_size = 400 + (rand() % (10-0+1))+0;
    audioRecorder->stop();
}


/*
 * Function: updatePosition_video
 * Usage: updatePosition_video(qint64 duration)
 * ------------------------------------
 * Record the duration for the sound file. The recorder time is on the title of the
 * windows and increased with time.
 */
void Recorder::updateProgress(qint64 duration)
{
    if (audioRecorder->error() != QMediaRecorder::NoError || duration < 1000)
        return;
    setWindowTitle(tr("Recorded %1 sec").arg(duration / 1000));
}


/*
 * Function: showThread_recorder
 * Usage: showThread_recorder();
 * ------------------------------------
 *
 *
 */
void Recorder::showThread_recorder()
{
    QDateTime time = QDateTime::currentDateTime();
    QString t = time.toString("yyyy-MM-dd hh:mm:ss");
    emit sendData("Recorder is running:" + t);
}
