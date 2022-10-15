#ifndef ROOMLOCK_H
#define ROOMLOCK_H
#include "Key.h"

class RoomLock
{
private:
    bool isRoomLocked = false;
public://Room Lock
    RoomLock();
    ~RoomLock();
    Key *keyNeeded;
    void lockRoom(Key *key);
    bool isLocked();
};

#endif // ROOMLOCK_H
