#include <iostream>
#include "auxiliary.hpp"

enum TokenType {Plus, Minus, Mul, Div, Factorial, Bracket, Value};

class Token {
private:
    TokenType myType;
    double value;
    Token* leftBranch= NULL;
    Token* rightBranch= NULL;
    Token* parent= NULL;
public:
    Token(TokenType inputType, double inputValue) :
	myType(inputType), value(inputValue) {};
    Token(TokenType inputType) : myType(inputType) {};
    void addLeftBranch(Token* inputToken) {
	leftBranch= inputToken;
    };
    void addRightBranch(Token* inputToken) {
	rightBranch= inputToken;
    };
    void setParent(Token* inputToken) {
	parent= inputToken;
    };
    Token* getParent() {
	return parent;
    };
    double eval() {
	if (myType== TokenType::Plus) {
	    double valLeft= leftBranch->eval();
	    double valRight= rightBranch->eval();
	    return valLeft + valRight;
	}
	if (myType== TokenType::Minus) {
	    double valLeft= leftBranch->eval();
	    double valRight= rightBranch->eval();
	    return valLeft - valRight;
	}
	if (myType== TokenType::Mul) {
	    double valLeft= leftBranch->eval();
	    double valRight= rightBranch->eval();
	    return valLeft * valRight;
	}
	if (myType== TokenType::Div) {
	    double valLeft= leftBranch->eval();
	    double valRight= rightBranch->eval();
	    return valLeft / valRight;
	}
	if (myType== TokenType::Factorial) {
	    int valLeft= leftBranch->eval();
	    return factorial(valLeft);
	}
	if (myType== TokenType::Bracket) {
	    double valLeft= leftBranch->eval();
	    return valLeft;
	}
	return value;
    };
};

Token* processString (std::string inputString, Token* inputToken) {
    Token* tmpToken = new Token(TokenType::Value, 0);
    return tmpToken;
}

int main () {
    // Token foo(TokenType::Div);
    // Token val1(TokenType::Value, 42);
    // Token val2(TokenType::Value, 0);
    // foo.addLeftBranch(&val1);
    // foo.addRightBranch(&val2);
    // std::cout << val1.eval() <<std::endl;
    // std::cout << foo.eval() << std::endl;
    Token startSentence(TokenType::Bracket);
    Token fortyTwo(TokenType::Value, 42);
    fortyTwo.setParent(&startSentence);
    startSentence.addLeftBranch(&fortyTwo);
    Token add1(TokenType::Plus);
    add1.addLeftBranch(&fortyTwo);
    add1.setParent(fortyTwo.getParent());
    fortyTwo.setParent(&add1);
    add1.getParent()->addLeftBranch(&add1);
    Token oneValue(TokenType::Value, 1);
    add1.addRightBranch(&oneValue);
    oneValue.setParent(&add1);
    std::cout << startSentence.eval() << std::endl;
}
