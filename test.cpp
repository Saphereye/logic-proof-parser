#include <iostream>
#include <cassert>
#include "logic.h"

using namespace std;

int main() {
    string infix_1 = "(a*b)>(a+c)";
    string infix_2 = "a*b>a+c";

    assert(Logic::infixToPrefix(infix_1) == ">*ab+ac");
    assert(Logic::infixToPrefix(infix_2) == ">*ab+ac");
    return 0;

}

