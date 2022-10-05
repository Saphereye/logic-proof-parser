#include <iostream>
using namespace std;

template < typename T >
class Stack {
    private:
        int _top;
        T *_stack;
        int _MAX;
    
    public:
        Stack(int stackSize) {
            _top = -1; // TODO : Make it generic
            _MAX = stackSize;
            _stack = new T[_MAX];
        };

        bool push(T newElement) {
            if (_top >= (_MAX - 1)) {
                cout << "Stack Overflow" << endl;
                return false;
            }

            _top++;
            _stack[_top] = newElement;
            return true;
            
        };

        T pop() {
            // Removes the top most element of stack and return it
            if (_top < 0) {
                cout << "Stack Underflow" << endl;
            } else {
                return _stack[_top--];
            }
        };

        T peek() {
            // Returns top most element of stack
            return _stack[_top];
        };

        bool isEmpty() {
            // If _top is -1, the stack is empty
            return _top < 0;
        };

        bool isFull() {
            // If _top is pointing to the top-most index
            return _top == (_MAX - 1); // TODO : Make this comparison more generic
        };
};