//
// Created by Pinhas on 08/06/2020.
//

#ifndef METROPOLIN_MAP_IMPL_H
#define METROPOLIN_MAP_IMPL_H


//template<typename K , typename V>
//ostream& operator<<(ostream& out , Pair<K,V>& p){
//    out<<p.key<<" "<<p.value;
//    return out;
//}


/**
 * add element to the array
 * if the key is already exist override it
 * else create size+1 array and put it sortly
 *
 * @tparam K
 * @tparam V
 * @param key
 * @param value
 */
template<typename K , typename V>
void Map<K,V>::add(const K& key ,const V& value) {
    for (int i = 0; i < size ; i++) {
        if(elem_array[i].getKey() == key){
            elem_array[i].setValue(value);
            return;
        }
    }
    /**
     * if there is no such key: change the size of the array and put it in the right position
     */
    size++;
    Pair<K,V> temp(key ,value);
    Pair<K,V> *t_list = new Pair<K,V>[size];
    for (int i = 0; i < size-1 ; i++) {
        if(elem_array[i].getKey() < key ) {
            t_list[i] = elem_array[i];
        }else{
            t_list[i] = temp;
            for (int j = i+1; j < size ; j++) {
                t_list[j] = elem_array[j-1];
            }
            delete [] elem_array;
            elem_array = t_list;
            return;
        }
    }
    t_list[size-1] = temp;
    delete [] elem_array;
    elem_array = t_list;
}

/**
 * find the element by its key value
 * @tparam K
 * @tparam V
 * @param key
 * @return
 */
template<typename K , typename V>
const V* Map<K,V>::find(const K& key) const{
    for (int i = 0; i < size ; i++) {
        if(elem_array[i].getKey() == key) return &elem_array[i].getValue();
    }
    return NULL;
}

/**
 * remove element from the list
 * @tparam K
 * @tparam V
 * @param key
 * @return
 */
template<typename K , typename V>
bool Map<K,V>::remove(const K& key){
    bool flag = false;
    for (int i = 0; i < size ; i++) {
        if(key == elem_array[i].getKey()){
            elem_array[i].setKey();
            flag = true;
            break;
        }
    }
    if(flag){
        Pair<K,V>* t_list = new Pair<K,V>[--size];
        for (int i = 0 , j = 0 ; i < size ; i++ , j++ ) {
            if(elem_array[j].getKey() == "") {
                j++;
            }
            t_list[i] = elem_array[j];
        }
        delete [] elem_array;
        elem_array = t_list;
    }
    return flag;
}

/**
 * destroy all the map
 */
template<typename K , typename V>
void Map<K,V>::destroy(){
    delete [] elem_array;
    elem_array = NULL;
}

/**
 * print the elemnt
 */
template<typename K , typename V>
void Map<K,V>::print() const {
    for (int i = 0; i < size ; i++) {
        cout << elem_array[i].getKey() << " " << elem_array[i].getValue() << endl;
    }
}



#endif //METROPOLIN_MAP_IMPL_H
