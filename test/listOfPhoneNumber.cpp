#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool solution(std::vector<std::string> phone_book);

int main() {

    std::vector<std::string> phone_book = {"123","456","789" };

    std::cout << ((solution(phone_book)) ? "true" : "false") << '\n';
}

bool solution(std::vector<std::string> phone_book) {

    std::unordered_map<std::string, int> map;

    for (int i = 0; i < static_cast<int>(phone_book.size()); i++) {
        map.insert(std::pair<std::string, int>(phone_book[i], i));
    }

    for (std::string phone_number : phone_book) {
        for (int i = 0; i < static_cast<int>(phone_number.size()); i++) {
            if (map.count(phone_number.substr(0, i)) > 0) {
                return false;
            }
        }
    }

    return true;
}
