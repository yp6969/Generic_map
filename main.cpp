#include <string>
#include "Metropolis.h"

void InputError();
void createMatrix(ifstream& matrix ,  double** &_graph , unsigned int& size);

int main(int argc , char* argv[]) {

    /**
     * open the files .......
     */
    ifstream matrix(argv[1] );
    ifstream cars(argv[2]);
    if(!matrix || !cars){
        InputError();
    }

    /**
     * check the input ......
     */
    unsigned int size = 9;

    double** _graph = new double*[size];
    for (unsigned int k = 0; k < size; ++k) {
        _graph[k] = new double [size];
    }

    createMatrix(matrix , _graph , size );
    Metropolis* metropolis = new Metropolis( _graph , size);
    metropolis->createCarList(cars);

    int time = 20;
    //cout<<"Please enter C"<<endl;
    //cin>>poll_const;
    //cout<<"Please enter time"<<endl;
    //cin>>time;
    //poll_const = 7;
    //time = 0;

    for (int i = 0 ; i < time ; i++ ) {
        metropolis->tick();
    }

    metropolis->printPollution();
    metropolis->printCarList();
    delete metropolis;
    for (unsigned int j = 0; j < size; ++j) {
        delete [] _graph[j];
    }
    delete [] _graph;

    return 0;
}

/**
 * create the graph
 * @param matrix
 * @param _graph
 * @param size
 * @return
 */
void createMatrix(ifstream& matrix ,  double** &_graph , unsigned int& size){
    string s;
    getline(matrix , s);
    for (unsigned int i = 0; i < size; ++i) {
        for (unsigned int j = 0; j < size; ++j) {
            matrix>>_graph[i][j];
        }
    }
}

/**
 * exit if the input is not correct
 */
void InputError(){
    cerr<<"Error: Invalid input."<<endl;
    exit(0);
}

