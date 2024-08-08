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
 * \brief ƽ���� ����׸���
 * \param spaces ������ ���� ��Ȳ 
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
 * \brief �÷��̾ ���忡 ǥ���ϵ��� �Ѵ�.
 * \param spaces ������ ���� ��Ȳ
 * \param player �÷��̾��� ǥ�� ����
 */
void player_move(char* spaces, const char player) {
    int number;
    do {
        std::cout << "ǥ���� ��ġ�� �Է��ϼ��� (1~9): ";
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
            std::cout << "����ִ� ��ġ�� �Է��ϼ���!\n";
            number = 100;
        }
    }
    while (!(number >= 0 && number <= 8));
}

/**
 * \brief ��ǻ�Ͱ� �������� ���忡 ǥ���Ѵ�.
 * \param spaces ������ ���� ��Ȳ
 * \param computer ��ǻ���� ǥ�� ����
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
 * \brief ���忡 �� �ٷ� ���� ǥ�ð� �ִ��� Ȯ���Ͽ� ���� �̰������ Ȯ���Ѵ�.
 * \param spaces ������ ���� ��Ȳ
 * \param player �÷��̾��� ǥ�� ����
 * \return ������ ���� ����
 */
bool check_winner(const char* spaces, const char player) {

    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player ? std::cout << "�̰���ϴ�!\n" : std::cout << "�����ϴ�!\n";
    } else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
        spaces[3] == player ? std::cout << "�̰���ϴ�!\n" : std::cout << "�����ϴ�!\n";
    } else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
        spaces[6] == player ? std::cout << "�̰���ϴ�!\n" : std::cout << "�����ϴ�!\n";
    } else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
        spaces[0] == player ? std::cout << "�̰���ϴ�!\n" : std::cout << "�����ϴ�!\n";
    } else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
        spaces[1] == player ? std::cout << "�̰���ϴ�!\n" : std::cout << "�����ϴ�!\n";
    } else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
        spaces[2] == player ? std::cout << "�̰���ϴ�!\n" : std::cout << "�����ϴ�!\n";
    } else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
        spaces[0] == player ? std::cout << "�̰���ϴ�!\n" : std::cout << "�����ϴ�!\n";
    } else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player ? std::cout << "�̰���ϴ�!\n" : std::cout << "�����ϴ�!\n";
    } else {
        return false;
    }

    return true;
}

/**
 * \brief ������ ǥ�ð� �� á���� Ȯ���Ѵ�.
 * \param spaces ������ ���� ��Ȳ
 * \return ���尡 ������ á������ ���� ����
 */
bool check_tie(const char* spaces) {

    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "���º��Դϴ�!\n";
    return true;
}
