#include <string>
#include "stack.h"
#include <map>

using namespace std;

map<char, int> precedenceMap = {
    {'>', 1},
    {'+', 2},
    {'*', 3},
    {'~', 4},
};

class Logic {
    public:
	static string infixToPrefix(string infix) {
	    int index = infix.length() - 1;
	    string outputPrefix = "";
	    Stack<char> stck(int(infix.length()));

	    while(index >= -1) {
		// cout << outputPrefix << " , " << index << endl;
		// Checking if the element is a letter or something else
		// This is assuming all inputs would be perfect
		// cout << "Current Element : " << infix[index] << " Current Index : " << index << endl;
		if (infix[index] == '(') {
		    char stackElement = stck.pop();
		    while(stackElement != ')') {
				outputPrefix = stackElement  + outputPrefix;
				stackElement = stck.pop();
		    }

		}
		else if(isalpha(infix[index])) {
		    outputPrefix = infix[index] + outputPrefix;
		} else if (stck.isEmpty() || (precedenceMap[infix[index]] >= precedenceMap[stck.peek()]) || (infix[index] == ')')) {
		    stck.push(infix[index]);
		} else {
		    outputPrefix = stck.pop() + outputPrefix;
		    continue;
		}
		index--;
	    }
	    return outputPrefix;
	};


#include "parseTree.h"
	static ParseTree prefixToParseTree(string prefix);

	static string parseTreeToInfix(ParseTree pTree);

	static int getParseTreeHeight(ParseTree pTree);

	static bool getParseTreeVal(ParseTree);


	// void _setInfix(string val);
	// string _getInfix();

	// string _getPrefix(string inputInfix) {
	//     return infixToPrefix(inputInfix);
	// };

	// ParseTree _getParseTree(string inputPrefix) {
	//     return prefixToParseTree(inputPrefix);
	// };
};
