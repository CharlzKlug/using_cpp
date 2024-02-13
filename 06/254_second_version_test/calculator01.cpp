//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

// #include "./std_lib_facilities.h"
#include <string>
#include <iostream>

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

void error(std::string message) {
    std::cerr << message << std::endl;
}

void keep_window_open(std::string message) {
    message = message + "";
}

//------------------------------------------------------------------------------

class Token_stream {
    public:
        Token get();            // get a Token
        void putback(Token t);  // put a Token back
    private:
        bool full {false};      // is there a Token in the buffer?
        Token buffer = {'0'};           // where we store a 'putback' Token
};

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;         // copy t to buffer
    full = true;        // buffer is now full
}

Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch;

    switch (ch) {
        case ';':       // for "print"
        case 'q':       // for "quit"
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token{ch};   // let each character represent itself
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            {
		std::cin.putback(ch);
                double val;
		std::cin >> val;
                return Token{'8', val};
            }
        default:
            error("Bad Token");
    }
    return Token{' '};
}

//------------------------------------------------------------------------------

Token_stream ts;      // provides get() and putback()

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
    return 0;
}
//------------------------------------------------------------------------------

int main() {
    try {
	double val= 0;
	while (std::cin) {
	    Token t= ts.get();
	    if (t.kind == 'q') break;
	    if (t.kind == ';')
		std::cout << "=" << val << '\n';
	    else
		ts.putback(t);
	    val = expression();
	}
	keep_window_open("~0");
    }
    catch (...) {
	std::cerr << "exception \n";
	keep_window_open ("~2");
	return 2;
    }
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token
    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = ts.get();     // get the next token

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------
