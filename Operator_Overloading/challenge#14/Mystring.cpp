#include<cstring>
#include<iostream>
#include "Mystring.h"

Mystring::Mystring():str{nullptr}{
    this->str=new char[1];
    *str='\0';
}
Mystring::Mystring(char *s):str{nullptr}{
    if(s==nullptr){
        str=new char[1];
        *str='\0';
    }
    else{
        str=new char[std::strlen(s)+1];
        std::strcpy(str,s);
        
    }
}
//deep copy
Mystring::Mystring(const Mystring &source):str{nullptr}{
    str=new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);

}
//move cons.
Mystring::Mystring(Mystring &&source):str{source.str}{
    source.str=nullptr;
}
//dest
Mystring::~Mystring(){
    delete []str;
}
//assigment copy
Mystring &Mystring::operator=(const Mystring &rhs){
    if(this==&rhs){
        return *this;
    }
    delete []str;
    str=new char[std::strlen(rhs.str)+1];
    strcpy(str,rhs.str);
    return *this;
}
//assigment move
Mystring &Mystring::operator=(Mystring &&rhs){
    if(this==&rhs) return *this;
    delete[]this->str;
    str=rhs.str;
    rhs.str=nullptr;
    return *this;
}
// - operator
Mystring Mystring::operator-(){
    char *result=new char[std::strlen(this->str)+1];
    std::strcpy(result,this->str);
    for(size_t i=0;i<std::strlen(result);i++){
        result[i]=std::tolower(result[i]);
    }
    Mystring son{result};
    delete []result;
    return son;

}
//boolean functions
bool Mystring::operator==(const Mystring &rhs){
    if(std::strcmp(this->str,rhs.str)==0)return 1;
    return 0;
}
bool Mystring::operator!=(const Mystring &rhs){
    if(std::strcmp(this->str,rhs.str)!=0)return 1;
    return 0;
}
bool Mystring::operator<(const Mystring &rhs){
    if(this->str[0]<rhs.str[0])return 1;
    return 0;
}
bool Mystring::operator>(const Mystring &rhs){
    if(this->str[0]>rhs.str[0])return 1;
    return 0;
}
Mystring Mystring::operator+(const Mystring &rhs){//this+obj2 olacak
    char *result=new char[std::strlen(this->str)+std::strlen(rhs.str)+1];
    std::strcpy(result,this->str);
    std::strcat(result,rhs.str);
    Mystring son{result};
    delete []result;
    return son;
}
Mystring &Mystring::operator+=(const Mystring &rhs){//this+=obj i son=this+obj "abc"+"abcd"="abcabcd"
    char *result=new char[std::strlen(this->str)+std::strlen(rhs.str)+1];
    std::strcpy(result,this->str);
    std::strcat(result,rhs.str);
    *this=result;
    delete[]result;
    return *this;
}
Mystring Mystring::operator*(int num){
    char *result=new char[std::strlen(this->str)*num+1];
    std::strcpy(result,this->str);
    for(int i=1;i<num;i++){
        std::strcat(result,this->str);
    }
    Mystring son{result};
    delete []result;
    return son;
}
Mystring &Mystring::operator*=(int num){//obj1*=5 obj1=obj1*5
    *this=*this*5;
    return *this;
}//pre-increment
Mystring &Mystring::operator++(){
    for(size_t i=0;i<std::strlen(this->str);i++){
        this->str[i]=std::toupper(this->str[i]);
    }
    return *this;
}
//post-increment
Mystring Mystring::operator++(int){
    Mystring temp(*this);
    operator++();
    return temp;
}
Mystring &Mystring::operator--(){
    for(size_t i=0;i<std::strlen(this->str);i++){
        this->str[i]=std::tolower(this->str[i]);
    }
    return *this;
}
Mystring Mystring::operator--(int){
    Mystring temp(*this);
    operator--();
    return temp;
}
std::ostream &operator<<(std::ostream &os,const Mystring &rhs){
    os<<rhs.str;
    return os;
}
std::istream &operator>>(std::istream &is,Mystring &rhs){
    char *result=new char[1000];
    is>>result;
    rhs=Mystring{result};
    delete []result;
    return is;
}