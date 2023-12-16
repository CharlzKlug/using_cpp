#include <vector> // For std::vector
#include <cassert> // For assert
#include <iostream> // For std::cout

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

int readChar() {
  char ch;
  do {
    std::cin >> ch;
  } while (ch < '0' || ch > '9');
  return ch - '0';
}

void printVectorInt(std::vector<int> inputVector) {
  for(int x : inputVector) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> computerNumber{1, 2, 3, 4};
  std::vector<int> userNumber{};
  do {
    userNumber= {};
    for (int i= 0; i < 4; ++i) {
      userNumber.push_back(readChar());
    }
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
