//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_CAR_H
#define METROPOLIN_CAR_H
#include <iostream>
using namespace std;


class car {
private:
    const unsigned int id;
    unsigned int location;
    unsigned int num_of_move;

public:
    car* next;

    car(int id , int location);
    car(const car& c);
    /*
     * getters setters
     */
    const unsigned int getId() const {return id;}
    unsigned int getLocation() const {return location;}
    void setLocation(int location) { this->location = location;}
    unsigned int get_num_of_move() const{return num_of_move;}
    void operator++(int) {num_of_move++;}

};


#endif //METROPOLIN_CAR_H
