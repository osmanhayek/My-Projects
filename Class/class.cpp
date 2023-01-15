//l value = int a=20; a is an l-value! 
//R-value 10 ,20 ,30 bunlar R-value! 
//int a=10;
//int &b=a; a is a l-value b is a referance for l-value!
//b=100;
//int &&b=100;//100 is an R-value b is referance to 100

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Player{
private:    
    static int Active_Players;
    std::string name;
    int health;
    int xp;
public:
    Player(string name="None",int health=0,int xp=0):name{name},health{health},xp{xp}{
        Active_Players++;
    }
    string get_name()const {return name;}
    void set_name(string name){this->name=name;}

    int get_health()const{return health;}
    int get_xp()const{return xp;}
    Player (const Player &source):
        Player{source.name,source.health,source.xp}
    {
        cout<<"The Constructure"+name<<"got copied!"<<endl;
    }
    static int get_Active(){
        return Active_Players;
    }
    ~Player(){
        --Active_Players;
    }
};
class Deep{
private:
    int *data;
public:
    void set_val(int d){*data=d;}
    Deep(int d=0){
        data=new int;
        *data=d;
    }
    Deep(const Deep &source):
        Deep{*source.data}
    {
        cout<<"done for "<<source.data<<endl;

    }
    ~Deep(){
        delete data;
        cout<<"delete"<<endl;
    }        
};
class Move{
    private:
        int *data;
    public:
        void set_data(int d){*data=d;}
        int get_data(){return *data;}
        //constructur
        Move(int d=0){
            data =new int;
            *data=d;
        }
        //Deep copy constructur
        Move(const Move &source):Move{*source.data}{
            cout<<"make"<<endl;
        }
        //move copy Constructur
        Move(Move &&source) noexcept :Move{*source.data}{
            source.data=nullptr;
            cout<<"moved"<<endl;
        }
        //destructor
        ~Move(){
            if(data!=nullptr) cout<<"LOL "<<data<<endl;
            else cout<<"LOL for null"<<endl;
            delete data;
        }    
};
int Player::Active_Players{0};
void Diplay(Player P){
    cout<<"name "<<P.get_name()<<endl;
}


int main(){
    //Player empty;
    //Player osman{"osman",100};
    //Player Lol{"Lol",100,10};
    //Diplay(empty);
    //Diplay(osman);
    //Diplay(Lol);
    //Deep ob1;
    //Deep ob2{1000};
    //Deep ob3{ob2};

    //ob1.set_val(100);
    //vector<Move> mv;//lets create a list that takes objects of move class!
    //mv.push_back(Move{10});// the Move{10} is a R-value object because it has no name
    //mv.push_back(Move{20});
    //mv.push_back(Move{20});
    //Player const obj("osman");
    Player a{"isnab",10,100};
    cout<<Player::get_Active();
    
    
}