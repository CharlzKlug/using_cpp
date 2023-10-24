#include <iostream> // Для std::cin
#include <cmath> // Для abs

#define THRESHOLD (1.0/100)

void print_numbers(double input_num1, double input_num2) {
    double max_num, min_num;
    if (input_num1 > input_num2) {
	max_num= input_num1;
	min_num= input_num2;
    } else {
	max_num= input_num2;
	min_num= input_num1;
    }

    if (max_num == min_num) {
	std::cout << "Числа равны" << std::endl;
	return;
    }

    if (abs(max_num - min_num) < THRESHOLD) {
	std::cout << "Числа почти равны" << std::endl;
	return;
    }
    
    if (max_num != min_num) {
	std::cout << "Наименьшее значение равно: " << min_num << std::endl;
	std::cout << "Наибольшее значение равно: " << max_num << std::endl;
	return;
    }
}

int main () {
    double temp;
    double number1, number2;
    bool settedNumber1 = false;
    while (std::cin >> temp) {
	std::cout << temp << '\n';
	if (settedNumber1) {
	    number2= temp;
	    print_numbers(number1, number2);
	} else {
	    number1= temp;
	    settedNumber1= true;
	}
    }
    return 0;
}
