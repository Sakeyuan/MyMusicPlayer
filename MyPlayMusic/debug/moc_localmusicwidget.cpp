/****************************************************************************
** Meta object code from reading C++ file 'localmusicwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../localmusicwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localmusicwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalMusicWidget_t {
    QByteArrayData data[10];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalMusicWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalMusicWidget_t qt_meta_stringdata_LocalMusicWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "LocalMusicWidget"
QT_MOC_LITERAL(1, 17, 15), // "durationChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 8), // "duration"
QT_MOC_LITERAL(4, 43, 15), // "positionChanged"
QT_MOC_LITERAL(5, 59, 8), // "position"
QT_MOC_LITERAL(6, 68, 22), // "on_addMusicBtn_clicked"
QT_MOC_LITERAL(7, 91, 37), // "on_localMusicListWidget_doubl..."
QT_MOC_LITERAL(8, 129, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 141, 5) // "index"

    },
    "LocalMusicWidget\0durationChanged\0\0"
    "duration\0positionChanged\0position\0"
    "on_addMusicBtn_clicked\0"
    "on_localMusicListWidget_doubleClicked\0"
    "QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalMusicWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x08 /* Private */,
       7,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void LocalMusicWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LocalMusicWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->on_addMusicBtn_clicked(); break;
        case 3: _t->on_localMusicListWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LocalMusicWidget::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LocalMusicWidget::durationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LocalMusicWidget::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LocalMusicWidget::positionChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LocalMusicWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_LocalMusicWidget.data,
    qt_meta_data_LocalMusicWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LocalMusicWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalMusicWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalMusicWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LocalMusicWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LocalMusicWidget::durationChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LocalMusicWidget::positionChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
