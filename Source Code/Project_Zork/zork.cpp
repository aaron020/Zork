#include "zork.h"
#include "ui_zork.h"
#include "Room.h"
#include <iostream>

//Global varibales - Should not use
int keyShopIndex = 0;
int weaponIndex = 0;
bool keysInventory = false;
bool weaponsInventory = false;
bool timerOn = false;
QListWidgetItem *equip;
//Ugly variable for timer
std::chrono::time_point<std::chrono::_V2::high_resolution_clock,std::chrono::duration<long long, std::ratio<1,1000000000>>> start, end;


#define WIDTH 551
#define HEIGHT 471

#define MAIN 0
#define ENEMY 1
#define SHOP 2
#define KEYS 3
#define WEAPONS 4
#define MAP 5
#define INFO 6

#define ERROR(a) qDebug() << #a

Zork::Zork(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Zork)
{
    ui->setupUi(this);
    QPixmap map(":/images/Images/map.png");
    ui->MapPic->setPixmap(map.scaled(WIDTH,HEIGHT));

    QPixmap lock(":/images/Images/lock.png");
    ui->Lock->setPixmap(lock.scaled(50,50));
    ui->Lock->setVisible(false);

    Refresh();
    ui->Balance->setText(control.getBalance());
    ui->Balance2->setText(control.getBalance());

    ui->tabWidget->setTabVisible(KEYS,false);
    ui->tabWidget->setTabVisible(WEAPONS,false);
    ui->tabWidget->setTabVisible(ENEMY,false);

    ui->Attack->setVisible(false);
    ui->HealthBarLabel->setVisible(false);
    ui->HealthBar->setVisible(false);

    ui->Information->setText("1. Up, down, left, and right used to move. \n\n"
    "2. Search will search for items in the current room + add total cost to your balance \n\n"
    "3. Enemies are indicated on the map by red X’s\n\n"
    "4. Locked rooms are indicated on the map by locks\n\n"
    "5. Enemies detected do not have to be fought right away, you can come back to them \n\n"
    "6. Best way to fight enemies is in order of their level\n\n"
    "7. Be careful what you spend your money on as you can end up trapped in a Section\n\n");
}

Zork::~Zork()
{
    delete ui;
}

void Zork::BalanceUpdater(){
    //Updates the balance in the Shop menu and in the weapons menu
    ui->Balance->setText(control.getBalance());
    ui->Balance2->setText(control.getBalance());
}

void Zork::Refresh(){
    ui->CurrentRoom->setText(control.currentRoomDescription());
    ui->Console->setText("Welcome to " + control.currentRoomDescription());
    ui->Lock->setVisible(false);

    //Checks if the room you have entered has an entity in it + if the entity is still alive
    if(control.hasEntity() && !(control.isEntityDead())){
        //Enemy tab set visible
        ui->tabWidget->setTabVisible(ENEMY,true);
        ui->Battle->setVisible(true);
        ui->EnemyConsole->setText(control.getEntityInfo());
        QString console = ui->Console->toPlainText();
        ui->Console->setText(console + "\n\n***Entity detected in this room!***");
    }else{
        //If the room does not have an entity in it then we hide all the stuff to do with entity
        ui->tabWidget->setTabVisible(ENEMY,false);
        ui->Attack->setVisible(false);
        ui->HealthBarLabel->setVisible(false);
        ui->HealthBar->setVisible(false);
    }

}

//Code is run when you click to move to another room but the moveRooms() function returns false meaning the room has a lock on it
void Zork::enterRoom(){
    if(control.isNextRoomLocked()){
        ui->Lock->setVisible(true);
        //Enemy tab
        ui->tabWidget->setTabVisible(ENEMY,false);


        //roomLock() will check to see if you have the key if you do you proceed to that room
        try {
            ui->Console->setText(control.roomLock());
            ui->CurrentRoom->setText(control.currentRoomDescription());
        }  catch (std::exception& e) {
            ERROR("roomLock() called - NULL value for nextRoom");
        }

    }else{
        ui->Console->setText("Cant move in that direction!");
    }
}


//---------------------------------------------
//All the movement button calls
void Zork::on_Up_clicked()
{
    if(control.moveRooms("up")){
        Refresh();
    }else{
        enterRoom();
    }

}

void Zork::on_Down_clicked()
{
    if(control.moveRooms("down")){
        Refresh();
    }else{
        enterRoom();
    }
}

void Zork::on_Right_clicked()
{
    if(control.moveRooms("right")){
        Refresh();
    }else{
        enterRoom();
    }
}

void Zork::on_Left_clicked()
{
    if(control.moveRooms("left")){
        Refresh();
    }else{
        enterRoom();
    }
}
//--------------------------------------------------



void Zork::on_Search_clicked()
{
    ui->Console->setText(control.search());
    BalanceUpdater();
}

void Zork::on_Keys_activated(const QString &arg1)
{
    keyShopIndex = ui->Keys->currentIndex();
    if(keyShopIndex == 0){
        ui->KeyConsole->setText("");
    }else{
        ui->KeyConsole->setText(control.keyInfo(arg1));
    }

}

