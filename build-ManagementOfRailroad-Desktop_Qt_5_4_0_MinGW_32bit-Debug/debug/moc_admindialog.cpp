/****************************************************************************
** Meta object code from reading C++ file 'admindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ManagementOfRailroad/admindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdminDialog_t {
    QByteArrayData data[8];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminDialog_t qt_meta_stringdata_AdminDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AdminDialog"
QT_MOC_LITERAL(1, 12, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 5), // "index"
QT_MOC_LITERAL(4, 47, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(5, 68, 23), // "on_DeleteButton_clicked"
QT_MOC_LITERAL(6, 92, 21), // "on_EditButton_clicked"
QT_MOC_LITERAL(7, 114, 11) // "timerUpdate"

    },
    "AdminDialog\0on_tabWidget_currentChanged\0"
    "\0index\0on_addButton_clicked\0"
    "on_DeleteButton_clicked\0on_EditButton_clicked\0"
    "timerUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AdminDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminDialog *_t = static_cast<AdminDialog *>(_o);
        switch (_id) {
        case 0: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_addButton_clicked(); break;
        case 2: _t->on_DeleteButton_clicked(); break;
        case 3: _t->on_EditButton_clicked(); break;
        case 4: _t->timerUpdate(); break;
        default: ;
        }
    }
}

const QMetaObject AdminDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AdminDialog.data,
      qt_meta_data_AdminDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdminDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdminDialog.stringdata))
        return static_cast<void*>(const_cast< AdminDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AdminDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
