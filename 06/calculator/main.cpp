#include <iostream>

void keep_window_open() {
    char c;
    std::cin >> c;
}

void error(std::string message) {
    std::cerr << message << std::endl;
    exit(1);
}

int main() {
    std::cout << "Введите выражение (разрешены +, -, * и /)\n";
    std::cout << "Добавьте x к концу выражения (1+2*3x): ";
    int lval= 0;
    int rval;
    std::cin >> lval;

    if (!std::cin) {
	error("Нет первого операнда");
    }

    for (char op; std::cin >> op ;) {
	if (op != 'x') {
	    std::cin >> rval;
	}

	if (!std::cin) {
	    error("нет второго операнда");
	}

	switch (op) {
	case '+':
	    lval += rval;
	    break;

	case '-':
	    lval -= rval;
	    break;

	case '*':
	    lval *= rval;
	    break;

	case '/':
	    lval /= rval;
	    break;

	default:
	    std::cout << "Результат: " << lval << '\n';
	    keep_window_open();
	    return 0;
	}
    }
    // char op;
    // int res;
    // std::cin >> lval >> op >> rval;
    // if (op == '+')
    // 	res= lval + rval;
    // else if (op == '-')
    // 	res= lval - rval;
    // std::cout << "Результат: " << res << '\n';
    // keep_window_open();
    error("неверное выражение");
}
