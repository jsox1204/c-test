#include <iostream>
#include <string>

int get_digit(const int number);
int sum_odd_digits(const std::string &card_number);
int sum_even_digits(const std::string &card_number);

int main() {
    std::string card_number;
    int result = 0; // ī�� ��ȣ�� �� �˰������� ����ϱ� ���� ����

    std::cout << "ī���ȣ�� �Է��ϼ���: ";
    std::getline(std::cin, card_number);

    card_number.erase(std::remove(card_number.begin(), card_number.end(), ' '), card_number.end()); // ���� ����

    result = sum_even_digits(card_number) + sum_odd_digits(card_number);

    if (result % 10 == 0) {
        std::cout << "ī���ȣ�� ��ȿ�մϴ�.";
    } else {
        std::cout << "ī���ȣ�� ��ȿ���� �ʽ��ϴ�.";
    }

    return 0;
}

/**
 * \brief �� �ڸ� �����̸� �״�� ��ȯ�ϰ� �� �ڸ� ���� �̸� �� �ڸ��� ���� ���Ѵ�.
 * \param number ����� ����
 * \return ����� ��
 */
int get_digit(const int number) {

    return number % 10 + (number / 10 % 10);
}

/**
 * \brief ī���ȣ �����ʺ��� Ȧ����°�� ���ڸ� ���Ѵ�.
 * \param card_number ī���ȣ
 * \return Ȧ����°�� ���ڸ� ��� ���� ��
 */
int sum_odd_digits(const std::string &card_number) {

    int sum = 0;

    for (int i = static_cast<int>(card_number.size()) - 1; i >= 0; i -= 2) {
        sum += card_number[i] - '0';
    }

    return sum;
}

/**
 * \brief ī���ȣ �����ʺ��� ¦����°�� ���ڸ� 2��� �Ͽ� ���Ѵ� 2��� �� ���� 10�̻� �̸� �� �ڸ����� ���Ѵ�.
 * \param card_number ī���ȣ
 * \return ���Ͽ� ����� �����
 */
int sum_even_digits(const std::string &card_number) {

    int sum = 0;

    for (int i = static_cast<int>(card_number.size()) - 2; i >= 0; i -= 2) {
        sum += get_digit((card_number[i] - '0') * 2);
    }

    return sum;
}