void Zork::on_KeyBuy_clicked()
{
    //If the title Keys is selected
    if(keyShopIndex == 0){
        ui->KeyConsole->setText("No key selected??");
    }else{
        if(control.BuyKey(ui->Keys->currentText())){
            BalanceUpdater();
            ui->KeyConsole->setText("Succesfully purchased: \n" + ui->Keys->currentText());
            ui->KeyInventory->addItem(ui->Keys->currentText());
            ui->Keys->removeItem(keyShopIndex);
            ui->Keys->setCurrentIndex(0);
            keyShopIndex = 0;
            if(!keysInventory){
                ui->tabWidget->setTabVisible(KEYS,true);
                keysInventory = true;
            }

        }else{
            ui->KeyConsole->setText("Unable to buy!");
        }
    }


}



void Zork::on_KeyInventory_itemClicked()
{
    ui->KeyInfo->setText(control.keyInInventoryInfo(ui->KeyInventory->currentItem()->text()));
}




void Zork::on_WeaponBuy_clicked()
{
    if(weaponIndex == 0){
        ui->WeaponConsole->setText("No weapon selected??");
    }else{
        if(control.BuyWeapon(ui->Weapons->currentText())){
            BalanceUpdater();
            ui->WeaponConsole->setText("Succesfully purchased: \n" + ui->Weapons->currentText());
            ui->WeaponsInventory->addItem(ui->Weapons->currentText());
            ui->Weapons->removeItem(weaponIndex);
            ui->Weapons->setCurrentIndex(0);
            weaponIndex = 0;
            if(!weaponsInventory){
                 ui->tabWidget->setTabVisible(WEAPONS,true);
                 weaponsInventory = true;
            }

        }else{
            ui->WeaponConsole->setText("Unable to buy!");
        }
    }
}


void Zork::on_Weapons_activated(const QString &arg1)
{
    weaponIndex = ui->Weapons->currentIndex();
    if(weaponIndex == 0){
        ui->WeaponConsole->setText("");
    }else{
        ui->WeaponConsole->setText(control.WeaponInfo(arg1));
    }
}



void Zork::on_WeaponsInventory_itemClicked()
{
    ui->WeaponsInfo->setText(control.weaponInInventoryInfo(ui->WeaponsInventory->currentItem()->text()));
}

void Zork::on_Upgrade_clicked()
{
    if(control.upgradeWeapon(ui->WeaponsInventory->currentItem()->text())){
        ui->WeaponsInfo->setText(control.weaponInInventoryInfo(ui->WeaponsInventory->currentItem()->text()));
        BalanceUpdater();
    }else{
        ui->WeaponsInfo->setText("Unable to upgrade!");
    }
}

void Zork::on_Battle_clicked()
{
    if(control.weaponActive()){
        ui->EnemyConsole->setText("Once Attack is clicked a timer will start,\n "
                                  "the timer will stop when enemies health is completely depleted!\n"
                                  "***Clicking attack will deplete the enemies health***\n");
        ui->Attack->setVisible(true);
        ui->HealthBarLabel->setVisible(true);
        ui->HealthBar->setVisible(true);
        ui->HealthBar->setText(control.entityhealth());
        ui->Battle->setVisible(false);
        //Hide all the other tabs
        ui->tabWidget->setTabVisible(MAIN,false);
        ui->tabWidget->setTabVisible(SHOP,false);
        ui->tabWidget->setTabVisible(KEYS,false);
        ui->tabWidget->setTabVisible(WEAPONS,false);
        ui->tabWidget->setTabVisible(MAP,false);
    }else{
        ui->EnemyConsole->setText("***No weapon***\n"
                                  "***Make sure you have a weapon equipped***\n"
                                  "Weapons can be bought from the shop");
    }

}


void Zork::on_Equip_clicked()
{
    if(control.equipWeapon(ui->WeaponsInventory->currentItem()->text())){
        ui->WeaponsInfo->setText(control.equipWeaponInfo());
        if(equip == NULL){
            ui->WeaponsInventory->currentItem()->setForeground(Qt::red);
            equip = ui->WeaponsInventory->currentItem();
        }else{
            equip->setForeground(Qt::white);
            equip = ui->WeaponsInventory->currentItem();
            ui->WeaponsInventory->currentItem()->setForeground(Qt::red);
        }

    }else{
        ui->WeaponsInfo->setText("Nope");
    }
}



void Zork::timer(){


    if(!control.isEntityDead()){
            start = std::chrono::high_resolution_clock::now();
    }else{
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        float ms = duration.count() * 10000.0f;
        ui->EnemyConsole->setText(QString::number(ms));
    }

}

void Zork::on_Attack_clicked(){
         if(!timerOn){
            start = std::chrono::high_resolution_clock::now();
            timerOn = true;
        }else{
           control.attackEntity();
           ui->HealthBar->setText(control.entityhealth());
           if(control.isEntityDead()){
               end = std::chrono::high_resolution_clock::now();
               std::chrono::duration<float> duration = end - start;
               float ms = duration.count() * 1000.0f;
               ui->EnemyConsole->setText("Time Taken: " + QString::number(ms) + "ms" + "\nReward: $" + control.reward(ms));
               BalanceUpdater();
               ui->Attack->setVisible(false);
               timerOn = false;
               ui->tabWidget->setTabVisible(MAIN,true);
               ui->tabWidget->setTabVisible(SHOP,true);
               if(keysInventory){
                 ui->tabWidget->setTabVisible(KEYS,true);
               }
               ui->tabWidget->setTabVisible(WEAPONS,true);
               ui->tabWidget->setTabVisible(MAP,true);
           }

        }

}


