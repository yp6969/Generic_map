//
// Created by Pinhas on 03/06/2020.
//

#include "Maserati.h"

Maserati::Maserati(const string& name , int location)
    : car(name,  location , LUXURY_C) , sportCar(name, location), LuxuryCar(name, location) {}

Maserati::~Maserati() {}



