#ifndef AUXILIARY_HPP
#define AUXILIARY_HPP

unsigned int factorial(unsigned int k) {
    int result= 1;
    for(unsigned int i= k; i > 1; i--) {
	result *= i;
    }
    return result;
}

#endif	// AUXILIARY_HPP
