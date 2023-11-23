#include <vector>   // For std::vector
#include <string>   // For std::string
#include <iostream> // For std::cout

size_t searchName(std::vector<std::string> const & inputNamesVector,
	       std::string const inputName) {
    size_t index;
    for (index= 0; index < inputNamesVector.size(); index++) {
	if (inputNamesVector.at(index) == inputName) {break;}
    }
    return index;
}

int main() {
    std::vector<std::string> names{"John", "Smith", "Karl", "May",
	"Kate", "Vanessa"};
    std::vector<int> scores{10, 9, 12, 45, 7, 100};
    std::string name;

    while (true) {
	std::cout << "Пожалуйста, введите имя: ";
	std::cin >> name;
	size_t index= searchName(names, name);
	if (index != names.size()) {
	    std::cout << scores.at(index) << std::endl;
	} else {
	    std::cout << "Имя не найдено!" << std::endl;
	}
    }
    return 0;
}
