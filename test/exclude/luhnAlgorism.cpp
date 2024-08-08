#include <iostream>
#include <string>

int get_digit(const int number);
int sum_odd_digits(const std::string &card_number);
int sum_even_digits(const std::string &card_number);

int main() {
    std::string card_number;
    int result = 0; // 카드 번호를 룬 알고리즘으로 계산하기 위한 변수

    std::cout << "카드번호를 입력하세요: ";
    std::getline(std::cin, card_number);

    card_number.erase(std::remove(card_number.begin(), card_number.end(), ' '), card_number.end()); // 공백 제거

    result = sum_even_digits(card_number) + sum_odd_digits(card_number);

    if (result % 10 == 0) {
        std::cout << "카드번호가 유효합니다.";
    } else {
        std::cout << "카드번호가 유효하지 않습니다.";
    }

    return 0;
}

/**
 * \brief 한 자리 숫자이면 그대로 반환하고 두 자리 숫자 이면 각 자리의 수를 합한다.
 * \param number 계산할 숫자
 * \return 계산한 값
 */
int get_digit(const int number) {

    return number % 10 + (number / 10 % 10);
}

/**
 * \brief 카드번호 오른쪽부터 홀수번째의 숫자를 더한다.
 * \param card_number 카드번호
 * \return 홀수번째의 숫자를 모두 더한 값
 */
int sum_odd_digits(const std::string &card_number) {

    int sum = 0;

    for (int i = static_cast<int>(card_number.size()) - 1; i >= 0; i -= 2) {
        sum += card_number[i] - '0';
    }

    return sum;
}

/**
 * \brief 카드번호 오른쪽부터 짝수번째의 숫자를 2배로 하여 더한다 2배로 한 값이 10이상 이면 각 자릿수를 더한다.
 * \param card_number 카드번호
 * \return 더하여 계산한 결과값
 */
int sum_even_digits(const std::string &card_number) {

    int sum = 0;

    for (int i = static_cast<int>(card_number.size()) - 2; i >= 0; i -= 2) {
        sum += get_digit((card_number[i] - '0') * 2);
    }

    return sum;
}
