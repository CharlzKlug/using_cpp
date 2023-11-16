#include <map> // Для std::map
#include <ctime> // Для std::time
#include <cstdlib> // Для std::srand
#include <iostream> // Для std::cout

enum Chose {Rock, Paper, Scissors};
std::map<Chose, Chose> win{{Chose::Rock, Chose::Scissors}, {Chose::Paper, Chose::Rock}, {Chose::Scissors, Chose::Paper}};

enum State {Win, Lose, Draw};
State referee(Chose input_chose_computer, Chose input_chose_player) {
  if (input_chose_computer == input_chose_player) {
    return State::Draw;
  }
  if (win[input_chose_computer] == input_chose_player) {
    return State::Win;
  }
  return State::Lose;
}
Chose genRandomChose() {
  double randomValue= (double) std::rand() / RAND_MAX;
  if (randomValue >= 0.66) {
    return Chose::Scissors;
  }
  if (randomValue >= 0.33) {
    return Chose::Paper;
  }
  return Chose::Rock;
}
Chose getUserChose() {
  std::cout << "Your chose [R - Rock, P - Paper, S - Scissors, E - Exit]: " << std::endl;
  char ch;
  std::cin >> ch;
  switch (ch) {
  case 'r':
    return Chose::Rock;
    break;
  case 'p':
    return Chose::Paper;
    break;
  case 's':
    return Chose::Scissors;
    break;
  case 'e':
    exit(0);
    break;
  default:
    std::cout << "Wrong char '" << ch << "'" << std::endl;
    return getUserChose();
  }
}
std::string chose2String(Chose inputChose){
  if (inputChose == Chose::Rock) {
    return "Rock";
  } else if (inputChose == Chose::Paper) {
    return "Paper";
  } else {
    return "Scissors";
  }
}
void gamePlay() {
  std::cout << "New round!" << std::endl;
  Chose computerChose= genRandomChose();
  Chose userChose= getUserChose();
  std::cout << "My Chose is " << chose2String(computerChose) <<
    ", your Chose is " << chose2String(userChose) <<
    ". Result: ";
  State currentState= referee(computerChose, userChose);
  if (State::Win == currentState) {
    std::cout << "You lose!" << std::endl;
  } else if (State::Lose == currentState) {
    std::cout << "You win!" << std::endl;
  } else {
    std::cout << "Draw!" << std::endl;
  }
}
int main() {
  std::srand(std::time(nullptr) + 101);
  do {
    gamePlay();
  } while (true);

  return 0;
}
