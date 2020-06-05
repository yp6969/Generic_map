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
 * @param type of the car
 * @return the spesific junction to move to
 * depending on the type of the car
 */
int edge::getProbability(char type) {
    int random = rand() , index = 0 ;
    if(number_of_neighbors) {
        switch (type) {
            case 'F':
                index = random % (number_of_neighbors + 1);
                break;
            case 'L':
                if (rand() % 2) { index = (random % (number_of_neighbors)) + 1; }
                break;
            case 'M':
            case 'S':
                if (number_of_neighbors) { index = (random % (number_of_neighbors)) + 1; }
                break;
        }
    }
    return neighbor[index];
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
        out<<head->getType()<<head->getId();
        head = head->next;
    }
    out<<endl;
    out.flush();
    return out;
}
