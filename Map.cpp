//
// Created by Pinhas on 05/06/2020.
//

#include "Map.h"


Map::~Map(){
    destroy();
    delete [] junction;
}

/*
 * functionality
 */
void Map::add(unsigned int key , edge* junc);
edge* Map::find(unsigned int key) const;
bool Map::remove(unsigned int key);
void Map::destroy();
void Map::print() const;
const unsigned int Map::getSize() const;

edge* operator[](unsigned int key);