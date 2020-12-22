#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        void insert(const T& data);
        bool is_empty();
        T min();
        T remove_min();
    private:
        std::vector<T> elements{};
        int size = 0;
        void down_heap(int i);
        void up_heap(int i);

        //Pre-implemented helper functions
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        int right_child(int i) {return 2*i + 2;}
        int left_child(int i) {return 2*i + 1;}
        int parent(int i) {return floor((i-1)/2);}
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

template <typename T>
void BinaryHeap<T>::insert(const T& data){
    size++;
    int newSize = size - 1;
    elements.push_back(data);
    up_heap(newSize);
}

template <typename T>
bool BinaryHeap<T>::is_empty(){
    if(size == 0){
        return true;
    }
    return false;
}

template <typename T>
T BinaryHeap<T>::min(){
    if(is_empty()){
        throw "Empty binary heap";
    }
    else{
        T val = elements[0];
        return val;
    }
}

template <typename T>
T BinaryHeap<T>::remove_min(){
    if(is_empty()){
        throw "Empty binary heap";
    }
    else{
        T val = elements[0];
        int newSize = --size;
        elements[0] = elements[newSize];
        elements.erase(--elements.end());
        down_heap(0);
        return val;
    }
}
/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i){
    int parent_index = parent(i);
    /*
     * Can be computed iteratively or recursively
     */
    while(elements[i] < elements[parent(i)] && 0 < i){
        swap(i, parent(i));
        i = parent(i);
    }
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 * O(log n)
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i){
    int right_index = right_child(i);
    int left_index = left_child(i);
    /*
     * Can be computed iteratively or recursively
     */
    int index = i;
    if(right_index < size && elements[right_index] < elements[index]){
        index = right_index;
    }
    if(left_index < size && elements[left_index] < elements[index]){
        index = left_index;
    }
    if(i != index){
        swap(index, i);
        down_heap(index);
    }
}
#endif