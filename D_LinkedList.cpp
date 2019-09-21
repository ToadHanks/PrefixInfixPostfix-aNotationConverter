/*
	Author of this file:	Mihir Patel
		    Purpose:	This is data structure for D_LinkedList.hpp. 
*/
#include "D_LinkedList.hpp"
/*D_LinkedList constructor that creates sentinels*/
D_LinkedList::D_LinkedList(){
    header = new D_Node;
    trailer = new D_Node;
    header->next = trailer;
    trailer->prev = header;
}
/*D_LinkedList destructor*/
D_LinkedList::~D_LinkedList(){
    while (!empty()){ /*Remove the front node, until header points to trailer*/
        removeFront();
    }
    delete header;/*Delete sentinels*/
    delete trailer;
}
bool D_LinkedList::empty() const{ /*Check if header is pointing to trailer*/
    return (header->next == trailer);
}
const StringElem D_LinkedList::front() const{/*Returns the first nodes element*/
	if (empty()) {
		throw ("front() failed.\n");
	}
    return (header->next->str_elem);
}
void D_LinkedList::addFront(const StringElem str_para) { /*Adds a node after header*/
	add(header->next, str_para);
}
void D_LinkedList::removeFront() {/*Removes the node after header*/
	if (empty()) {
		throw("removeFront() failed.\n");
	}
	remove(header->next);
}
/*Add a node after v, and put the element of string*/
void D_LinkedList::add(D_Node* v, const StringElem str_para) {
	D_Node* u = new D_Node; /*Make new node*/
	u->str_elem = str_para;/*Sets the value of that node*/
	u->next = v; /*points the new node to the node passed*/
	u->prev = v->prev; /*Set its previous to olds previos*/
	v->prev->next = u; /*Change pointer of old's node next to new node*/
	v->prev = u; /*Pointer reverse pointer to the new node*/
}
/*Removes the node before v*/
void D_LinkedList::remove(D_Node* v) {
	D_Node* u = v->prev; /*copy the v's previous node to u */
	D_Node* w = v->next; /*copy the v's next node to w*/
	u->next = w; /*Set next pointer to V's next*/
	w->prev = u; /*set previous pointer to back to v previosu*/
	delete v; /*Delete the node passed*/
}
