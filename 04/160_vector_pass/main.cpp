#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {5, 7, 9, 4, 6, 8};
    for (unsigned int i=0; i < v.size(); ++i) {
	std::cout << v[i] << '\n';
    }

    for (int x : v) {
	std::cout << x << '\n';
    }
    return 0;
}
