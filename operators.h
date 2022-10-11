#include <iostream>

using namespace std;

class Operator {
    private:
	char _operator;
	bool _leftOperand;
	bool _rightOperand;

    public:
	Operator(char op, bool rightOp) {
	    //Operator only for ~
	    _operator = op;
	    _rightOperand = rightOp;
	}

	Operator(char op, bool leftOp, bool rightOp) {
	    // Operator for *, + and >
	    _operator = op;
	    _leftOperand = leftOp;
	    _rightOperand = rightOp;
	}


	bool getTruthValue() {
	    switch (_operator) {
		case '~':
		    return (!_rightOperand);
		    break;
		case '*':
		    return (_leftOperand && _rightOperand);
		    break;
		case '+':
		    return (_leftOperand || _rightOperand);
		    break;
		case '>':
		    return ((!_leftOperand) || _rightOperand);
		    break;
		default:
		    cout <<  "Incorrenct operator" << endl;
		    break;
	    }
	}
};
