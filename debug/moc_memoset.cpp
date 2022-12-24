/****************************************************************************
** Meta object code from reading C++ file 'memoset.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CSC3002project/memoset.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'memoset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Memoset_t {
    QByteArrayData data[9];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Memoset_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Memoset_t qt_meta_stringdata_Memoset = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Memoset"
QT_MOC_LITERAL(1, 8, 8), // "sendData"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "sendData2"
QT_MOC_LITERAL(4, 28, 29), // "on_pushButton_memoset_clicked"
QT_MOC_LITERAL(5, 58, 29), // "on_pushButton_showall_clicked"
QT_MOC_LITERAL(6, 88, 28), // "on_pushButton_search_clicked"
QT_MOC_LITERAL(7, 117, 15), // "showThread_memo"
QT_MOC_LITERAL(8, 133, 28) // "on_pushButton_delete_clicked"

    },
    "Memoset\0sendData\0\0sendData2\0"
    "on_pushButton_memoset_clicked\0"
    "on_pushButton_showall_clicked\0"
    "on_pushButton_search_clicked\0"
    "showThread_memo\0on_pushButton_delete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Memoset[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   55,    2, 0x08 /* Private */,
       5,    0,   56,    2, 0x08 /* Private */,
       6,    0,   57,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Memoset::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Memoset *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendData2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_memoset_clicked(); break;
        case 3: _t->on_pushButton_showall_clicked(); break;
        case 4: _t->on_pushButton_search_clicked(); break;
        case 5: _t->showThread_memo(); break;
        case 6: _t->on_pushButton_delete_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Memoset::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Memoset::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Memoset::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Memoset::sendData2)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Memoset::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Memoset.data,
    qt_meta_data_Memoset,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Memoset::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Memoset::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Memoset.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Memoset::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Memoset::sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Memoset::sendData2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
