#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Room.h"
#include "Balance.h"
#include "Item.h"
#include "Inventory.h"
#include "Enemy.h"
#include <ctime>
#include <Shop.h>
#include <QString>
#include <CreateEntities.h>

class Controller : public CreateEntities {
private:
    Balance balance;

    Shop shop;
    Inventory inventory;

    Key *goldKey,*silverKey, *sectionB, *sectionC,
    *sectionD,*final;

public:
    Controller();
    ~Controller();

    void ItemGenerator(Room *room, double itemPrice = 1);
    QString currentRoomDescription()const;
    bool moveRooms(string);

    QString getBalance();

    QString search();

    QString keyInfo(QString keyName);
    bool BuyKey(QString keyName);
    bool unlock();
    bool isNextRoomLocked();
    QString roomLock();
    QString keyInInventoryInfo(QString keyName);

    bool BuyWeapon(QString weaponName);
    QString WeaponInfo(QString weaponName);
    QString weaponInInventoryInfo(QString weaponName);
    bool upgradeWeapon(QString weaponName);
    bool equipWeapon(QString weaponName);
    QString equipWeaponInfo();
    bool weaponActive();

    bool hasEntity();
    QString getEntityInfo();
    void attackEntity();
    QString entityhealth();
    bool isEntityDead();
    QString reward(float time);

};



#endif // CONTROLLER_H
