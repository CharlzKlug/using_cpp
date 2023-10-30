#include <vector> // Для std::vector
#include <iostream> // Для std::cout

enum Parity {Odd, Even};

Parity numberParity(const size_t x) {
    if (x % 2 == 0) return Parity::Even;
    return Parity::Odd;
}

double median(std::vector<double> inputVector) {
    size_t vectorLength= inputVector.size();
    double result;
    if (numberParity(vectorLength) == Parity::Odd) {
	size_t middleIndex= vectorLength / 2;
	result= inputVector.at(middleIndex);
    } else {
	size_t half_index= (vectorLength / 2) - 1;
	result= (inputVector.at(half_index) +
		 inputVector.at(half_index + 1)) / 2;
    }
    return result;
}

int main() {
    std::vector<double> myVector= {0, 1, 57,58,59};
    std::cout << median(myVector) << std::endl;

    std::vector<double> testVector= {3};
    std::cout << median(testVector) << std::endl;

    std::vector<double> testVector2= {0, 1, 2, 4};
    std::cout << median(testVector2) << std::endl;
    
    return 0;
}
