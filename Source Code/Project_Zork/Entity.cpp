#include "Entity.h"



QString Entity::getName() const{
    return name;
}

bool Entity::isFriend() const{
    return isFriendly;
}

Entity::~Entity(){}
