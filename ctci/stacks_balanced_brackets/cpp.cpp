/**
 * Stacks: Balanced Brackets
 *
 * Author: Eddo W. Hintoso
 * E-mail: eddo.hintoso+github@gmail.com
 */

#include <iostream>
#include <stack>

bool is_balanced(std::string expression) {
    std::stack<char> expr_stack;
    char bracket;
    char recent_char;
    for (int i = 0; i < (int) expression.length(); i++) {
        bracket = expression[i];
        if (bracket == '{' || bracket == '[' || bracket == '(') {
            expr_stack.push(bracket);
        }
        else {  // closing brackets
            if (expr_stack.size() < 1) {
                return false;
            }
            recent_char = expr_stack.top();
            if ((bracket == '}' && recent_char != '{')
                    || (bracket == ']' && recent_char != '[')
                    || (bracket == ')' && recent_char != '(')) {
                return false;
            }
            expr_stack.pop();
        }
    }
    if (!(expr_stack.empty())) {
        return false;
    }
    return true;
}

int main(void)
{
    int t;
    std::string expression;
    bool answer;

    std::cin >> t;

    for (int a0 = 0; a0 < t; a0++) {
        std::cin >> expression;
        answer = is_balanced(expression);
        std::cout << (answer ? "YES" : "NO") << std::endl;
    }

    return 0;
}
