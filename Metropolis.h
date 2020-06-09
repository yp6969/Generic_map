//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_METROPOLIS_H
#define METROPOLIN_METROPOLIS_H
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "edge.h"
#include "vertice.h"
#include "Map.h"



class Metropolis {
private:
    const unsigned int size;
    unsigned int num_of_ticks;
    edge** junction;
    vertice** road;
    unsigned int num_of_roads;

public:
    Metropolis(double** graph , unsigned int size);
    ~Metropolis();

    void createCarList(ifstream& cars);
    void tick(); //iterate time skip
    void printPollution();
    void printCarList();



    /*
         * getters and setters
         */
    vertice* getRoad(int from , int to );
    const unsigned int getSize() const { return size;}
};


#endif //METROPOLIN_METROPOLIS_H
