#include <iostream>
#include <cmath>

int main() {
    std::cout << "Пожалуйста, введите два имени\n";
    std::string first;
    std::string second;
    std::cin >> first >> second;
    if (first == second) std::cout << "имена совпадают\n";
    if (first < second)
	std::cout << first << " предшествует " << second
	     << " в алфавитном порядке" << '\n';
    if (first > second)
	std::cout << first << " следует за " << second
	     << " в алфавитном порядке" << '\n';
}
