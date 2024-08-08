#include <iostream>
#include <queue>
#include <vector>

int solution(int bridge_length, int weigth, std::vector<int> trick_weights);

int main() {

    int bridge_length = 100;
    int weight = 100;
    std::vector<int> trick_weights = {10,10,10,10,10,10,10,10,10,10};

    std::cout << solution(bridge_length, weight, trick_weights) << '\n';
}

int solution(int bridge_length, int weigth, std::vector<int> trick_weights) {

    std::queue<int> bridge; // 다리에 있는 트럭
    std::queue<int> time_trucks_entered_the_bridge; // 다리에 트럭이 들어간 시간
    std::queue<int> waiting_trucks; // 대기 중인 트럭

    int answer = 0;
    int total_weight = 0; // 현재 다리에 있는 트럭의 총무게

    for (int i : trick_weights) {
        waiting_trucks.emplace(i);
    }

    do {
        answer++;

        if (!time_trucks_entered_the_bridge.empty() && answer == time_trucks_entered_the_bridge.front() + bridge_length) {
            time_trucks_entered_the_bridge.pop();
            total_weight -= (!bridge.empty()) ? bridge.front() : 0;
            bridge.pop();
        } // 다리를 다 건너간 트럭 계산

        if (!waiting_trucks.empty() && weigth >= total_weight + waiting_trucks.front()) {
            total_weight += (!waiting_trucks.empty()) ? waiting_trucks.front() : 0;
            bridge.emplace(waiting_trucks.front());
            waiting_trucks.pop();
            time_trucks_entered_the_bridge.emplace(answer);
        } // 다리에 들어가는 트럭 계산
    } while (!(waiting_trucks.empty() && bridge.empty()));

    return answer;
}
