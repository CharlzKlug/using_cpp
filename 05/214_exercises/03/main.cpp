#include <iostream>

double ctok(double c) {
    double k = c + 273.15;
    return k;
}

int main() {
    double c;
    if (std::cin >> c) {
	double k = ctok(c);
	if (k >= 0) {
	    std::cout << k << '\n';
	} else {
	    std::cerr << "Wrong temperature!\n";
	}
    } else {
	std::cerr << "Error!\n";
    }
}
