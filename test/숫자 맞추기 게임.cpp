#include <iostream>
#include <random>


int main() {

    // 시드값을 얻기 위한 random_device 생성
    std::random_device random_device;

    // random_device 를 통해 난수 생성 엔진을 초기화
    std::mt19937 gen_mt19937(random_device());

    // 0 부터 100 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의
    std::uniform_int_distribution<int> distribution(1, 100);

    int guess; // 입력한 숫자
    int tries = 0; // 시도한 횟수
    int num = distribution(gen_mt19937); // 정답 숫자

    std::cout << "***** 숫자 맞추기 게임 *****\n";

    do {
        std::cout << "숫자를 입력하세요 (1 ~ 100): ";
        std::cin >> guess;
        tries++;

        if (guess > num) {
            std::cout << "입력한 숫자가 더 큽니다.\n";

        } else if (guess < num) {
            std::cout << "입력한 숫자가 더 작습니다.\n";

        } else {
            std::cout << "정답! 시도 횟수: " << tries << '\n';
        }
    }
    while (guess != num);

    std::cout << "***** 숫자 맞추기 게임 *****\n";

	return 0;
}
