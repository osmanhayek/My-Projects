#include "Accounts.h"

std::ostream &operator<<(std::ostream &os,const I_printable &obj){
    obj.print(os);
    return os;
}
I_printable::~I_printable(){

}
Account::~Account(){}
Saving_Account::~Saving_Account(){}

Checking_Account::~Checking_Account(){}

Trust_Account::~Trust_Account(){}
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
bool Account::withdraw(double amonut){
    if(balance-amonut>=0){
        balance-=amonut;
        return true;
    }
    return false;
}

Saving_Account::Saving_Account(std::string name,double balance,double intrected_ratel)
:Account{name,balance},intrected_ratel{intrected_ratel}{

}
bool Saving_Account::deposit(double amount){
    amount+=amount*(intrected_ratel/100);
    return Account::deposit(amount);
}
bool Saving_Account::withdraw(double amount){return Account::withdraw(amount);}

//Checking Account

Checking_Account::Checking_Account(std::string name,double balance)
:Account{name,balance}{

}
bool Checking_Account::deposit(double amount){
    return Account::deposit(amount);
}
bool Checking_Account::withdraw(double amount){
    amount=amount+1.5;
    return Account::withdraw(amount);
}

//Trust_Account

Trust_Account::Trust_Account(std::string name,double balance,double interested_rate)
:Account{name,balance},interested_rate{interested_rate}{
    allowed=3;
}

bool Trust_Account::deposit(double amount){
    if(amount>=5000) amount=amount*(interested_rate/100)+50.0;
    else amount=amount*(interested_rate/100);
    return Account::deposit(amount);
}
bool Trust_Account::withdraw(double amount){
    if(allowed==0||amount>=(balance*20)/100) return false;
    else{
        allowed--;
        return Account::withdraw(amount);
    }
}

void Checking_Account::print(std::ostream &os)const{
    os<<"Checking Account: "<<name<<" , "<<balance<<std::endl;
}

void Saving_Account::print(std::ostream &os)const{
    os<<"saving Account: "<<name<<" , "<<balance<<std::endl;
}

void Trust_Account::print(std::ostream &os)const{
    os<<"Checking Trust Account: "<<name<<" , "<<balance<<std::endl;
}

void Account::print(std::ostream &os)const{
}
