#include <iostream>
#include <string>
#include "operators.h"
#include "parseTree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    string infix = "3+4";
    string prefix = "+34";
    ParseTree pTree;

    cout << infix << endl;
    cout << prefix << endl;
    //cout << pTree << endl;
    return 0;
}
