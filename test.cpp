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
	Logic::Operator dis('+', &a, &c);
	Logic::Operator head('>', &con, &dis);

	string infix;
	Logic::parseTreeToInfix(&head, &infix);
	cout << infix << endl;
	

}
int main() {
    testLogic();
    testOperators();
    return 0;

}

