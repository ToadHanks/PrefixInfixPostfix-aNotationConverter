/*
	Author of this file:	Mihir Patel
				Previous:	Following is a source file for NotationConverter.hpp. It defines the 
							assignement functions, and uses the Deque ADT based on the double 
							linked list data structures.
*/
#include "NotationConverter.hpp"

/*Checks the PEMDAS priority and returns the rank*/
int NotationConverter::operator_priority(StringElem str_para) {
	if ((str_para == "*") || (str_para == "/")) {
		return 2;
	}
	else if ((str_para == "-") || (str_para == "+")) {
		return 1;
	}
	else {
		return 0; 
	}
}
/*Verify if the passed string has space+*-)/( A-Z & a-z....character by characters*/
bool NotationConverter::verify_inStr(StringElem str_para) {
	for (char c : str_para) {
		if (!(std::isalpha(c)) && (c != '(') && (c != ')') && (c != '*')
			&& (c != '/') && (c != '+') && (c != '-') && (c != ' ')) {
			return false;
		}
	}
	return true;
}
/*Goes from reverse polish to standard notaation.*/
std::string NotationConverter::postfixToInfix(std::string inStr) {
	StringElem infix_string = ""; /*Temprory string*/
	DL_Deque deque; /*Node object*/
	
	if (verify_inStr(inStr)) {

		for (char c : inStr) { /*loop through each character*/
			StringElem inStr_substr = "";
			inStr_substr += c; /*Append the charcter to null string*/

			if (c == ' ') { /*If space, ignore it*/
				continue;
			}
			else if (std::isalpha(c)) { /*If character then push to queue*/
				deque.front_push(inStr_substr);
			}
			else {/*If operator then remove the letters and push the punctuations*/
				StringElem top_deque = deque.front_has(); 
				deque.front_pop();
				StringElem below_top_deque = deque.front_has();
				deque.front_pop();
				deque.front_push("(" + below_top_deque + " " + inStr_substr
					+ " " + top_deque + ")"); /*Push with assignment required parenthesis*/
			}
		}
		infix_string = deque.front_has();/*Append the queue*/
	}
	else {
		throw("postfixToInfix() failed.\n");
	}

	return infix_string;/*Returns the string*/
}
/*Change standard to postfix notation*/
std::string NotationConverter::infixToPostfix(std::string inStr) {
	StringElem postfix_string = "";
	StringElem hold_infixToPrefix = "";

	hold_infixToPrefix = infixToPrefix(inStr); /*First change infixToString*/
	postfix_string = prefixToPostfix(hold_infixToPrefix); /*Then prefixToPostfix*/

	return postfix_string; /*Returns the postfix string*/
}
/*Change polish notation to standard notation*/
std::string NotationConverter::prefixToInfix(std::string inStr) {
	StringElem infix_string = "";
	StringElem hold_prefixToInfix = "";

	hold_prefixToInfix = prefixToPostfix(inStr);/*First change prefixToPostfix*/
	infix_string = postfixToInfix(hold_prefixToInfix);/*Then postfixToInfix*/

	return infix_string;/*Returns the infix string*/
}
/*Change from standard notation to polish notation*/
std::string NotationConverter::infixToPrefix(std::string inStr) {
	StringElem prefix_string = "";
	DL_Deque temp_deque; /*a temprory deque object*/
	DL_Deque deque; /*deque object*/

	if (verify_inStr(inStr)) {
		/*First reverse the given string*/
		std::reverse(inStr.begin(), inStr.end());

		for (char c : inStr) {
			StringElem inStr_substr = "";
			inStr_substr += c;/*Converts characters to string*/

			if (c == ' ') {/*if space then ignore*/

			}
			else if (c == '(') {/*If closing bracket then keep pushing the deque element to temp_deque*/
				while (deque.front_has() != ")") {
					temp_deque.front_push(deque.front_has());
					temp_deque.front_push(" ");
					deque.front_pop();/*Keep removing the front element from deque until left bracket*/
				}
				if (deque.front_has() == ")") {/*Then remove closing bracket*/
					deque.front_pop();
				}
			}
			else if (c == ')') { /*Push the closing bracket to front*/
				deque.front_push(inStr_substr);
			}
			else if (std::isalpha(c)) { /*Character push directly in queue*/
				temp_deque.front_push(inStr_substr);
				temp_deque.front_push(" ");/*Push the space*/
			}
			else {
				if (!deque.is_empty()) {/*Check the operator rank & then push to temp_deque */
					while (operator_priority(inStr_substr) < operator_priority(deque.front_has())) {
						temp_deque.front_push(deque.front_has());
						temp_deque.front_push(" ");
						deque.front_pop();/*Removes the front of the queue*/
					}
					deque.front_push(inStr_substr);/*Then push the character to deque */
				}
				else {
					deque.front_push(inStr_substr);/*Push the character if deque is empty*/
				}
			}
		}
		while (!deque.is_empty()) {/*Keep pushing the to temp_deque*/
			temp_deque.front_push(deque.front_has());
			temp_deque.front_push(" ");
			deque.front_pop();/*And remove front original deque*/
		}

		temp_deque.front_pop();/*Pop while notation from front of the deque*/

		while (!temp_deque.is_empty()) {/*Then load temp_deque into prefix_string*/
			prefix_string += temp_deque.front_has();
			temp_deque.front_pop();
		}
	}
	else {
		throw("infixToPrefix() failed.\n");
	}

	return prefix_string; /*Returns the prefix_string*/
}
/*Converts from reverse polish to polish notation*/
std::string NotationConverter::postfixToPrefix(std::string inStr) {
	StringElem prefix_string = "";
	StringElem hold_postfixToInfix = "";
	
	hold_postfixToInfix = postfixToInfix(inStr);/*Change postfixToInfix*/
	prefix_string = infixToPrefix(hold_postfixToInfix);/*hold the infixToPrefix*/

	return prefix_string; /*Returns the prefix_string*/
}
/*Change polish notation to reverse polish notation*/
std::string NotationConverter::prefixToPostfix(std::string inStr) {
	StringElem postfix_string = "";
	DL_Deque deque;

	if (verify_inStr(inStr)) {

		std::reverse(inStr.begin(), inStr.end());/*Reverse the string*/

		for (char c : inStr) {
			StringElem inStr_strstr = "";
			inStr_strstr += c;/*Converts from character to string*/

			if (c == ' ') {/*If space then ignore*/
				continue;
			}
			else if (std::isalpha(c)) {/*If letter then add front to deque*/
				deque.front_push(inStr_strstr);
			}
			else {/*If operator then add to the deque then the letters*/
				StringElem top_deque = deque.front_has();
				deque.front_pop();
				StringElem below_top_deque = deque.front_has();
				deque.front_pop();
				deque.front_push(top_deque + " " + below_top_deque + " " + inStr_strstr);
			}
		}
		postfix_string = deque.front_has();/*then unload the deque to the string*/
	}
	else {
		throw("prefixToPostfix() failed.\n");
	}

	return postfix_string;/*Returns the postfix_string*/
}