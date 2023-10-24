#include <iostream>
int main() {
    for (char i = 'a'; i <= 'z'; i++) {
	std::cout << i << '\t' << (int) i << std::endl;
    }

    for (char i = '0'; i <= '9'; i++) {
	std::cout << i << '\t' << (int) i << std::endl;
    }
    return 0;
}
