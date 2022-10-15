#ifndef ITEM_H
#define ITEM_H
#include <QString>
using std::string;

namespace pickUps {


class Item{
private:
    double *price;
    QString name;
public:
    Item(const Item &i);
    ~Item();
    Item(double price = 5,QString name = "Item");

    double getPrice()const;
    QString getName()const;
};


}


#endif // ITEM_H
