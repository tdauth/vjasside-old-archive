/****************************************************************************
** Meta object code from reading C++ file 'expressiondialog.h'
**
** Created: Fri Jan 30 22:42:40 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/expressiondialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'expressiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_vjasside__ExpressionDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__ExpressionDialog[] = {
    "vjasside::ExpressionDialog\0\0refresh()\0"
};

const QMetaObject vjasside::ExpressionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__ExpressionDialog,
      qt_meta_data_vjasside__ExpressionDialog, 0 }
};

const QMetaObject *vjasside::ExpressionDialog::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::ExpressionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__ExpressionDialog))
	return static_cast<void*>(const_cast< ExpressionDialog*>(this));
    if (!strcmp(_clname, "Ui::ExpressionDialog"))
	return static_cast< Ui::ExpressionDialog*>(const_cast< ExpressionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::ExpressionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: refresh(); break;
        }
        _id -= 1;
    }
    return _id;
}
