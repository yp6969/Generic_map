//
// Created by Pinhas on 03/06/2020.
//

#ifndef METROPOLIN_SPORTCAR_H
#define METROPOLIN_SPORTCAR_H
#include "car.h"
#define SPORT_C 4

class sportCar : public virtual car {
public:
    sportCar(const string& name , int location) : car( name , location , SPORT_C) {}
    virtual int prob(const int& number_of_neighbors) const { return (rand() % (number_of_neighbors)) + 1;}

};


#endif //METROPOLIN_SPORTCAR_H
