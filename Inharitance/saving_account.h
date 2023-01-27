#ifndef _SAVING_H_
#define _SAVING_H_
#include "Account.h"


class Savings_Account:public Account{
    friend std::ostream&operator<<(std::ostream &os,const Savings_Account&saving_account);
protected:
    double int_rate;
public:
    Savings_Account(std::string name="Unnamed Savings Account",double balance=0.0,double int_rate=0.0);
    bool deposit(double amount);
        
};


#endif