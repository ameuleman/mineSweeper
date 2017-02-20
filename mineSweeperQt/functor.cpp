/*
 * functor.cpp
 *
 *  Created on: 9 mai 2016
 *
 *  Diférents foncteurs permettant d'utiliser les algorithme de la librairie standard et de faciliter les opérations sur les tableaux
 */

#include "functor.h"
#include "Square.h"

#include <algorithm>
#include <cstdlib>

/*
 * Permet de créer aléatoirement une case mine ou une case Safe
 */
Square* GenerateSquare::operator()(){
    if ((rand() % 10)>7) {
        _gameManager->addNbMine();
        return new Mined(_w, _gameManager, _tailleCase);
    }
    else{
        return new Safe(_w, _gameManager, _tailleCase);
    }
}

GenerateSquare::GenerateSquare( int const& tailleCase, GameManager* gameManager, QWidget* w):  _tailleCase(tailleCase), _gameManager(gameManager), _w(w){
}

CreateLine::CreateLine(int const& tailleCase, int const& m, GameManager* gameManager, QWidget* w): _tailleCase(tailleCase), _m(m), _gameManager(gameManager), _w(w){
}

vector<Square* > CreateLine::operator()(){
    vector<Square* > line(_m);
    GenerateSquare generateSquare(_tailleCase, _gameManager, _w);
    generate(line.begin(), line.end(), generateSquare);
    return line;
}

void AppearSquare::operator()(Square* square){
    square->toAppear();
}

void AppearLine::operator()(vector<Square* > line){
    for_each(line.begin(), line.end(), AppearSquare());
}





