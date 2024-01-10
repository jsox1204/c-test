#include <iostream>
#include <set>
#include <vector>

int solution(std::vector<int> num);

int main() {

    std::vector<int> num = { 3, 3, 3, 2, 2, 2 };

    std::cout << solution(num) << '\n';

    return 0;
}

int solution(std::vector<int> num) {

    int answer = 0;

    std::set<int> set(num.begin(), num.end());

    int num_size = static_cast<int>(set.size());
    int num_div2 = static_cast<int>(num.size()) / 2;

    answer = std::min(num_size, num_div2);

    return answer;
}
