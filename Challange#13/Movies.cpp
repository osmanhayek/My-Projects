#include "Movies.h"
bool Movies::exist(Movie mv){
    for(Movie i:collection){
        if(i.name==mv.name) return 1;
    }
    return 0;
}
bool Movies::not_exist(std::string name){
    for(Movie i:collection){
        if(i.name==name)return 0;
    }
    return 1;
}

void Movies::add_movie(Movie mv){
    //checking if the movie is in the collection
    if(Movies::exist(mv))
    { std::cout<<"Please Enter a Movie that doesnt exist!"<<std::endl;}
    else{
       collection.push_back(mv);
    }
    
    
}
void Movies::whatced_plus(std::string name){
    if(Movies::not_exist(name)) 
    std::cout<<"Please Enter a Movie thats exist!"<<std::endl;
    else {
        for(int i=0;i<collection.size();i++){
            if(collection[i].name==name){
                collection[i].wathced++;
                break;
            }
        }
    }
}

void Movies::Display(){
    int j=1;
    for(Movie i:collection){
        std::cout<<j<<": Movies information is:"<<std::endl<<i.name<<
        std::endl<<i.rating<<std::endl<<i.wathced<<std::endl;
        j++;
    }
    
}