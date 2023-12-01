#include <vector>
#include <iostream>
#include <cassert>

int main() {
    std::vector<double> temps;

    double sum = 0;
    double high_temp = -136;
    double low_temp = 136;

    int no_of_temps = 0;
    
    for (double temp; std::cin >> temp;) {
	++no_of_temps;
	sum += temp;
	if (temp > high_temp) high_temp = temp;
	if (temp < low_temp) low_temp = temp;
    }

    std::cout << "Максимальная температура: "
	 << high_temp << std::endl;
    std::cout << "Минимальная температура: "
	 << low_temp << std::endl;
    std::cout << "Средняя температура: "
	 << sum / no_of_temps << std::endl;
}
