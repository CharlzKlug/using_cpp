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

template<typename T>
void printVector(std::vector<T> const inputVector) {
    for (T str : inputVector) {
	std::cout << str << ' ';
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

int dayNumber(std::string const inputWord) {
    std::string tmp= inputWord;
    std::transform(tmp.begin(), tmp.end(), tmp.begin(),
		   [](unsigned char c){return std::tolower(c);});
    for (size_t i=0; i < allowedDays.size() / 2; ++i) {
	if (allowedDays.at(i*2) == tmp || allowedDays.at(i*2 + 1) == tmp) {
	    return i;
	}
    }
    return -1;
}

std::vector<std::string> const daysOfWeek {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

int main() {
    // std::vector<std::string> tmp= words("      -1.89    \t    2 3");
    // printVectorString(tmp);
    // bool inputFinished= false;
    bool readDayOfWeek= true;
    // std::vector<int> sundayVector{};
    // std::vector<int> mondayVector{};
    // std::vector<int> tuesdayVector{};
    // std::vector<int> wednesdayVector{};
    // std::vector<int> thursdayVector{};
    // std::vector<int> fridayVector{};
    // std::vector<int> saturdayVector{};
    std::vector<std::vector<int>> weekVector;
    for (int i= 0; i < 7; ++i) {
	weekVector.push_back(std::vector<int> {});
    }
    int currentDay;
    bool exitP=false;
    while (!exitP) {
	std::string inputString;
	std::cin >> inputString;
	auto currentWords= words(inputString);
	for (auto word : currentWords) {
	    if ("exit" == word) {
		exitP= true;
		break;
	    }
	    if (readDayOfWeek && isDay(word)) {
		currentDay= dayNumber(word);
		readDayOfWeek= false;
	    } else {
		std::size_t pos{};
		try {
		    int val= std::stoi(word, &pos);
		    std::cout << "val: " << val << std::endl;
		    std::cout << "currentDay: " << currentDay << std::endl;
		    (weekVector[currentDay]).push_back(val);
		} catch (...) {
		    readDayOfWeek= true;
		}
	    }
	}
    }

    // std::cout << "Monday:\n";
    // printVector <int> (weekVector.at(1));

    for (size_t i= 0; i < daysOfWeek.size(); ++i) {
	std::cout << daysOfWeek.at(i) << ": ";
	printVector(weekVector.at(i));
	std::cout << std::endl;
    }
    
    return 0;
}
