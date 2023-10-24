#include <iostream>

int main() {
    std::cout << "Пожалуйста, введите своё имя и возраст\n";
    std::string first_name;
    double age;
    std::cin >> first_name >> age;
    
    std::cout << "Привет, " << first_name << " (" << (age * 12) << " месяцев)\n";
}
