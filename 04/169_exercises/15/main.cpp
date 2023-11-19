#include <vector> // For std::vector
#include <iostream> // For std::cout

std::vector<int> primes;

int main() {
  std::size_t n;
  std::cout << "Enter n: ";
  std::cin >> n;
  std::cout << "Prime numbers:" << std::endl;
  for (std::size_t i=2; primes.size() < n; i++) {
    std::size_t k;
    for (k=0; k < primes.size(); k++) {
      if (i % primes.at(k) == 0) {break;}
    }

    if (k == primes.size()) {
      std::cout << i << std::endl;
      primes.push_back(i);
    }
  }
  return 0;
}
