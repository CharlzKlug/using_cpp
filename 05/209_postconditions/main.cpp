#include <iostream>

class Bad_area {};

int area(int length, int width) {
    if (length <= 0 || width <= 0) throw("area() pre-condition");
    int a = length * width;
    if (a <=0) throw("area() post-condition");
    return length*width;
}

int main() {
    try {
	std::cout << "Size = " << area(21474836,4) << std::endl;
    } catch (const char* errorMessage) {
	std::cout << "Exception: " << errorMessage << std::endl;
    }
    return 0;
}
