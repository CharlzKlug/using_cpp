#include <vector>
#include <iostream>

int main() {
  std::cout << "Eratosthenes seave" << std::endl;
  std::cout << "Please enter Maximum: ";
  size_t maxNumber;
  std::cin >> maxNumber;
  std::vector<int> numbers;
  for (size_t i=2; i <= maxNumber; i++) {
    numbers.push_back(i);
  }
  for (size_t i=0; i < numbers.size(); i++) {
    for (size_t k=i+1; k < numbers.size(); k++) {
      if (numbers.at(k) % numbers.at(i) == 0) {
	numbers.erase(numbers.begin() + k);
      }
    }
  }

  for (int n : numbers) {
    std::cout << n << std::endl;
  }
  return 0;
}
