#include <iostream> // Для std::cin

void print_numbers(int input_num1, int input_num2) {
    int max_num, min_num;
    if (input_num1 > input_num2) {
	max_num= input_num1;
	min_num= input_num2;
    } else {
	max_num= input_num2;
	min_num= input_num1;
    }
    std::cout << "Наименьшее значение равно: " << min_num << std::endl;
    std::cout << "Наибольшее значение равно: " << max_num << std::endl;
}

int main () {
    int temp;
    int number1, number2;
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
