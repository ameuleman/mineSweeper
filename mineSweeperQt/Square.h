/*
 * Square.h
 *
 *  Created on: 9 mai 2016
 *
 *  Ensemble de classes permettant de décrire une case du champ de mine : soit Mined soit Safe
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include <string>
#include <QApplication>
#include <QPushButton>
#include <QWidget>

#include "gamemanager.h"

/*
 * Classe abstraite mère des classes décrivant les cases, elle hérite de QPushButton pour l'interface graphique
 */
class Square: public QPushButton {
    Q_OBJECT

public:
    Square(QWidget* = 0, GameManager* = 0, const int& = 0); //constructeur
    virtual ~Square(); //destructeur

    virtual bool isMined() const=0; //Renvoie vrai si la case est minée
    virtual void add()=0;

public slots:
    virtual void toAppear() =0; //affiche la nature de la case

protected:
    GameManager* _gameManager;
};

/*
 * Classe pour les cases sans danger
 */
class Safe: public Square {
    Q_OBJECT

public:
        Safe(QWidget* = 0,  GameManager* = 0, const int& = 0);
        virtual ~Safe();

        bool isMined() const; //renvoie faux car non minée
        void add(); //ajoute 1 à _nb

public slots:
        void toAppear(); //affiche _nb

private:
        int _nb; //nombre de case minée adjacente
};

/*
 * Classe pour les cases minées
 */
class Mined: public Square {
    Q_OBJECT

public:
        Mined(QWidget* = 0,  GameManager* = 0, const int& = 0);
        virtual ~Mined();

        bool isMined() const; //renvoie vrai car minée
        void add();

public slots:
        void toAppear(); //affiche *, cela représente une case minée
};


#endif /* SQUARE_H_ */
