/*
	Author of this file:	Mihir Patel
		    Purpose:	Following the header Deque ADT that use Double Linked List Structures to 
				solve the reverse polish notification operations and goes back-and-forth
				between notations.
*/
#ifndef DL_DEQUE_HPP
#define DL_DEQUE_HPP

#include "D_LinkedList.hpp"	

class DL_Deque {
private:
	D_LinkedList D; /*Double Linked List object*/
	friend class NotationConverter; //Interface??
public:
	DL_Deque();
	bool is_empty() const; /*Checks if the double linked list is empty*/
	const StringElem front_has() const; /*Returs the node's element after header*/
	void front_push(const StringElem& str_para);/*Pushes the element after header*/
	void front_pop();/*Removes the element after the header*/
};
#endif // !DL_DEQUE_HPP
