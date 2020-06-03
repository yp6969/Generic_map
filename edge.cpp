//
// Created by Pinhas on 14/05/2020.
//

#include "edge.h"

edge::edge(unsigned int id , unsigned int number_of_neighbors) : id(id) , number_of_neighbors(number_of_neighbors){
    neighbor = new unsigned int[number_of_neighbors+1];
    neighbor[0] = id; // neighbor[0] is me !
    carList = NULL;
    srand (time(NULL)); //******* maybe ot side of function
}

edge::~edge(){
    car* c = carList;
    delete [] neighbor;
    while(c){
        car* prev = c;
        c = c->next;
        delete prev;
    }
}


/**
 * adding car to the end of the car list
 * @param c
 */
void edge::addCar(car* c) {
    if(!carList){
        carList = c;
        return;
    }
    car* temp = carList;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = c;
}
/**
 * remove car from the top of the car list
 * @return the removal car
 */
car* edge::removeCar(){
    car* temp = carList;
    carList = carList->next;
    temp->next = NULL;
    return temp;
}

/**
 * @return the spesific junction to move to
 */
int edge::getProbability() {

    return neighbor[ rand() % (number_of_neighbors+1)];
}

/**
 * print the junction with the car list
 * @param out : ostream cout
 * @param junction
 * @return cout
 */
ostream& operator<<(ostream& out , edge& junction ){
    out<<junction.id<<":";
    car* head = junction.carList;
    while(head){
        out<<" ";
        out<<head->getId();
        head = head->next;
    }
    out<<endl;
    out.flush();
    return out;
}
