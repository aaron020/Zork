#include "RoomLock.h"

RoomLock::RoomLock()
{
    keyNeeded = new Key;
}


RoomLock::~RoomLock(){
    delete keyNeeded;
}


void RoomLock::lockRoom(Key *key){
    keyNeeded = key;
    isRoomLocked = true;
}

bool RoomLock::isLocked(){
    return isRoomLocked;
}
