#include <iostream>
#include <locale>
#include <string>

int main() {

    const std::string questions[] = {"1. 광복이 된 연도는 언제인가?: ",
                                "2. c++는 만들어진 연도는?: ",
                                "3. 알파벳 I 다음 순서의 알파벳은?: ",
                                "4. 31 + 15는?: "};

    const std::string options[][4] = {{"A. 1934년", "B. 1945년", "C. 1964년", "D. 1972년"},
                                {"A. 1969년", "B. 1975년", "C. 1985년", "D. 1989년"},
                                {"A. G", "B. J", "C. L", "D. N"},
                                {"A. 42", "B. 44", "C. 46", "D. 48"}};

    char answer_key[] = {'B', 'C', 'B', 'C'};

    constexpr int size = std::size(questions);
    char guess;
    int score = 0;

    for (int i = 0; i < size; i++) {

        std::cout << "**************************************\n";
        std::cout << questions[i] << '\n';
        std::cout << "**************************************\n";

        for (int j = 0; j < static_cast<int>( std::size(options[i]) ); j++) {

            std::cout << options[i][j] << '\n';
        }

        std::cin >> guess;
        guess = static_cast<char>(toupper(guess));

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (guess == answer_key[i]) {

            std::cout << "정답입니다!\n";
            score++;

        } else {

            std::cout << "틀렸습니다!\n";
            std::cout << "정답은 " << answer_key[i] << "입니다.\n";
        }
    }

    std::cout << "\n***********************************************\n";
    std::cout << size << "문제 중에 " << score << "문제를 맞췄습니다.\n";
    std::cout << "점수는 " <<  (static_cast<double>(score) / size) * 100 << "점입니다.\n";

    return 0;
}


