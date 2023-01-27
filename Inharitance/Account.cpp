#include "Account.h"

Account::Account(std::string name,double balance):name{name},balance{balance}{

}
bool Account::deposit(double amount){
    if(amount<0){
        return false;
    }
    else{
        balance+=amount;
        return true;
    }
}
bool Account::withdraw(double amount){
    if(balance-amount>=0){
        balance-=amount;
        return true;
    }
    return false;
}
double Account::get_balance()const{
    return this->balance;
}
std::ostream &operator<<(std::ostream &os,const Account&account){
    os<<"Account: "<<account.name<<": "<<account.balance<<std::endl;
    return os;
}

Checking_Account::Checking_Account(std::string name,double balance)
:Account{name,balance}{

}
bool Checking_Account::withdraw(double amount){
    amount=amount+1,5;
    return Account::withdraw(amount);
}


Trust_Account::Trust_Account(std::string name,double balance,double interest_rate)
:Account(name,balance),interest_rate{interest_rate}{
    allowed=3;
}

bool Trust_Account::deposit(double amount){
    if(amount>=5000) amount=amount*(interest_rate/100)+50.0;
    else amount=amount*(interest_rate/100);
    return Account::deposit(amount);
}
bool Trust_Account::withdraw(double amount){
    if(allowed==0||amount>=(balance*20)/100) return false;
    else{
        allowed--;
        return Account::withdraw(amount);
    }
}
std::ostream &operator<<(std::ostream &os, const Trust_Account &acc){
    os<<"Trusted Account: "<<acc.name<<": "<<acc.balance<<": "<<acc.interest_rate<<std::endl;
    return os;
}