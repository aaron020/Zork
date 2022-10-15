#include "Storage.h"

template <class T>
void Storage<T>::add(T &o){
    storage.push_back(o);
}




template <class T>
bool Storage<T>::remove(T &o){
    if(storage.size() > 0){
        int position = 0;
        for(auto& i : storage){
            if(i == o){
                storage.erase(storage.begin()+position);
                return true;
            }
            position++;
        }
    }
    return false;
}



template <class T>
T* Storage<T>::find(QString name){
    if(storage.size() > 0){
        for(auto& i : storage){
            if(i.find(name)){
                return &i;
            }
        }
    }
    return NULL;
}

