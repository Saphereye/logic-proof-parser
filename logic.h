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

		
		#include "operators.h"
		static Operator prefixToParseTree(string prefix);

		static void parseTreeToInfix(Operator* op, string* output) {
			if (op->isAtom()) {
				*output += op->getSymbol();
				return;
			} else {
				parseTreeToInfix(op->getLeftChild(), output);
				*output += op->getSymbol();
				parseTreeToInfix(op->getRightChild(), output);
			}
		};

		static int getParseTreeHeight(Operator op);

		static bool getParseTreeVal(Operator);
};
