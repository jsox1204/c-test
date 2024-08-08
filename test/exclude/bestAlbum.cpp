#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays);

int main() {

    std::vector<std::string> genres = { "classic", "pop", "classic", "classic", "pop" };
    std::vector<int> plays = { 500, 600, 150, 800, 2500};

    for (const auto &item : solution(genres, plays)) {
        std::cout << item << ", ";
    }
    std::cout << '\n';

    return 0;
}

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays) {

    std::unordered_map<std::string, int> total_plays_genres;

    for (int i = 0; i < static_cast<int>(genres.size()); i++) {
        total_plays_genres[genres[i]] += plays[i];
    }

    std::vector<std::pair<std::string, int>> sort_genre_by_plays(total_plays_genres.begin(), total_plays_genres.end());
    
    std::sort(sort_genre_by_plays.begin(), sort_genre_by_plays.end(), 
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) -> bool {return  a.second >= b.second; });

    std::unordered_map<int, int> index_plays;

    std::vector<int> answer;

    for (const std::pair<std::string, int>& item : sort_genre_by_plays) {
        for (int i = 0; i < static_cast<int>(genres.size()); i++) {
            if (item.first == genres[i]) {
                index_plays.insert({ i, plays[i] });
            }
        }


        std::vector<std::pair<int, int>> index_keys(index_plays.begin(), index_plays.end());

        std::sort(index_keys.begin(), index_keys.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool {
                if (a.second == b.second) {
                    return a.first < b.first;
                }
                return a.second > b.second;
            }); // 재생 수가 같으면 고유 번호가 낮은 순으로 정렬

        if (index_keys.size() < 2) {
            answer.emplace_back(index_keys.begin()->first); // 장르의 노래가 하나만 있으면 하나만 넣기
        }
        else {
            answer.emplace_back(index_keys.begin()->first);
            answer.emplace_back((index_keys.begin() + 1)->first);
        }

        index_plays.clear();
    }


    return answer;
}
