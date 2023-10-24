#include <vector>
#include <iostream>
#include <algorithm>

#define SORT(some_vector) do { \
    std::sort(some_vector.begin(), some_vector.end()); \
    } while (0)

int main() {
    std::vector<double> temps;
    for (double temp; std::cin>>temp;)
	temps.push_back(temp);

    double sum= 0;
    for (int x : temps) sum += x;
    std::cout << "Средняя температура: "
	 << sum / temps.size() << '\n';
    // do {
    // 	std::sort(temps.begin(), temps.end());
    // } while(0);
    SORT(temps);
    
    std::cout << "Медианная температура: "
	 << temps[temps.size()/2] << '\n';
    return 0;
}
