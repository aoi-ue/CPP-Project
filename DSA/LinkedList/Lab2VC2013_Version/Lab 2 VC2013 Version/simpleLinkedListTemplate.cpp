#pragma once

#ifndef SIMPLELINKEDLISTTEMPLATEHPP
#define SIMPLELINKEDLISTTEMPLATEHPP

#include <iostream>
#include "simpleLinkedListTemplate.h"
using namespace std;

template <class T>
ListNode<T>::ListNode(T n)
{
	_item = n;
	_next = NULL;
}

template <class T>
void List<T>::insertHead(T n)
{
	ListNode<T> *aNewNode = new ListNode<T>(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

template <class T>
void List<T>::removeHead()
{
	if (_size > 0)
	{
		ListNode<T> *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

template <class T>
void List<T>::print(bool withNL)
{

	ListNode<T> *temp = _head;
	while (temp)
	{
		cout << temp->_item;
		if (withNL)
			cout << endl;
		else
			cout << " ";
		temp = temp->_next;
	}
	cout << endl;
}

template <class T>
bool List<T>::exist(T n)
{
	// modify this
	ListNode<T> *nodePtr = _head;

	while (nodePtr != NULL)
	{
		if (nodePtr->_item == n)
			return true;
		nodePtr = nodePtr->_next;
	}

	return false;
}

template <class T>
T List<T>::headItem()
{
	if (_size)
		return *_head;
}

template <class T>
T List<T>::extractMax()
{
	float max;
	ListNode<T> *nodePtr = _head;
	ListNode<T> *previous;

	if (nodePtr == NULL) return 0; 

	// Check loop while head not equal to NULL
	while (nodePtr != NULL)
	{
		// If max is less then head->data then
		// assign value of head->data to max
		// otherwise node point to next node.
		if (max < nodePtr->_item)
			max = nodePtr->_item;
		nodePtr = nodePtr->_next;
	}

	nodePtr = _head;

	if (nodePtr->_item == max)
	{
		// previous = _head; //backup to free the memory
		// _head = _head->_next;
		// free(previous);
		removeHead(); 
	}
	else
	{
		while (nodePtr->_next != NULL)
		{
			//if yes, we need to delete the current->next node
			if (nodePtr->_next->_item == max)
			{
				previous = nodePtr->_next;
				//node will be disconnected from the linked list.
				nodePtr->_next = nodePtr->_next->_next;
				free(previous);
				break;
			}
			//Otherwise, move the current node and proceed
			else
				nodePtr = nodePtr->_next;
		}
	}

	// if there are duplicates maximas in the list, return the leftmost one (the one closest to the _head)
	return T();
}

template <class T>
void List<T>::reverseOp()
{
	ListNode<T> *temp = NULL;
	ListNode<T> *prev = NULL;
	ListNode<T> *curr = _head;

    while(curr != NULL) {
        temp = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = temp;
    }
    _head = prev;
}

template <class T>
List<T>::~List()
{
	while (_head)
		removeHead();
};

#endif