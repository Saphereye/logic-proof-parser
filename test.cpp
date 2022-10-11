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
    bool val[] = {true, false};
    for(int leftIndex = 0; leftIndex < 2; leftIndex++) {
	for(int rightIndex = 0; rightIndex < 2; rightIndex++) {
	    Operator neg('~', val[rightIndex]);
	    Operator conjunc('*', val[leftIndex], val[rightIndex]);
	    Operator disjunc('+', val[leftIndex], val[rightIndex]);
	    Operator impl('>', val[leftIndex], val[rightIndex]);

	    assert(neg.getTruthValue() == (!val[rightIndex]));
	    assert(conjunc.getTruthValue() == (val[leftIndex] && val[rightIndex]));
	    assert(disjunc.getTruthValue() == (val[leftIndex] || val[rightIndex]));
	    assert(impl.getTruthValue() == ((!val[leftIndex]) || val[rightIndex]));
	}
    }
}
int main() {
    testLogic();
    testOperators();
    return 0;

}

