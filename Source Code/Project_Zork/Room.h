#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <vector>
#include <string>
#include <map>

#include "Item.h"
#include "Balance.h"
#include "Key.h"
#include "Inventory.h"
#include "EntityInRoom.h"
#include "RoomLock.h"
using std::map;
using std::string;
using std::vector;
using namespace pickUps;

class Room : public EntityInRoom, public RoomLock{
private:
    QString description;
    map<string, Room*> exits;
    vector<Item> itemsInRoom;
public:
    ~Room();
    //General Functions
    Room(QString description = "Empty");
    void setExits(Room *up, Room *right, Room *down, Room *left);
    QString getDescription()const;
    Room* nextRoom(string direction);

    //Items in the room
    void addItem(Item);
    void removeAllItems();
    QString searchRoom(Balance &);
};





#endif // ROOM_H
