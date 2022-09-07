//
//  linkedlist.cpp
//  linkedList
//
//  Created by Yuhan on 11/12/21.
//

#include <stdio.h>
#include "linkedlist.h"

template<class T>
LinkedList<T>:: LinkedList() {
    cout<<"Constructor Called"<< endl;
    _first == NULL;
    _last == NULL; 
}


