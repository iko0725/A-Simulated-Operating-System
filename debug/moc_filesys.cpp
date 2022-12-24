/****************************************************************************
** Meta object code from reading C++ file 'filesys.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CSC3002project/filesys.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesys.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileSys_t {
    QByteArrayData data[13];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileSys_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileSys_t qt_meta_stringdata_FileSys = {
    {
QT_MOC_LITERAL(0, 0, 7), // "FileSys"
QT_MOC_LITERAL(1, 8, 8), // "sendData"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "sendData2"
QT_MOC_LITERAL(4, 28, 28), // "on_pushButton_finder_clicked"
QT_MOC_LITERAL(5, 57, 37), // "on_tableWidget_file_cellDoubl..."
QT_MOC_LITERAL(6, 95, 3), // "row"
QT_MOC_LITERAL(7, 99, 6), // "column"
QT_MOC_LITERAL(8, 106, 9), // "renamebtn"
QT_MOC_LITERAL(9, 116, 6), // "rename"
QT_MOC_LITERAL(10, 123, 10), // "deletefile"
QT_MOC_LITERAL(11, 134, 19), // "showThread_filesysy"
QT_MOC_LITERAL(12, 154, 29) // "on_pushButton_refresh_clicked"

    },
    "FileSys\0sendData\0\0sendData2\0"
    "on_pushButton_finder_clicked\0"
    "on_tableWidget_file_cellDoubleClicked\0"
    "row\0column\0renamebtn\0rename\0deletefile\0"
    "showThread_filesysy\0on_pushButton_refresh_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileSys[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   65,    2, 0x08 /* Private */,
       5,    2,   66,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileSys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileSys *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendData2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_finder_clicked(); break;
        case 3: _t->on_tableWidget_file_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->renamebtn(); break;
        case 5: _t->rename(); break;
        case 6: _t->deletefile(); break;
        case 7: _t->showThread_filesysy(); break;
        case 8: _t->on_pushButton_refresh_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileSys::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSys::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileSys::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileSys::sendData2)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileSys::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_FileSys.data,
    qt_meta_data_FileSys,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileSys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileSys::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileSys.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FileSys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void FileSys::sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileSys::sendData2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
