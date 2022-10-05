#include <string>
#include <algorithm> 
#include "stack.h"
#include <map>

using namespace std;

map<char, int> precedenceMap = {
    {'>', 1},
    {'+', 2},
    {'*', 3},
    {'~', 4},
};

class Logic {
    public:
        static string infixToPrefix(string infix) {
            int index = infix.length() - 1;
            string outputPrefix = "";
            Stack<char> stck(int(infix.length()));

            while(index >= -1) {
                // Checking if the element is a letter or something else
                // This is assuming all inputs would be perfect
                // cout << "Current Element : " << infix[index] << " Current Index : " << index << endl;
                if(isalpha(infix[index])) {
                    outputPrefix += infix[index];
                } else {
                    if (stck.isEmpty()) {
                        stck.push(infix[index]);
                    } else if (precedenceMap[infix[index]] >= precedenceMap[stck.peek()]) {
                        stck.push(infix[index]);
                    } else {
                        outputPrefix += stck.pop();
                        continue;
                    }
                }
                
                index--;
            }
            reverse(outputPrefix.begin(), outputPrefix.end());
            return outputPrefix;
        };

        
        #include "parseTree.h"
        static ParseTree prefixToParseTree(string prefix);


        // void _setInfix(string val);
        // string _getInfix();

        // string _getPrefix(string inputInfix) {
        //     return infixToPrefix(inputInfix);
        // };

        // ParseTree _getParseTree(string inputPrefix) {
        //     return prefixToParseTree(inputPrefix);
        // };
};