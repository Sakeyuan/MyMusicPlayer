/****************************************************************************
** Meta object code from reading C++ file 'qcarousel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qcarousel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcarousel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCarousel_t {
    QByteArrayData data[13];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCarousel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCarousel_t qt_meta_stringdata_QCarousel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QCarousel"
QT_MOC_LITERAL(1, 10, 18), // "signalImageClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "index"
QT_MOC_LITERAL(4, 36, 19), // "signalTextActivated"
QT_MOC_LITERAL(5, 56, 4), // "text"
QT_MOC_LITERAL(6, 61, 8), // "addImage"
QT_MOC_LITERAL(7, 70, 6), // "pixmap"
QT_MOC_LITERAL(8, 77, 11), // "insertImage"
QT_MOC_LITERAL(9, 89, 11), // "removeImage"
QT_MOC_LITERAL(10, 101, 15), // "setCurrentIndex"
QT_MOC_LITERAL(11, 117, 11), // "slideToLeft"
QT_MOC_LITERAL(12, 129, 12) // "slideToRight"

    },
    "QCarousel\0signalImageClicked\0\0index\0"
    "signalTextActivated\0text\0addImage\0"
    "pixmap\0insertImage\0removeImage\0"
    "setCurrentIndex\0slideToLeft\0slideToRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCarousel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   70,    2, 0x0a /* Public */,
       6,    1,   75,    2, 0x2a /* Public | MethodCloned */,
       8,    3,   78,    2, 0x0a /* Public */,
       8,    2,   85,    2, 0x2a /* Public | MethodCloned */,
       9,    1,   90,    2, 0x0a /* Public */,
      10,    1,   93,    2, 0x0a /* Public */,
      11,    0,   96,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap, QMetaType::QString,    7,    5,
    QMetaType::Void, QMetaType::QPixmap,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap, QMetaType::QString,    3,    7,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QPixmap,    3,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QCarousel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QCarousel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalImageClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalTextActivated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addImage((*reinterpret_cast< const QPixmap(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->addImage((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 4: _t->insertImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->insertImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPixmap(*)>(_a[2]))); break;
        case 6: _t->removeImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slideToLeft(); break;
        case 9: _t->slideToRight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QCarousel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCarousel::signalImageClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QCarousel::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCarousel::signalTextActivated)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QCarousel::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QCarousel.data,
    qt_meta_data_QCarousel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QCarousel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCarousel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCarousel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QCarousel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QCarousel::signalImageClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QCarousel::signalTextActivated(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
