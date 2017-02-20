/*
 * NegativeDimentionException.cpp
 *
 *  Created on: 9 mai 2016
 */

#include "Exceptions.h"

#include <string>

const char* NegativeDimensionException::what() const throw(){
        return "Error: negative dimension";
}

const char* UninitializedException::what() const throw(){
    return "Error: pointer uninitialized";
}
