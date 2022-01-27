/****************************************************************************
** Meta object code from reading C++ file 'mpqdialog.h'
**
** Created: Thu Jan 1 21:05:22 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/mpqdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mpqdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_vjasside__MpqDialog[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      40,   20,   20,   20, 0x08,
      54,   20,   20,   20, 0x08,
      76,   20,   20,   20, 0x08,
      87,   20,   20,   20, 0x08,
     110,   20,   20,   20, 0x08,
     130,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__MpqDialog[] = {
    "vjasside::MpqDialog\0\0createNewArchive()\0"
    "openArchive()\0closeCurrentArchive()\0"
    "addFiles()\0extractSelectedFiles()\0"
    "openSelectedFiles()\0deleteSelectedFiles()\0"
};

const QMetaObject vjasside::MpqDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__MpqDialog,
      qt_meta_data_vjasside__MpqDialog, 0 }
};

const QMetaObject *vjasside::MpqDialog::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::MpqDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__MpqDialog))
	return static_cast<void*>(const_cast< MpqDialog*>(this));
    if (!strcmp(_clname, "Ui::MpqDialog"))
	return static_cast< Ui::MpqDialog*>(const_cast< MpqDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::MpqDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: createNewArchive(); break;
        case 1: openArchive(); break;
        case 2: closeCurrentArchive(); break;
        case 3: addFiles(); break;
        case 4: extractSelectedFiles(); break;
        case 5: openSelectedFiles(); break;
        case 6: deleteSelectedFiles(); break;
        }
        _id -= 7;
    }
    return _id;
}
