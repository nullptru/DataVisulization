/****************************************************************************
** Meta object code from reading C++ file 'area2.h'
**
<<<<<<< Updated upstream
** Created: Thu Dec 11 20:59:04 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
=======
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
>>>>>>> Stashed changes
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../area2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'area2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Area2[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Area2[] = {
    "Area2\0"
};

void Area2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Area2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Area2::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Area2,
      qt_meta_data_Area2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Area2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Area2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Area2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Area2))
        return static_cast<void*>(const_cast< Area2*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Area2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
