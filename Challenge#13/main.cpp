#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Movie{
    friend class Movies;
    string name;
    string rating;//G,PG,PG-13,R
    int watched;
    public:
        Movie(string name,string rating,int watched):name{name},rating{rating},watched{watched}{}
        Movie(const Movie &source):Movie(source.name,source.rating,source.watched){}
        ~Movie(){}
        string get_name()const{
            return name;
        }
        void set_name(string name){this->name=name;}
        string get_rating()const{return rating;}
        void set_rating(string rating){this->rating=rating;}
        int get_watched()const{return watched;}
        void set_watched(int watched){this->watched=watched;}
        void Display()const{
            cout<<"name: "<<name<<" Rating: "<<rating<<"Watched: "<<watched<<" time"<<endl;
        }


        
};
class Movies{
    vector <Movie> my_list;
    public:
    Movies();
    ~Movies();
    bool add_movie(string name,string rating,int watched){
       
    }
        

};





int main(){

}