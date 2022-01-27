/****************************************************************************
** Meta object code from reading C++ file 'textedit.h'
**
** Created: Sat Apr 4 13:52:49 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/textedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__TextEdit[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      36,   19,   19,   19, 0x08,
      55,   19,   19,   19, 0x08,
      76,   19,   19,   19, 0x08,
      91,   19,   19,   19, 0x08,
     104,   19,   19,   19, 0x08,
     121,   19,   19,   19, 0x08,
     145,   19,   19,   19, 0x08,
     171,  161,   19,   19, 0x08,
     194,  161,   19,   19, 0x08,
     217,  161,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__TextEdit[] = {
    "vjasside::TextEdit\0\0commentFormat()\0"
    "docCommentFormat()\0preprocessorFormat()\0"
    "stringFormat()\0charFormat()\0"
    "bracketsFormat()\0squaredBracketsFormat()\0"
    "nothingFormat()\0available\0"
    "setUndoAvailable(bool)\0setRedoAvailable(bool)\0"
    "setCopyAvailable(bool)\0"
};

const QMetaObject vjasside::TextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_vjasside__TextEdit,
      qt_meta_data_vjasside__TextEdit, 0 }
};

const QMetaObject *vjasside::TextEdit::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__TextEdit))
        return static_cast<void*>(const_cast< TextEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int vjasside::TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: commentFormat(); break;
        case 1: docCommentFormat(); break;
        case 2: preprocessorFormat(); break;
        case 3: stringFormat(); break;
        case 4: charFormat(); break;
        case 5: bracketsFormat(); break;
        case 6: squaredBracketsFormat(); break;
        case 7: nothingFormat(); break;
        case 8: setUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: setRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: setCopyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
