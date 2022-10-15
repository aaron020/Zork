#ifndef ENTITY_H
#define ENTITY_H
#include <QString>


class Entity{
protected:
    QString name;
    bool isFriendly;

public:
    QString getName()const;

    //Enemy funcitons - Abstract funstions
    virtual int getLevel()const=0;
    virtual int getHealth()const = 0;
    virtual void attack(int hitpoints)= 0;
    virtual int calcReward(float time)=0;


    bool isFriend()const;
    virtual ~Entity();
};


#endif // ENTITY_H
