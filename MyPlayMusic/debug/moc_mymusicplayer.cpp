/****************************************************************************
** Meta object code from reading C++ file 'mymusicplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mymusicplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymusicplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyMusicPlayer_t {
    QByteArrayData data[16];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyMusicPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyMusicPlayer_t qt_meta_stringdata_MyMusicPlayer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MyMusicPlayer"
QT_MOC_LITERAL(1, 14, 19), // "on_closeBtn_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "on_shrinkBtn_clicked"
QT_MOC_LITERAL(4, 56, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 78, 34), // "on_recommendListWidget_itemCl..."
QT_MOC_LITERAL(6, 113, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 130, 4), // "item"
QT_MOC_LITERAL(8, 135, 32), // "on_myMusicListWidget_itemClicked"
QT_MOC_LITERAL(9, 168, 36), // "on_createMusicListWidget_item..."
QT_MOC_LITERAL(10, 205, 31), // "on_playMusicListFormBtn_clicked"
QT_MOC_LITERAL(11, 237, 26), // "musicPlayerDurationChanged"
QT_MOC_LITERAL(12, 264, 8), // "duration"
QT_MOC_LITERAL(13, 273, 17), // "onPositionChanged"
QT_MOC_LITERAL(14, 291, 8), // "position"
QT_MOC_LITERAL(15, 300, 30) // "on_musicTimeSlider_sliderMoved"

    },
    "MyMusicPlayer\0on_closeBtn_clicked\0\0"
    "on_shrinkBtn_clicked\0on_pushButton_clicked\0"
    "on_recommendListWidget_itemClicked\0"
    "QListWidgetItem*\0item\0"
    "on_myMusicListWidget_itemClicked\0"
    "on_createMusicListWidget_itemClicked\0"
    "on_playMusicListFormBtn_clicked\0"
    "musicPlayerDurationChanged\0duration\0"
    "onPositionChanged\0position\0"
    "on_musicTimeSlider_sliderMoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMusicPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
       9,    1,   73,    2, 0x08 /* Private */,
      10,    0,   76,    2, 0x08 /* Private */,
      11,    1,   77,    2, 0x08 /* Private */,
      13,    1,   80,    2, 0x08 /* Private */,
      15,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void MyMusicPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyMusicPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_closeBtn_clicked(); break;
        case 1: _t->on_shrinkBtn_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_recommendListWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_myMusicListWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_createMusicListWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_playMusicListFormBtn_clicked(); break;
        case 7: _t->musicPlayerDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->onPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: _t->on_musicTimeSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyMusicPlayer::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MyMusicPlayer.data,
    qt_meta_data_MyMusicPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyMusicPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyMusicPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyMusicPlayer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyMusicPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
