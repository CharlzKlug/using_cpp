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
 "tuesday", "tue",
 "wednesday", "wed",
 "thursday", "thu",
 "friday", "fri",
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

int intVectorSum (std::vector<int> const inputVector) {
    int sum= 0;
    for (int t : inputVector) {
	sum += t;
    }
    return sum;
}

int main() {
    bool readDayOfWeek= true;
    std::vector<std::vector<int>> weekVector;
    for (int i= 0; i < 7; ++i) {
	weekVector.push_back(std::vector<int> {});
    }
    int currentDay;
    bool exitP=false;
    int ignoredDaysCount= 0;
    while (!exitP) {
	std::string inputString;
	std::cin >> inputString;
	auto currentWords= words(inputString);
	for (auto word : currentWords) {
	    if ("exit" == word) {
		exitP= true;
		break;
	    }
	    if (readDayOfWeek) {
		if (isDay(word)) {
		    currentDay= dayNumber(word);
		    readDayOfWeek= false;
		} else {
		    ignoredDaysCount++;
		}
	    } else if (!readDayOfWeek) {
		std::size_t pos{};
		try {
		    int val= std::stoi(word, &pos);
		    (weekVector[currentDay]).push_back(val);
		} catch (...) {
		    readDayOfWeek= true;
		}
		readDayOfWeek= true;
	    }
	}
    }

    for (size_t i= 0; i < daysOfWeek.size(); ++i) {
	std::cout << daysOfWeek.at(i) << ": ";
	printVector(weekVector.at(i));
	std::cout << "sum: " << intVectorSum(weekVector.at(i)) << std::endl;
    }

    std::cout << "Ignored days count: " << ignoredDaysCount << std::endl;
    return 0;
}
