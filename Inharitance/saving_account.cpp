#include "saving_account.h"

Savings_Account::Savings_Account(std::string name,double balance,double int_rate)
:Account(name,balance),int_rate{int_rate}{

}
bool Savings_Account::deposit(double amount){
    amount+=amount*(int_rate/100);
    return Account::deposit(amount);
}
std::ostream &operator<<(std::ostream &os,const Savings_Account &saving_account){
    os<<"Saving_Account "<<saving_account.name<<": "<<saving_account.balance<<", "<<saving_account.int_rate<<"%";
    return os;
}
