/*
	Author of this file:	Mihir Patel
	            Purpose:    Following is a header file that depends on D_Node.hpp. This creates the data structures
			            	for doubly-linked list. It also friends the Deque.
*/
#ifndef D_LINKEDLIST_HPP
#define D_LINKEDLIST_HPP

#include "D_Node.hpp"

class D_LinkedList{
private:
    D_Node* header; /*Pointer to access nodes*/
    D_Node* trailer;
    friend class DL_Deque; /*Gives functions for Deque ADT*/
protected:
    void add(D_Node* v, const StringElem str_para); /*Add the node before node v*/
    void remove(D_Node* v); /*remove the node before the node v*/
public:
    D_LinkedList();
    ~D_LinkedList();

    bool empty() const; /*Checks wether if heder points to trailer*/

    void addFront(const StringElem str_para);/*add the String node after header*/
    void removeFront(); /*removes the String node after header*/
    const StringElem front() const; /*returns the node after the next*/
};
#endif //!D_LINKEDLIST_HPP