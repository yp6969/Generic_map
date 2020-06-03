//
// Created by Pinhas on 14/05/2020.
//

#include "car.h"

car::car(int id , int location) : id(id) , location(location) , num_of_move(0) , next(NULL){}

car::car(const car& c) : id(c.id) , location(c.location) , num_of_move(c.num_of_move) , next(NULL) {}