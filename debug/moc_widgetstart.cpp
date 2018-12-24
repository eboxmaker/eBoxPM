/****************************************************************************
** Meta object code from reading C++ file 'widgetstart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widgetstart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetstart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetStart_t {
    QByteArrayData data[11];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetStart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetStart_t qt_meta_stringdata_WidgetStart = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WidgetStart"
QT_MOC_LITERAL(1, 12, 32), // "on_WidgetStart_windowIconChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 4), // "icon"
QT_MOC_LITERAL(4, 51, 41), // "on_WidgetStart_customContextM..."
QT_MOC_LITERAL(5, 93, 3), // "pos"
QT_MOC_LITERAL(6, 97, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 121, 28), // "on_cbMCUname_editTextChanged"
QT_MOC_LITERAL(8, 150, 4), // "arg1"
QT_MOC_LITERAL(9, 155, 31), // "on_cbMcuName_currentTextChanged"
QT_MOC_LITERAL(10, 187, 24) // "on_btnMakeConfig_clicked"

    },
    "WidgetStart\0on_WidgetStart_windowIconChanged\0"
    "\0icon\0on_WidgetStart_customContextMenuRequested\0"
    "pos\0on_pushButton_2_clicked\0"
    "on_cbMCUname_editTextChanged\0arg1\0"
    "on_cbMcuName_currentTextChanged\0"
    "on_btnMakeConfig_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetStart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,
       9,    1,   54,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QIcon,    3,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void WidgetStart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetStart *_t = static_cast<WidgetStart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 4: _t->on_cbMcuName_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_btnMakeConfig_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject WidgetStart::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WidgetStart.data,
      qt_meta_data_WidgetStart,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WidgetStart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetStart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetStart.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetStart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
