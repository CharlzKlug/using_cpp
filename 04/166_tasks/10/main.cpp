#include <iostream> // Для std::cin
#include <unordered_map> // Для std::unordered_map
#include <vector> // Для std::vector
#include <algorithm> // Для std::for_each

typedef std::unordered_map<std::string, double> UnitCm;

bool isMapContains(UnitCm inputMap, std::string inputString) {
    if (inputMap.count(inputString) != 0) {
	return true;
    }
    return false;
}

int main () {
    double temp_double;
    std::string temp_str;
    double min_number, max_number;
    bool isFirstTime = true;

    UnitCm unitValues = {{"cm", 1},
			 {"in", 2.54},
			 {"ft", 30.48}};

    double sum = 0;
    size_t valuesCount= 0;
    std::vector<double> storage = {};
    
    while (std::cin >> temp_double && std::cin >> temp_str) {
	if (isMapContains(unitValues, temp_str)) {
	    double coefficient = unitValues.at(temp_str);
	    temp_double *= coefficient;
	    storage.push_back(temp_double / 100);
	    sum += temp_double;
	    valuesCount++;
	    if (!isFirstTime) {
		
		if (temp_double < min_number) {
		    min_number= temp_double;
		    std::cout << "Наименьшее среди введённых\n";
		}
		if (temp_double > max_number) {
		    max_number=temp_double;
		    std::cout << "Наибольшее среди введённых\n";
		}
	    } else {
		min_number= temp_double;
		max_number= temp_double;
		isFirstTime= false;
	    }
	}
    }

    std::cout << "Наименьшее введённое значение: " << min_number / 100 << " м." << std::endl;
    std::cout << "Наибольшее введённое значение: " << max_number / 100 << " м." << std::endl;
    std::cout << "Всего введено " << valuesCount << " значений." << std::endl;
    std::cout << "Сумма: " << (sum - min_number - max_number) / 100 << " м."
	      << std::endl;
    
    std::for_each(storage.begin(), storage.end()-1,
		  [](const double t) {std::cout << t << " ";});
    std::cout << storage.back() << std::endl;
    
    return 0;
}
