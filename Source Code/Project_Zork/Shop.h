#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <string>

#include "Balance.h"
#include "Key.h"
#include "QString"
#include "Inventory.h"
#include "Weapon.h"
#include "ExceptionHandler.h"


class Shop{
private:
    Storage<Key> keyShop;
    Storage<Weapon> weaponShop;
    Inventory &inventory;
public:
    Shop(Inventory &);
    void add(Key &);
    QString keyInfo(QString keyName);
    bool remove(Key &);
    bool buyKey(Balance &,QString keyName);

    void add(Weapon &);
    bool remove(Weapon &);
    bool buyWeapon(Balance &,QString weaponName);
    QString weaponInfo(QString weaponName);
};




#endif // SHOP_H
