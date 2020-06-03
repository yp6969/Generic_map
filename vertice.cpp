//

#include "vertice.h"

//
// Created by Pinhas on 14/05/2020.

vertice::vertice(const unsigned int from, const unsigned int to, const double length ) :
from(from),
to(to),
length(length),
pollution(0) {}

const vertice vertice::operator++(int){
    vertice temp = *this;
    pollution += poll_const/length; // update the pollution
    return temp;
}


