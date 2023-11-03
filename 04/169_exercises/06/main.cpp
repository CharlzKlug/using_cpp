#include <vector> // Для std::vector
#include <string> // Для std::string
#include <iostream> // Для std::cin
#include <algorithm> // Для std::find

const std::vector<std::string>
stringNumbers{"zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"};

void numberToString (std::string inputValue) {
    size_t i;
    if(sscanf(inputValue.c_str(), "%ld", &i) == 1) {
	// Если введённое значение --- численное
	if (i < stringNumbers.size()) {
	    std::cout << stringNumbers.at(i) << std::endl;
	} else {
	    std::cout << "Too big or too small!" << std::endl;
	}
    } else {
	// Если введённое значение --- не численное
	for (size_t i= 0; i < stringNumbers.size(); i++) {
	    if (stringNumbers.at(i) == inputValue) {
		std::cout << i << std::endl;
		break;
	    }
	}
    }
}

int main() {
    std::string inputValue;
    while (true) {
	std::cin >> inputValue;
	numberToString(inputValue);
    }
    return 0;
}
