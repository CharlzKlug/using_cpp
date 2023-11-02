#include <iostream>
#include <map>

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

void calc(std::map<char,
	  std::pair<int, double> (*)(double const, double const)> inputFuncsTable,
	  char const inputFuncSign,
	  double const inputA,
	  double const inputB) {
    if (auto search = inputFuncsTable.find(inputFuncSign);
	search != inputFuncsTable.end()) {
	std::pair<int, double> calcResult= search->second(inputA, inputB);
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
    double a;
    double b;
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
