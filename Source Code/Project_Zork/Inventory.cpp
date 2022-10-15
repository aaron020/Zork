#include "Inventory.h"


void Inventory::add(Key &key){
    keysInventory.add(key);
}

bool Inventory::find(Key &key){
    Key *k = keysInventory.find(key.getKeyDescription());
    if(k == NULL){
        return false;
    }else{
        return true;
    }
}


QString Inventory::keyInfo(QString keyName){
     Key *k = keysInventory.find(keyName);
     if(k == NULL){
         ExceptionHandler e;
         throw e;
     }else{
         return k->getKeyDescription() + " bought for $" + QString::number(k->getKeyPrice()) + " used to unlock " + k->getRoom();
     }
}


void Inventory::add(Weapon &weapon){
    weaponsInventory.add(weapon);
}

QString Inventory::weaponInfo(QString weaponName){
    Weapon *w = weaponsInventory.find(weaponName);
    if(w == NULL){
        ExceptionHandler e;
        throw e;
    }else{
        if(w->getLevel() == w->getMaxLevel()){
             return w->getName() + " bought for $" + QString::number(w->getPrice()) + "\nStrength: " + QString::number(w->getStrength()) + "\nLevel: " +
             "Max";
        }else{
            return w->getName() + " bought for $" + QString::number(w->getPrice()) + "\nStrength: " + QString::number(w->getStrength()) + "\nLevel: " +
            QString::number(w->getLevel()) + " / " + QString::number(w->getMaxLevel()) + "\nUpgrade Price: $" + QString::number(w->upgradePrice());
        }
    }
}


bool Inventory::upgradeWeapon(Balance &balance,QString weaponName){
    Weapon *k = weaponsInventory.find(weaponName);
    if(k == NULL){
        return false;
    }
    if(k->upgrade(balance)){
        return true;
    }else{
        return false;
    }
}


bool Inventory::equipWeapon(QString weaponName){
    Weapon *k = weaponsInventory.find(weaponName);
    if(k == NULL){
       return false;
    }else{
        equip = k;
        weaponActive = true;
        return true;
    }
}



QString Inventory::getEquipInfo(){
    if(equip == NULL){
        return "Null";
    }else{
        return equip->getName() + " Level: " + QString::number(equip->getLevel()) + " is now in use";
    }
}


bool Inventory::isWeaponActive(){
    return weaponActive;
}


int Inventory::weaponHitPoints(){
    if(weaponActive){
        return equip->getStrength();
    }else{
        return 0;
    }
}

