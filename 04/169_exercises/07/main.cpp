#include <iostream>
#include <map>
#include <vector> // Для std::vector

std::pair<int, double> plus(double const inputA, double const inputB) {
    return std::make_pair(0, (inputA + inputB));
}

std::pair<int, double> minus(double const inputA, double const inputB) {
    return std::make_pair(0, (inputA + inputB));
}

std::pair<int, double> mul(double const inputA, double const inputB) {
    return std::make_pair(0, (inputA * inputB));
}

std::pair<int, double> div(double const inputA, double const inputB) {
    if (0 != inputB) {
	return std::make_pair(0, (inputA / inputB));
    }
    return std::make_pair(1, 0);
}

const std::vector<std::string>
stringNumbers{"zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"};

int proceedString (std::string const inputValue) {
    size_t i;
    if(sscanf(inputValue.c_str(), "%ld", &i) == 1) {
      // Если введённое значение --- численное
      return i;
    }
    // Если введённое значение --- не численное
    size_t currentIndex;
    for (currentIndex= 0; currentIndex < stringNumbers.size(); currentIndex++) {
      if (stringNumbers.at(currentIndex) == inputValue) {
	goto exit;
	break;
      }
    }
 exit:
    return currentIndex;
}

void calc(std::map<char,
	  std::pair<int, double> (*)(double const, double const)> inputFuncsTable,
	  char const inputFuncSign,
	  std::string const inputA,
	  std::string const inputB) {
  int valueA= proceedString(inputA);
  int valueB= proceedString(inputB);
  if (auto search = inputFuncsTable.find(inputFuncSign);
      search != inputFuncsTable.end()) {
    std::pair<int, double> calcResult= search->second(valueA, valueB);
    if (0 == calcResult.first) {
      std::cout << "Result " << calcResult.second << std::endl;
    } else {
      std::cout << "Calculation error!" << std::endl;
    }
  } else {
    std::cout << "The function '" << inputFuncSign << "' not found!" << std::endl;
  }
}

int main() {
    std::map<char, std::pair<int, double> (*)(double const , double const)>
	functionsMap{{'+', plus}, {'-', minus}, {'*', mul}, {'/', div}};
    std::string a;
    std::string b;
    std::cout << "Enter value A: ";
    std::cin >> a;
    std::cout << "Enter value B: ";
    std::cin >> b;

    char functionChar;
    std::cout << "Enter function char [+, -, *, /]: ";
    std::cin >> functionChar;
    
    calc(functionsMap, functionChar, a, b);
    return 0;
}
