#pragma once

#include<iostream>
int allowed;

class I_printable{
    friend std::ostream &operator<<(std::ostream &os,const I_printable &obj);
public:
    virtual void print(std::ostream &os) const=0;
    virtual ~I_printable();
};

class Account:public I_printable{
protected:
    std::string name;
    double balance;
public:
    Account(std::string name="Unnamed Account",double balance=0.0);
    virtual void print(std::ostream &os)const override;
    virtual bool deposit(double amount)=0;
    virtual bool withdraw(double amount)=0;
    virtual ~Account();
};
class Saving_Account:public Account{
protected:
    double intrected_ratel;
public:
    Saving_Account(std::string name="Unnamed Saving_Account",double balance=0.0,double intrected_ratel=0.0 );
    virtual void print(std::ostream &os) const override;
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual ~Saving_Account();

};

class Checking_Account:public Account{
public:
    Checking_Account(std::string name="Unnamed Chached_Account",double balance=0.0);
    virtual void print(std::ostream &os) const override;
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual ~Checking_Account();
};
class Trust_Account:public Account{
protected:
    double interested_rate;
public:
    Trust_Account(std::string name="Unnamed Trus_Account",double balance=0.0,double interested_rate=0.0);
    virtual void print(std::ostream &os) const override;
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;     
    virtual ~Trust_Account();
};










