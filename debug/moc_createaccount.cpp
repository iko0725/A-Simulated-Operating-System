/****************************************************************************
** Meta object code from reading C++ file 'createaccount.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CSC3002project/createaccount.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createaccount.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreateAccount_t {
    QByteArrayData data[7];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateAccount_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateAccount_t qt_meta_stringdata_CreateAccount = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CreateAccount"
QT_MOC_LITERAL(1, 14, 8), // "sendData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "sendData2"
QT_MOC_LITERAL(4, 34, 17), // "on_create_clicked"
QT_MOC_LITERAL(5, 52, 24), // "on_delete_button_clicked"
QT_MOC_LITERAL(6, 77, 24) // "showThread_createaccount"

    },
    "CreateAccount\0sendData\0\0sendData2\0"
    "on_create_clicked\0on_delete_button_clicked\0"
    "showThread_createaccount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateAccount[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   45,    2, 0x08 /* Private */,
       5,    0,   46,    2, 0x08 /* Private */,
       6,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreateAccount *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendData2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_create_clicked(); break;
        case 3: _t->on_delete_button_clicked(); break;
        case 4: _t->showThread_createaccount(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CreateAccount::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateAccount::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CreateAccount::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateAccount::sendData2)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CreateAccount::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_CreateAccount.data,
    qt_meta_data_CreateAccount,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CreateAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreateAccount.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CreateAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CreateAccount::sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CreateAccount::sendData2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_DeleteAccount_t {
    QByteArrayData data[4];
    char stringdata0[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeleteAccount_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeleteAccount_t qt_meta_stringdata_DeleteAccount = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DeleteAccount"
QT_MOC_LITERAL(1, 14, 24), // "on_deleteconfirm_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 18) // "on_refresh_clicked"

    },
    "DeleteAccount\0on_deleteconfirm_clicked\0"
    "\0on_refresh_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeleteAccount[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeleteAccount::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeleteAccount *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_deleteconfirm_clicked(); break;
        case 1: _t->on_refresh_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DeleteAccount::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DeleteAccount.data,
    qt_meta_data_DeleteAccount,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeleteAccount::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeleteAccount::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeleteAccount.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DeleteAccount::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
