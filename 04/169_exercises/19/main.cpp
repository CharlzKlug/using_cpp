#include <vector>   // For std::vector
#include <string>   // For std::string
#include <iostream> // For std::cout
#include <set>      // For std::set

bool hasDuplicate(std::vector<std::string> const & inputNames){
    std::set<std::string> s(inputNames.begin(), inputNames.end());
    return s.size() != inputNames.size();
}

int main() {
    std::vector<std::string> names;
    std::vector<int> scores;
    std::string name;
    int score;
    std::cout << "Enter name and score: ";
    while (std::cin >> name && std::cin >> score && !((name == "NoName") & (score == 0))) {
	names.push_back(name);
	scores.push_back(score);
	std::cout << "Enter name and score: ";
    }

    if (hasDuplicate(names)) {
	std::fprintf(stderr, "Error! There are duplicates!\n");
	exit(1);
    }

    std::cout << "Name\tScore" << std::endl;

    for (size_t i= 0; i < names.size(); i++) {
	std::cout << names.at(i) << "\t" << scores.at(i) << std::endl;
    }
    return 0;
}
