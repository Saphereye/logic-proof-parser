/**
 * @brief Node of parse tree. Contains a symbol, pointer to left child, poitner to right child
 * 
 */
class Operator {
    private:
		char _symbol;
		Operator* _leftChild;
		Operator* _rightChild;

    public:
		/**
		 * @brief Constructor of new Operator object in case of propositional atom which has no children
		 * 
		 * @param sym Can be a propositional atom or a binary or unary operator 
		 */

		Operator(char sym) {
			_symbol = sym;
			_leftChild = nullptr;
			_rightChild = nullptr;
		}

		/**
		 * @brief Constructor of new Operator object used in case of negation operator which has one child (one propositional atom)
		 * 
		 * @param sym Negation operator
		 * @param rChild Propositional atom whose negation is taken 
		 */
		Operator(char sym, Operator* rChild) {
			_symbol = sym;
			_leftChild = nullptr;
			_rightChild = rChild;
		}

		/**
		 * @brief Constructor of new Operator object used in case of binary operators which have both left and right children (two propositional atoms )
		 * 
		 * @param sym Binary operators
		 * @param lChild Pointer to left child which can be either propositional atom or other operator
		 * @param rChild Pointer to right child which can be either propositional atom or other operator
		 */
		Operator(char sym, Operator* lChild, Operator* rChild) {
			_symbol = sym;
			_leftChild = lChild;
			_rightChild = rChild;
		}

		/**
		 * @brief Get the Left Child object
		 * 
		 * @return Operator* Left child object
		 */
		Operator* getLeftChild() {
			return _leftChild;
		}

		/**
		 * @brief Get the Right Child object
		 * 
		 * @return Operator* Right child object
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
		 * @param child Pointer to operator object
		 */
		void addLeftChild(Operator* child) {
			_leftChild = child;
		}

		/**
		 * @brief Adds right child
		 * 
		 * @param child Pointer to operator object
		 */
		void addRightChild(Operator* child) {
			_rightChild = child;
		}

		/**
		 * @brief Adds both children simultaneosly
		 * 
		 * @param lChild Pointer to operator object
		 * @param rChild Pointer to operator object
		 */
		void addChildren(Operator* lChild, Operator* rChild) {
			_leftChild = lChild;
			_rightChild = rChild;
		}

		/**
		 * @brief To check if it is propositional atom
		 * 
		 * @return true If it is propositional atom
		 * @return false If it is not a propositional atom 
		 */
		bool isAtom() {
			return (_leftChild == nullptr) && (_rightChild == nullptr);
		}

		/**
		 * @brief Checks if it's a unary operator, i.e. is of the form <none> <operator> <operand>, unlike common operators <left operand> <operator> <right operand>
		 * 
		 * @return true In case it is unary operator
		 * @return false In case it is unary operator
		 */
		bool isUnaryOperator() {
			return (_leftChild == nullptr) && (_rightChild != nullptr);
		}
};
