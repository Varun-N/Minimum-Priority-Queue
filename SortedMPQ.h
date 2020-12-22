#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include "MPQ.h"
#include <iostream>
#include <vector>

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
    private:
        std::list<T> newList;
    public:
        T remove_min();
        T min();
        bool is_empty();
        void insert(const T& data);
};

template <typename T>
bool SortedMPQ<T>::is_empty(){
    if(newList.size() == 0){
        return true;
    }
    return false;
}

template <typename T>
T SortedMPQ<T>::min(){
    if(is_empty()){
        throw "minimum priority queue is empty.";
    }
    return newList.front();
}

template <typename T>
T SortedMPQ<T>::remove_min(){
    if(is_empty()){
        throw "minimum priority queue is empty.";
    }
    T temp = min();
    newList.pop_front();
    return temp;
}

template <typename T>
void SortedMPQ<T>::insert(const T& data){
    if (newList.size() == 0) {
        newList.push_front(data);
        return;
    }

    typename std::list<T>::iterator it;
    for (it = newList.begin(); it != newList.end(); ++it){
        
        if (data < *it) {
            newList.insert(it, data);
            return;
        }

    }

    newList.push_back(data);
    return;
}

#endif