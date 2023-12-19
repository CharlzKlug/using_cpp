#include <vector>
#include <string>
#include <iostream>

void addStringToVectorDestructive(std::string & inputString,
				  std::vector<std::string> & outputVector) {
    if (!inputString.empty()) {
	outputVector.push_back(inputString);
	inputString.clear();
    }
}

std::vector<std::string> words(std::string const inputString) {
    std::string str= "";
    std::vector<std::string> result{};
    for (char ch : inputString) {
	if (ch != ' ' && ch != '\t') {
	    str += ch;
	} else {
	    addStringToVectorDestructive(str, result);
	}
    }
    addStringToVectorDestructive(str, result);
    return result;
}

void printVectorString(std::vector<std::string> const inputVector) {
    for (std::string str : inputVector) {
	std::cout << str << '\n';
    }
}

int main() {
    std::vector<std::string> tmp= words("      1    \t    2 3");
    printVectorString(tmp);
    return 0;
}
