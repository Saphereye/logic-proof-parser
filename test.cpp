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
    Operator neg('~', true);
    Operator conjunc('*', true, false);
    Operator disjunc('+', true, false);
    Operator impl('>', true, false);

    assert(neg.getTruthValue() == false);
    assert(conjunc.getTruthValue() == false);
    assert(disjunc.getTruthValue() == true);
    assert(impl.getTruthValue() == false);
}
int main() {
    testLogic();
    testOperators();
    return 0;

}

