//
// Created by Pinhas on 03/06/2020.
//

#ifndef METROPOLIN_FAMILYCAR_H
#define METROPOLIN_FAMILYCAR_H
#include "car.h"
#define FAMILY_C 2

class FamilyCar : public car {
public:
    FamilyCar(int id, char type , int location) : car(id, type , location , FAMILY_C) {}
    virtual int prob(const int& number_of_neighbors) const { return rand() % (number_of_neighbors + 1);}

};


#endif //METROPOLIN_FAMILYCAR_H
