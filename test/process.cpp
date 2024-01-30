#include <iostream>
#include <queue>
#include <vector>

int solution(std::vector<int> priorities, int location);

int main() {

    std::vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;

    std::cout << solution(priorities, location);
}

int solution(std::vector<int> priorities, int location) {

    std::queue<int> integer_queue;
    std::priority_queue<int> priority_queue;
    int answer = 0;

    for (int i = 0; i < static_cast<int> (priorities.size()); i++) {
        integer_queue.emplace(i);
        priority_queue.emplace(priorities[i]);
    }

    while (!integer_queue.empty()) {

        int process = integer_queue.front();
        integer_queue.pop();

        if (priorities[process] == priority_queue.top()) {
            priority_queue.pop();
            answer++;
            if (process == location) {
                return answer;
            }
        } else {
            integer_queue.push(process);
        }
    }

    return 0;
}

