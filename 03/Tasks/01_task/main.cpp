#include <iostream> // Для std::cout

void simple_error(std::string response) {
    std::cout << response << '\n';
    exit(0);
}

int main() {
    std::cout << "Введите имя адресата: ";
    std::string correspondent_name;
    std::cin >> correspondent_name;
    std::cout << "Введите имя друга: ";
    std::string friend_name;
    std::cin >> friend_name;

    char friend_sex= 0;
    std::cout << "Введите пол друга (m - мужской, f - женский): ";
    std::cin >> friend_sex;

    int age;
    std::cout << "Введите возраст адресата: ";
    std::cin >> age;

    if (age <= 0 || age >= 110) {
	simple_error("Ты шутишь!");
    }
    
    std::cout << "Дорогой " << correspondent_name << ",\n";
    std::cout << "Как дела? У меня всё хорошо. Я скучаю по тебе."
	" Мистер Сальери передаёт тебе привет! ";
    std::cout << "Давно ли ты встречал " << friend_name << "? ";

    std::cout << "Если ты увидишь " << friend_name <<
	", пожалуйста, попроси ";
    switch (friend_sex) {
    case 'm':
	std::cout << "его ";
	break;
    case 'f':
	std::cout << "её ";
	break;
    default:
    {}
    }

    std::cout << "позвонить мне.\n";

    std::cout << "Я слышал, ты только что отметил день рождения и тебе исполнилось " <<
	age << " лет.\n";

    if (age < 12) {
	std::cout << "На следующий год тебе исполнится " << age + 1 << " лет.\n";
    }

    if (age == 17) {
	std::cout << "В следующем году ты сможешь голосовать.\n";
    }

    if (age > 70) {
	std::cout << "Я надеюсь, что ты не скучаешь на пенсии.\n";
    }

    std::cout << "Искренне твой" << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "Имиль\n";
    return 0;
}
