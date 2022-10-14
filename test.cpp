#include <iostream>
#include <cassert>
#include "logic.h"

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

	debug("Infix from parse tree", Logic::parseTreeToInfix(&head));
	debug("Height", Logic::getParseTreeHeight(&head));
	

}
int main() {
    testLogic();
    testOperators();
    return 0;

}

