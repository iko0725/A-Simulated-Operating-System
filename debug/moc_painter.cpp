/****************************************************************************
** Meta object code from reading C++ file 'painter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CSC3002project/painter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'painter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Painter_t {
    QByteArrayData data[13];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Painter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Painter_t qt_meta_stringdata_Painter = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Painter"
QT_MOC_LITERAL(1, 8, 8), // "sendData"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "sendData2"
QT_MOC_LITERAL(4, 28, 6), // "zoomIn"
QT_MOC_LITERAL(5, 35, 7), // "zoomOut"
QT_MOC_LITERAL(6, 43, 34), // "on_pushButton_save_painter_cl..."
QT_MOC_LITERAL(7, 78, 29), // "on_spinBox_width_valueChanged"
QT_MOC_LITERAL(8, 108, 4), // "arg1"
QT_MOC_LITERAL(9, 113, 27), // "on_pushButton_color_clicked"
QT_MOC_LITERAL(10, 141, 18), // "showThread_painter"
QT_MOC_LITERAL(11, 160, 28), // "on_pushButton_zoomin_clicked"
QT_MOC_LITERAL(12, 189, 29) // "on_pushButton_zoomout_clicked"

    },
    "Painter\0sendData\0\0sendData2\0zoomIn\0"
    "zoomOut\0on_pushButton_save_painter_clicked\0"
    "on_spinBox_width_valueChanged\0arg1\0"
    "on_pushButton_color_clicked\0"
    "showThread_painter\0on_pushButton_zoomin_clicked\0"
    "on_pushButton_zoomout_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Painter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   70,    2, 0x08 /* Private */,
       5,    0,   71,    2, 0x08 /* Private */,
       6,    0,   72,    2, 0x08 /* Private */,
       7,    1,   73,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Painter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Painter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendData2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->zoomIn(); break;
        case 3: _t->zoomOut(); break;
        case 4: _t->on_pushButton_save_painter_clicked(); break;
        case 5: _t->on_spinBox_width_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_color_clicked(); break;
        case 7: _t->showThread_painter(); break;
        case 8: _t->on_pushButton_zoomin_clicked(); break;
        case 9: _t->on_pushButton_zoomout_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Painter::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Painter::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Painter::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Painter::sendData2)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Painter::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Painter.data,
    qt_meta_data_Painter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Painter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Painter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Painter.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Painter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Painter::sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Painter::sendData2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
