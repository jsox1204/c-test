#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int solution(std::vector<std::vector<std::string>> clothes);

int main() {

    std::vector<std::vector<std::string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};

    std::cout << solution(clothes);
}

int solution(std::vector<std::vector<std::string>> clothes) {

    int answer = 1;

    if (clothes.empty()) {
        return 0;
    }

    std::unordered_map<std::string, int> map;

    for (auto v_string : clothes) {
        map[v_string[1]] += 1;
    }

    for (std::pair<std::string, int> pair : map) {
        answer *= (pair.second + 1);
    }

    answer -= 1;

    return answer;
}
