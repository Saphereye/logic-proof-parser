#include <iostream>
#include <string>
#include "operators.h"
#include "parseTree.h"
#include "logic.h"

using namespace std;

int main() {
    string infix = "a*b>a+c";
    string prefix = "+ab";
    //ParseTree pTree;
    //cout << pTree << endl;

    cout << Logic::infixToPrefix(infix) <<endl;
    return 0;
}
