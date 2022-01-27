/****************************************************************************
** Meta object code from reading C++ file 'apidatabasedialog.h'
**
** Created: Sat Apr 4 13:52:35 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/apidatabasedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apidatabasedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__ApiDatabaseDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x08,
      56,   28,   28,   28, 0x08,
      71,   28,   28,   28, 0x08,
      89,   28,   28,   28, 0x08,
      96,   28,   28,   28, 0x08,
     105,   28,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__ApiDatabaseDialog[] = {
    "vjasside::ApiDatabaseDialog\0\0"
    "databaseSelectionChanged()\0addDatabases()\0"
    "removeDatabases()\0save()\0cancel()\0"
    "restoreDefaults()\0"
};

const QMetaObject vjasside::ApiDatabaseDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__ApiDatabaseDialog,
      qt_meta_data_vjasside__ApiDatabaseDialog, 0 }
};

const QMetaObject *vjasside::ApiDatabaseDialog::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::ApiDatabaseDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__ApiDatabaseDialog))
        return static_cast<void*>(const_cast< ApiDatabaseDialog*>(this));
    if (!strcmp(_clname, "Ui::ApiDatabaseDialog"))
        return static_cast< Ui::ApiDatabaseDialog*>(const_cast< ApiDatabaseDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::ApiDatabaseDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: databaseSelectionChanged(); break;
        case 1: addDatabases(); break;
        case 2: removeDatabases(); break;
        case 3: save(); break;
        case 4: cancel(); break;
        case 5: restoreDefaults(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
