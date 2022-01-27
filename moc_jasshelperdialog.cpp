/****************************************************************************
** Meta object code from reading C++ file 'jasshelperdialog.h'
**
** Created: Sat Apr 4 13:52:41 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/jasshelperdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jasshelperdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__JasshelperDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x08,
      59,   27,   27,   27, 0x08,
      77,   27,   27,   27, 0x08,
      99,   27,   27,   27, 0x08,
     130,   27,   27,   27, 0x08,
     148,   27,   27,   27, 0x08,
     170,   27,   27,   27, 0x08,
     193,   27,   27,   27, 0x08,
     210,   27,   27,   27, 0x08,
     233,   27,   27,   27, 0x08,
     257,   27,   27,   27, 0x08,
     276,   27,   27,   27, 0x08,
     295,   27,   27,   27, 0x08,
     316,   27,   27,   27, 0x08,
     334,   27,   27,   27, 0x08,
     340,   27,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__JasshelperDialog[] = {
    "vjasside::JasshelperDialog\0\0"
    "lookUpFolderSelectionChanged()\0"
    "addLookUpFolder()\0removeLookUpFolders()\0"
    "externalToolSelectionChanged()\0"
    "addExternalTool()\0removeExternalTools()\0"
    "setMapScriptFilePath()\0setMapFilePath()\0"
    "setInputFileFilePath()\0setOutputFileFilePath()\0"
    "selectJasshelper()\0selectConfigFile()\0"
    "selectJassCompiler()\0selectWewarlock()\0"
    "run()\0restoreDefaults()\0"
};

const QMetaObject vjasside::JasshelperDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__JasshelperDialog,
      qt_meta_data_vjasside__JasshelperDialog, 0 }
};

const QMetaObject *vjasside::JasshelperDialog::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::JasshelperDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__JasshelperDialog))
        return static_cast<void*>(const_cast< JasshelperDialog*>(this));
    if (!strcmp(_clname, "Ui::JasshelperDialog"))
        return static_cast< Ui::JasshelperDialog*>(const_cast< JasshelperDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::JasshelperDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: lookUpFolderSelectionChanged(); break;
        case 1: addLookUpFolder(); break;
        case 2: removeLookUpFolders(); break;
        case 3: externalToolSelectionChanged(); break;
        case 4: addExternalTool(); break;
        case 5: removeExternalTools(); break;
        case 6: setMapScriptFilePath(); break;
        case 7: setMapFilePath(); break;
        case 8: setInputFileFilePath(); break;
        case 9: setOutputFileFilePath(); break;
        case 10: selectJasshelper(); break;
        case 11: selectConfigFile(); break;
        case 12: selectJassCompiler(); break;
        case 13: selectWewarlock(); break;
        case 14: run(); break;
        case 15: restoreDefaults(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
