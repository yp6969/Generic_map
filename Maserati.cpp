//
// Created by Pinhas on 03/06/2020.
//

#include "Maserati.h"

Maserati::Maserati(int id , char type , int location)
    : car(id, type,  location , LUXURY_C) , sportCar(id , type , location), LuxuryCar(id , type , location) {}

Maserati::~Maserati() {}



