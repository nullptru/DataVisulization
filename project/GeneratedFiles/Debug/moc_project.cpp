/****************************************************************************
** Meta object code from reading C++ file 'project.h'
**
** Created: Sun Dec 21 20:08:17 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../project.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'project.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Project[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      26,    8,    8,    8, 0x0a,
      38,    8,    8,    8, 0x0a,
      52,    8,    8,    8, 0x0a,
      59,    8,    8,    8, 0x0a,
      77,    8,    8,    8, 0x0a,
      93,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Project[] = {
    "Project\0\0ExponentialSmo()\0SeasonExp()\0"
    "BpNeuralNet()\0Open()\0changeExpertExp()\0"
    "changeFactors()\0changeMental()\0"
};

const QMetaObject Project::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Project,
      qt_meta_data_Project, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Project::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Project::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Project::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Project))
        return static_cast<void*>(const_cast< Project*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Project::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ExponentialSmo(); break;
        case 1: SeasonExp(); break;
        case 2: BpNeuralNet(); break;
        case 3: Open(); break;
        case 4: changeExpertExp(); break;
        case 5: changeFactors(); break;
        case 6: changeMental(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
