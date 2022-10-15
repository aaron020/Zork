#ifndef BALANCE_H
#define BALANCE_H



class Balance{
private:
    double balance;
public:
    //Constructor which allows you to set the initial balance
    Balance(double balance = 0);


    //Add money to your balance
    template<typename T>
    void add(T amount){
        balance += amount;
    };

    //Take away maoney from your balance
    template<typename T>
    void subtract(T amount){
        if(amount > balance){
            balance = 0;
        }else{
            balance -= amount;
        }
    };


    //Returns the balance amount
    double getBalance()const;

    friend void setBalance(Balance &, double amount);
};


#endif // BALANCE_H
