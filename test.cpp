#include <iostream>
#include <cassert>
#include "logic.h"

using namespace std;

void testLogic() {
    assert(Logic::infixToPrefix("(a*b)>(a+c)") == ">*ab+ac");
    assert(Logic::infixToPrefix("a*b>a+c") == ">*ab+ac");
    assert(Logic::infixToPrefix("(a*b>a)+c") == "+>*abac");
}

void testParseTreeToInfix() {
	Logic::Operator a('a');
	Logic::Operator b('b');
	Logic::Operator c('c');
	Logic::Operator con('*', new Logic::Operator('~', &a), &b);
	Logic::Operator impl('>', &con, &a);
	Logic::Operator dis('+', &c, &c);
	Logic::Operator dis2('+', &dis, &c);
	Logic::Operator head('+', &impl, &dis2);
	debug("Infix from parse tree", Logic::parseTreeToInfix(&head));
}

void testParseTreeHeight() {
	Logic::Operator a('a');
	Logic::Operator b('b');
	Logic::Operator c('c');
	Logic::Operator con('*', new Logic::Operator('~', &a), &b);
	Logic::Operator impl('>', &con, &a);
	Logic::Operator dis('+', &c, &c);
	Logic::Operator dis2('+', &dis, &c);
	Logic::Operator head('+', &impl, &dis2);
	debug("Height", Logic::getParseTreeHeight(&head));
}

void testParseTreeVal() {
	Logic::Operator p('p');
	Logic::Operator q('q');
	Logic::Operator head('~', &p, &q);

	map<char, bool> valueMap = {
		{'p', true},
		{'q', false},
	};
	debug("Value", Logic::getParseTreeVal(&head, valueMap));
}



int main() {
    testLogic();
    testParseTreeToInfix();
	testParseTreeHeight();
	testParseTreeVal();
    return 0;
}

