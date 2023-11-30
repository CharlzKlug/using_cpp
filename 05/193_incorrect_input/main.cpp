#include <iostream>

void error(std::string s) {
    throw std::runtime_error(s);
}

void error(std::string s1, std::string s2) {
    throw std::runtime_error(s1+s2);
}

int main() {
    try {
	double d;
	std::cin >> d;
	if (std::cin) {
	    std::cout << "Everything is correct\n";
	} else {
	    error("Wrong data!");
	}
    } catch (std::exception& e) {
	std::cerr << "runtime error: " << e.what() << std::endl;
	return 1;
    } catch (...) {
	std::cerr << "Неизвестное исключение!\n";
	return 2;
    }
    return 0;
}
