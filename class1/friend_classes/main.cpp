#include<iostream>
#include "class1.cpp"
#include "class2.cpp"

int main(){
    class1 cl{42,420,1};
    
    class2 the;
    the.get_class1_members(cl);
    
    return 0;
}