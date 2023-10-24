#include <iostream>

int main() {
    int a = 20000;
    char c = a;

    int b = c;
    if (a != b) {
	std::cout << "Ой!: " << a << "!=" << b << '\n';
    } else {
	std::cout << "Ого! Однако у нас очень большой char\n";
    }

    double x {2.7};
    std::cout << x << '\n';

    // int y {x};

    int d {10000};
    std::cout << d << '\n';

    // char e {a};
}
