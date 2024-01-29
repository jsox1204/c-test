#include <iostream>
#include <stack>
#include <vector>

std::vector<int> solution(std::vector<int> prices);

int main() {
    std::vector<int> prices = { 1, 2, 3, 2, 3 };

    for (int i : solution(prices)) {
        std::cout << i << ' ';
    }
}

std::vector<int> solution(std::vector<int> prices) {

    std::vector<int> answer;
    answer.resize(static_cast<int> (prices.size()), 0);

    std::stack<int> time;

    for (int i = 0; i < static_cast<int> (prices.size()); i++) {
        while (!time.empty() && prices[i] < prices[time.top()]) {
            answer[time.top()] = i - time.top();
            time.pop();
        }
        time.push(i);
    }

    while (!time.empty()) {
        answer[time.top()] = static_cast<int> (prices.size()) - time.top() - 1;
        time.pop();
    }

    return answer;
}
