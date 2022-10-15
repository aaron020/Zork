#include "CreateEntities.h"




CreateEntities::CreateEntities()
{
    Entity *enemy = NULL;
    evilMan = new Enemy(100000,15000,50,"Evil-Man",1,50);
    addEntity(enemy,evilMan,A1);

    Entity *enemy2 = NULL;
    evilSnakeMan = new Enemy(50000,3000,100,"Evil Snake-Man",2,150);
    addEntity(enemy2,evilSnakeMan,A3);

    Entity *enemy3 = NULL;
    BadGuy = new Enemy(25000,2000,200,"Bad Guy",3,170);
    addEntity(enemy3,BadGuy,A7);

    Entity *enemy4 = NULL;
    unholyFella = new Enemy(5000,1000,300,"Unholly Fella",4,200);
    addEntity(enemy4,unholyFella,A9);

    Entity *enemy5 = NULL;
    wickedSnakeGuy = new Enemy(4000,1000,400,"Wicked Snake-Guy",5,200);
    addEntity(enemy5,wickedSnakeGuy,A10);

    Entity *enemy6 = NULL;
    wickedSnakeGuy2 = new Enemy(4000,1000,450,"Wicked Snake-Guy 2",6,250);
    addEntity(enemy6,wickedSnakeGuy2,A16);

    Entity *enemy7 = NULL;
    malvelontguy = new Enemy(6000,700,500,"Malvelont Guy",7,350);
    addEntity(enemy7,malvelontguy,B1);

    Entity *enemy8 = NULL;
    spiteful = new Enemy(10000,700,700,"Spiteful",8,400);
    addEntity(enemy8,spiteful,B3);

    Entity *enemy9 = NULL;
    maliciousman = new Enemy(3000,700,1000,"Malicious Man",9,500);
    addEntity(enemy9,maliciousman,B4);

    Entity *enemy10 = NULL;
    horribleguy = new Enemy(3000,500,1500,"Horrible Guy",10,550);
    addEntity(enemy10,horribleguy,B6);

    Entity *enemy11 = NULL;
    Bearman = new Enemy(4000,500,3500,"Bear-Man",11,1200);
    addEntity(enemy11,Bearman,C1);

    Entity *enemy12 = NULL;
    misrableman = new Enemy(4000,500,4500,"Misrable Man",12,2000);
    addEntity(enemy12,misrableman,C3);

    Entity *enemy13 = NULL;
    doctorbearman = new Enemy(3000,500,6000,"Doctor-Bear-Man",13,3000);
    addEntity(enemy13,doctorbearman,C4);

    Entity *enemy14 = NULL;
    wickedSnakeGuy3 = new Enemy(3000,1000,10000,"Wicked Snake-Guy 3",12,5000);
    addEntity(enemy14,wickedSnakeGuy3,C6);

    Entity *enemy15 = NULL;
    worst = new Enemy(3000,700,15000,"Worst",13,10000);
    addEntity(enemy15,worst,D1);

    Entity *enemy16 = NULL;
    evil = new Enemy(3000,700,25000,"Evil",14,12000);
    addEntity(enemy16,evil,D3);

    Entity *enemy17 = NULL;
    verybad = new Enemy(3000,700,35000,"Very-Bad",15,15000);
    addEntity(enemy17,verybad,D4);

    Entity *enemy18 = NULL;
    worstever = new Enemy(3000,700,50000,"Very-Bad",16,20000);
    addEntity(enemy18,worstever,D6);

    Entity *enemy19 = NULL;
    boss = new Enemy(12000,6000,150000,"Boss",99,1000000);
    addEntity(enemy19,boss,Boss);

    Entity *enemy20 = NULL;
    finalboss = new Enemy(10000,5000,500000,"Final Boss",100,5000000);
    addEntity(enemy20,finalboss,FinalBoss);

    //addEntity(enemy20,enemy10,A1); - Example of dynamic cast returning null

    qDebug() << "Entities have been created";
}

CreateEntities::~CreateEntities(){
    delete evilMan;
    delete evilSnakeMan;
    delete BadGuy;
    delete unholyFella;
    delete wickedSnakeGuy;
    delete wickedSnakeGuy2;
    delete malvelontguy;
    delete spiteful;
    delete maliciousman;
    delete horribleguy;
    delete Bearman;
    delete misrableman;
    delete doctorbearman;
    delete wickedSnakeGuy3;
    delete  worst;
    delete evil;
    delete verybad;
    delete worstever;
    delete boss;
    delete finalboss;
}

template <typename T>
void CreateEntities::addEntity(Entity *entity, T *name, Room *room){
    entity = name;

    name = dynamic_cast<Enemy*>(entity);
    if(name){
        room->addEntity(entity);
    }else{
        qDebug() << "dynamic_cast return NULL: Entity cannot be added";
    }
}
