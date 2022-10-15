#include "Shop.h"


//Initializer list because inventory is a reference
Shop::Shop(Inventory &inventory) : inventory(inventory){};

//_______________________________________________________

void Shop::add(Key &k){
    keyShop.add(k);
}

QString Shop::keyInfo(QString keyName){
    Key *k = keyShop.find(keyName);
    if(k == NULL){
        ExceptionHandler e;
        throw e;
    }
    return "Name: " + k->getKeyDescription() + "\nPrice: $"  + QString::number(k->getKeyPrice());
}


bool Shop::remove(Key &k){
    return keyShop.remove(k);
}

bool Shop::buyKey(Balance &balance, QString keyName){
    Key *k = keyShop.find(keyName);
    if(k == NULL){
        return false;
    }
    if(k->getKeyPrice() <= balance.getBalance()){
        balance.subtract(k->getKeyPrice());
        inventory.add(*k);
        remove(*k);
        return true;
    }else{
        return false;
    }


}

//__________________________________________________________


void Shop::add(Weapon &w){
    weaponShop.add(w);
}


bool Shop::remove(Weapon &w){
    return weaponShop.remove(w);
}



bool Shop::buyWeapon(Balance &balance, QString weaponName){
    Weapon *w = weaponShop.find(weaponName);
    if(w == NULL){
        return false;
    }
    if(balance.getBalance() >= w->getPrice()){
        balance.subtract(w->getPrice());
        inventory.add(*w);
        remove(*w);
        return true;
    }else{
        return false;
    }
}

QString Shop::weaponInfo(QString weaponName){
    Weapon *w = weaponShop.find(weaponName);
    if(w == NULL){
        ExceptionHandler e;
        throw e;
    }else{
        return "Name: " + w->getName() + "\nPrice: $" + QString::number(w->getPrice()) + "\nStrength: " + QString::number(w->getStrength());
    }
}




