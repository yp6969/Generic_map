//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_CAR_H
#define METROPOLIN_CAR_H
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;


class car {
private:
    const unsigned int id;
    const unsigned char type;
    unsigned int location;
    const unsigned int poll_const;
    unsigned int num_of_move;

public:
    car* next;
    car(int id , char type,  int location , int poll_const);
    car(const car& c);
    virtual ~car();
    /*
     * getters setters
     */
    const unsigned int getId() const {return id;}
    const unsigned char getType() const {return type;}
    unsigned int getLocation() const {return location;}
    void setLocation(int location) { this->location = location;}
    unsigned int getPoll_const() const { return poll_const;}
    unsigned int get_num_of_move() const{return num_of_move;}
    void operator++(int) {num_of_move++;}
    virtual int prob(const int& number_of_neighbors) const = 0;

};


#endif //METROPOLIN_CAR_H
