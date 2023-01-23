#ifndef _MOVIE_H_
#define _MOVIE_H_
#include<iostream>
class Movie{
    std::string name;
    std::string rating;//G,PG,PG-13,R
    int wathced;
public:
    Movie(std::string name,std::string rating,int watched);
    friend class Movies;
}; 






#endif