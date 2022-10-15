#include "EntityInRoom.h"



void EntityInRoom::addEntity(Entity *entity){
    hasEntity = true;

    this->entity = entity;
}


QString EntityInRoom::getEntity()const{
    if(entity == NULL){
        throw "Entity not found";
    }else{
        return "Name: " + entity->getName() + "\nLevel: " + QString::number(entity->getLevel())
                  + "\nHealth: " + QString::number(entity->getHealth());
    }
}

bool EntityInRoom::entityPresent() const{
    return hasEntity;
}




void EntityInRoom::attackEntity(Inventory &inventory){
    int hitpoints = inventory.weaponHitPoints();
    entity->attack(hitpoints);
}

int EntityInRoom::entityHealth(){
    return entity->getHealth();
}

bool EntityInRoom::isEntityDead(){
    if(entity->getHealth() == 0){
        return true;
    }else{
        return false;
    }

}


int EntityInRoom::entityReward(float time){
    return entity->calcReward(time);
}
