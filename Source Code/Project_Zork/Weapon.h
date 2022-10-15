#ifndef WEAPON_H
#define WEAPON_H
#include <QString>
#include "Balance.h"
class Weapon{
private:
    double price;
    int strength;
    QString name;

    int maxUpgradeLevel = 5;
    struct level{
        unsigned int upgradeLevel : 3;
    }lvl;
public:
    Weapon(double,int,QString);
    double getPrice()const;
    int getStrength()const;
    QString getName()const;
    bool find(QString weaponName);
    bool upgrade(Balance &);
    double upgradePrice();
    int getLevel();
    int getMaxLevel();
    friend bool operator==(const Weapon &w1,const Weapon &w2);
};



#endif // WEAPON_H
