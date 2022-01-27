/****************************************************************************
** Meta object code from reading C++ file 'pjassdialog.h'
**
** Created: Sat Apr 4 13:52:56 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/pjassdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pjassdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__PjassDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      37,   22,   22,   22, 0x0a,
      43,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__PjassDialog[] = {
    "vjasside::PjassDialog\0\0selectPjass()\0"
    "run()\0restoreDefaults()\0"
};

const QMetaObject vjasside::PjassDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__PjassDialog,
      qt_meta_data_vjasside__PjassDialog, 0 }
};

const QMetaObject *vjasside::PjassDialog::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::PjassDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__PjassDialog))
        return static_cast<void*>(const_cast< PjassDialog*>(this));
    if (!strcmp(_clname, "Ui::PjassDialog"))
        return static_cast< Ui::PjassDialog*>(const_cast< PjassDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::PjassDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: selectPjass(); break;
        case 1: run(); break;
        case 2: restoreDefaults(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
