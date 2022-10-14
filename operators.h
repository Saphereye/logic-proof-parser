#include <iostream>

class Operator {
    private:
		char symbol;
		Operator* leftChild;
		Operator* rightChild;

    public:
		/**
		 * Contructor.
		 * For propositional atoms
		 */
		Operator(char sym) {
			symbol = sym;
			leftChild = NULL;
			rightChild = NULL;
		}

		/**
		 * Contructor.
		 * For Negation operator
		 */
		Operator(char sym, Operator* rChild) {
			symbol = sym;
			leftChild = NULL;
			rightChild = rChild;
		}

		/**
		 * Contructor.
		 * For * + and > operator
		 */
		Operator(char sym, Operator* lChild, Operator* rChild) {
			symbol = sym;
			leftChild = lChild;
			rightChild = rChild;
		}

		Operator* getLeftChild() {
			return leftChild;
		}

		Operator* getRightChild() {
			return rightChild;
		}

		char getSymbol() {
			return symbol;
		}

		void addLeftChild(Operator* child) {
			leftChild = child;
		}

		void addRightChild(Operator* child) {
			rightChild = child;
		}

		void addChildren(Operator* lChild, Operator* rChild) {
			leftChild = lChild;
			rightChild = rChild;
		}

		bool isAtom() {
			return (leftChild == NULL) && (rightChild == NULL);
		}
};
