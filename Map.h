//
// Created by Pinhas on 05/06/2020.
//

#ifndef METROPOLIN_MAP_H
#define METROPOLIN_MAP_H

#include <shlobj.h>
#include "edge.h"

/**
 * declare pair of element (K , V)
 * @tparam K
 * @tparam V
 */

template< typename K , typename V >
class Pair {
private:
    K key;
    V value;
public:
    Pair(): key(NULL) , value(NULL){}
    Pair(K key ,V value): key(key) , value(value){}
    ~Pair(){}

    Pair<K,V>& operator=(const Pair<K,V>& other ){ key = other.key ; value = other.value ; return *this ;}
    K& getKey() const { return key;}
    K& getValue() const { return value;}
    void setValue(V& value) { this->value = value ;}
    ostream& operator<<(ostream& out){ out<<key<<" "<<value; return out;}
};

/**
 * Generic map
 *
 * hold element by (key , value) by order
 */

template< typename K , typename V >
class Map {
private:
    unsigned int size;
    Pair<K,V> *elem_array;
public:
    Map() :size(0) , elem_array(NULL){}
    ~Map();

    /*
     * functionality
     */
    void add(K key , V value); // adding element to the map by order  key must be have " < " operator , elem must have  " = "
    V* find(K key) const; // find the element by the key
    bool remove(K key); // delete the element by the key
    void destroy(); // destroy all the element
    void print() const;
    const unsigned int getSize() const {return size;}
};

#include "Map_impl.h"

#endif //METROPOLIN_MAP_H
