#include <vector>
#include <map> // For std::map
#include <iostream> // For std::cout

int main() {
  std::vector<int> sequence{1, 2, 2, 3, 4, 5, 2};
  std::map<int, int> moda;
  int maxCountKey = 0;
  for (int n : sequence) {
    if (moda.contains(n)) {
      moda[n] = moda[n] + 1;
      if (moda[maxCountKey] < moda[n]) {
	maxCountKey = n;
      }
    } else {
      moda[n] = 1;
    }
  }
  std::cout << maxCountKey << std::endl;
  std::cout << moda[maxCountKey] << std::endl;
  return 0;
}
