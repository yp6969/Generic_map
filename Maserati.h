//
// Created by Pinhas on 03/06/2020.
//

#ifndef METROPOLIN_MASERATI_H
#define METROPOLIN_MASERATI_H
#include "sportCar.h"
#include "LuxuryCar.h"


class Maserati : public sportCar , public LuxuryCar{
public:
    Maserati(int id , char type , int location);
    ~Maserati();

};


#endif //METROPOLIN_MASERATI_H
