/****************************************************************************
** Meta object code from reading C++ file 'vjassdocdialog.h'
**
** Created: Sat Apr 4 13:52:54 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/vjassdocdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vjassdocdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__VjassdocDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x08,
      38,   25,   25,   25, 0x08,
      53,   25,   25,   25, 0x08,
      72,   25,   25,   25, 0x08,
      89,   25,   25,   25, 0x08,
      95,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__VjassdocDialog[] = {
    "vjasside::VjassdocDialog\0\0chooseDir()\0"
    "addImportDir()\0removeImportDirs()\0"
    "selectVjassdoc()\0run()\0restoreDefaults()\0"
};

const QMetaObject vjasside::VjassdocDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__VjassdocDialog,
      qt_meta_data_vjasside__VjassdocDialog, 0 }
};

const QMetaObject *vjasside::VjassdocDialog::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::VjassdocDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__VjassdocDialog))
        return static_cast<void*>(const_cast< VjassdocDialog*>(this));
    if (!strcmp(_clname, "Ui::VjassdocDialog"))
        return static_cast< Ui::VjassdocDialog*>(const_cast< VjassdocDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::VjassdocDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: chooseDir(); break;
        case 1: addImportDir(); break;
        case 2: removeImportDirs(); break;
        case 3: selectVjassdoc(); break;
        case 4: run(); break;
        case 5: restoreDefaults(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
