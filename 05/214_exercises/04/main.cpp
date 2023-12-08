#include <iostream>

double ctok(double c) {
    int errorCode= 1;
    double absoluteZeroCelsius = -273.15;
    
    if (c < absoluteZeroCelsius) {
	std::cerr << "Too low temperature: " << c << ", must be greater or equal to " << absoluteZeroCelsius << std::endl;
	exit(errorCode);
    }
    double k = c + 273.15;
    return k;
}

int main() {
    double c;
    if (std::cin >> c) {
	double k = ctok(c);
	std::cout << "Temperature in Kelvin is " << k << std::endl;
    } else {
	std::cerr << "Error!\n";
    }
}
