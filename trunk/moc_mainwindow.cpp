/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Apr 24 17:42:51 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   12,   11,   11, 0x0a,
      36,   11,   11,   11, 0x08,
      57,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     136,  128,   11,   11, 0x08,
     162,  128,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     219,  213,   11,   11, 0x08,
     249,  213,   11,   11, 0x08,
     282,  278,   11,   11, 0x08,
     309,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0message\0update(QString)\0"
    "on_nextBTN_clicked()\0on_prevBTN_clicked()\0"
    "on_saveLayoutBTN_clicked()\0"
    "on_reprocBTN_clicked()\0checked\0"
    "on_whiteBTN_clicked(bool)\0"
    "on_blackBTN_clicked(bool)\0"
    "on_openfileBTN_clicked()\0event\0"
    "mousePressEvent(QMouseEvent*)\0"
    "mouseMoveEvent(QMouseEvent*)\0pos\0"
    "valueChangeRequest(QPoint)\0showHelp()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: update((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_nextBTN_clicked(); break;
        case 2: on_prevBTN_clicked(); break;
        case 3: on_saveLayoutBTN_clicked(); break;
        case 4: on_reprocBTN_clicked(); break;
        case 5: on_whiteBTN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: on_blackBTN_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: on_openfileBTN_clicked(); break;
        case 8: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: valueChangeRequest((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 11: showHelp(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE