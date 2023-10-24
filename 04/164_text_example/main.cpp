// Как собрать: g++ main.cpp -Wall -Wextra -Werror -std=c++17 -g
#include <vector> // Для std::vector
#include <string> // Для std::string
#include <iostream> // Для std::cin
#include <algorithm> // Для std::sort
#include <set> // Для std::set


bool isLikedWord(std::string word) {
    std::set<std::string> disliked_words = {"Broccoli", "Banana"};
    return disliked_words.find(word) == disliked_words.end();
}

int main() {
    std::vector<std::string> words;
    for (std::string temp; std::cin>>temp;)
	words.push_back(temp);
    std::cout << "Количество слов: " << words.size() << '\n';

    std::sort(words.begin(), words.end());

    for (size_t i=0; i < words.size(); ++i) {
	if (isLikedWord(words[i]) && (i == 0 || words[i-1] != words[i]))
	    std::cout << words[i] << "\n";
    }
}
