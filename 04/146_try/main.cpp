#include <iostream>

int main() {
    constexpr double dollar_per_hryvnya = 0.027;
    constexpr double dollar_per_rouble  = 0.01;
    constexpr double dollar_per_yuan    = 0.14;
    
    double amount = 1;
    char unit = 0;
    std::cout << "Пожалуйста, введите количество денег"
	      << " и единицу валюты (h, r или y):\n";
    std::cin >> amount >> unit;
    if ('h' == unit) {
	std::cout << amount << " гривна == "
		  << dollar_per_hryvnya * amount << " доллар\n";
    } else if ('r' == unit) {
	std::cout << amount << " рубль == "
		  << amount * dollar_per_rouble << " доллар\n";
    } else if ('y' == unit) {
	std::cout << amount << " юань == "
		  << amount * dollar_per_yuan << " доллар\n";
    } else {
	std::cout << "Извините, я не знаю, что это такое'"
		  << unit << "'\n";
    }
}
