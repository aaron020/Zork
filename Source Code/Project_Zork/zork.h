#ifndef ZORK_H
#define ZORK_H

#include <QMainWindow>
#include "Controller.h"
#include <QListWidgetItem>
#include <QPixmap>
#include <chrono>


QT_BEGIN_NAMESPACE
namespace Ui { class Zork; }
QT_END_NAMESPACE

class Zork : public QMainWindow
{
    Q_OBJECT

public:
    Zork(QWidget *parent = nullptr);
    ~Zork();
    void Refresh();
    void enterRoom();
    void BalanceUpdater();
    void timer();




private slots:
   void on_Up_clicked();

   void on_Down_clicked();

   void on_Right_clicked();

   void on_Left_clicked();

   void on_Search_clicked();

   void on_Keys_activated(const QString &arg1);

   void on_KeyBuy_clicked();



   void on_KeyInventory_itemClicked();

   void on_WeaponBuy_clicked();

   void on_Weapons_activated(const QString &arg1);
   void on_WeaponsInventory_itemClicked();

   void on_Upgrade_clicked();


   void on_Battle_clicked();

   void on_Equip_clicked();

   void on_Attack_clicked();


private:
    Ui::Zork *ui;
    Controller control;
};
#endif // ZORK_H
