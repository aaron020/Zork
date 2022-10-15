#include "Room.h"


Room::Room(QString description){
    this->description = description;
}

Room::~Room(){
}


void Room::setExits(Room *up, Room *right, Room *down, Room *left){
    if(up != NULL){
        exits["up"] = up;

    }
    if(right != NULL){
        exits["right"] = right;

    }
    if(down != NULL){
        exits["down"] = down;

    }
    if(left != NULL){
        exits["left"] = left;

    }
}

QString Room::getDescription()const{
    return description;
}



Room* Room::nextRoom(string direction){
    map<string, Room*>::iterator next = exits.find(direction);
    if (next == exits.end())
        return NULL;
    return next->second;
}

//----------------------------------------------------------------------



void Room::addItem(Item item){
    itemsInRoom.push_back(item);
}

void Room::removeAllItems(){
    itemsInRoom.clear();
}

QString Room::searchRoom(Balance &balance){
    if(itemsInRoom.size() > 0){
        QString items;
        double price = 0;
        for(auto& i : itemsInRoom){
            items  += "$"+QString::number(i.getPrice()) + " : " + i.getName() + "\n";
            price += i.getPrice();
        }
        removeAllItems();
        balance.add(price);
        return "Found: \n" + items + "\nSold All For: $" + QString::number(price);
    }else{
        return "No items in this room...";
    }
}


