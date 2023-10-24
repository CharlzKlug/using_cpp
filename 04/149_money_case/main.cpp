#include <iostream>

int main() {
    constexpr double dollar_per_hryvnya = 0.027;
    constexpr double dollar_per_rouble  = 0.01;
    constexpr double dollar_per_yuan    = 0.14;
    constexpr double dollar_per_euro    = 1.06;
    constexpr double dollar_per_pound   = 1.22;
    
    double amount = 1;
    char unit = 0;
    std::cout << "Пожалуйста, введите количество денег"
	      << " и единицу валюты (h, r, y, e или p):\n";
    std::cin >> amount >> unit;
    switch (unit) {
    case 'h':
	std::cout << amount << " гривна == "
		  << dollar_per_hryvnya * amount << " доллар\n";
	break;
    case 'r':
	std::cout << amount << " рубль == "
		  << amount * dollar_per_rouble << " доллар\n";
	break;
    case 'y':
	std::cout << amount << " юань == "
		  << amount * dollar_per_yuan << " доллар\n";
	break;
    case 'e':
	std::cout << amount << " евро == "
		  << amount * dollar_per_euro << " доллар\n";
	break;
    case 'p':
	std::cout << amount << " фунт стерлингов == "
		  << amount * dollar_per_pound << " доллар\n";
	break;
    default:
	std::cout << "Извините, я не знаю, что это такое '"
		  << unit << "'\n";
	std::cout << "Количество: " << amount << std::endl;
    }
}
