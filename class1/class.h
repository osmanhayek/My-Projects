#ifndef CLASS_H_
#define CLASS_H_
#include <string>
#include<iostream>
class Player{
    static int player_number;
    int xp;
    int health;
    std::string name;
public:
    Player(std::string name="None",int health=0,int xp=0);
    //copy constructure 
    Player(const Player &source);
    void set_name(std::string);
    void set_int(int,int);
    void get_data();
    static int get_number();
    ~Player();
    

};
class Shallow_Copy{
    int *next;
    Shallow_Copy(int d=0);
    Shallow_Copy(const Shallow_Copy &source);
    ~Shallow_Copy();
};
class Deep_Copy{
    int *next;
    Deep_Copy(int d=0);
    Deep_Copy(const Deep_Copy &source);

    ~Deep_Copy();
};
class Move{
    int *data;
public:
    Move(int d=0);
    Move(const Move &source);
    Move(Move &&source);//Move Constructure 
    ~Move();
};

#endif