#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"



class Enemy :  public Entity{
private:
    int level;
    int health;
    int maxTime;
    int minTime;
    int maxReward;
    union reward{
        float time;
        int payout;
    }prize;
public:
    ~Enemy();
    Enemy(int maxTime, int minTime, int maxReward, QString name = "Enemy", int level = 10, int health = 100);
    int getLevel()const override;
    int getHealth()const override;
    void attack(int hitpoints)override;
    int calcReward(float time)override;
};



#endif // ENEMY_H

