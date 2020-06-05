//
// Created by Pinhas on 05/06/2020.
//

#ifndef METROPOLIN_MAP_H
#define METROPOLIN_MAP_H

#include "edge.h"

/**
 * Generic map
 *
 * hold element by (key , value) by order
 */

class Map {
private:
    unsigned int size;
    edge** junction;
public:
    Map(unsigned int size) :size(size) { junction = new edge*[size] ;}
    ~Map();

    /*
     * functionality
     */
    void add(unsigned int key , edge* junc); // adding element to the map by order  key must be have " < " operator , elem must have  " = "
    edge* find(unsigned int key) const; // find the element by the key
    bool remove(unsigned int key); // delete the element by the key
    void destroy(); // destroy all the element
    void print() const;
    const unsigned int getSize() const;

    edge* operator[](unsigned int key);


};


#endif //METROPOLIN_MAP_H
