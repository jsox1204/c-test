#include <iostream>
#include <random>

void draw_board(const char* spaces);
void player_move(char* spaces, char player);
void computer_move(char* spaces, char computer);
bool check_winner(const char* spaces, char player);
bool check_tie(const char* spaces);

int main() {

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    constexpr char computer = 'O';
    constexpr char player = 'X';

    draw_board(spaces);

    while (true) {
        
        player_move(spaces, player);
        draw_board(spaces);

        if (check_winner(spaces, player)) {
            break;
        } else if (check_tie(spaces)) {
            break;
        }

        computer_move(spaces, computer);
        draw_board(spaces);

        if (check_winner(spaces, player)) {
            break;
        } else if (check_tie(spaces)) {
            break;
        }
    }

    return 0;
}

/**
 * \brief 틱택토 보드그리기
 * \param spaces 보드의 현재 상황 
 */
void draw_board(const char* spaces) {
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << '\n';
}

/**
 * \brief 플레이어가 보드에 표시하도록 한다.
 * \param spaces 보드의 현재 상황
 * \param player 플레이어의 표시 문자
 */
void player_move(char* spaces, const char player) {
    int number;
    do {
        std::cout << "표시할 위치를 입력하세요 (1~9): ";
        std::cin >> number;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        number--;

        if (!(number >= 0 && number <= 8)) {
            continue;
        }

        if (spaces[number] == ' ') {
            spaces[number] = player;
        } else {
            std::cout << "비어있는 위치를 입력하세요!\n";
            number = 100;
        }
    }
    while (!(number >= 0 && number <= 8));
}

/**
 * \brief 컴퓨터가 무작위로 보드에 표시한다.
 * \param spaces 보드의 현재 상황
 * \param computer 컴퓨터의 표시 문자
 */
void computer_move(char* spaces, const char computer) {
    std::random_device random_device;
    std::mt19937 gen_mt19937(random_device());
    std::uniform_int_distribution<int> distribution(0, 8);

    while (true) {
        int number = distribution(gen_mt19937);
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
    
}

/**
 * \brief 보드에 한 줄로 같은 표시가 있는지 확인하여 누가 이겼는지를 확인한다.
 * \param spaces 보드의 현재 상황
 * \param player 플레이어의 표시 문자
 * \return 승자의 존재 여부
 */
bool check_winner(const char* spaces, const char player) {

    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player ? std::cout << "이겼습니다!\n" : std::cout << "졌습니다!\n";
    } else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
        spaces[3] == player ? std::cout << "이겼습니다!\n" : std::cout << "졌습니다!\n";
    } else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
        spaces[6] == player ? std::cout << "이겼습니다!\n" : std::cout << "졌습니다!\n";
    } else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
        spaces[0] == player ? std::cout << "이겼습니다!\n" : std::cout << "졌습니다!\n";
    } else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
        spaces[1] == player ? std::cout << "이겼습니다!\n" : std::cout << "졌습니다!\n";
    } else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
        spaces[2] == player ? std::cout << "이겼습니다!\n" : std::cout << "졌습니다!\n";
    } else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
        spaces[0] == player ? std::cout << "이겼습니다!\n" : std::cout << "졌습니다!\n";
    } else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player ? std::cout << "이겼습니다!\n" : std::cout << "졌습니다!\n";
    } else {
        return false;
    }

    return true;
}

/**
 * \brief 보드의 표시가 꽉 찼는지 확인한다.
 * \param spaces 보드의 현재 상황
 * \return 보드가 완전히 찼는지에 대한 여부
 */
bool check_tie(const char* spaces) {

    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "무승부입니다!\n";
    return true;
}
