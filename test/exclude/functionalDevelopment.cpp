#include <iostream>
#include <stack>
#include <vector>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds);

int main() {

    std::vector<int> progresses = {95, 90, 99, 99, 80, 99};
    std::vector<int> speeds = {1, 1, 1, 1, 1, 1};

    for (int i : solution(progresses, speeds)) {
        std::cout << i << ' ';
    }
}

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds) {

    std::stack<int> integer_stack;
    std::vector<int> days;

    days.reserve(static_cast<int>(progresses.size()));

    for (int i = 0; i < static_cast<int> (progresses.size()); i++) {
        days.emplace_back(static_cast<int> ( std::ceil (static_cast<double> (100 - progresses[i]) / speeds[i]) ) );
    }

    std::vector<int> for_each_distribution;

    integer_stack.push(0);

    for (int i = 0; i < static_cast<int> (days.size()); i++) {
        if (days[integer_stack.top()] < days[i]) {
            for_each_distribution.emplace_back(i - integer_stack.top());
            integer_stack.push(i);
        }
    }

    if (days[integer_stack.top()] != days[static_cast<int> (days.size()) - 1]) {
        for_each_distribution.emplace_back(static_cast<int> (days.size()) - integer_stack.top());
    } else {
        for_each_distribution.emplace_back(1);
    }

    return for_each_distribution;
}
