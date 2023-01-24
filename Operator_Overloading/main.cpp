#include<iostream>
#include "MyString.cpp"
using namespace std;
int main(){
    MyString empty;
    MyString osman{"osman"};
    MyString cpy{osman};//thats not assigment!
    cpy="lol";
    //cpy=empty;
    cout<<cpy.get_str();
    


}
//unary operators are (++,--,-,!)
//bitwise operators are (+,-,!=,==)