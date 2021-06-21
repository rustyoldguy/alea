/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../alea/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[23];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 12), // "loadSRCDatei"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "Setkodiermodus"
QT_MOC_LITERAL(4, 36, 7), // "getrand"
QT_MOC_LITERAL(5, 44, 3), // "min"
QT_MOC_LITERAL(6, 48, 3), // "max"
QT_MOC_LITERAL(7, 52, 13), // "GenRandomByts"
QT_MOC_LITERAL(8, 66, 11), // "PrepareFile"
QT_MOC_LITERAL(9, 78, 13), // "SaveOrgDatlen"
QT_MOC_LITERAL(10, 92, 9), // "srcdatlen"
QT_MOC_LITERAL(11, 102, 9), // "fputDWORD"
QT_MOC_LITERAL(12, 112, 6), // "letter"
QT_MOC_LITERAL(13, 119, 14), // "std::ofstream*"
QT_MOC_LITERAL(14, 134, 5), // "datei"
QT_MOC_LITERAL(15, 140, 17), // "SetDifBytesInFile"
QT_MOC_LITERAL(16, 158, 7), // "NewsBox"
QT_MOC_LITERAL(17, 166, 8), // "Newstext"
QT_MOC_LITERAL(18, 175, 5), // "Koden"
QT_MOC_LITERAL(19, 181, 12), // "srcgetdatlen"
QT_MOC_LITERAL(20, 194, 16), // "initglobvariable"
QT_MOC_LITERAL(21, 211, 8), // "QWidget*"
QT_MOC_LITERAL(22, 220, 6) // "parent"

    },
    "Dialog\0loadSRCDatei\0\0Setkodiermodus\0"
    "getrand\0min\0max\0GenRandomByts\0PrepareFile\0"
    "SaveOrgDatlen\0srcdatlen\0fputDWORD\0"
    "letter\0std::ofstream*\0datei\0"
    "SetDifBytesInFile\0NewsBox\0Newstext\0"
    "Koden\0srcgetdatlen\0initglobvariable\0"
    "QWidget*\0parent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    2,   76,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    1,   83,    2, 0x08 /* Private */,
      11,    2,   86,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    1,   92,    2, 0x08 /* Private */,
      18,    0,   95,    2, 0x08 /* Private */,
      19,    0,   96,    2, 0x08 /* Private */,
      20,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int, QMetaType::ULong,   10,
    QMetaType::Int, QMetaType::UInt, 0x80000000 | 13,   12,   14,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Long,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->loadSRCDatei();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->Setkodiermodus(); break;
        case 2: { int _r = _t->getrand((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->GenRandomByts();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->PrepareFile(); break;
        case 5: { int _r = _t->SaveOrgDatlen((*reinterpret_cast< ulong(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->fputDWORD((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< std::ofstream*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->SetDifBytesInFile();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->NewsBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->Koden(); break;
        case 10: { long _r = _t->srcgetdatlen();
            if (_a[0]) *reinterpret_cast< long*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->initglobvariable((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.data,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
