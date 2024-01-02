#include <iomanip>
#include <iostream>

void show_balance(double balance);
double deposit();
double withdraw(double balance);

int main() {

    double balance = 30000;
    int choice = 0;
    std::cout.imbue(std::locale(""));

    do
    {
        std::cout << "************************\n";
        std::cout << "작업을 선택하세요:\n";
        std::cout << "************************\n";
        std::cout << "1. 잔액 확인\n";
        std::cout << "2. 입금\n";
        std::cout << "3. 출금\n";
        std::cout << "4. 나가기\n";
        std::cin >> choice;

        while (getchar() != '\n') {} // 입력버퍼 지우기

        switch (choice) {
        case 1: show_balance(balance);
            break;
        case 2: balance += deposit();
                show_balance(balance);
            break;
        case 3: balance -= withdraw(balance);
                show_balance(balance);
                break;
        case 4: std::cout << "방문해주셔셔 감사합니다.";
            break;
        default: std::cout << "맞지 않는 선택입니다.\n";
        }
    } while (choice != 4);

    return 0;
}

/**
 * \brief 현재 은행에 있는 잔액을 보여준다.
 * \param balance 은행 예금의 잔액
 */
void show_balance(double balance) {
    std::cout << "잔액은 \uFFE6" << std::setprecision(2) << std::fixed << balance << '\n';
}

/**
 * \brief 은행의 계좌에 입금한다.
 * \return 은행계좌에서 입금한 금액
 */
double deposit() {

    double amount = 0;

    std::cout << "입금금액을 입력하세요: \uFFE6";
    std::cin >> amount;

    if (amount > 0) {
        return amount;
    } else {
        std::cout << "허용하지 않은 값입니다.\n";
        return 0;
    }
}

/**
 * \brief 은행의 계좌에서 출금한다.
 * \param balance 은행 예금의 잔액
 * \return 은행계좌에서 출금한 금액
 */
double withdraw(double balance) {

    double amount = 0;

    std::cout << "출금금액을 입력하세요: \uFFE6";
    std::cin >> amount;

    if (amount > balance) {
        std::cout << "현재 계좌에 있는 잔액보다 출금할 금액이 더 큽니다.\n";
        return 0;
    } else if (amount < 0) {
        std::cout << "허용하지 않은 값입니다.\n";
        return 0;
    }
    else {
        return amount;
    }
}