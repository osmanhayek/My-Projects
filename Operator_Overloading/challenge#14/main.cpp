#include<iostream>
#include "Mystring.cpp"
using namespace std;
int main(){
    cout<<boolalpha<<endl;
    char q[]="frank";
    Mystring a{q};
    Mystring b{"frank"};
    cout<<(a==b)<<endl;
    cout<<(a!=b)<<endl;

    b="george";
    cout<<(a==b)<<endl;
    cout<<(a!=b)<<endl;
    cout<<(a<b)<<endl;
    cout<<(a>b)<<endl;

    Mystring s1 {"FRANK"};
   // s1=-s1;
    cout<<s1<<endl;

    s1=(s1+"****");
    cout<<s1<<endl;

    s1+="_____";
    cout<<s1<<endl;

    Mystring s2{"12345"};
    s1=s2*3;
    cout<<s1<<endl;

    Mystring s3{"abcdef"};
    s3*=5;
    cout<<s3<<endl;

    Mystring repeat_string;
    int repeat_time;
    cout<<"Enter a string to repeat"<<endl;
    cin>>repeat_string;
    cout<<"number: ";
    cin>>repeat_time;
    repeat_string*=repeat_time;
    cout<<"result is: "<<repeat_string<<endl;

    cout<<(repeat_string*12)<<endl;

    repeat_string="RepeatMe";
    repeat_string+=(repeat_string+repeat_string+repeat_string);
    cout<<repeat_string<<endl;
    Mystring s="Frank";
    ++s;
    cout<<s<<endl;

    s=-s;
    cout<<s<<endl;
    Mystring result1;
    result1=++s;
    cout<<s<<endl;
    cout<<result1<<endl;

    s="Frank";
    s++;
    cout<<s<<endl;

    s=-s;
    cout<<s<<endl;
    result1=s++;
    cout<<s<<endl;
    cout<<result1<<endl;
    return 0;
}