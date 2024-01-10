#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string solution(std::vector<std::string> participant, std::vector<std::string> completion);

int main() {

    std::vector<std::string> participant = {"mislav", "stanko", "mislav", "ana"};
    std::vector<std::string> completion =  {"stanko", "ana", "mislav"};

    std::cout << solution(participant, completion) << '\n';
}

std::string solution(std::vector<std::string> participant, std::vector<std::string> completion) {

    std::unordered_map<std::string, int> unordered_map;
    std::string answer;

    for (auto c : completion) {
        unordered_map[c] += 1;
    }

    for (auto p : participant) {
        unordered_map[p] -= 1;

        if (unordered_map[p] < 0) {
            answer = p;
        }
    }

    return answer;
}