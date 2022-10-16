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
	// Logic::Operator a('a');
	// Logic::Operator b('b');
	// Logic::Operator c('c');
	// Logic::Operator con('*', &a, &b);
	// Logic::Operator impl('>', &con, &a);
	// Logic::Operator dis('+', &c, &c);
	// Logic::Operator dis2('+', &dis, &c);
	// Logic::Operator head('+', &impl, &dis2);
	Logic::Operator p('p');
	Logic::Operator q('q');
	Logic::Operator negp('~', &p);
	Logic::Operator negq('~', &q);
	Logic::Operator impl('>', &negq, &negp);
	Logic::Operator head('*', &p, &impl);



	debug("Infix from parse tree", Logic::parseTreeToInfix(&head));
	debug("Height", Logic::getParseTreeHeight(&head));
	

}
int main() {
    testLogic();
    testOperators();
    return 0;
}

