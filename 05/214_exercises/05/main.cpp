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

double ktoc(double inputKelvinTemperature) {
    int errorCode= 1;
    double addition = 273.15;
    
    if (inputKelvinTemperature < 0) {
	std::cerr << "Too low temperature: "
		  << inputKelvinTemperature
		  << ", must be greater or equal to 0\n";
	exit(errorCode);
    }
    double c = inputKelvinTemperature - addition;
    return c;
}

int main() {
    double k;
    if (std::cin >> k) {
	double c = ktoc(k);
	std::cout << "Temperature in Celsius is " << c << std::endl;
    } else {
	std::cerr << "Error!\n";
    }
}
