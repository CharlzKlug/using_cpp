#include <cstddef> // For size_t
#include <iostream> // For std::cout

class Fibonacci {
private:
    int s0= 1;
    int s1= 1;
    size_t currentIndex= 0;
public:
    Fibonacci(){}
    int next(){
	int result;
	if (currentIndex > 1) {
	    result= s0 + s1;
	    s0= s1;
	    s1= result;
	} else if (currentIndex == 1) {
	    result= s1;
	} else if (currentIndex == 0) {
	    result= s0;
	}
	currentIndex++;
	return result;
    }
};

int main() {
    size_t n;
    std::cin >> n;
    Fibonacci fibSequence;
    for (size_t i= 0; i <= n; ++i) {
	std::cout << fibSequence.next() << " ";
    }
    std::cout << std::endl;
    return 0;
}
