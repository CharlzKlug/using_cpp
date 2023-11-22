#include <iostream> // For std::cout
#include <cmath> // For std::sqrt

void solveEquation(double const a, double const b, double const c) {
  if (0 == a) {
    if (0 == b) {
      if (0 == c) {
	std::cout << "Very many solutions" << std::endl;
      } else {
	std::cout << "No solutions" << std::endl;
      }
    } else {
      std::cout << "Answer is " << - (c / b) << std::endl;
    }
  } else {
    double d= (b / a) * (b / a) * (0.25) - (c / a);
    if (d < 0) {
      std::cout << "No solutions" << std::endl;
      return ;
    }
    double const s = - (b / a) * (0.5);
    if (0 == d) {
      std::cout << "Answer is " << s << std::endl;
      return ;
    }
    if (d > 0) {
      double rootD = std::sqrt(d);
      std::cout << "Answer is x1 = " << s - rootD << ", x2 = "
		<< s + rootD << std::endl;
    }
  }
}

int main() {
  std::cout << "Enter a: ";
  double a;
  std::cin >> a;
  std::cout << "Enter b: ";
  double b;
  std::cin >> b;
  std::cout << "Enter c: ";
  double c;
  std::cin >> c;
  solveEquation(a, b, c);
  return 0;
}
