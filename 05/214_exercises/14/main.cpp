#include <vector>
#include <string>
#include <iostream>
#include <cstring> // For tolower()
#include <algorithm> // For std::transform

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

std::vector<std::string> allowedDays
{"sunday", "sun",
 "monday", "mon",
 "tuesday", "tue"
 "wednesday", "wed"
 "thursday", "thu"
 "friday", "fri"
 "saturday", "sat"};

bool isDay(std::string const inputWord) {
    std::string tmp= inputWord;
    std::transform(tmp.begin(), tmp.end(), tmp.begin(),
		   [](unsigned char c){return std::tolower(c);});
    for (std::string str : allowedDays) {
	if (str == tmp) {return true;}
    }
    return false;
}

int main() {
    // std::vector<std::string> tmp= words("      -1.89    \t    2 3");
    // printVectorString(tmp);
    bool inputFinished= false;
    bool readDayOfWeek= true;
    while (!inputFinished) {
	std::string inputString;
	std::cin >> inputString;
	
    }
    return 0;
}
