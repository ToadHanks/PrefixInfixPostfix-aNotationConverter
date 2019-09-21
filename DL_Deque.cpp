/*
	Author of this file:	Mihir Patel
		    Purpose:	Following is a source file for DL_Deque.hpp ADT. It has access to the D_LinkedList.hpp 
				data structures.	
*/
#include "DL_Deque.hpp"

DL_Deque::DL_Deque() : D(){ }/*empty constructor that nulls D_LinkedList object*/
/*Returns wether deque is empty*/
bool DL_Deque::is_empty() const {
	return (D.empty());
}
/*Returns the front node's element of the queue*/
const StringElem DL_Deque::front_has() const {
	if (is_empty()) {
		throw("front_has() failed.\n");
	}
	return (D.front());
}
/*Pushes the node in front of the queue*/
void DL_Deque::front_push(const StringElem& str_para) {
	D.addFront(str_para);
}
/*Removes the front node*/
void DL_Deque::front_pop() {
	if (is_empty()) {
		throw("front_pop() failed.\n");
	}
	D.removeFront();
}
