/****************************************************************************
** Meta object code from reading C++ file 'phone.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../phone.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phone.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_phone[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      33,    6,    6,    6, 0x08,
      59,    6,    6,    6, 0x08,
      85,    6,    6,    6, 0x08,
     111,    6,    6,    6, 0x08,
     137,    6,    6,    6, 0x08,
     163,    6,    6,    6, 0x08,
     189,    6,    6,    6, 0x08,
     215,    6,    6,    6, 0x08,
     241,    6,    6,    6, 0x08,
     267,    6,    6,    6, 0x08,
     294,    6,    6,    6, 0x08,
     321,    6,    6,    6, 0x08,
     351,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_phone[] = {
    "phone\0\0on_toolButton_1_clicked()\0"
    "on_toolButton_2_clicked()\0"
    "on_toolButton_3_clicked()\0"
    "on_toolButton_4_clicked()\0"
    "on_toolButton_5_clicked()\0"
    "on_toolButton_6_clicked()\0"
    "on_toolButton_7_clicked()\0"
    "on_toolButton_8_clicked()\0"
    "on_toolButton_9_clicked()\0"
    "on_toolButton_0_clicked()\0"
    "on_toolButton_10_clicked()\0"
    "on_toolButton_12_clicked()\0"
    "on_toolButton_audio_clicked()\0"
    "on_toolButton_video_clicked()\0"
};

void phone::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        phone *_t = static_cast<phone *>(_o);
        switch (_id) {
        case 0: _t->on_toolButton_1_clicked(); break;
        case 1: _t->on_toolButton_2_clicked(); break;
        case 2: _t->on_toolButton_3_clicked(); break;
        case 3: _t->on_toolButton_4_clicked(); break;
        case 4: _t->on_toolButton_5_clicked(); break;
        case 5: _t->on_toolButton_6_clicked(); break;
        case 6: _t->on_toolButton_7_clicked(); break;
        case 7: _t->on_toolButton_8_clicked(); break;
        case 8: _t->on_toolButton_9_clicked(); break;
        case 9: _t->on_toolButton_0_clicked(); break;
        case 10: _t->on_toolButton_10_clicked(); break;
        case 11: _t->on_toolButton_12_clicked(); break;
        case 12: _t->on_toolButton_audio_clicked(); break;
        case 13: _t->on_toolButton_video_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData phone::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject phone::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_phone,
      qt_meta_data_phone, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &phone::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *phone::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *phone::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_phone))
        return static_cast<void*>(const_cast< phone*>(this));
    return QWidget::qt_metacast(_clname);
}

int phone::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
