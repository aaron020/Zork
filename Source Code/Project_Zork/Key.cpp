#include "Key.h"



Key::Key(QString description, double price){
    this->description = description;
    this->price = price;
}


QString Key::getKeyDescription()const{
    return description;
}

double Key::getKeyPrice() const{
    return price;
}

bool Key::find(QString keyName){
    return keyName == description;
}


bool operator==(const Key &k1,const Key &k2){
    return (k1.description == k2.description &&
            k1.price == k2.price);
}

void Key::setRoom(QString room){
    roomToUnlock = room;
}


QString Key::getRoom() const{
    return roomToUnlock;
}
