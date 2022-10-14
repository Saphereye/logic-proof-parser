#include <iostream>
#include <cassert>
#include "logic.h"
#include "operators.h"

using namespace std;

void testLogic() {
    assert(Logic::infixToPrefix("(a*b)>(a+c)") == ">*ab+ac");
    assert(Logic::infixToPrefix("a*b>a+c") == ">*ab+ac");
    assert(Logic::infixToPrefix("(a*b>a)+c") == "+>*abac");
}

void testOperators() {
	Logic::Operator a('a');
	Logic::Operator b('b');
	Logic::Operator c('c');
	Logic::Operator con('*', &a, &b);
	Logic::Operator impl('>', &con, &a);
	Logic::Operator head('+', &impl, &c);

	string infix;
	Logic::parseTreeToInfix(&head, &infix);
	debug("Infix from parse tree", infix);

	int height = Logic::getParseTreeHeight(&head);
	debug("Height", height);
	

}
int main() {
    testLogic();
    testOperators();
    return 0;

}

