/*
선물을 직접 전하기 힘들 때 카카오톡 선물하기 기능을 이용해 축하 선물을 보낼 수 있습니다.
당신의 친구들이 이번 달까지 선물을 주고받은 기록을 바탕으로 다음 달에 누가 선물을 많이 받을지 예측하려고 합니다.

    두 사람이 선물을 주고받은 기록이 있다면, 이번 달까지 두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 선물을 하나 받습니다.
        예를 들어 A가 B에게 선물을 5번 줬고, B가 A에게 선물을 3번 줬다면 다음 달엔 A가 B에게 선물을 하나 받습니다.
    두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같다면, 선물 지수가 더 큰 사람이 선물 지수가 더 작은 사람에게 선물을 하나 받습니다.
        선물 지수는 이번 달까지 자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값입니다.
        예를 들어 A가 친구들에게 준 선물이 3개고 받은 선물이 10개라면 A의 선물 지수는 -7입니다. B가 친구들에게 준 선물이 3개고 받은 선물이 2개라면 B의 선물 지수는 1입니다.
        만약 A와 B가 선물을 주고받은 적이 없거나 정확히 같은 수로 선물을 주고받았다면, 다음 달엔 B가 A에게 선물을 하나 받습니다.
        만약 두 사람의 선물 지수도 같다면 다음 달에 선물을 주고받지 않습니다.

위에서 설명한 규칙대로 다음 달에 선물을 주고받을 때, 당신은 선물을 가장 많이 받을 친구가 받을 선물의 수를 알고 싶습니다.

친구들의 이름을 담은 1차원 문자열 배열 friends 이번 달까지 친구들이 주고받은 선물 기록을 담은 1차원 문자열 배열 gifts가 매개변수로 주어집니다.
이때, 다음달에 가장 많은 선물을 받는 친구가 받을 선물의 수를 return 하도록 solution 함수를 완성해 주세요.

제한사항

    2 ≤ friends의 길이 = 친구들의 수 ≤ 50
        friends의 원소는 친구의 이름을 의미하는 알파벳 소문자로 이루어진 길이가 10 이하인 문자열입니다.
        이름이 같은 친구는 없습니다.

    1 ≤ gifts의 길이 ≤ 10,000
        gifts의 원소는 "A B"형태의 문자열입니다. A는 선물을 준 친구의 이름을 B는 선물을 받은 친구의 이름을 의미하며 공백 하나로 구분됩니다.
        A와 B는 friends의 원소이며 A와 B가 같은 이름인 경우는 존재하지 않습니다.

 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <sstream>

int solution(std::vector<std::string> friends, std::vector<std::string> gifts);

int main() {
    std::vector<std::string> friends = { "muzi", "ryan", "frodo", "neo" };
    std::vector<std::string> gifts = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };

    std::cout << solution(friends, gifts) << "\n";
}

int solution(std::vector<std::string> friends, std::vector<std::string> gifts) {
    int answer = 0;
    std::vector<std::vector<int>> friends_to_gifts(friends.size(), std::vector<int>(friends.size(), 0)); // 주고 받은 선물 2차원 배열
    std::vector<int> gifting_indexes(friends.size(), 0); // 선물 지수 배열
    int temp_answer = 0; // 임시로 주고 받은 선물 갯수 저장

    for (const std::string& gift : gifts) {
        std::stringstream ss(gift);
        std::string given_friend, received_friend;
        ss >> given_friend >> received_friend;

        friends_to_gifts[std::distance(friends.begin(), std::find(friends.begin(), friends.end(), given_friend))]
        [std::distance(friends.begin(), std::find(friends.begin(), friends.end(), received_friend))] += 1;
    } // 2차원 배열로 주고 받은 선물 갯수 계산

    for (int i = 0; i < friends.size(); i++) {
        int given_gift = std::accumulate(friends_to_gifts[i].begin(), friends_to_gifts[i].end(), 0);
        int received_gift = std::accumulate(friends_to_gifts.begin(), friends_to_gifts.end(), 0, [&](int total, auto& v) {return total + v[i];});
        gifting_indexes[i] = given_gift - received_gift;
    } // // 각 친구의 준 선물의 합에서 받은 선물의 합을 빼서 선물 지수 계산

    for (int i = 0; i < friends_to_gifts.size(); i++) {
        for (int j = 0; j < friends_to_gifts[i].size(); j++) {
            if (i == j) continue;
            if (friends_to_gifts[i][j] > friends_to_gifts[j][i]) temp_answer++;
            if (friends_to_gifts[i][j] == friends_to_gifts[j][i] && gifting_indexes[i] > gifting_indexes[j]) temp_answer++;
        }
        if (temp_answer > answer) answer = temp_answer;
        temp_answer = 0;
    }

    return answer;
}