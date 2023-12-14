#include <iostream>
#include <climits> // For INT_MAX
#include <vector>

int add (int const inputA, int const inputB) {
    if (inputA>=0) {
	if (inputB > INT_MAX - inputA) {
	    std::cerr << "Error! Buffer overflow!\n";
	    exit(1);
	}
    } else {
	if (inputB < INT_MAX - inputA + 1) {
	    std::cerr << "Error! Buffer overflow!\n";
	    exit(1);
	}
    }
    return inputA + inputB;
}

void printNums(std::vector<int> inputVectorInt, size_t inputNumsCount) {
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
    std::vector<int> vectorInt{};

    int tmp;
    while(std::cin >> tmp) {
	vectorInt.push_back(tmp);
    }

    if (vectorInt.size() < n) {
	std::cerr << "Недостаточно данных! Размер вектора меньше чем требуемое количество чисел!\n";
	exit(1);
    }

    int sum= 0;
    for (size_t i = 0; i < n; ++i) {
	sum= add(sum, vectorInt.at(i));
    }

    std::cout << "Сумма первых " << n << " чисел (";
    printNums(vectorInt, n);
    std::cout << ") равна " << sum << std::endl;
    return 0;
}
