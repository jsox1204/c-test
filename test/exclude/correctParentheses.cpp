#include <iostream>
#include <stack>

bool solution(std::string parentheses);

int main() {

    std::string parentheses = "((((((())))((())))))";

    std::cout << (solution(parentheses) ? "true" : "false") << '\n';
}

bool solution(std::string parentheses) {

    std::stack<int> integer_stack;

    for (int i = 0; i < static_cast<int> (parentheses.size()); i++) {
        if (parentheses[i] == '(') {
            integer_stack.push(1);
        } else if (parentheses[i] == ')') {
            if (integer_stack.empty()) {
                return false;
            }
            integer_stack.pop();
        }
    }

    return integer_stack.empty();
}
