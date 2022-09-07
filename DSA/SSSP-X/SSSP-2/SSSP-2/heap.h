#pragma once
#define DEFAULTHEAPSIZE 1023
template <class T>
class Heap {
private:
    int _parent(int x);
    int _leftNode(int x);
    int _rightNode(int x);
protected:
    T* _heap;
    int _n;
    void _swap(int x, int y);
    void _bubbleUp(int index);
    void _bubbleDown(int index);
    int _lookFor(T x); // return the index of the item x, return -1 if not found
    // it is not a good/usual implementation, so we hide it from public
public:
    Heap() {
        _heap = new T[DEFAULTHEAPSIZE];
        _n = 0;
    };
    void insert(T);
    bool empty() {return _n==0;};
    T extractMin();
    T peekMax() {return _heap[0];};
    void printHeapArray();
    void printTree();
    void increaseKey(T from, T to);
    void decreaseKey(T from, T to);
    void deleteItem(T);
    
    ~Heap() { delete[] _heap; };
};


#include "heap.hpp"
