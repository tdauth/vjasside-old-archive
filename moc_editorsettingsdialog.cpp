/****************************************************************************
** Meta object code from reading C++ file 'editorsettingsdialog.h'
**
** Created: Sat Apr 4 13:52:38 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/editorsettingsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editorsettingsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__EditorSettingsDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      32,   31,   31,   31, 0x08,
      45,   31,   31,   31, 0x08,
      57,   31,   31,   31, 0x08,
      72,   31,   31,   31, 0x08,
      87,   31,   31,   31, 0x08,
     103,   31,   31,   31, 0x08,
     124,  118,   31,   31, 0x08,
     149,   31,   31,   31, 0x08,
     164,   31,   31,   31, 0x08,
     178,   31,   31,   31, 0x08,
     193,   31,   31,   31, 0x08,
     211,   31,   31,   31, 0x08,
     221,   31,   31,   31, 0x08,
     235,   31,   31,   31, 0x08,
     242,   31,   31,   31, 0x08,
     251,   31,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__EditorSettingsDialog[] = {
    "vjasside::EditorSettingsDialog\0\0"
    "selectFont()\0newSchema()\0deleteSchema()\0"
    "renameSchema()\0importSchemas()\0"
    "exportSchema()\0index\0changeCurrentSchema(int)\0"
    "selectFormat()\0addTemplate()\0"
    "editTemplate()\0removeTemplates()\0"
    "addList()\0removeLists()\0save()\0cancel()\0"
    "restoreDefaults()\0"
};

const QMetaObject vjasside::EditorSettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__EditorSettingsDialog,
      qt_meta_data_vjasside__EditorSettingsDialog, 0 }
};

const QMetaObject *vjasside::EditorSettingsDialog::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::EditorSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__EditorSettingsDialog))
        return static_cast<void*>(const_cast< EditorSettingsDialog*>(this));
    if (!strcmp(_clname, "Ui::EditorSettingsDialog"))
        return static_cast< Ui::EditorSettingsDialog*>(const_cast< EditorSettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::EditorSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: selectFont(); break;
        case 1: newSchema(); break;
        case 2: deleteSchema(); break;
        case 3: renameSchema(); break;
        case 4: importSchemas(); break;
        case 5: exportSchema(); break;
        case 6: changeCurrentSchema((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 7: selectFormat(); break;
        case 8: addTemplate(); break;
        case 9: editTemplate(); break;
        case 10: removeTemplates(); break;
        case 11: addList(); break;
        case 12: removeLists(); break;
        case 13: save(); break;
        case 14: cancel(); break;
        case 15: restoreDefaults(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
