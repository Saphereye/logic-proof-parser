#include <string>
#include "stack.h"
#include <map>
#include "helper.h"

using namespace std;

// map<char, int> precedenceMap = {
//     {'>', 1},
//     {'+', 2},
//     {'*', 3},
//     {'~', 4},
// };

int precedenceMap(char symbol) {
	switch (symbol) {
		case '~' : return 4; break;
		case '*' : return 3; break;
		case '+' : return 2; break;
		case '>' : return 1; break;
		default: return 0; break;
	}
}

class Logic {
    public:
		/**
		 * @brief Converts infix into prefix using stack
		 * 
		 * @param infix 
		 * @return string 
		 */
		static string infixToPrefix(string infix) {
			int index = infix.length() - 1;
			string outputPrefix = "";
			Stack<char> stck(int(infix.length()));

			while(index >= -1) {
			if (infix[index] == '(') {
				char stackElement = stck.pop();
				while(stackElement != ')') {
					outputPrefix = stackElement  + outputPrefix;
					stackElement = stck.pop();
				}
			}
			else if(isalpha(infix[index])) {
				outputPrefix = infix[index] + outputPrefix;
			} else if (stck.isEmpty() || (precedenceMap(infix[index]) >= precedenceMap(stck.peek())) || (infix[index] == ')')) {
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

		/**
		 * @brief Traverses binary tree in order and evaluates infix
		 * 
		 * @param op 
		 * @return string 
		 */
		static string parseTreeToInfix(Operator* op) {
			string output;
			calcparseTreeToInfix(op, &output);
			return output;
		}

		/**
		 * @brief Traverses binary tree in order and evaluates infix, but requires string pointer to write to
		 * 
		 * @param op 
		 * @param output 
		 */
		static void calcparseTreeToInfix(Operator* op, string* output) {
			if (op->isAtom()) {
				*output += op->getSymbol();
				return;
			}
			*output += '(';
			calcparseTreeToInfix(op->getLeftChild(), output);
			*output += op->getSymbol();
			calcparseTreeToInfix(op->getRightChild(), output);
			*output += ')';
		};

		/**
		 * @brief Get the Parse Tree Height object. Performs recursive evaluation on each child in O(n).
		 * 
		 * @param op 
		 * @return int 
		 */
		static int getParseTreeHeight(Operator* op) {
			if (op->isAtom()) {
				return 0;
			}
			int leftChildHeight = getParseTreeHeight(op->getLeftChild());
			int rightChildHeight = getParseTreeHeight(op->getRightChild());
			return max(leftChildHeight, rightChildHeight) + 1;
		}

		static bool getParseTreeVal(Operator* op);
};
