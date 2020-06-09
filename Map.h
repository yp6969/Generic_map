//
// Created by Pinhas on 05/06/2020.
//

#ifndef METROPOLIN_MAP_H
#define METROPOLIN_MAP_H

#include <shlobj.h>
#include <string>

/**
 * declare pair of element (K , V)
 * @tparam K
 * @tparam V
 */

template< typename T , typename U >
class Pair {
private:
    T key;
    U value;
public:
    Pair(): key() , value(0){}
    Pair(T key ,U value): key(key) , value(value){}
    ~Pair(){}

    Pair<T,U>& operator=(const Pair<T,U>& other ){
        if(this != &other) {
            key = other.key;
            value = other.value;
        }
        return *this ;
    }
    const T& getKey() const { return key;}
    const U& getValue() const { return value;}
    void setValue(const U& value ) { this->value = value ;}
    void setKey( const T& key = "") { this->key = key ;}
    //friend ostream& operator<<(ostream& out , Pair<K,V>& p);//{ out<<key<<" "<<value; return out;}
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
    Map() :size(0) , elem_array(0){}
    ~Map();

    /*
     * functionality
     */
    void add(const K& key , const V& value); // adding element to the map by order  key must be have " < " operator , elem must have  " = "
    const V* find(const K& key) const; // find the element by the key
    bool remove(const K& key); // delete the element by the key
    void destroy(); // destroy all the element
    void print() const;
    const unsigned int getSize() const {return size;}
};

#include "Map_impl.h"

#endif //METROPOLIN_MAP_H
