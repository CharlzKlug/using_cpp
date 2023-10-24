#include <iostream>
int square(int);

int main() {
    int i = 0;
    while (i < 100) {
	std::cout << i << '\t' << square(i) << '\n';
	++i;
    }
}

int square(int x) {
    return (x * x);
}
