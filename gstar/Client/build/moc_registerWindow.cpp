/****************************************************************************
** Meta object code from reading C++ file 'registerWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../registerWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_registerWindow_t {
    QByteArrayData data[13];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_registerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_registerWindow_t qt_meta_stringdata_registerWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "registerWindow"
QT_MOC_LITERAL(1, 15, 18), // "newdocker_finished"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 57, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 81, 25), // "newdocker_process_started"
QT_MOC_LITERAL(6, 107, 26), // "newdocker_process_finished"
QT_MOC_LITERAL(7, 134, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(8, 155, 26), // "stopdocker_process_started"
QT_MOC_LITERAL(9, 182, 27), // "stopdocker_process_finished"
QT_MOC_LITERAL(10, 210, 22), // "send_process_successed"
QT_MOC_LITERAL(11, 233, 7), // "command"
QT_MOC_LITERAL(12, 241, 20) // "command_finished_get"

    },
    "registerWindow\0newdocker_finished\0\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "newdocker_process_started\0"
    "newdocker_process_finished\0"
    "QProcess::ExitStatus\0stopdocker_process_started\0"
    "stopdocker_process_finished\0"
    "send_process_successed\0command\0"
    "command_finished_get"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_registerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    2,   63,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    2,   69,    2, 0x08 /* Private */,
      10,    1,   74,    2, 0x08 /* Private */,
      12,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    2,    2,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void registerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        registerWindow *_t = static_cast<registerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newdocker_finished(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->newdocker_process_started(); break;
        case 4: _t->newdocker_process_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 5: _t->stopdocker_process_started(); break;
        case 6: _t->stopdocker_process_finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 7: _t->send_process_successed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->command_finished_get((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (registerWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&registerWindow::newdocker_finished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject registerWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_registerWindow.data,
      qt_meta_data_registerWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *registerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *registerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_registerWindow.stringdata0))
        return static_cast<void*>(const_cast< registerWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int registerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void registerWindow::newdocker_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
