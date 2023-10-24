#include <iostream>

int main() {
    int y = 'y';
    constexpr char n = 'n';
    constexpr char m = '?';
    std::cout << "Вы любите рыбу?\n";
    char a;
    std::cin >> a;
    switch (a) {
    case n:
	break;
    case y:
	break;
    case m:
	break;
    case 'n':
	break;
    default:
	break;
    }
}
