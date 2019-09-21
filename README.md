Project Proposal
-----------------
Dr. William Oropallo (Former Instructor I at the University of South Florida)

Author
-------
Mihir Patel   

Instructions
-------------   
This projet implements a Deque (Double-Ended Queue) and uses that data structure to write a class that can 
convert between the three common mathematical notation for arithmetic.

The three notations are:
   
**Postfix (Reverse Polish) Notation:** Operators are written after operands A B - C + == (A - B) + C     
**Infix Notation:**   The standard notation we use where the operator is between the operands.    
**Prefix (Polish) Notation:**   Operators are written before operands: * - A B C == (A - B) * C    

The converter will be able to convert from one of those three to any other. The input will be a string written in a single notation,
and the output will be the conversion to the specified notation.   

The input string for the functions will only ever contain the standard four arithmetic operators (* / + -), an operand denoted by
a letter (upper or lower case), a left or right parentheses (only round), or spaces. Whitespace (one or more characters of space) 
separate all operand and operators, while parentheses must have whitespace on the outside (between operators), and inside parentheses
whitespace is optional. Parentheses are only used in infix strings. Parentheses must have operators between them, as all operations
must be binary and not implied. This is basic for these notations. For example: 
   
**Valid Postfix**: c  d / a b * r r        * / *      
**Valid Prefix**: *   +    A B - C D   
**Valid Infix**: (( X + B ) * ( Y - D ))    
**Invalid Postfix**:c d a b * r r * / * *(Operators don’t match up with operands)*    
**Invalid Prefix**: * ^ A B & C D *(Invalid Characters)*     
**Invalid Infix**: ((a / f) ((a * b) / (r * r))) *(No operator between parentheses)*     

The output string separates all operand and operators by one space. The interior of a parenthesis has
no whitespace between the letter and the parenthesis or another parenthesis, while the exterior of a parenthesis is separated 
by one space from an operator and none for another parenthesis. This is this way, so output looks good, ya know?! For example:    

**Output**: ((x / y) - g)   
**Output**: ((x / y) - (a * b))   
**Output**: x y * g / h +   
    
Please use test file NotationConverterTest.cpp to test your given input. 
      
Examples   
--------   
Below are some examples of how this code runs. The test file can also be used to get an idea of how the code can run. 
````````cpp
NotationConverter nc; 

std::string examplePost = "c d / a b * r r * / *";   
nc.postfixToInfix(examplePost)  // Infix: ((c / d) * ((a * b) / (r * r)))  
nc.postfixToPrefix(examplePost) // Prefix * / c d / * a b * r r   

std::string examplePre = "* + A B - C D”;   
nc.prefixToInfix(examplePre)  // Infix: ((A + B) * (C - D))    
nc.prefixToPostfix(examplePre) // Postfix A B + C D - *    

std::string exampleInfix = "((a / f) ((a * b) / (r * r)))";   
nc.infixToPostfix(exampleInfix) // Postfix: a f / a b * r r * /    
nc.infixToPrefix(exampleInfix)  // Prefix / a f / * a b * r r      
````````
