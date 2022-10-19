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

	// map<char, bool> valueMap = {
	// 	{'p', true},
	// 	{'q', false},
	// };
	TruthValStore tvs("pq", 0b01);
	debug("Value", Logic::getParseTreeVal(&head, tvs));
}

void testValStore() {
	// p=F q=T r=T
	TruthValStore tvs("pqr", 0b110);
	tvs.setTruthVal('q', false);
	debug("Truth val of p", tvs.getTruthVal('p'));
	debug("Truth val of q", tvs.getTruthVal('q'));
	debug("Truth val of r", tvs.getTruthVal('r'));
	//debug("Truth val of z", tvs.getTruthVal('z'));
}

void testPrinting() {
	Logic::Operator a('a');
	Logic::Operator b('b');
	Logic::Operator c('c');
	Logic::Operator con('*', new Logic::Operator('~', &a), &b);
	Logic::Operator impl('>', &con, &a);
	Logic::Operator dis('+', &c, &c);
	Logic::Operator dis2('+', &dis, &c);
	Logic::Operator head('+', &impl, &dis2);

	Logic::displayParseTree(&head);
}

void testprefixToParseTree() {
	string test = "~(a+b)";
	debug(test, Logic::parseTreeToInfix(Logic::prefixToParseTree(Logic::infixToPrefix(test))));
}



int main() {
	debug("debug", 69);
	trace("trace");
	todo("todo");
	error("error");
    testLogic();
    testParseTreeToInfix();
	testParseTreeHeight();
	testParseTreeVal();
	testValStore();
	testprefixToParseTree();
	testPrinting();
    return 0;
}

