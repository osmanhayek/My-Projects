#include<iostream>
#include<string>
#include "class.cpp"
using namespace std;
void get_player(Player p){
    p.get_data();
}
void get_num_p(){
    cout<<Player::get_number()<<endl;
}
int main(){
    get_num_p();
    
    Player ob1,ob2,ob3{"osman"};
    get_num_p();
    return 0;
}
