QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Balance.cpp \
    Controller.cpp \
    CreateEntities.cpp \
    CreateRooms.cpp \
    Enemy.cpp \
    Entity.cpp \
    EntityInRoom.cpp \
    Exceptionhandler.cpp \
    Inventory.cpp \
    Item.cpp \
    Key.cpp \
    Room.cpp \
    RoomLock.cpp \
    Shop.cpp \
    Storage.cpp \
    Weapon.cpp \
    main.cpp \
    zork.cpp

HEADERS += \
    Balance.h \
    Controller.h \
    CreateEntities.h \
    CreateRooms.h \
    Enemy.h \
    Entity.h \
    EntityInRoom.h \
    ExceptionHandler.h \
    Inventory.h \
    Item.h \
    Key.h \
    Room.h \
    RoomLock.h \
    Shop.h \
    Storage.h \
    Weapon.h \
    zork.h

FORMS += \
    zork.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
