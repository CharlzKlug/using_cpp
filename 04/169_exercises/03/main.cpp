#include <vector> // Для std::vector
#include <iostream> // Для std::cin
#include <algorithm> // Для std::max_element
#include <numeric> // Для std::accumulate

double meanArithmetic(std::vector<double>);
double maxDistance(std::vector<double>);
double minDistance(std::vector<double>);
std::vector<double> getDistances();
double sumDistances(std::vector<double>);

int main() {
    std::vector<double> distances = {};
    distances= getDistances();

    std::cout << "Общая сумма: " << sumDistances(distances) <<
	std::endl;
    std::cout << "Минимальное расстояние: " << minDistance(distances) <<
	std::endl;
    std::cout << "Максимальное расстояние: " << maxDistance(distances) <<
	std::endl;
    std::cout << "Среднее расстояние: " << meanArithmetic(distances) <<
	std::endl;
    return 0;
}

double meanArithmetic(std::vector<double> inputVector) {
    double sum = std::accumulate(inputVector.begin(), inputVector.end(), 0);
    double result = sum / (inputVector.size());
    return result;
}

double maxDistance(std::vector<double> inputVector) {
    std::vector<double>::iterator maxElementPnt=
	std::max_element(inputVector.begin(), inputVector.end());
    return *maxElementPnt;
}

double minDistance(std::vector<double> inputVector) {
    std::vector<double>::iterator minElementPnt=
	std::min_element(inputVector.begin(), inputVector.end());
    return *minElementPnt;
}

std::vector<double> getDistances() {
    std::vector<double> distances = {};
    double temp;
    while (std::cin >> temp) {
	distances.push_back(temp);
    }
    return distances;
}

double sumDistances(std::vector<double> inputVector) {
    return std::accumulate(inputVector.begin(), inputVector.end(), 0);
}
