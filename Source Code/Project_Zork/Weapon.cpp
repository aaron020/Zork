#include "Weapon.h"


Weapon::Weapon(double price, int strength, QString name){
    this->price = price;
    this->strength = strength;
    this->name = name;
    lvl.upgradeLevel = 1;
}

double Weapon::getPrice() const{
    return price;
}

int Weapon::getStrength() const{
    return strength;
}

QString Weapon::getName() const{
    return name;
}


bool operator==(const Weapon &w1,const Weapon &w2){
    return ((w1.name == w2.name) && (w1.price == w2.price));
}


bool Weapon::find(QString weaponName){
    return weaponName == name;
}

bool Weapon::upgrade(Balance &balance){
    if(balance.getBalance() >= upgradePrice()){
        if(lvl.upgradeLevel < 5){
            strength = strength + strength/2;
            balance.subtract(upgradePrice());
            lvl.upgradeLevel++;
            return true;
        }else{
            return false;
        }
    }
    return false;
}


double Weapon::upgradePrice(){
    if(lvl.upgradeLevel < 5){
        return price/2 * lvl.upgradeLevel;
    }else{
        return 0;
    }

}



int Weapon::getLevel(){
    return lvl.upgradeLevel;
}

int Weapon::getMaxLevel(){
    return maxUpgradeLevel;
}
