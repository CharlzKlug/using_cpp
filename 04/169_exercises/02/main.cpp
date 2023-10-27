#include <vector> // Для std::vector

enum Parity {Odd, Even};

Parity numberParity(const size_t x) {
    if (x % 2 == 0) return Parity::Odd;
    return Parity::Even;
}

double median(std::vector<double> inputVector) {
    size_t vectorLength= inputVector.size();
    double result;
    if (numberParity(vectorLength) == Parity::Odd) {
	size_t middleIndex= vectorLength / 2;
	result= inputVector.at(middleIndex);
    } else {
	
    }
}

int main() {
    std::vector<double> myVector= {0, 1, 57,58,59};
    return 0;
}
