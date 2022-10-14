#include <iostream>
using namespace std;

template <typename T>
class Stack {
    private:
        int _top;
        T *_stack;
        int _MAX;
    
    public:
        /**
         * @brief Construct a new Stack object
         * 
         * @param stackSize 
         */
        Stack(int stackSize) {
            _top = -1;
            _MAX = stackSize;
            _stack = new T[_MAX];
        };

        /**
         * @brief Pushes object of type T on stack
         * 
         * @param newElement 
         * @return true 
         * @return false 
         */
        bool push(T newElement) {
            if (_top >= (_MAX - 1)) {
                cout << "Stack Overflow" << endl;
                return false;
            }

            _top++;
            _stack[_top] = newElement;
            return true;
            
        };

        /**
         * @brief Removes and returns top most objec of stack
         * 
         * @return T 
         */
        T pop() {
            if (_top < 0) {
                cout << "Stack Underflow" << endl;
            } else {
                return _stack[_top--];
            }
        };

        /**
         * @brief Returns top most object of stack
         * 
         * @return T 
         */
        T peek() {
            return _stack[_top];
        };

        /**
         * @brief Return true if stack is empty
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty() {
            // If _top is -1, the stack is empty
            return _top < 0;
        };

        /**
         * @brief Returns true if stack ios full
         * 
         * @return true 
         * @return false 
         */
        bool isFull() {
            // If _top is pointing to the top-most index
            return _top == (_MAX - 1); // TODO : Make this comparison more generic
        };
};
