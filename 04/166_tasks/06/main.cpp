#include <iostream> // Для std::cin

int main () {
    double temp;
    double min_number, max_number;
    bool isFirstTime = false;
    
    while (std::cin >> temp) {
	if (!isFirstTime) {
	    if (temp < min_number) {
		min_number= temp;
		std::cout << "Наименьшее среди введённых\n";
	    }
	    if (temp > max_number) {
		max_number=temp;
		std::cout << "Наибольшее среди введённых\n";
	    }
	} else {
	    min_number= temp;
	    max_number= temp;
	}
    }
    
    return 0;
}
