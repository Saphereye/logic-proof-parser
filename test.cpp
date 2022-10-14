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
    // TODO
}
int main() {
    testLogic();
    testOperators();
    return 0;

}

