#ifndef CREATEENTITIES_H
#define CREATEENTITIES_H
#include <Enemy.h>
#include <QDebug>
#include "CreateRooms.h"
class CreateEntities : public CreateRooms
{
protected:
    Enemy *evilMan;
    Enemy *evilSnakeMan;
    Enemy *BadGuy;
    Enemy *unholyFella;
    Enemy *wickedSnakeGuy;
    Enemy *wickedSnakeGuy2;

    Enemy *malvelontguy;
    Enemy *spiteful;
    Enemy *maliciousman;
    Enemy *horribleguy;

    Enemy *Bearman;
    Enemy *misrableman;
    Enemy *doctorbearman;
    Enemy *wickedSnakeGuy3;

    Enemy *worst;
    Enemy *evil;
    Enemy *verybad;
    Enemy *worstever;
    Enemy *boss;
    Enemy *finalboss;
public:
    CreateEntities();
    ~CreateEntities();
    template<typename T>
    void addEntity(Entity *, T *,Room *);
};

#endif // CREATEENTITIES_H
