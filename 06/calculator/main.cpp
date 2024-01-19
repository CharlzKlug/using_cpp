#include <iostream>

void keep_window_open() {
    char c;
    std::cin >> c;
}

void error(std::string message) {
    std::cerr << message << std::endl;
    exit(1);
}

class Token {
public:
    char kind;
    double value;
};

Token get_token(); // Функция чтения лексемы из потока cin
vector<Token> tok; // Сюда помещаем лексемы

double expression() {
    double left= expression();
    Token t= get_token();
    switch (t.kind) {
    case '+':
	return left + term();
    case '-':
	return left - term();
    default:
	return left;
    }
}

int main() {
    // Token t;
    // t.kind= '+';
    // Token t2;
    // t2.kind= '8';
    // t2.value= 3.14;

    // Token tt= t;
    // if (tt.kind != t.kind) error("невозможно!");
    // t= t2;
    // std::cout << t.value << std::endl;

    while (cin) {
	Token t= get_token();
	tok.push_back(4);
    }
    
    Token t1{'+',0};
    Token t2{'8', 11.5};
    
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
