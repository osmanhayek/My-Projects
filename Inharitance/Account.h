#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<iostream>
int allowed;
class Account{
    friend std::ostream&operator<<(std::ostream &os,const Account &account);
protected:
    std::string name;
    double balance;
public:
    Account(std::string name="Unnamed Account",double balance=0.0);    
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance()const;
};

class Checking_Account:public Account{
public:
    Checking_Account(std::string name="Unnamed Checking Account",double balance=0.0);
    bool withdraw(double amount);
};
class Trust_Account:public Account{
protected:
    double interest_rate;
    int allowed;
public:
    Trust_Account(std::string name="Unnamed Trust_Account",double balance=0.0,double interest_rate=0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    friend std::ostream&operator<<(std::ostream &os,const Trust_Account&acc);
    

};





#endif