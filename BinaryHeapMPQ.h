#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
    private:
        BinaryHeap<T> newBinaryHeap;
    public:
        void insert(const T& data);
        bool is_empty();
        T min();
        T remove_min();
};

template <typename T>
void BinaryHeapMPQ<T>::insert(const T& data){
    newBinaryHeap.insert(data);
}

template <typename T>
bool BinaryHeapMPQ<T>::is_empty(){
    newBinaryHeap.is_empty();
}

template <typename T>
T BinaryHeapMPQ<T>::min(){
    return newBinaryHeap.min();
}

template <typename T>
T BinaryHeapMPQ<T>::remove_min(){
    return newBinaryHeap.remove_min();
}

#endif