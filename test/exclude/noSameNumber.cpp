#include <iostream>
#include <queue>
#include <vector>

std::vector<int> solution(std::vector<int> arr);

template<class T>
std::ostream& operator << (std::ostream& stream, const std::vector<T>& values) {
    std::copy(std::begin(values), std::end(values), std::ostream_iterator<T>(stream, " "));
    return stream;
}

int main() {

    std::vector<int> arr = { 1, 1, 3, 3, 0, 1, 1 };

    std::cout << solution(arr);

}



std::vector<int> solution(std::vector<int> arr) {

    std::vector<int> answer;
    std::queue<int> int_queue;
    int check_num = -1;

    for (int num : arr) {
        if (num != check_num) {
            int_queue.push(num);
            check_num = num;
        }
    }

    while (!(int_queue.empty())) {
        answer.emplace_back(int_queue.front());
        int_queue.pop();
    }

    return answer;
}
