/****************************************************************************
** Meta object code from reading C++ file 'mpqeditor.h'
**
** Created: Sat Apr 4 13:52:46 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/mpqeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mpqeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__MpqEditor[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      40,   20,   20,   20, 0x08,
      54,   20,   20,   20, 0x08,
      76,   20,   20,   20, 0x08,
      87,   20,   20,   20, 0x08,
     110,   20,   20,   20, 0x08,
     130,   20,   20,   20, 0x08,
     152,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__MpqEditor[] = {
    "vjasside::MpqEditor\0\0createNewArchive()\0"
    "openArchive()\0closeCurrentArchive()\0"
    "addFiles()\0extractSelectedFiles()\0"
    "openSelectedFiles()\0deleteSelectedFiles()\0"
    "showSettingsDialog()\0"
};

const QMetaObject vjasside::MpqEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vjasside__MpqEditor,
      qt_meta_data_vjasside__MpqEditor, 0 }
};

const QMetaObject *vjasside::MpqEditor::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::MpqEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__MpqEditor))
        return static_cast<void*>(const_cast< MpqEditor*>(this));
    if (!strcmp(_clname, "Ui::MpqEditor"))
        return static_cast< Ui::MpqEditor*>(const_cast< MpqEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int vjasside::MpqEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 7: showSettingsDialog(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
