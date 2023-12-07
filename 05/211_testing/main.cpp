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

	// 09
	// std::string s = "ape";
	// bool c = "fool"<s;
	// if (c) std::cout << "Success!\n";

	// 10
	// std::string s = "ape";
	// if (s=="fool") std::cout << "Success!\n";

	// 11
	// std::string s = "ape";
	// if (s=="fool") std::cout << "Success!\n";

	// 12
	// std::string s = "ape";
	// if (s=="fool") std::cout << "Success!\n";

	// 13
	// std::vector<char> v(5);
	// for (size_t i=0; i<v.size(); ++i);
	// std::cout << "Success!\n";

	// 14
	// std::vector<char> v(5);
	// for (size_t i=0; i <= v.size(); ++i);
	// std::cout << "Success!\n";

	// 15
	// std::string s = "Success!\n";
	// for (size_t i=0; i<s.length(); ++i) std::cout << s[i];

	// 16
	// if (true)
	//     std::cout << "Success!\n";
	// else
	//     std::cout << "Fail!\n";

        // 17
	// int x = 2000;
	// int c = x;
	// if (c==2000) std::cout << "Success!\n";

	// 18
	// std::string s = "Success!\n";
	// for (size_t i=0; i<s.size(); ++i)
	//     std::cout << s[i];

	// 19
	// std::vector<int> v(5);
	// for (std::vector<int>::size_type i=0; i <= v.size(); ++i);
	// std::cout << "Success!\n";

	// 20
	// int i=0;
	// int j=9;
	// while (i<10) ++i;
	// if (j<i) std::cout << "Success!\n";

	// 21
	// int x = 3;
	// double d = 5 / (x-2);
	// if (d==2*x+0.5) std::cout << "Success!\n";

	// 22
	// std::string s = "Success!\n";
	// for (size_t i = 0; i <= s.size(); ++i)
	//     std::cout << s[i];

	// 23
	// int i=0;
	// int j=0;
	// while (i<10)
	//     ++i;
	// if (j<i) std::cout << "Success!\n";

	// 24
	
	return 0;
    } catch (Exception& e) {
	std::cerr << "Ошибка: " << e.what() << std::endl;
	return 1;
    } catch (...) {
	std::cerr << "Неизвестное исключение!\n";
	return 2;
    }
}
