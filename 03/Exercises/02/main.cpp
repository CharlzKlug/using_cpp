#include <iostream>

int main() {
    double miles=0;
    std::cout << "Enter miles: ";
    std::cin >> miles;

    double kilometers = miles * 1.609;
    std::cout << "Is " << kilometers << " kilometers." << std::endl;
    return 0;
}
