#include <string>
#include "stack.h"
#include <map>
#include "helper.h"

using namespace std;

map<char, int> precedenceMap = {
    {'>', 1},
    {'+', 2},
    {'*', 3},
    {'~', 4},
};
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
		 * @brief Get the Parse Tree Height object
		 * 
		 * @param op 
		 * @return int 
		 */
		static int getParseTreeHeight(Operator* op) {
			int height = 0;
			return calcParseTreeHeight(op, &height);
		}

		/**
		 * @brief Gets the Parse Tree Height object but requires integer pointer to update to
		 * 
		 * @param op 
		 * @param height 
		 * @return int 
		 */
		static int calcParseTreeHeight(Operator* op, int* height) {
			if (op->isAtom()) {
				*height += 1;
				return 1;
			}
			int leftTreeHeight = calcParseTreeHeight(op->getLeftChild(), height);
			int rightTreeHeight = calcParseTreeHeight(op->getRightChild(), height);
			debug("left", leftTreeHeight);
			debug("right", rightTreeHeight);
			
			return *height;
		};

		static bool getParseTreeVal(Operator* op);
};
