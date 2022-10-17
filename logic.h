#include <string>
#include "stack.h"
#include "helper.h"
#include "truthValStore.h"

using namespace std;

int precedenceMap(char symbol) {
	switch (symbol) {
		case '~' : return 4; break;
		case '*' : return 3; break;
		case '+' : return 2; break;
		case '>' : return 1; break;
		default: return 0; break;
	}
}

/**
 * @brief Implementation of logic methods
 * 
 */
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
				if (infix[index] == ' ') {
					index--;
					continue;
				} else if (infix[index] == '(') {
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
		static Operator* prefixToParseTree(string prefix) {
			long unsigned int index = 0;
			return calcprefixToParseTree(prefix, &index);
		}
		
		/**
		 * @brief Prefix to parse tree
		 * 
		 * @param prefix 
		 * @return Operator* 
		 */
		static Operator* calcprefixToParseTree(string prefix, long unsigned int* index) {
			debug("prefix", prefix);
			debug("index", *index);

			if (*index == prefix.length()) {
				return NULL;
			}
			char currentCharacter = prefix[*index];
			Operator* head = new Operator(currentCharacter);

			*index+=1;

			switch (currentCharacter) {
				case '~':
					head->addRightChild(calcprefixToParseTree(prefix, index));
					break;
				case '>':
				case '+':
				case '*':
					head->addLeftChild(calcprefixToParseTree(prefix, index));
					head->addRightChild(calcprefixToParseTree(prefix, index));
				default:
					break;
			}
			return head;
		};

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
				debug("output per step", *output);
				return;
			}
			*output += '(';
			if (!op->isUnaryOperator()) calcparseTreeToInfix(op->getLeftChild(), output);
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
			int leftChildHeight = 0;
			int rightChildHeight = 0;

			if (!op->isUnaryOperator()) {
				leftChildHeight = getParseTreeHeight(op->getLeftChild());
			}

			rightChildHeight = getParseTreeHeight(op->getRightChild());

			return max(leftChildHeight, rightChildHeight) + 1;
		}

		/**
		 * @brief Get the Parse Tree Val object using a dictionary of symbols and their values
		 * 
		 * @param op Pointer to parse tree
		 * @param valueMap Dictionary mappiing symbols to their truth values
		 * @return true 
		 * @return false 
		 */
		static bool getParseTreeVal(Operator* op, TruthValStore valueMap) {
			debug("Symbol", op->getSymbol());
			debug("Value", valueMap.getTruthVal(op->getSymbol()));
			if (op->isAtom()) {
				return valueMap.getTruthVal(op->getSymbol());
			}

			switch (op->getSymbol()) {
				case '~':
					return !getParseTreeVal(op->getRightChild(), valueMap);	
				case '*':
					return (getParseTreeVal(op->getLeftChild(), valueMap) && getParseTreeVal(op->getRightChild(), valueMap));
				case '+':
					return (getParseTreeVal(op->getLeftChild(), valueMap) || getParseTreeVal(op->getRightChild(), valueMap));
				case '>':
					return (!getParseTreeVal(op->getLeftChild(), valueMap) && getParseTreeVal(op->getRightChild(), valueMap));
				default:
					return false;
			}
		};
		
		static void displayParseTree(Operator* op) {
			todo("Make function to display parse tree");
		}
};
