//
// Created by Pinhas on 03/06/2020.
//

#ifndef METROPOLIN_LUXURYCAR_H
#define METROPOLIN_LUXURYCAR_H
#include "car.h"
#define LUXURY_C 3

class LuxuryCar : public virtual car{

public:
    LuxuryCar(int id, char type , int location) : car(id, type , location , LUXURY_C) {}
    virtual int prob(const int& number_of_neighbors) const { if (rand() % 2) { return (rand() % (number_of_neighbors)) + 1;} else return 0;}
};


#endif //METROPOLIN_LUXURYCAR_H
