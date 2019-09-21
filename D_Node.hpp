/*
	Author of this file:	Mihir K Patel
	Purpose:	            Following is header file the creates the doubly linked node's properties.
*/
#ifndef D_NODE_HPP
#define D_NODE_HPP

#include <string>

typedef std::string StringElem; /*String element typedefed*/
class D_Node{
private:
    StringElem str_elem;
    D_Node* next;
    D_Node* prev;
    friend class D_LinkedList; /*gives the access to node's properties.*/
};
#endif //!D_NODE_HPP