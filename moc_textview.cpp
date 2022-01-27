/****************************************************************************
** Meta object code from reading C++ file 'textview.h'
**
** Created: Thu Apr 9 22:11:48 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/textview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vjasside__TextView[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      26,   20,   19,   19, 0x05,
      62,   46,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     119,   86,   19,   19, 0x08,
     165,  155,   19,   19, 0x08,
     198,  193,   19,   19, 0x08,
     223,  217,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vjasside__TextView[] = {
    "vjasside::TextView\0\0index\0contentChanged(int)\0"
    "index,available\0undoAvailable(int,bool)\0"
    "position,charsRemoved,charsAdded\0"
    "textEditContentChanged(int,int,int)\0"
    "available\0textEditUndoAvailable(bool)\0"
    "font\0refreshFont(QFont)\0lines\0"
    "setLineNumbers(int)\0"
};

const QMetaObject vjasside::TextView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vjasside__TextView,
      qt_meta_data_vjasside__TextView, 0 }
};

const QMetaObject *vjasside::TextView::metaObject() const
{
    return &staticMetaObject;
}

void *vjasside::TextView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vjasside__TextView))
        return static_cast<void*>(const_cast< TextView*>(this));
    if (!strcmp(_clname, "Ui::TextView"))
        return static_cast< Ui::TextView*>(const_cast< TextView*>(this));
    return QWidget::qt_metacast(_clname);
}

int vjasside::TextView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: contentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: undoAvailable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: textEditContentChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: textEditUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: refreshFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 5: setLineNumbers((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void vjasside::TextView::contentChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vjasside::TextView::undoAvailable(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
