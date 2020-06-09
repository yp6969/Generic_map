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
};


#endif //METROPOLIN_LUXURYCAR_H
