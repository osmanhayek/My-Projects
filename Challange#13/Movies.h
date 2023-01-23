#ifndef _MOVIES_H_
#define _MOVIES_H_
#include<iostream>
#include<vector>
#include "Movie.h"
class Movies{
    std::vector<Movie> collection;
public:
    void add_movie(Movie mv);
    void whatced_plus(std::string name);
    void Display();
    bool exist(Movie mv);
    bool not_exist(std::string name);

    
};



#endif