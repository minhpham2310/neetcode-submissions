using namespace std;

class Solution {
public:
    int doMath(int left, string& mathOperator, int right) {
        switch (mathOperator[0]) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case'*':
            return left * right;
        case'/':
            return left / right;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        vector<int> operandStack;
        for (string& item : tokens) {
            if (item != "+" && item != "*" && item != "-" && item != "/") {
                operandStack.push_back(stoi(item));
            }
            else {
                int operand1{ operandStack.back() };
                operandStack.pop_back();
                int operand2{ operandStack.back() };
                operandStack.pop_back();
                operandStack.push_back(doMath(operand2, item, operand1));
            }
        }
        return operandStack.back();
    }
};