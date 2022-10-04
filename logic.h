#include <string>
#include "parseTree.h"

using namespace std;

class Logic {
    public:
        static string calculatePrefix(string infix);
        static ParseTree calculateParseTree(string prefix);


        void _setInfix(string val);
        string _getInfix();

        string _getPrefix(string inputInfix) {
            return calculatePrefix(inputInfix);
        };

        ParseTree _getParseTree(string inputPrefix) {
            return calculateParseTree(inputPrefix);
        };
};