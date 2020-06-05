//
// Created by Pinhas on 03/06/2020.
//

#ifndef METROPOLIN_SPORTCAR_H
#define METROPOLIN_SPORTCAR_H
#include "car.h"
#define SPORT_C 4

class sportCar : public virtual car {
public:
    sportCar(int id, char type , int location) : car(id, type , location , SPORT_C) {}

};


#endif //METROPOLIN_SPORTCAR_H
