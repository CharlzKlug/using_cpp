#include <iostream>

double ctok(double c) {
    double k = c + 273.15;
    return k;
}

int main() {
    double c;
    if (std::cin >> c) {
	double k = ctok(c);
	std::cout << k << '\n';
    } else {
	std::cerr << "Error!\n";
    }
}
