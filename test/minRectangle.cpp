#include <algorithm>
#include <iostream>
#include <vector>

int solution(const std::vector<std::vector<int>> &sizes);

int main() {
    const std::vector<std::vector<int>> sizes = {{60, 50}, {30, 70}, {60, 30}, {80, 40}};

    std::cout << solution(sizes) << '\n';
}

int solution(const std::vector<std::vector<int>> &sizes) {
    std::vector<int> widths; // 명함 너비 배열
    std::vector<int> heights; // 명함 높이 배열

    for (std::vector<int> size : sizes) { // 명함의 너비와 높이를 배열에 추가
        widths.emplace_back(size.at(0));
        heights.emplace_back(size.at(1));
    }

    // 명함의 너비와 높이의 최대값 구하기
    int width_max_index = static_cast<int>(std::max_element(widths.begin(), widths.end()) - widths.begin());
    int height_max_index = static_cast<int>(std::max_element(heights.begin(), heights.end()) - heights.begin());

    // 명함 중에 높이가 최대값인 명함의 너비가 높이보다 짧으면 명함을 눕힌 후(너비와 높이를 서로 바꾼다.) 최대값 다시 계산
    while (widths.at(height_max_index) < heights[height_max_index]) {
        const int temp = widths.at(height_max_index);
        widths.at(height_max_index) = heights[height_max_index];
        heights.at(height_max_index) = temp;

        width_max_index = static_cast<int>(std::max_element(widths.begin(), widths.end()) - widths.begin());
        height_max_index = static_cast<int>(std::max_element(heights.begin(), heights.end()) - heights.begin());
    }

    return widths[width_max_index] * heights[height_max_index];
}