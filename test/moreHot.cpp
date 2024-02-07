#include <iostream>
#include <queue>
#include <vector>

/*
�ſ� ���� �����ϴ� Leo�� ��� ������ ���ں� ������ K �̻����� ����� �ͽ��ϴ�. ��� ������ ���ں� ������ K �̻����� ����� ���� Leo�� ���ں� ������ ���� ���� �� ���� ������ �Ʒ��� ���� Ư���� ������� ���� ���ο� ������ ����ϴ�.

���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)

Leo�� ��� ������ ���ں� ������ K �̻��� �� ������ �ݺ��Ͽ� �����ϴ�.
Leo�� ���� ������ ���ں� ������ ���� �迭 scoville�� ���ϴ� ���ں� ���� K�� �־��� ��, ��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����

    - scoville�� ���̴� 2 �̻� 1,000,000 �����Դϴ�.
    - K�� 0 �̻� 1,000,000,000 �����Դϴ�.
    - scoville�� ���Ҵ� ���� 0 �̻� 1,000,000 �����Դϴ�.
    - ��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return �մϴ�.
 */

int solution(std::vector<int> scoville, int k);

int main() {

    std::vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int k = 7;

    std::cout << solution(scoville, k) << '\n';
}

int solution(std::vector<int> scoville, int k) {

    std::priority_queue<int, std::vector<int>, std::greater<>> queue_scoville;
    int answer = 0;

    for (int i : scoville) {
        queue_scoville.emplace(i);
    }

    if (!queue_scoville.empty() && queue_scoville.top() >= k) {
        return answer;
    }

    do {
        answer++;

        if (queue_scoville.size() < 2) {
            return -1;
        }
        int minScoville1 = queue_scoville.top();
        queue_scoville.pop();
        int minScoville2 = queue_scoville.top();
        queue_scoville.pop();
        queue_scoville.emplace(minScoville1 + (minScoville2 * 2));
        
    }
    while (!queue_scoville.empty() && queue_scoville.top() < k);

    return answer;
}
