#include "Item.h"
#include <QDebug>



pickUps::Item::Item(double p, QString name){
    price = new double;
    *price = p;
    this->name = name;
}

pickUps::Item::Item(const Item &i){
    price = new double;
    *price = *(i.price);
    name = i.name;
}


pickUps::Item::~Item(){
    delete price;
}



double pickUps::Item::getPrice() const{
    return *price;
}


QString pickUps::Item::getName() const{
    return name;
}

