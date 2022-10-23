#include <iostream>
#include "helper.h"
using namespace std;

/**
 * @brief Generic stack implementation using array
 * 
 * @tparam T 
 */
template <typename T>
class Stack {
    private:
        int _top;
        T *_stack;
        size_t _MAX;
    
    public:
        /**
         * @brief Construct a new Stack object
         * 
         * @param stackSize 
         */
        Stack(size_t stackSize) {
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
            if (_top >= (int(_MAX))) {
                error("Stack Overflow", _top);
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
                //error("Stack Underflow", _top);
                return T();
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
         * @brief Returns true if stack is full
         * 
         * @return true 
         * @return false 
         */
        bool isFull() {
            // If _top is pointing to the top-most index
            return _top == (int(_MAX) - 1); // TODO : Make this comparison more generic
        };
};
