#include<iostream>
#include "Accounts.cpp"
#include <vector>
using namespace std;
void display(const std::vector<Account *> &collection){
    for(auto acc:collection){
        std::cout<<*acc;
    }
}

void deposit(std::vector<Account *> &collection,double amount){
    for(auto acc:collection){
       if(acc->deposit(amount)){
            std::cout<<"deposited "<<amount<<"for "<<*acc;
       } 
       else{
        std::cout<<"filed for"<<*acc;//its filed when the amount is negative
       }
    }
}

void withdraw(std::vector<Account *> &collection,double amount){
    for(auto acc:collection){
        if(acc->withdraw(amount)){
            std::cout<<"withdrawed from "<<*acc;
        }
        else{
            std::cout<<"feiled withdrawed from "<<*acc;
        }
    }
}
int main(){

    Checking_Account frank {"Frank",5000};
    cout<<frank;

    Account *trust=new Trust_Account("james");
    cout<<*trust;

    Account *p1=new Checking_Account("osman",10000);
    Account *p2=new Saving_Account("osman1",1000);
    Account *p3=new Trust_Account("osman2");    
    
    vector<Account *> acc{p1,p2,p3};

    display(acc);
    cout<<endl;
    deposit(acc,1000);
    cout<<endl;
    withdraw(acc,2000);

    cout<<endl<<endl;

    display(acc);

    delete p1;
    delete p2;
    delete p3;
    delete trust;

    return 0;
}
