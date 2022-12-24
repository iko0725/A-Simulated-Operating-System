/****************************************************************************
** Meta object code from reading C++ file 'videoplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CSC3002project/videoplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoPlayer_t {
    QByteArrayData data[26];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoPlayer_t qt_meta_stringdata_VideoPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VideoPlayer"
QT_MOC_LITERAL(1, 12, 8), // "sendData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "sendData2"
QT_MOC_LITERAL(4, 32, 15), // "on_play_clicked"
QT_MOC_LITERAL(5, 48, 19), // "on_stopplay_clicked"
QT_MOC_LITERAL(6, 68, 16), // "on_pause_clicked"
QT_MOC_LITERAL(7, 85, 19), // "on_previous_clicked"
QT_MOC_LITERAL(8, 105, 15), // "on_next_clicked"
QT_MOC_LITERAL(9, 121, 17), // "on_addnew_clicked"
QT_MOC_LITERAL(10, 139, 17), // "on_remove_clicked"
QT_MOC_LITERAL(11, 157, 26), // "on_videoslider_sliderMoved"
QT_MOC_LITERAL(12, 184, 8), // "position"
QT_MOC_LITERAL(13, 193, 14), // "updatePosition"
QT_MOC_LITERAL(14, 208, 12), // "stateChanged"
QT_MOC_LITERAL(15, 221, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(16, 241, 5), // "state"
QT_MOC_LITERAL(17, 247, 18), // "mediaStatusChanged"
QT_MOC_LITERAL(18, 266, 25), // "QMediaPlayer::MediaStatus"
QT_MOC_LITERAL(19, 292, 6), // "status"
QT_MOC_LITERAL(20, 299, 9), // "showError"
QT_MOC_LITERAL(21, 309, 19), // "QMediaPlayer::Error"
QT_MOC_LITERAL(22, 329, 5), // "error"
QT_MOC_LITERAL(23, 335, 24), // "metaDataAvailableChanged"
QT_MOC_LITERAL(24, 360, 9), // "available"
QT_MOC_LITERAL(25, 370, 22) // "showThread_videoplayer"

    },
    "VideoPlayer\0sendData\0\0sendData2\0"
    "on_play_clicked\0on_stopplay_clicked\0"
    "on_pause_clicked\0on_previous_clicked\0"
    "on_next_clicked\0on_addnew_clicked\0"
    "on_remove_clicked\0on_videoslider_sliderMoved\0"
    "position\0updatePosition\0stateChanged\0"
    "QMediaPlayer::State\0state\0mediaStatusChanged\0"
    "QMediaPlayer::MediaStatus\0status\0"
    "showError\0QMediaPlayer::Error\0error\0"
    "metaDataAvailableChanged\0available\0"
    "showThread_videoplayer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  100,    2, 0x08 /* Private */,
       5,    0,  101,    2, 0x08 /* Private */,
       6,    0,  102,    2, 0x08 /* Private */,
       7,    0,  103,    2, 0x08 /* Private */,
       8,    0,  104,    2, 0x08 /* Private */,
       9,    0,  105,    2, 0x08 /* Private */,
      10,    0,  106,    2, 0x08 /* Private */,
      11,    1,  107,    2, 0x08 /* Private */,
      13,    1,  110,    2, 0x08 /* Private */,
      14,    1,  113,    2, 0x08 /* Private */,
      17,    1,  116,    2, 0x08 /* Private */,
      20,    1,  119,    2, 0x08 /* Private */,
      23,    1,  122,    2, 0x08 /* Private */,
      25,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,

       0        // eod
};

void VideoPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendData2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_play_clicked(); break;
        case 3: _t->on_stopplay_clicked(); break;
        case 4: _t->on_pause_clicked(); break;
        case 5: _t->on_previous_clicked(); break;
        case 6: _t->on_next_clicked(); break;
        case 7: _t->on_addnew_clicked(); break;
        case 8: _t->on_remove_clicked(); break;
        case 9: _t->on_videoslider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updatePosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 11: _t->stateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 12: _t->mediaStatusChanged((*reinterpret_cast< QMediaPlayer::MediaStatus(*)>(_a[1]))); break;
        case 13: _t->showError((*reinterpret_cast< QMediaPlayer::Error(*)>(_a[1]))); break;
        case 14: _t->metaDataAvailableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->showThread_videoplayer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::MediaStatus >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::Error >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoPlayer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPlayer::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoPlayer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoPlayer::sendData2)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VideoPlayer::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_VideoPlayer.data,
    qt_meta_data_VideoPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoPlayer.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int VideoPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void VideoPlayer::sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoPlayer::sendData2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
