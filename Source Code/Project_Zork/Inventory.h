#ifndef INVENTORY_H
#define INVENTORY_H
#include "Key.h"
#include "vector"
#include "Weapon.h"
#include "Balance.h"
#include "Storage.cpp"
#include "ExceptionHandler.h"
using std::vector;


class Inventory{
private:
    Storage<Key> keysInventory;
    Storage<Weapon> weaponsInventory;
    Weapon *equip;
    bool weaponActive = false;
public:
     void add(Key &);
     bool find(Key &);
     QString keyInfo(QString keyName);


     void add(Weapon &);
     QString weaponInfo(QString weaponName);
     bool upgradeWeapon(Balance &balance,QString weaponName);
     bool equipWeapon(QString weaponName);
     QString getEquipInfo();
     bool isWeaponActive();
     int weaponHitPoints();

};




#endif // INVENTORY_H
