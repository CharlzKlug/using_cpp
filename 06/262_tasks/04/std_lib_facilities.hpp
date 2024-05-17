#include <string>
#include <iostream>
using namespace std;
void error(std::string message) {
    std::cout << message;
    exit(1);
}

void keep_window_open(void) {
    char ch= 0;
    cin >> ch;
}
