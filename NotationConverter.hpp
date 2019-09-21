/*
	Author of this file:	Mihir Patel
		    Purpose:	This is header file that the inherits the assignment interface files, and override
				the virtual functions and implements the functions to solve the strings to different 
				notations.
*/
#ifndef NOTATIONCONVERTER_HPP
#define NOTATIONCONVERTER_HPP

#include <iostream>
#include <algorithm>
#include <cctype>
#include "DL_Deque.hpp"
#include "NotationConverterInterface.hpp"

class NotationConverter :public NotationConverterInterface { /*Public inhertience*/
public:
	int operator_priority(StringElem str_para);/*Prototype for operator  rules*/
	bool verify_inStr(StringElem str_para); /*Verify A-Z && a-z && ()/+*_*/

	/*general prototypes*/
	std::string postfixToInfix(std::string inStr);
	std::string postfixToPrefix(std::string inStr);

	std::string infixToPostfix(std::string inStr);
	std::string infixToPrefix(std::string inStr);

	std::string prefixToInfix(std::string inStr);
	std::string prefixToPostfix(std::string inStr);
};
#endif // !NOTATIONCONVERTER_HPP
