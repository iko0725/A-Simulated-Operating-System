/****************************************************************************
** Meta object code from reading C++ file 'texteditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CSC3002project/texteditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'texteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextEditor_t {
    QByteArrayData data[11];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextEditor_t qt_meta_stringdata_TextEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TextEditor"
QT_MOC_LITERAL(1, 11, 8), // "sendData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "sendData2"
QT_MOC_LITERAL(4, 31, 15), // "on_save_clicked"
QT_MOC_LITERAL(5, 47, 16), // "on_clear_clicked"
QT_MOC_LITERAL(6, 64, 15), // "on_undo_clicked"
QT_MOC_LITERAL(7, 80, 15), // "on_redo_clicked"
QT_MOC_LITERAL(8, 96, 19), // "on_findtext_clicked"
QT_MOC_LITERAL(9, 116, 13), // "updatecontent"
QT_MOC_LITERAL(10, 130, 21) // "showThread_texteditor"

    },
    "TextEditor\0sendData\0\0sendData2\0"
    "on_save_clicked\0on_clear_clicked\0"
    "on_undo_clicked\0on_redo_clicked\0"
    "on_findtext_clicked\0updatecontent\0"
    "showThread_texteditor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEditor[] = {

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
       5,    0,   66,    2, 0x08 /* Private */,
       6,    0,   67,    2, 0x08 /* Private */,
       7,    0,   68,    2, 0x08 /* Private */,
       8,    0,   69,    2, 0x08 /* Private */,
       9,    0,   70,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,

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

       0        // eod
};

void TextEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendData2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_save_clicked(); break;
        case 3: _t->on_clear_clicked(); break;
        case 4: _t->on_undo_clicked(); break;
        case 5: _t->on_redo_clicked(); break;
        case 6: _t->on_findtext_clicked(); break;
        case 7: _t->updatecontent(); break;
        case 8: _t->showThread_texteditor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TextEditor::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextEditor::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TextEditor::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextEditor::sendData2)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TextEditor::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_TextEditor.data,
    qt_meta_data_TextEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TextEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextEditor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TextEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TextEditor::sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TextEditor::sendData2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_SaveWarn_t {
    QByteArrayData data[4];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SaveWarn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SaveWarn_t qt_meta_stringdata_SaveWarn = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SaveWarn"
QT_MOC_LITERAL(1, 9, 19), // "on_save_yes_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18) // "on_save_no_clicked"

    },
    "SaveWarn\0on_save_yes_clicked\0\0"
    "on_save_no_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SaveWarn[] = {

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

void SaveWarn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SaveWarn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_save_yes_clicked(); break;
        case 1: _t->on_save_no_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SaveWarn::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_SaveWarn.data,
    qt_meta_data_SaveWarn,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SaveWarn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SaveWarn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SaveWarn.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SaveWarn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
