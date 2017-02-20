/*
 * NegativeDimentionException.h
 *
 *  Created on: 9 mai 2016
 */

#ifndef SRC_NEGATIVEDIMENSIONEXCEPTION_H_
#define SRC_NEGATIVEDIMENSIONEXCEPTION_H_

#include <exception>

/*
 * Exception personalisée permettant de gerer le cas où un nombre négatif est rentré comme valeur de dimention du champ de mine
 */
class NegativeDimensionException: public std::exception {
public:
        virtual const char* what() const throw();
};

/*
 * Exception si un pointeur n'a pas été correctement initialisé
 */
class UninitializedException: public std::exception {
public:
        virtual const char* what() const throw();
};

#endif /* SRC_NEGATIVEDIMENTIONEXCEPTION_H_ */
