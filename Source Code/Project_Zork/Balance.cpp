#include "Balance.h"



Balance::Balance(double balance){
    this->balance = balance;
}

double Balance::getBalance() const{
    return balance;
}

void setBalance(Balance &balance, double amount){
    balance.balance = amount;
}



