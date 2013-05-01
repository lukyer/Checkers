/****************************************************************************
** Meta object code from reading C++ file 'guiboard.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Checkers/guiboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guiboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GUIBoard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x0a,
      42,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GUIBoard[] = {
    "GUIBoard\0\0,\0figureMove(Position,Position)\0"
    "redraw()\0"
};

void GUIBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GUIBoard *_t = static_cast<GUIBoard *>(_o);
        switch (_id) {
        case 0: _t->figureMove((*reinterpret_cast< Position(*)>(_a[1])),(*reinterpret_cast< Position(*)>(_a[2]))); break;
        case 1: _t->redraw(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GUIBoard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GUIBoard::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GUIBoard,
      qt_meta_data_GUIBoard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GUIBoard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GUIBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GUIBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GUIBoard))
        return static_cast<void*>(const_cast< GUIBoard*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GUIBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
