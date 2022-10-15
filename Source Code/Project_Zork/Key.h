#ifndef KEY_H
#define KEY_H
#include "QString"





class Key{
private:
    double price;
    QString description;
    QString roomToUnlock;

public:
    Key(QString decription = "Key", double price = 10);
    QString getKeyDescription()const;
    double getKeyPrice()const;
    bool find(QString keyName);
    void setRoom(QString room);
    QString getRoom()const;
    friend bool operator==(const Key &k1,const Key &k2);
};







#endif // KEY_H
