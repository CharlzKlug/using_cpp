#include <cmath> // Для **
#include <iostream> // Для std::cout

int solve(int const inputQuantity) {
  int cells= 0;
  int currentQuantity= 0;
  while (currentQuantity < inputQuantity) {
    cells++;
    currentQuantity += pow(2, cells);
  }
  return cells;
}

int main() {
  int quantity;
  while (true) {
    std::cout << "Enter rice quantity: ";
    std::cin >> quantity;
    std::cout << "Cells: " << solve(quantity) << std::endl;
  }
  return 0;
}
