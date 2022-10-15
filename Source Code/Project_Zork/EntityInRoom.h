#ifndef ENTITYINROOM_H
#define ENTITYINROOM_H
#include "Entity.h"
#include "Inventory.h"

class EntityInRoom
{
private:
    Entity *entity;
    bool hasEntity = false;
public:
    //Room entity
    void addEntity(Entity *);
    QString getEntity()const;
    bool entityPresent()const;

    //Room Entity battle
    void attackEntity(Inventory &);
    int entityHealth();
    bool isEntityDead();
    int entityReward(float time);
};

#endif // ENTITYINROOM_H
