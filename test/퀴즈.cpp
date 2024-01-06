#include <iostream>
#include <locale>
#include <string>

int main() {

    const std::string questions[] = {"1. ������ �� ������ �����ΰ�?: ",
                                "2. c++�� ������� ������?: ",
                                "3. ���ĺ� I ���� ������ ���ĺ���?: ",
                                "4. 31 + 15��?: "};

    const std::string options[][4] = {{"A. 1934��", "B. 1945��", "C. 1964��", "D. 1972��"},
                                {"A. 1969��", "B. 1975��", "C. 1985��", "D. 1989��"},
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

            std::cout << "�����Դϴ�!\n";
            score++;

        } else {

            std::cout << "Ʋ�Ƚ��ϴ�!\n";
            std::cout << "������ " << answer_key[i] << "�Դϴ�.\n";
        }
    }

    std::cout << "\n***********************************************\n";
    std::cout << size << "���� �߿� " << score << "������ ������ϴ�.\n";
    std::cout << "������ " <<  (static_cast<double>(score) / size) * 100 << "���Դϴ�.\n";

    return 0;
}


