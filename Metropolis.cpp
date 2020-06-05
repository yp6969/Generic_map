//
// Created by Pinhas on 14/05/2020.
//

#include "Metropolis.h"

Metropolis::Metropolis(double** _graph , unsigned int size) : size(size) , num_of_ticks(0){
    junction = new edge*[size];

    int cnt_roads = 0 , cnt_neighbors = 0;
    /*
     * create the junctions
     * count number of edges
     */
    for(unsigned int i=0 ; i<size ; i++) {
        for (unsigned int j = 0; j < size; j++) {
            if (_graph[i][j] != 0){
                cnt_roads++;
                cnt_neighbors++;
            }
        }
        /*
         * init junctions
         */
        junction[i] = new edge(i+1 , cnt_neighbors);
        cnt_neighbors = 0;
    }

    road = new vertice*[cnt_roads];
    num_of_roads = cnt_roads;
    cnt_neighbors = 0;
    cnt_roads = 0;

    /*
     * init roads
     * init neighbors
     */
    for(unsigned int i=0 ; i<size ; i++){
        for(unsigned int j=0 ; j<size ; j++){
            if(_graph[i][j] != 0){
                road[cnt_roads++] = new vertice(i+1 , j+1 , _graph[i][j] );
                junction[i]->setNeighbor( ++cnt_neighbors , j+1);
            }
        }
        cnt_neighbors = 0;
    }
}

/**
 * distractor
 */
Metropolis::~Metropolis() {
    for(unsigned int i=0 ; i<size ; i++)
        delete junction[i];
    delete [] junction;

    for(unsigned int i=0 ; i<num_of_roads ; i++)
        delete road[i];
    delete [] road;
}

/**
 * create car list for each junction
 * @param cars
 * @return
 */
void Metropolis::createCarList(ifstream& cars){
    string s;
    int id;
    char type;
    for (unsigned int i = 0; i < size ; ++i) {
        getline(cars , s);
        stringstream sso(s);
        sso>>s; // junk
        //cout<<s<<endl; // print the function id like 1: ....(cars)...
        while(sso>>type && sso>>id){ // insert the car id into varlible
            switch (type) {
                case 'F':
                    junction[i]->addCar(new FamilyCar(id, type , junction[i]->getId() )); // add the car
                    break;
                case 'S':
                    junction[i]->addCar(new sportCar(id, type , junction[i]->getId() )); // add the car
                    break;
                case 'L':
                    junction[i]->addCar(new LuxuryCar(id, type , junction[i]->getId() )); // add the car
                    break;
                case 'M':
                    junction[i]->addCar(new Maserati(id, type , junction[i]->getId() )); // add the car
                    break;
            }
        }
        //cout<<endl;
    }
}

/**
 * stimulate the car exchange with in one unit of time
 */
void Metropolis::tick(){
    int next_id;
    vertice* t_road;
    for(unsigned int i=0 ; i<size ; i++){
        car* head = junction[i]->getCarList();
        while(head && head->get_num_of_move() == num_of_ticks){
            next_id = junction[i]->getProbability(head->getType());
            junction[next_id-1]->addCar(junction[i]->removeCar());
            (*head)++; // update the car to know it moved
            head->setLocation(next_id);
            t_road = getRoad(i+1 , next_id);
            if(t_road) (*t_road) += head->getPoll_const(); // update the pollution
            head = junction[i]->getCarList();
        }
    }
    num_of_ticks++;
}

/**
 * print the pollution metrix
 */
void Metropolis::printPollution(){
    double poll;
    vertice* v;
    for(unsigned int i=0 ; i<size ; i++){
        for(unsigned int j=0 ; j<size ; j++){
            if( (v = getRoad(i+1,j+1)) != NULL ) {
                poll = v->getPollution();
                cout << round(100 * poll) / 100;
            }
            else cout<<"0";
            cout<<(j < (size-1) ? " ":"");
        }
        cout<<endl;
    }
}

/**
 * print the information about the cars in the junctions
 */
void Metropolis::printCarList(){
    for(unsigned int i=0 ; i<size ; i++) cout<<(*junction[i]);
    cout<<endl;
}


/**
 *
 * @param from
 * @param to
 * @return the road [from][to]
 */
vertice* Metropolis::getRoad(int from , int to ){
    for(unsigned int i=0 ; i<num_of_roads ; i++)
        if((unsigned)from == road[i]->getFrom() && (unsigned)to == road[i]->getTo()) return road[i];
    return NULL;
}

