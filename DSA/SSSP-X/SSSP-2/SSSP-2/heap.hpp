#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

template<class T>
void Heap<T>::_swap(int x, int y)
{
    T temp = _heap[x];
    _heap[x] = _heap[y];
    _heap[y] = temp;
}
template <class T>
void Heap<T>::_bubbleUp(int index) {
    while (_heap[index] < _heap[_parent(index)])
    {
        _swap(index, _parent(index));
        index = _parent(index);
    }
}
template <class T>
void Heap<T>::_bubbleDown(int index) {
    while ((_leftNode(index) < _n) && (_rightNode(index) < _n)) //if node has no children -> break
    {
        if (_heap[index] > _heap[_leftNode(index)]) //only left child & left child smaller
        {
            cout << "bubble down leftt:" << index << endl;
            _swap(index, _leftNode(index));
            index = _leftNode(index);

        } else {
            cout << "bubble down rightt:" << index << endl;
            _swap(index, _rightNode(index));
            index = _rightNode(index);
            
        }
    }
}
template <class T>
void Heap<T>::insert(T item) {
    _n++;
    int curr = _n - 1; //index
    _heap[curr] = item; //value of index
    _bubbleDown(curr);
}

template <class T>
T Heap<T>::extractMin() {
    T root = _heap[0];
    deleteItem(root);
    return T(root);
}

template <class T>
void Heap<T>::printHeapArray() {
    for (int i = 0; i < _n; i++)
        cout << _heap[i] << " ";
    cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
    for(i=0;i<_n;i++)
        if (_heap[i] == x)
            return i;
    
    return -1;
}

template <class T>
void Heap<T>::decreaseKey(T from, T to)
{
    if (_lookFor(from) != -1)
    {
        _heap[_lookFor(from)] = to;
    }
    _bubbleDown(_lookFor(to));
}
template <class T>
void Heap<T>::increaseKey(T from, T to)
{
    if (_lookFor(from) != -1)
    {
        _heap[_lookFor(from)] = to;
    }
    _bubbleUp(_lookFor(to));
}
template <class T>
void Heap<T>::deleteItem(T x)
{
    int deletedIndex = _lookFor(x);
    T deletedIndexValue = x;
    T lastIndexValue = _heap[_n - 1];
    
    if (lastIndexValue > deletedIndexValue)
    {
        
        _swap(_n - 1, deletedIndex);
        //        _heap[_n - 1] = NULL;
        --_n;
        _bubbleDown(deletedIndex);
    }
    else if (lastIndexValue < deletedIndexValue)
    {
        
        _swap(_n - 1, deletedIndex);
        
        //        _heap[_n - 1] = NULL;
        --_n;
        _bubbleUp(deletedIndex);
    }
    
}
template <class T>
int Heap<T>::_parent(int x){
    return floor((x - 1) / 2);
};
template <class T>
int Heap<T>::_leftNode(int x){
    return (2 * x + 1);
};
template <class T>
int Heap<T>::_rightNode(int x){
    return (2 * x + 2);
};
template <class T>
void Heap<T>::printTree() {
    int parity = 0;
    if (_n == 0)
        return;
    int space = pow(2,1 + (int) log2f(_n)),i;
    int nLevel = (int) log2f(_n)+1;
    int index = 0,endIndex;
    int tempIndex;
    
    for (int l = 0; l < nLevel; l++)
    {
        index = 1;
        parity = 0;
        for (i = 0; i < l; i++)
            index *= 2;
        endIndex = index * 2 - 1;
        index--;
        tempIndex = index;
        while (index < _n && index < endIndex) {
            for (i = 0; i < space-1; i++)
                cout << " ";
            if(index==0)
                cout << "|";
            else if (parity)
                cout << "\\";
            else
                cout << "/";
            parity = !parity;
            for (i = 0; i < space; i++)
                cout << " ";
            index++;
        }
        cout << endl;
        index=tempIndex;
        while (index < _n && index < endIndex) {
            for (i = 0; i < (space-1-((int) log10(_heap[index]))); i++)
                cout << " ";
            cout << _heap[index];
            for (i = 0; i < space; i++)
                cout << " ";
            index++;
        }
        
        cout << endl;
        space /= 2;
    }
}

#endif
