#include <iostream>
#include <random>

char get_user_choice();
char get_computer_choice();
void show_choice(char choice);
void choose_winner(char player, char computer);

std::random_device random_device;

int main() {

    char answer; // 가위바위보 게임을 다시하는 지에 대한 대답

    do {
        
        char player = get_user_choice();

        show_choice(player);
        std::cout << "를 선택했습니다.\n";

        char computer = get_computer_choice();
        std::cout << "컴퓨터의 선택: ";
        show_choice(computer);

        std::cout << '\n';
        choose_winner(player, computer);

        do {
            std::cout << "다시 하시겠습니까? (y / n): ";
            std::cin >> answer;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (answer != 'y' && answer != 'n') {
                std::cout << "허용하지 않은 값입니다. 다시 입력하세요.\n";
            }
        } while (answer != 'y' && answer != 'n');

    } while (answer != 'n');


    return 0;
}

/**
 * \brief 유저가 가위바위보에 대한 선택을 하도록 하는 함수
 * \return 유저가 선택한 가위바위보
 */
char get_user_choice() {

    char player;
    std::cout << "가위바위보 게임!";

    do {
        std::cout << "***************************";
        std::cout << "하나를 선택하세요!\n";
        std::cout << "'s'은 가위\n";
        std::cout << "'r'는 바위\n";
        std::cout << "'p'는 보\n";
        std::cin >> player;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (player != 's' && player != 'r' && player != 'p');

    return player;
}

/**
 * \brief 컴퓨터가 무작위로 가위바위보를 선택하는 함수
 * \return 컴퓨터가 선택한 가위바위보
 */
char get_computer_choice() {

    std::mt19937 gen_mt19937(random_device());

    std::uniform_int_distribution<int> distribution(1, 3);

    switch (distribution(gen_mt19937)) {
        case 1 :
            return 'r';
        case 2 :
            return 'p';
        case 3 :
            return 's';
        default :
            std::cout << "알 수 없는 오류\n";
            EOF;
            return 0;
    }
}

/**
 * \brief 선택한 대상 가위바위보를 출력
 * \param choice 출력할 대상 (유저 또는 컴퓨터)
 * @warning 파라미터는 'r', 'p', 's'만 입력
 */
void show_choice(char choice) {

    switch (choice) {
        case 's' :
            std::cout << "가위";
            break;
        case 'r' :
            std::cout << "바위";
            break;
        case 'p' :
            std::cout << "보";
            break;
        default :
            std::cout << "알 수 없는 오류\n";
            EOF;
    }
}

/**
 * \brief 두 입력 값을 비교하여 플레이어가 가위바위보에 승리했는지 확인하는 함수
 * \param player 플레이어가 선택한 가위바위보
 * \param computer 컴퓨터가 선택한 가위바위보
 * @warning 파라미터는 'r', 'p', 's'만 입력
 */
void choose_winner(char player, char computer) {
    switch (player) {
        case 'r' :
            if (computer == 'r') {
                std::cout << "비겼습니다!\n";
            } else if (computer == 'p') {
                std::cout << "졌습니다!\n";
            } else {
                std::cout << "이겼습니다!\n";
            }
            break;
        case 'p' :
            if (computer == 'r') {
                std::cout << "이겼습니다!\n";
            } else if (computer == 'p') {
                std::cout << "비겼습니다!\n";
            } else {
                std::cout << "졌습니다!\n";
            }
            break;
        case 's' :
            if (computer == 'r') {
                std::cout << "졌습니다!\n";
            } else if (computer == 'p') {
                std::cout << "이겼습니다!\n";
            } else {
                std::cout << "비겼습니다!\n";
            }
            break;
        default :
            std::cout << "알 수 없는 오류\n";
            EOF;
    }
}