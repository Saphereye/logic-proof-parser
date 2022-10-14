#include <iostream>

using namespace std;

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
};
