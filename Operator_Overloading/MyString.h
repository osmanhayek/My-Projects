#ifndef _MY_STRING_H_
#define _MY_STRING_H_

class MyString{
    char *str;
public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &source);//deep copy constructure
    ~MyString();
    MyString &operator=(const MyString &rhs);//copy assigment  like obj1=obj2;
    MyString (MyString &&source);//move constructure
    MyString &operator=(MyString &&rhs);//move assigment for R value like obj1="lol";or obj1=MyString{"LOL"};
    MyString operator-();//unary operator its include nothing 
    //MyString operator+(const MyString &rhs)const;
    bool operator==(const MyString &rhs) const;
    void display() const;
    int get_lenght() const;
    const char *get_str() const;
    friend MyString operator+(const MyString &lhs,const MyString &rhs);//im gonna re write this as a global function
    friend std::ostream &operator<<(std::ostream &os,const MyString &rhs);
    friend std::istream &operator>>(std::istream &os,MyString &rhs);
};


#endif