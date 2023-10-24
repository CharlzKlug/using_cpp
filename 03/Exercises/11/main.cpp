#include <vector> // Для std::vector
#include <string> // Для std::string
#include <iostream> // Для std::cout

int main() {
    std::vector<std::string> messages=
	{
	    "одноцентовых монет",
	    "пятицентовых монет",
	    "десятицентовых монет",
	    "двадцатипятицентовых монет",
	    "пятидесятицентовых монет",
	    "долларовых монет"
	};
    std::vector<int> coin_counts= {};
    
    for (std::string someString : messages) {
	std::cout << "Сколько у вас " << someString << "? ";
	int counts= 0;
	std::cin >> counts;
	coin_counts.push_back(counts);
    }

    std::vector<std::string> message_for_one =
	{
	    "одноцентовая монета",
	    "пятицентовая монета",
	    "десятицентовая монета",
	    "двадцатипятицентовая монета",
	    "пятидесятицентовая монета",
	    "долларовая монета"
	};
    
    std::vector<int> prices= {1, 5, 10, 25, 50, 100};
    int summ = 0;

    for (long unsigned int i = 0; i < coin_counts.size(); i++) {
	int coin_count = coin_counts.at(i);
	summ += coin_count * prices.at(i);
	std::cout << "У вас " << coin_count << " " <<
	    (1 != coin_count ? messages.at(i) : message_for_one.at(i)) << "\n";
    }

    std::cout << "Общая стоимость ваших монет равна " << summ << " центам.\n";
    return 0;
}
