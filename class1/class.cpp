
#include "class.h"
Player::Player(std::string name,int health,int xp)
:name{name},health{health},xp{xp}{
    player_number++;
}
Player::~Player(){
    --player_number;
}
void Player::set_name(std::string name){
    this->name=name;
}
void Player::set_int(int health,int xp){
    this->health=health;
    this->xp=xp;
}
void Player::get_data(){
    std::cout<<"name "<<name<<"\n"<<"xp "<<xp<<"\n"<<"health "<<health<<"\n";
}
Player::Player(const Player &source)
:name{source.name},health{source.health},xp{source.xp}{
    std::cout<<"LOL";
}
int Player::player_number=0;
int Player::get_number(){
    return player_number;
}
Shallow_Copy::Shallow_Copy(int d){
    next=new int;
    *next=d;
}
Shallow_Copy::Shallow_Copy(const Shallow_Copy &source):next{source.next}{//shallow copy

}
Shallow_Copy::~Shallow_Copy(){
    delete next;
    std::cout<<"Called";
}

Deep_Copy::Deep_Copy(int d){
    next=new int;
    *next=d;
}
Deep_Copy::Deep_Copy(const Deep_Copy &source){//deep copy
    next=new int;
    *next=*source.next;
    std::cout<<"Deep Copy!"<<std::endl;
}

Move::Move(int d){
    data=new int;
    *data=d;
}
Move::Move(const Move &source){//deep copy
    data=new int;
    *data=*source.data;
}
Move::Move(Move &&source)//when we call an R value this construcure gonna be called an its way better then the deep copy con.
:data{source.data}{//move constructure!
    source.data=nullptr;
}
Move::~Move(){
    delete data;
}
