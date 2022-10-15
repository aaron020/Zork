#include "Enemy.h"


Enemy::Enemy(int maxTime, int minTime, int maxReward,QString name, int level, int health)
{
    this->name = name;
    this->level = level;
    this->health = health;
    this->maxTime = maxTime;
    this->minTime = minTime;
    this->maxReward = maxReward;
    isFriendly = false;
}


int Enemy::getLevel() const{
    return level;
}


int Enemy::getHealth() const{
    return health;
}

void Enemy::attack(int hitpoints){
    if(hitpoints > health){
        health = 0;
    }else{
        health = health - hitpoints;
    }

}



int Enemy::calcReward(float time){
    //Time stored in a union variable
    prize.time = time;
    int timeInterval = maxTime - minTime;
    //Extremely fast
    if(prize.time < 150){
        //Get 4 times the max
        return maxReward * 4;
    }else if(prize.time > maxTime){
        return 0;
    } else if(prize.time <= minTime){
        return maxReward;
    }else{
        double timePercentage = 1 - (prize.time/timeInterval);
        //Time variable no longer needed, use other union variable
        prize.payout = maxReward * timePercentage;
        return prize.payout;
    }
}



Enemy::~Enemy(){
}
