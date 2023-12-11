#include <iostream>

double ctof (double inputFahrenheit) {
    double fahrenheit= 1.8 * inputFahrenheit + 32;
    return fahrenheit;
}

int main() {
    double celsius;
    if (std::cin >> celsius) {
	std::cout << "F: " << ctof(celsius) << std::endl;
    }
    return 0;
}
