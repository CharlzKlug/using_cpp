#include <iostream> // Для std::cout

int main () {
    constexpr double cm_per_inch = 2.54;
    double length = 1;
    char unit = 'a';
    std::cout << "Пожалуйста, введите длину"
	      << " и единицу измерения (c или i):\n";
    std::cin >> length >> unit;
    switch (unit) {
    case 'i':
	std::cout << length << "in == "
		  << cm_per_inch*length << "cm\n";
	break;
    case 'c':
	std::cout << length << "cm == "
		  << length/cm_per_inch << "in\n";
	break;
    default:
	std::cout << "Извините, я не знаю, что это такое '"
		  << unit << "'\n";
	break;
    }
}
