#include "CreateRooms.h"

CreateRooms::CreateRooms()
{
    SectionA = new Room("Section A");
    A1 = new Room("A1");
    A2 = new Room("A2");
    A3 = new Room("A3");
    A4 = new Room("A4");
    A5 = new Room("A5");
    A6 = new Room("A6");
    A7 = new Room("A7");
    A8 = new Room("A8");
    A9 = new Room("A9");
    A10 = new Room("A10");
    A11 = new Room("A11");
    A12 = new Room("A12");
    A13 = new Room("A13");
    A14 = new Room("A14");
    A15 = new Room("A15");
    A16= new Room("A16");
    A17 = new Room("A17");
    Asilver = new Room("A Silver");
    Agold = new Room("A Gold");

    SectionB = new Room("Section B");
    B1 = new Room("B1");
    B2 = new Room("B2");
    B3 = new Room("B3");
    B4 = new Room("B4");
    B5 = new Room("B5");
    B6 = new Room("B6");

    SectionC = new Room("Section C");
    C1 = new Room("C1");
    C2 = new Room("C2");
    C3 = new Room("C3");
    C4 = new Room("C4");
    C5 = new Room("C5");
    C6 = new Room("C6");

    SectionD = new Room("Section D");
    D1 = new Room("D1");
    D2 = new Room("D2");
    D3 = new Room("D3");
    D4 = new Room("D4");
    D5 = new Room("D5");
    D6 = new Room("D6");

    Final = new Room("Final");
    Boss = new Room("Boss");
    FinalBoss = new Room("Final Boss");


    //Exits
    SectionA->setExits(SectionB,A10,A1,A9);
    A1->setExits(SectionA,A17,NULL,A2);
    A2->setExits(A9,A1,NULL,A3);
    A3->setExits(A8,A2,NULL,A4);
    A4->setExits(A7,A3,NULL,A5);
    A5->setExits(Asilver,A4,NULL,NULL);
    Asilver->setExits(A6,NULL,A5,NULL);
    A6->setExits(NULL,A7,Asilver,NULL);
    A7->setExits(NULL,A8,A4,A6);
    A8->setExits(NULL,A9,A3,A7);
    A9->setExits(NULL,SectionA,A2,A8);
    A10->setExits(NULL,A11,A17,SectionA);
    A11->setExits(NULL,A12,A16,A10);
    A12->setExits(NULL,A13,A15,A11);
    A13->setExits(NULL,NULL,Agold,A12);
    Agold->setExits(A13,NULL,A14,NULL);
    A14->setExits(Agold,NULL,NULL,A15);
    A15->setExits(A12,A14,NULL,A16);
    A16->setExits(A11,A15,NULL,A17);
    A17->setExits(A10,A16,NULL,A1);

    SectionB->setExits(SectionC,B4,SectionA,B1);
    B1->setExits(NULL,SectionB,NULL,B2);
    B2->setExits(NULL,B1,NULL,B3);
    B3->setExits(NULL,B2,NULL,NULL);
    B4->setExits(NULL,B5,NULL,SectionB);
    B5->setExits(NULL,B6,NULL,B4);
    B6->setExits(NULL,NULL,NULL,B5);

    SectionC->setExits(SectionD,C4,SectionB,C1);
    C1->setExits(NULL,SectionC,NULL,C2);
    C2->setExits(NULL,C1,NULL,C3);
    C3->setExits(NULL,C2,NULL,NULL);
    C4->setExits(NULL,C5,NULL,SectionC);
    C5->setExits(NULL,C6,NULL,C4);
    C6->setExits(NULL,NULL,NULL,C5);

    SectionD->setExits(Final,D4,SectionC,D1);
    D1->setExits(NULL,SectionD,NULL,D2);
    D2->setExits(NULL,D1,NULL,D3);
    D3->setExits(NULL,D2,NULL,NULL);
    D4->setExits(NULL,D5,NULL,SectionD);
    D5->setExits(NULL,D6,NULL,D4);
    D6->setExits(NULL,NULL,NULL,D5);

    Final->setExits(NULL,FinalBoss,SectionD,Boss);
    Boss->setExits(NULL,Final,NULL,NULL);
    FinalBoss->setExits(NULL,NULL,NULL,Final);

    currentRoom = SectionA;
    qDebug() << "Rooms have been created";
}

CreateRooms::~CreateRooms(){
    delete currentRoom;
    delete nextRoom;
    delete SectionA;
    delete A1;
    delete A2;
    delete A3;
    delete A4;
    delete A5;
    delete A6;
    delete A7;
    delete A8;
    delete A9;
    delete A10;
    delete A11;
    delete A12;
    delete A13;
    delete A14;
    delete A15;
    delete A16;
    delete A17;
    delete SectionB;
    delete B1;
    delete B2;
    delete B3;
    delete B4;
    delete B5;
    delete B6;
    delete SectionC;
    delete C1;
    delete C2;
    delete C3;
    delete C4;
    delete C5;
    delete C6;
    delete SectionD;
    delete D1;
    delete D2;
    delete D3;
    delete D4;
    delete D5;
    delete D6;
    delete Final;
    delete FinalBoss;
    delete Boss;
}
