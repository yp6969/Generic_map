//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_VERTICE_H
#define METROPOLIN_VERTICE_H
#include <cstdio>
#include <iostream>

extern double poll_const;

class vertice {
private:
    const unsigned int from;
    const unsigned int to;
    const double length;
    double pollution;

public:

    vertice(const unsigned int from, const unsigned int to, const double length);


    const vertice operator++(int);


    /*
     * getters and setters
     */
    const unsigned int getFrom() const {return from;}

    const unsigned int getTo() const {return to;}

    const double getLength() const {return length;}

    double getPollution() const {return pollution;}

};


#endif //METROPOLIN_VERTICE_H
