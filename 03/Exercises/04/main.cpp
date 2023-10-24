#include <iostream>

int main() {
    int val1, val2;
    std::cout << "Enter val1: ";
    std::cin >> val1;
    std::cout << "Enter val2: ";
    std::cin >> val2;
    
    int sum = val1 + val2;
    std::cout << "Sum: " << sum << std::endl;

    int difference = val1 - val2;
    std::cout << "Difference: " << difference << std::endl;

    int multiplication = val1 * val2;
    std::cout << "Multiplication: " << multiplication << std::endl;

    int quotient = val1 / val2;
    std::cout << "Quotient: " << quotient << std::endl;

    int minimum = std::min(val1, val2);
    std::cout << "Minimum: " << minimum << std::endl;

    int maximum = std::max(val1, val2);
    std::cout << "Maximum: " << maximum << std::endl;
    return 0;
}
