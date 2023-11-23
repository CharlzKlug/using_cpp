#include <vector>   // For std::vector
#include <string>   // For std::string
#include <iostream> // For std::cout
#include <cassert>  // For assert

void printNamesWithScore(std::vector<std::string> const & inputNamesVector,
			 std::vector<int> const & inputScoreVector,
			 int const inputScore){
    assert(inputNamesVector.size() == inputScoreVector.size());
    bool scoreNotFound= true;
    for (size_t index= 0; index < inputScoreVector.size(); index++) {
	if (inputScore == inputScoreVector.at(index)) {
	    std::cout << inputNamesVector.at(index) << ' ';
	    scoreNotFound= false;
	}
    }
    if (scoreNotFound) {
	std::cout << "Баллы не найдены!" << std::endl;
    } else {std::cout << std::endl;}
}

int main() {
    std::vector<std::string> names{"John", "Smith", "Karl", "May",
	"Kate", "Vanessa"};
    std::vector<int> scores{100, 9, 12, 45, 7, 100};
    int score;
    while (true) {
	std::cout << "Пожалуйста, введите балл: ";
	std::cin >> score;
	printNamesWithScore(names, scores, score);
    }
    return 0;
}
