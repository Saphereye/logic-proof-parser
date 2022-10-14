#include <iostream>

class Operator {
    private:
		char _symbol;
		Operator* _leftChild;
		Operator* _rightChild;

    public:
		/**
		 * @brief Construct a new Operator object
		 * 
		 * @param sym 
		 */
		Operator(char sym) {
			_symbol = sym;
			_leftChild = NULL;
			_rightChild = NULL;
		}

		/**
		 * @brief Construct a new Operator object
		 * 
		 * @param sym 
		 * @param rChild 
		 */
		Operator(char sym, Operator* rChild) {
			_symbol = sym;
			_leftChild = NULL;
			_rightChild = rChild;
		}

		/**
		 * @brief Construct a new Operator object
		 * 
		 * @param sym 
		 * @param lChild 
		 * @param rChild 
		 */
		Operator(char sym, Operator* lChild, Operator* rChild) {
			_symbol = sym;
			_leftChild = lChild;
			_rightChild = rChild;
		}

		/**
		 * @brief Get the Left Child object
		 * 
		 * @return Operator* 
		 */
		Operator* getLeftChild() {
			return _leftChild;
		}

		/**
		 * @brief Get the Right Child object
		 * 
		 * @return Operator* 
		 */
		Operator* getRightChild() {
			return _rightChild;
		}

		/**
		 * @brief Get the Symbol object
		 * 
		 * @return char 
		 */
		char getSymbol() {
			return _symbol;
		}

		/**
		 * @brief Adds left child
		 * 
		 * @param child 
		 */
		void addLeftChild(Operator* child) {
			_leftChild = child;
		}

		/**
		 * @brief Adds right child
		 * 
		 * @param child 
		 */
		void addRightChild(Operator* child) {
			_rightChild = child;
		}

		/**
		 * @brief Adds both children simultaneosly
		 * 
		 * @param lChild 
		 * @param rChild 
		 */
		void addChildren(Operator* lChild, Operator* rChild) {
			_leftChild = lChild;
			_rightChild = rChild;
		}

		/**
		 * @brief Returns true if self is propositional atom
		 * 
		 * @return true 
		 * @return false 
		 */
		bool isAtom() {
			return (_leftChild == NULL) && (_rightChild == NULL);
		}
};
