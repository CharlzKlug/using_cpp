#include <vector> // For std::vector
#include <iostream> // For std::cin

int main() {
    try {
	std::vector<int> v;
	for (int x; std::cin>>x;)
	    v.push_back(x);
	for (size_t i= 0; i <= v.size(); i++)
	    std::cout << "v[" << i << "] == " << v.at(i) << '\n';
    } catch (std::out_of_range const& exc) {
	std::cerr << "Ошибка диапазона!\n";
	return 1;
    } catch (...) {
	std::cerr << "Исключение: что-то пошло не так\n";
	return 2;
    }
}
