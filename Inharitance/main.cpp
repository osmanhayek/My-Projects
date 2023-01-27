#include<iostream>
#include<vector>
#include"Account.cpp"
#include "saving_account.cpp"

using namespace std;
void display(const vector<Account> &account){
    cout<<"=== Accounts =================="<<endl;
    for(auto &acc:account){
        cout<<acc<<endl;
    }
}
void deposit(vector<Account> &account,double amount){//para yatirma
    cout<<"=== Deposting for Accounts=================="<<endl;
    for(auto acc:account){
        if(acc.deposit(amount)){
            cout<<"Deposited "<<amount<<" to "<<acc<<endl;
        }
        else{
            cout<<"Failed Deposit of "<<amount<<" to"<<acc<<endl;
        }
    }
}
void withdraw(vector<Account> &account,double amount){//para cekmek
    cout<<"===Withdraw for Accounts========================"<<endl;
    for(auto acc:account){
        if(acc.withdraw(amount)){
            cout<<"Withdrawed "<<amount<<" from "<<acc<<endl;
        }
        else{
            cout<<"Failed withdrawed of "<<amount<<" from"<<acc<<endl;
        }
    }
}


//for saving_account class!
void display(const vector<Savings_Account> &account){
    cout<<"=== Accounts =================="<<endl;
    for(const auto &acc:account){
        cout<<acc<<endl;
    }
}
void deposit(vector<Savings_Account> &account,double amount){//para yatirma
    cout<<"=== Deposting for Accounts=================="<<endl;
    for(auto &acc:account){
        if(acc.deposit(amount)){
            cout<<"Deposited "<<amount<<" to "<<acc<<endl;
        }
        else{
            cout<<"Failed Deposit of "<<amount<<" to"<<acc<<endl;
        }
    }
}
void withdraw(vector<Savings_Account> &account,double amount){//para cekmek
    cout<<"===Withdraw for Accounts========================"<<endl;
    for(auto &acc:account){
        if(acc.withdraw(amount)){
            cout<<"Withdrawed "<<amount<<" from "<<acc<<endl;
        }
        else{
            cout<<"Failed withdrawed of "<<amount<<" from"<<acc<<endl;
        }
    }
}


int main(){
    // vector<Account> acc;
    // acc.push_back(Account{});
    // acc.push_back(Account{"osman"});
    // acc.push_back(Account{"osman1",1300});
    // acc.push_back(Account{"caner",2000});
    // acc.push_back(Savings_Account{"osman",3000,3.5});

    // display(acc);
    // cout<<endl;
    // deposit(acc,10);
    // cout<<endl;
    // withdraw(acc,1500);

    // vector<Savings_Account> acc1;
    // acc1.push_back(Savings_Account{"osman",2000});
    // acc1.push_back(Savings_Account{"osman1",4000,50});
    // acc1.push_back(Savings_Account{"osman2",1000,100});
    // display(acc1);
    // cout<<endl;
    // deposit(acc1,50);
    // cout<<endl;
    // withdraw(acc1,2000);
    Checking_Account acc,acc1{"osman",1000},acc2{"osman1",4000.69}; 
    acc.withdraw(1000);
    acc1.withdraw(1000);
    acc2.withdraw(1000);
    cout<<acc;cout<<acc1;cout<<acc2;

    Trust_Account t1,t2{"osman",4000},t3{"caner",4500,50.0};
    cout<<t1<<t2<<t3;
    //t3.deposit(6000);
    t3.withdraw(2000);
    cout<<t3;
    t3.withdraw(800);
    cout<<t3;
    t3.withdraw(700);
    cout<<t3;
    t3.withdraw(550);
    cout<<t3;
    t3.withdraw(50);
    cout<<t3;
    
    

}