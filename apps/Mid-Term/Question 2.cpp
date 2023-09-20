#include <stack>
#include <iostream>

int main(){
    std::stack<char> myStack;
    std::string input;
    std::cout << "Please input your parenthesis!" << std::endl;
    std::cin >> input;

    for (int i = 0; i < input.length(); i++){
        if (input[i] == '('){
            myStack.push('(');
        }
        else if (input[i] == ')'){
            // if the stack is empty and you need to pop, then there is an inbalance
            if (myStack.empty()){
                std::cout << "Your parenthesis are inbalanced!" << std::endl;
                return 0;
            }
            else{
                myStack.pop();
            }
        }

        if (myStack.empty()){
            std::cout << "Your parenthesis are balanced!" << std::endl;
        }
        else{
            std::cout << "Your parenthesis are inbalanced!" << std::endl;
        }
        return 0;
    }
}