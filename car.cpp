//
// Created by Pinhas on 14/05/2020.
//

#include "car.h"

car::car(int id , char type , int location , int poll_const)
    : id(id) , type(type), location(location), poll_const(poll_const) , num_of_move(0) , next(NULL){
    srand (time(NULL));
}

car::car(const car& c) : id(c.id) , type(c.type), location(c.location) , poll_const(c.poll_const) , num_of_move(c.num_of_move) , next(NULL) {}

car::~car() {}
