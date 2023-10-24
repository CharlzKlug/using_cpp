#include <iostream> // Для std::cin

int main () {
    int temp;
    while (std::cin >> temp) {
	std::cout << temp << '\n';
    }
    return 0;
}
