#include <iostream>

int my_square(int x) {
    int result= 0;
    for(int i= 0; i < x; i++) {
	result += x;
    }
    return result;
}

int main () {
    std::cout << my_square(3) << std::endl;
    return 0;
}
