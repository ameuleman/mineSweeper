/*
 * functor.h
 *
 *  Created on: 9 mai 2016
 */

#ifndef SRC_FUNCTOR_H_
#define SRC_FUNCTOR_H_

#include <vector>
#include <QWidget>

#include "gamemanager.h"
#include "Square.h"


using namespace std;

class CreateLine{
public:
    CreateLine(const int&, const int&, GameManager*, QWidget*);

    vector<Square* > operator()();

private:
    int _m, _tailleCase;
    GameManager* _gameManager;
    QWidget* _w;
};

class GenerateSquare{
public:
    GenerateSquare(const int&,  GameManager*, QWidget*);

    Square* operator()();

private:
    QWidget* _w;
    GameManager* _gameManager;
    int _tailleCase;
};

class AppearLine{
public:
    void operator()(vector<Square* >);
};

class  AppearSquare{
public:
    void operator()(Square*);
};

#endif /* SRC_FUNCTOR_H_ */
