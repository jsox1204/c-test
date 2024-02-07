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

    std::queue<int> bridge; // �ٸ��� �ִ� Ʈ��
    std::queue<int> time_trucks_entered_the_bridge; // �ٸ��� Ʈ���� �� �ð�
    std::queue<int> waiting_trucks; // ��� ���� Ʈ��

    int answer = 0;
    int total_weight = 0; // ���� �ٸ��� �ִ� Ʈ���� �ѹ���

    for (int i : trick_weights) {
        waiting_trucks.emplace(i);
    }

    do {
        answer++;

        if (!time_trucks_entered_the_bridge.empty() && answer == time_trucks_entered_the_bridge.front() + bridge_length) {
            time_trucks_entered_the_bridge.pop();
            total_weight -= (!bridge.empty()) ? bridge.front() : 0;
            bridge.pop();
        } // �ٸ��� �� �ǳʰ� Ʈ�� ���

        if (!waiting_trucks.empty() && weigth >= total_weight + waiting_trucks.front()) {
            total_weight += (!waiting_trucks.empty()) ? waiting_trucks.front() : 0;
            bridge.emplace(waiting_trucks.front());
            waiting_trucks.pop();
            time_trucks_entered_the_bridge.emplace(answer);
        } // �ٸ��� ���� Ʈ�� ���
    } while (!(waiting_trucks.empty() && bridge.empty()));

    return answer;
}
