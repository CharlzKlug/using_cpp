#include <vector> // For std::vector
#include <cassert> // For assert
#include <iostream> // For std::cout
#include <ctime> // For std::time
#include <limits> // For numeric_limits

#define VECTOR_SIZE 4

int bullsCount (std::vector<int> const inputOrig, std::vector<int> const inputGuess) {
  assert(inputOrig.size() == VECTOR_SIZE);
  assert(inputGuess.size() == VECTOR_SIZE);
  int bullsNumber= 0;
  for (size_t i=0; i < VECTOR_SIZE; ++i) {
    if (inputOrig.at(i) == inputGuess.at(i)) {
      ++bullsNumber;
    }
  }
  return bullsNumber;
}

void clearBulls (std::vector<int> &outputOrig, std::vector<int> &outputGuess) {
  assert(outputOrig.size() == VECTOR_SIZE);
  assert(outputGuess.size() == VECTOR_SIZE);
  std::vector<int> truncatedOrig {};
  std::vector<int> truncatedGuess {};
  for (size_t i=0; i < VECTOR_SIZE; ++i) {
    if (outputOrig.at(i) != outputGuess.at(i)) {
      truncatedOrig.push_back(outputOrig.at(i));
      truncatedGuess.push_back(outputGuess.at(i));
    }
  }
  outputOrig= truncatedOrig;
  outputGuess= truncatedGuess;
}

int cowsCount (std::vector<int> inputOrig,
	       std::vector<int> inputGuess) {
  clearBulls(inputOrig, inputGuess);
  int count= 0;
  for (size_t i= 0; i < inputOrig.size(); ++i) {
    for (size_t j= 0; j < inputGuess.size(); ++j) {
      if (inputOrig.at(i) == inputGuess.at(j)) {
	++count;
	inputGuess.erase(inputGuess.begin() + j);
	break;
      }
    }
  }
  return count;
}

std::vector<int> genComputerSeq() {
  std::vector<int> result{};
  for (size_t i=0; i < VECTOR_SIZE; ++i) {
    double rnd = ((double) std::rand()) / RAND_MAX;
    rnd= rnd * 9;
    result.push_back((int)rnd);
  }
  return result;
}

std::vector<int> readVector() {
    std::string inputString;
    std::vector<int> result{};
    do {
	std::cin >> inputString;
	if (inputString.length() >= VECTOR_SIZE) {
	    for (size_t i= 0; i < VECTOR_SIZE; ++i) {
		char ch= inputString.at(i);
		if (ch >= '0' && ch <= '9') {
		    result.push_back(ch - '0');
		}
	    }
 
	}
    } while (result.size() != 4);
    return result;
}

int main() {
  std::srand(std::time(nullptr));
  std::vector<int> computerNumber= genComputerSeq();
  std::vector<int> userNumber{};
  do {
    userNumber= {};
    userNumber= readVector();
    std::cout << "Bulls: "
	      << bullsCount(computerNumber,userNumber)
	      << ", cows: "
	      << cowsCount(computerNumber, userNumber)
	      << std::endl;
  } while (bullsCount(computerNumber, userNumber)
	   != VECTOR_SIZE);
  std::cout << "You win!\n";
  return 0;
}
