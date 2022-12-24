QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT       +=  multimedia
QT += multimediawidgets
QT += core gui multimedia multimediawidgets

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyPushButton.cpp \
    browser.cpp \
    calculator.cpp \
    calendar.cpp \
    camera.cpp \
    createaccount.cpp \
    filesys.cpp \
    gluttonous_snake.cpp \
    h_gv.cpp \
    logindlg.cpp \
    main.cpp \
    mainwindow.cpp \
    memoset.cpp \
    monitor.cpp \
    opening.cpp \
    painter.cpp \
    photo.cpp \
    recorder.cpp \
    texteditor.cpp \
    videoplayer.cpp

HEADERS += \
    MyPushButton.h \
    browser.h \
    calculator.h \
    calendar.h \
    camera.h \
    createaccount.h \
    filesys.h \
    gluttonous_snake.h \
    h_gv.h \
    logindlg.h \
    mainwindow.h \
    memoset.h \
    monitor.h \
    opening.h \
    painter.h \
    photo.h \
    recorder.h \
    texteditor.h \
    videoplayer.h

FORMS += \
    browser.ui \
    calculator.ui \
    calendar.ui \
    camera.ui \
    createaccount.ui \
    deleteaccount.ui \
    #filesys.ui \
    filesys.ui \
    logindlg.ui \
    mainwindow.ui \
    memoset.ui \
    monitor.ui \
    opening.ui \
    painter.ui \
    photo.ui \
    recorder.ui \
    savewarn.ui \
    texteditor.ui \
    videoplayer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    account/account.qrc \
    images/images.qrc \
    music/music.qrc \
    text/text.qrc

DISTFILES += \
    account/password.txt \
    account/username.txt

exists($$PWD/res/*) {
    OTHER_FILES *= $$files($$PWD/res/*)
}
exists($$PWD/*.txt) {
    OTHER_FILES *= $$files($$PWD/*.txt)
}
exists($$PWD/input/*) {
    OTHER_FILES *= $$files($$PWD/input/*)
}
exists($$PWD/output/*) {
    OTHER_FILES *= $$files($$PWD/output/*)
}
