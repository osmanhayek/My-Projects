#ifndef  _SECTION14_H_
#define _SECTION14_H_
#include<iostream>
class Mystring{
    char *str;
public:
    Mystring();
    Mystring(char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();
    //operator_overlodings
    Mystring &operator=(const Mystring &rhs);//deep copy operator
    Mystring &operator=(Mystring &&source);//move operator
    //these two must use when the class has a raw pointers otherwise c++ gonna do it automaticly
    Mystring operator-();
    bool operator==(const Mystring &rhs);
    bool operator!=(const Mystring &rhs);
    bool operator<(const Mystring &rhs);
    bool operator>(const Mystring &rhs);
    Mystring operator+(const Mystring &rhs);
    Mystring &operator+=(const Mystring &rhs);
    Mystring operator*(int num);
    Mystring &operator*=(int num);
    Mystring &operator++();//pre-increment
    Mystring operator++(int);//post-increment
    Mystring &operator--();
    Mystring operator--(int);
    friend std::ostream &operator<<(std::ostream &os,const Mystring &rhs);
    friend std::istream &operator>>(std::istream &is,Mystring &rhs);
    //other methods
    void display();


};





#endif