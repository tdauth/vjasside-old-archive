/****************************************************************************
** Meta object code from reading C++ file 'formatdialog.h'
**
** Created: Sat Apr 4 13:52:58 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/formatdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__FormatDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      29,   24,   23,   23, 0x0a,
      50,   43,   23,   23, 0x0a,
      76,   66,   23,   23, 0x0a,
     105,   95,   23,   23, 0x0a,
     124,   23,   23,   23, 0x08,
     148,   23,   23,   23, 0x08,
     177,  172,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__FormatDialog[] = {
    "vjasside::FormatDialog\0\0bold\0setBold(bool)\0"
    "italic\0setItalic(bool)\0underline\0"
    "setUnderline(bool)\0strikeOut\0"
    "setStrikeOut(bool)\0selectForegroundColor()\0"
    "selectBackgroundColor()\0font\0"
    "refreshFont(QFont)\0"
};

const QMetaObject vjasside::FormatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__FormatDialog,
      qt_meta_data_vjasside__FormatDialog, 0 }
};

const QMetaObject *vjasside::FormatDialog::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::FormatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__FormatDialog))
        return static_cast<void*>(const_cast< FormatDialog*>(this));
    if (!strcmp(_clname, "Ui::FormatDialog"))
        return static_cast< Ui::FormatDialog*>(const_cast< FormatDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::FormatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setBold((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: setItalic((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: setUnderline((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: setStrikeOut((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: selectForegroundColor(); break;
        case 5: selectBackgroundColor(); break;
        case 6: refreshFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
