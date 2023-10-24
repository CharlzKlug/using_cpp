#include <iostream>

int main() {
    constexpr double cm_per_inch = 2.54;
    double length = 1;
    char unit = 0;
    std::cout << "Пожалуйста, введите длину"
	      << " и единицу измерения (c или i):\n";
    std::cin >> length >> unit;
    if ('i' == unit) {
	std::cout << length << "in == "
		  << cm_per_inch * length << "cm\n";
    } else if ('c' == unit) {
	std::cout << length << "cm == "
		  << length / cm_per_inch << "in\n";
    } else {
	std::cout << "Извините, я не знаю, что это такое'"
		  << unit << "'\n";
    }
}
