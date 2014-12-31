/****************************************************************************
** Meta object code from reading C++ file 'project.h'
**
** Created: Wed Dec 31 14:16:46 2014
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
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      26,    8,    8,    8, 0x0a,
      43,    8,    8,    8, 0x0a,
      55,    8,    8,    8, 0x0a,
      69,    8,    8,    8, 0x0a,
      76,    8,    8,    8, 0x0a,
      86,    8,    8,    8, 0x0a,
      99,    8,    8,    8, 0x0a,
     119,  115,    8,    8, 0x0a,
     146,    8,    8,    8, 0x0a,
     160,    8,    8,    8, 0x0a,
     175,    8,    8,    8, 0x0a,
     187,  115,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Project[] = {
    "Project\0\0chooseFunction()\0ExponentialSmo()\0"
    "SeasonExp()\0BpNeuralNet()\0Open()\0"
    "addItem()\0openChoice()\0changeFactors()\0"
    "txt\0changeFactorsType(QString)\0"
    "futureTrend()\0addTableItem()\0cboSelect()\0"
    "cboSel(QString)\0"
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
        case 0: chooseFunction(); break;
        case 1: ExponentialSmo(); break;
        case 2: SeasonExp(); break;
        case 3: BpNeuralNet(); break;
        case 4: Open(); break;
        case 5: addItem(); break;
        case 6: openChoice(); break;
        case 7: changeFactors(); break;
        case 8: changeFactorsType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: futureTrend(); break;
        case 10: addTableItem(); break;
        case 11: cboSelect(); break;
        case 12: cboSel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
