#include <string>
#include <iostream>

int main() {
    std::string previous = " ";
    std::string current;
    while (std::cin>>current) {
	if (previous == current)
	    std::cout << "Повторяющееся слово:" << current << '\n';
	previous = current;
    }
}
