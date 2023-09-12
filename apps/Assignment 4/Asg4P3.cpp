#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>
#include <string>
// Had help from ChatGPT with this program

using namespace std;

double evaluateExpression(const string& expression);
string infixToPrefix(const string& infix);
string infixToPostfix(const string& infix);

int main() {
    string input;
    cout << "Type a fully parenthesized expression" << endl;
    getline(cin, input);

    double answer = evaluateExpression(input);

    cout << "That evaluates to " << answer << endl;

    string prefixExpression = infixToPrefix(input);
    string postfixExpression = infixToPostfix(input);

    cout << "Prefix Notation: " << prefixExpression << endl;
    cout << "Postfix Notation: " << postfixExpression << endl;

    return 0;
}

double evaluateExpression(const string& expression) {
    stack<double> numbers;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        if (isdigit(ch)) {
            double num = 0;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                num = num * 10 + (expression[i] - '0');
                ++i;
            }
            --i;  // Move back one character to account for loop increment
            numbers.push(num);
        } else if (ch == ' ') {
            continue;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double op2 = numbers.top();
                numbers.pop();
                double op1 = numbers.top();
                numbers.pop();
                char op = operators.top();
                operators.pop();
                if (op == '+') {
                    numbers.push(op1 + op2);
                } else if (op == '-') {
                    numbers.push(op1 - op2);
                } else if (op == '*') {
                    numbers.push(op1 * op2);
                } else if (op == '/') {
                    numbers.push(op1 / op2);
                }
            }
            operators.pop(); // Remove the '('
        } else {
            while (!operators.empty() && operators.top() != '(' &&
                   ((ch == '*' || ch == '/') ||
                    (ch == '+' || ch == '-' && (operators.top() == '+' || operators.top() == '-')))) {
                double op2 = numbers.top();
                numbers.pop();
                double op1 = numbers.top();
                numbers.pop();
                char op = operators.top();
                operators.pop();
                if (op == '+') {
                    numbers.push(op1 + op2);
                } else if (op == '-') {
                    numbers.push(op1 - op2);
                } else if (op == '*') {
                    numbers.push(op1 * op2);
                } else if (op == '/') {
                    numbers.push(op1 / op2);
                }
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        double op2 = numbers.top();
        numbers.pop();
        double op1 = numbers.top();
        numbers.pop();
        char op = operators.top();
        operators.pop();
        if (op == '+') {
            numbers.push(op1 + op2);
        } else if (op == '-') {
            numbers.push(op1 - op2);
        } else if (op == '*') {
            numbers.push(op1 * op2);
        } else if (op == '/') {
            numbers.push(op1 / op2);
        }
    }

    return numbers.top();
}

string infixToPrefix(const string& infix) {
    stack<char> operators;
    stack<string> operands;

    for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        if (isdigit(ch)) {
            string operand;
            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
                operand += infix[i];
                ++i;
            }
            --i;
            operands.push(operand);
        } else if (ch == ' ') {
            continue;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string expression = op + operand1 + operand2;
                operands.push(expression);
            }
            operators.pop(); // Remove the '('
        } else {
            while (!operators.empty() && operators.top() != '(' &&
                   ((ch == '*' || ch == '/') ||
                    (ch == '+' || ch == '-' && (operators.top() == '+' || operators.top() == '-')))) {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string expression = op + operand1 + operand2;
                operands.push(expression);
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        string expression = op + operand1 + operand2;
        operands.push(expression);
    }

    return operands.top();
}

string infixToPostfix(const string& infix) {
    stack<char> operators;
    stack<string> operands;

    for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        if (isdigit(ch)) {
            string operand;
            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
                operand += infix[i];
                ++i;
            }
            --i;
            operands.push(operand);
        } else if (ch == ' ') {
            continue;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string expression = operand1 + operand2 + op;
                operands.push(expression);
            }
            operators.pop(); // Remove the '('
        } else {
            while (!operators.empty() && operators.top() != '(' &&
                   ((ch == '*' || ch == '/') ||
                    (ch == '+' || ch == '-' && (operators.top() == '+' || operators.top() == '-')))) {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string expression = operand1 + operand2 + op;
                operands.push(expression);
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        string expression = operand1 + operand2 + op;
        operands.push(expression);
    }

    return operands.top();
}
