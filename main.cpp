#include <iostream>
#include <string>
#include "operators.h"
#include "logic.h"

// This all is linux specific!!
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

using namespace std;

int main() {
    string infix = "";
    int choice = -1;
    cout << "Welcome to logic assignment."             << endl;
    cout << "Please enter the input infix expression." << endl;
    cout << BLUE << "Enter infix : " << RESET;
    cin  >> infix; 
    cout << "Now you can choose one of the following," << endl;

    while(true) {
        cout << "Option Menu : "                           << endl;
        cout << "1. Infix to prefix"                       << endl;
        cout << "2. Prefix to Parse Tree"                  << endl;
        cout << "3. Parse Tree to infix"                   << endl;
        cout << "4. Height of Parse Tree"                  << endl;
        cout << "5. Evaluate Parse Tree"                   << endl;
        cout << "6. Restart"                               << endl;
        cout << "7. Quit"                                  << endl;
        cout << "Choose option : ";
        cin  >> choice;

        // Clear screen, linux only, don't know what to do for windows
        clearScreen();

        switch (choice) {
            case 1:
                {
                    cout << GREEN << "The prefix expression of given infix is : " << Logic::infixToPrefix(infix) << RESET << endl;
                    break;
                }
            
            case 2:
                {
                    string prefix = Logic::infixToPrefix(infix);
                    Logic::Operator* op = Logic::prefixToParseTree(prefix);
                    cout << GREEN << "The Parse Tree of given infix is : " << RESET << endl;

                    todo("Figure out whether display is returning string or void");

                    Logic::displayParseTree(op);
                    break;
                }
            
            case 3:
                {
                    cout << GREEN << "The recalculated + bracketed infix form is : " << Logic::parseTreeToInfix(Logic::prefixToParseTree(Logic::infixToPrefix(infix))) << RESET << endl;
                    break;
                }

            case 4:
                {
                    string prefix = Logic::infixToPrefix(infix);
                    Logic::Operator* op = Logic::prefixToParseTree(prefix);
                    cout << GREEN << "Height of parse tree is : " << Logic::getParseTreeHeight(op) << RESET << endl;
                    break;
                }
            
            case 5:
                {
                    todo("Take inputs of truth values of the atoms");
                    // Calculate what atoms are there
                    // Ak for their values and store
                    // Evaluate the tree
                    break;
                }
            
            case 6:
                {
                    cout << YELLOW << "Starting afresh..." << RESET <<  endl;
                    cout << "Enter infix : ";
                    cin  >> infix;
                    break;
                }
            
            case 7:
                {
                    cout << BLUE << "Bye Bye \\O/" << RESET << endl;
                    return 0;
                    break;
                }
            
            default: 
                {
                    cout << RED << "Incorrect choice >:(" << RESET << endl;
                    return 0;
                }
        }
    }
}
