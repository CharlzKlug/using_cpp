#include <iostream> // Для std::cout
#define LEFT_SIDE 1
#define RIGHT_SIDE 100

int calcMiddle(std::pair<int, int> inputRange) {
    int result = (inputRange.first + inputRange.second) / 2;
    return result;
}

char getAnswer() {
    std::cout << "Введите 'y' или 'n': ";
    char answer;
    std::cin >> answer;
    if (answer != 'y' && answer != 'n') {
	return getAnswer();
    }
    return answer;
}

std::pair<int, int> processRange(std::pair<int, int> inputRange,
				 char inputAnswer) {
    int middle= calcMiddle(inputRange);
    if (inputAnswer == 'y') {
	if (inputRange.second - inputRange.first > 1) {
	    inputRange.first= middle+1;
	} else {
	    inputRange.first= inputRange.second;
	}
    }
    
    if (inputAnswer == 'n') {
	if (inputRange.second - inputRange.first > 1) {
	    inputRange.second= middle;
	} else {
	    inputRange.second= inputRange.first;
	}
    }

    return inputRange;
}

int main() {
    std::cout << "Пожалуйста, загадайте число!" << std::endl;
    std::pair<int, int> range= std::make_pair(LEFT_SIDE, RIGHT_SIDE);

    while (range.first != range.second) {
	int middle= calcMiddle(range);
	std::cout << "Ваше число больше чем " << middle << "? [y/n]: ";
	char answer= getAnswer();
	range= processRange(range, answer);
    }

    std::cout << "Вы загадали число " << range.first << std::endl;
    return 0;
}
