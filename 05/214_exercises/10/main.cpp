#include <iostream>
#include <vector>

void printNums(std::vector<double> inputVectorInt, size_t inputNumsCount) {
    for (size_t i = 0; i < inputNumsCount; i++) {
	std::cout << inputVectorInt.at(i);
	if (i != inputNumsCount - 1) {
	    std::cout << ' ';
	}
    }
}

int main() {
    std::cout << "Введите количество суммируемых значений:\n";
    size_t n;
    std::cin >> n;

    std::cout << "Введите несколько целых чисел (I для окончания ввода):\n";
    std::vector<double> vectorDouble{};

    double tmp;
    while(std::cin >> tmp) {
	vectorDouble.push_back(tmp);
    }

    if (vectorDouble.size() < n) {
	std::cerr << "Недостаточно данных! Размер вектора меньше чем требуемое количество чисел!\n";
	exit(1);
    }

    double sum= 0;
    for (size_t i = 0; i < n; ++i) {
	sum += vectorDouble.at(i);
    }

    std::cout << "Сумма первых " << n << " чисел (";
    printNums(vectorDouble, n);
    std::cout << ") равна " << sum << std::endl;

    std::vector<double> vectorRealNums{};
    for (size_t i=1; i < vectorDouble.size(); ++i) {
	vectorRealNums.push_back(vectorDouble.at(i) - vectorDouble.at(i-1));
    }
    printNums(vectorRealNums, vectorRealNums.size());
    std::cout << std::endl;
    
    return 0;
}
