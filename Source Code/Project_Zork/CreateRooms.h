#ifndef CREATEROOMS_H
#define CREATEROOMS_H
#include <Room.h>
#include <QDebug>
class CreateRooms
{
protected:
    Room *SectionA,*A1,*A2,*A3,*A4,*A5,*A6,*A7,*A8,*A9,*A10,*A11,
    *A12,*A13,*A14,*A15,*A16,*A17,*Asilver,*Agold,
    *SectionB,*B1,*B2,*B3,*B4,*B5,*B6,
    *SectionC, *C1,*C2,*C3,*C4,*C5,*C6,
    *SectionD, *D1,*D2,*D3,*D4,*D5,*D6,
    *Final,*Boss,*FinalBoss;
    Room *currentRoom;
    Room *nextRoom;
public:
    CreateRooms();
    ~CreateRooms();
};

#endif // CREATEROOMS_H
