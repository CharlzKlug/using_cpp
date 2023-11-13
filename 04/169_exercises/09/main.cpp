#include <cmath> // Для pow
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
  std::cout << "For Int" << std::endl;
  int quantity= 0;
  for (int i=1; i <= 64; i++) {
    quantity = quantity + pow(2, i);
    std::cout << "Cell: " << i << ", Quantity: " << quantity << std::endl;
  }

  std::cout << "For Double" << std::endl;
  double quantity_double= 0;
  for (int i=1; i <= 64; i++) {
    quantity_double = quantity_double + pow(2, i);
    std::cout << "Cell: " << i << ", Quantity: " << quantity_double << std::endl;
  }
  
  return 0;
}
