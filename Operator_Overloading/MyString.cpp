#include<cstring>
#include<iostream>
#include "MyString.h"

MyString::MyString()
:str{nullptr}{
    str=new char[1];
    *str='\0';
}
MyString::MyString(const char *s)
:str{nullptr}{
    if(s==nullptr){
        str=new char[1];
        *str='\0';
    }
    else{
        str=new char[std::strlen(s)+1];
        std::strcpy(str,s);
        
    }
}
MyString::MyString(const MyString &source):str{nullptr}{
   str=new char[std::strlen(source.str)+1];
   std::strcpy(str,source.str); 
}

MyString::~MyString(){
    delete[] str;
}

//copy assigment
MyString &MyString::operator=(const MyString &rhs){
    if(this==&rhs){
        return *this;
    }
    delete []str;
    str=new char[std::strlen(rhs.str)+1];
    strcpy(str,rhs.str);
    return *this;
}
void MyString::display() const{
    std::cout<<str<<":"<<get_lenght()<<std::endl;
}
int MyString::get_lenght() const{
    return (std::strlen(str));
}
const char *MyString::get_str ()const{
    return str;
}
//copy constructure
MyString::MyString(MyString &&source)
:str{source.str}{
    source.str=nullptr;
}
//Assigment constructure
MyString &MyString::operator=(MyString &&rhs){
    if(this==&rhs)return *this;
    delete []str;
    str=rhs.str;
    rhs.str=nullptr;
    return *this;
}
bool MyString::operator==(const MyString &rhs)const{
    if(std::strcmp(this->str,rhs.str)==0)return 1;
    return 0;//strcmp if the lenght are the same he returns 0
}
MyString MyString::operator-(){
   char *result=new char[std::strlen(this->str)+1];
    std::strcpy(result,this->str);
    for(size_t i=0;i<std::strlen(result);i++){
        result[i]=std::tolower(result[i]);
    }
    MyString result1{result};
    delete [] result;
    return result1;
}
// MyString MyString::operator+(const MyString &rhs) const{
//     char *result=new char
//     [std::strlen(this->str)+std::strlen(rhs.str)+1];
//     std::strcpy(result,this->str);
//     std::strcat(result,rhs.str);
//     MyString result1{result};
//     delete[] result;
//     return result1;
// }
MyString operator+(const MyString &lhs,const MyString &rhs){
    char *result=new char [std::strlen(lhs.str)+std::strlen(rhs.str)+1];
    std::strcmp(result,lhs.str);
    std::strcat(result,rhs.str);
    MyString result1{result};
    delete []result;
    return result1;
}//i can use obj="osm"+obj2 now!
//overloded insertion
std::ostream &operator<<(std::ostream &os,const MyString &rhs){
    os<<rhs.str;
    return os;
}
std::istream &operator>>(std::istream &os,MyString &rhs){
    char *result=new char [1000];
    os>>result;
    rhs=MyString{result};
    delete []result;
    return os;
}