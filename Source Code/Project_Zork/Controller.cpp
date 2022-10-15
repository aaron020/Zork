#include "Controller.h"

using namespace pickUps;
Controller::Controller() : shop(inventory){
    //Keys----------------------------------------------
    silverKey = new Key("Silver",100);
    goldKey = new Key("Gold",250);
    sectionB = new Key("SectionB",300);
    sectionC = new Key("SectionC",500);
    sectionD = new Key("SectionD",2000);
    final = new Key("Final", 10000);
    silverKey->setRoom(Asilver->getDescription());
    goldKey->setRoom(Agold->getDescription());
    sectionB->setRoom(SectionB->getDescription());
    sectionC->setRoom(SectionC->getDescription());
    sectionD->setRoom(SectionD->getDescription());
    final->setRoom(Final->getDescription());

    //Lock Rooms
    Asilver->lockRoom(silverKey);
    Agold->lockRoom(goldKey);
    SectionB->lockRoom(sectionB);
    SectionC->lockRoom(sectionC);
    SectionD->lockRoom(sectionD);
    Final->lockRoom(final);

    //Add keys to shop
    shop.add(*silverKey);
    shop.add(*goldKey);
    shop.add(*sectionB);
    shop.add(*sectionC);
    shop.add(*sectionD);
    shop.add(*final);

    //Weapons---------------------------------------------
    Weapon basicSword(25,2,"Basic Sword");
    Weapon stoneSword(150,15,"Stone Sword");
    Weapon silverSword(750,75,"Silver Sword");
    Weapon crystalSword(1500,270,"Crystal Sword");
    Weapon laserSword(3000,1200,"Laser Sword");
    Weapon fireSword(15000,6500,"Fire Sword");
    Weapon godSword(75000,35000,"God Sword");



    //Add Weapons to shop
    shop.add(basicSword);
    shop.add(stoneSword);
    shop.add(silverSword);
    shop.add(crystalSword);
    shop.add(laserSword);
    shop.add(fireSword);
    shop.add(godSword);

    //Items-----------------------------------------------------
    Item silver(200,"Silver");
    Item gold(350,"Gold");
    Item platinum(500, "Platinum");
    Item crystal(1000,"Crystal");
    Item diamond(5000,"Diamond");
    Item emerald(10000,"emerald");

    //Add the items
    Asilver->addItem(silver);
    Agold->addItem(gold);
    SectionB->addItem(platinum);
    SectionC->addItem(crystal);
    SectionD->addItem(diamond);
    Final->addItem(emerald);

    ItemGenerator(A2,2);
    ItemGenerator(SectionA,3);
    ItemGenerator(A1,2);
    ItemGenerator(A8,2);
    ItemGenerator(A6,2);
    ItemGenerator(A11,2);
    ItemGenerator(A12,2);
    ItemGenerator(A17,3);
    ItemGenerator(B2,2);
    ItemGenerator(B5,2);
    ItemGenerator(SectionB,4);
    ItemGenerator(SectionC,6);
    ItemGenerator(C2,5);
    ItemGenerator(C3,5);
    ItemGenerator(C4,5);
    ItemGenerator(C5,5);
    ItemGenerator(D1,10);
    ItemGenerator(D2,10);
    ItemGenerator(SectionD,10);
    ItemGenerator(D5,11);

    qDebug() << "Controller has been constructed";

}


void Controller::ItemGenerator(Room *room, double itemPrice){
    Item array[] = {
        {2*itemPrice,"Bag"},
        {5*itemPrice,"Rock"},
        {10*itemPrice,"Watch"},
        {15*itemPrice,"Keyboard"},
        {18*itemPrice,"Lamp"}
    };

    int itemCount = (rand() % 5) + 1;
    Item *end = array + itemCount;
    for(Item *i = array; i != end; i++){
        room->addItem(*i);
    }

}



QString Controller::currentRoomDescription() const{
    return currentRoom->getDescription();
}

Controller::~Controller(){
    delete goldKey;
    delete silverKey;
    delete sectionB;
    delete sectionC;
    delete sectionD;
    delete final;
}

bool Controller::moveRooms(string direction){
    //Checks to see if there is a room in the direction you have pressed
    if(currentRoom->nextRoom(direction) == NULL){
        nextRoom = NULL;
        return false;
    }else{
        //If there is a room check to see if its locked or not
        if((currentRoom->nextRoom(direction))->isLocked()){
            nextRoom = currentRoom->nextRoom(direction);
            return false;
        }else{
            currentRoom = currentRoom->nextRoom(direction);
            nextRoom = NULL;
            return true;
        }


    }
}

QString Controller::getBalance(){
    return "$" + QString::number(balance.getBalance());
}

QString Controller::search(){
    return currentRoom->searchRoom(balance);
}


QString Controller::keyInfo(QString keyName) {
    try {
        return shop.keyInfo(keyName);
        //Catches exception where the key is null
    }  catch (std::exception& e) {
        //converts const char to QString
        return QString::fromUtf8(e.what());
    }

}

bool Controller::BuyKey(QString keyName){
    return shop.buyKey(balance,keyName);
}


bool Controller::unlock(){
    if(nextRoom == NULL){
        return false;
    }
    Key *keyNeeded = nextRoom->keyNeeded;
    return inventory.find(*keyNeeded);
}


QString Controller::roomLock(){
    if(nextRoom == NULL){
        ExceptionHandler e;
        throw e;
    }
    //If the room is locked :  if not unlocked - the function unlock() checks if you have the key needed to open the room in your iventory
    if(!unlock()){
        return "Room Locked! \nKey Needed to open room: " + nextRoom->keyNeeded->getKeyDescription();
    }else{
        currentRoom = nextRoom;
        return "Unlocked!!\nWelcome to " + currentRoom->getDescription();
    }

}

bool Controller::isNextRoomLocked(){
    if(nextRoom == NULL){
        return false;
    }else{
        return true;
    }
}

QString Controller::keyInInventoryInfo(QString keyName){
    try {
        return inventory.keyInfo(keyName);
    }  catch (std::exception& e) {
        return QString::fromUtf8(e.what());
    }

}


bool Controller::BuyWeapon(QString weaponName){
    return shop.buyWeapon(balance,weaponName);
}

QString Controller::WeaponInfo(QString weaponName){
    try {
        return shop.weaponInfo(weaponName);
    }  catch (std::exception& e) {
        return QString::fromUtf8(e.what());
    }

}

QString Controller::weaponInInventoryInfo(QString weaponName){
    try {
        return inventory.weaponInfo(weaponName);
    }  catch (std::exception& e) {
        return QString::fromUtf8(e.what());
    }

}

bool Controller::upgradeWeapon(QString weaponName){
    return inventory.upgradeWeapon(balance,weaponName);
}

bool Controller::hasEntity(){
    return currentRoom->entityPresent();
}

QString Controller::getEntityInfo(){
    try{
        return currentRoom->getEntity();
    }catch(QString* msg){
        return *msg;
    }
}

bool Controller::equipWeapon(QString weaponName){
    return inventory.equipWeapon(weaponName);

}

QString Controller::equipWeaponInfo(){
    return inventory.getEquipInfo();
}

bool Controller::weaponActive(){
    return inventory.isWeaponActive();
}


void Controller::attackEntity(){
    currentRoom->attackEntity(inventory);
}

QString Controller::entityhealth(){
    return QString::number(currentRoom->entityHealth());
}

bool Controller::isEntityDead(){
    return currentRoom->isEntityDead();
}

QString Controller::reward(float time){
    balance.add<int>(currentRoom->entityReward(time));
    return QString::number(currentRoom->entityReward(time));
}
