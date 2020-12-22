#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
    private:
        std::vector<T> newVector;
    public:
        T remove_min();
        T min();
        bool is_empty();
        void insert(const T& data);
};

template <typename T>
T UnsortedMPQ<T>::remove_min(){
    if(is_empty()){
        throw ("minimum priority queue is empty.");
    }
    else{
        int num = 0;
        T value = newVector.at(0);
        for(int i = 0; i < newVector.size(); i++){
            if(newVector.at(i) < value){
                value = newVector.at(i);
                num = i;
            }
        }
        newVector.erase(newVector.begin() + num);
        return value;
    }
}

template <typename T>
T UnsortedMPQ<T>::min(){
    if(is_empty()){
        throw ("minimum priority queue is empty.");
    }
    else{
        T value = newVector.at(0);
        for(int i = 0; i < newVector.size(); i++){
            if(newVector.at(i) < value){
                value = newVector.at(i);
            }
        }
        return value;
    }
}

template <typename T>
bool UnsortedMPQ<T>::is_empty(){
    if(newVector.size() == 0){
        return true;
    }
    return false;
}

template <typename T>
void UnsortedMPQ<T>::insert(const T& data){
    newVector.push_back(data);    
}

#endif