#include <iostream> // For std::cerr
#include <vector> // For std::vector

class Exception {
private:
    std::string message;
public:
    Exception(std::string const inputMessage)
	: message(inputMessage) {}
    std::string what() {
	return message;
    }
};

int main() {
    try {
	// 01
	// std::cout << "Success!\n";

	// 02
	// std::cout << "Success!\n";

	// 03
	// std::cout << "Success" << "!\n";

	// 04
	// std::cout << "success" << '\n';

	// 05
	// int res = 7;
	// std::vector<int> v (10);
	// v[5] = res;
	// std::cout << "Success!\n";

	// 06
	// std::vector<int> v(10);
	// v[5] = 7;
	// if (v[5]!=7) std::cout << "Success!\n";

	// 07
	// bool cond= false;
	// if (cond)
	//     std::cout << "Success!\n";
	// else
	//     std::cout << "Fail!\n";

	// 08
	// bool c = true;
	// if (c) std::cout << "Success!\n";
	// else std::cout << "Fail!\n";
	return 0;
    } catch (Exception& e) {
	std::cerr << "Ошибка: " << e.what() << std::endl;
	return 1;
    } catch (...) {
	std::cerr << "Неизвестное исключение!\n";
	return 2;
    }
}
