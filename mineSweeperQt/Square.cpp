/*
 * Square.cpp
 *
 *  Created on: 9 mai 2016
 */


#include "Square.h"
#include "gamemanager.h"

/*
 * Constructeur de Square ;
 */
Square::Square(QWidget* w, GameManager* gameManager, int const& tailleCase): QPushButton("", w), _gameManager(gameManager){
    setFixedSize(tailleCase, tailleCase);
    connect(this, SIGNAL(clicked()), this, SLOT(toAppear())); //permet de lancer la fonction toApear() quand on appuis sur le bouton
}

Square::~Square() {
        // Pas d'allocation dynamique donc pas besoin de destructeur explicite
}

/*
 * Fait appel au constructeur de la classe mère Square et initialise le nombre de bombes adjacentes à 0
 */
Safe::Safe(QWidget* w, GameManager* gameManager, int const& tailleCase): Square(w, gameManager, tailleCase),_nb(0) {
}

Safe::~Safe() {
        // Pas d'allocation dynamique donc pas besoin de destructeur explicite
}

/*
 * incrémente le nombre de bombes adjacentes
 */
void Safe::add() {
        ++_nb;
}

/**
 * Afiche sur le bouton le nombre de bombes adjacentes
 */
void Safe::toAppear() {
    setEnabled(false);
    setText(QString::number(_nb));
    _gameManager->addNbDiscovered();
}

/*
 * Retourne faux car cette case n'est pas minée
 */
bool Safe::isMined() const {
        return false;
}

/*
 * Fait appel au constructeur de la classe mère
 */
Mined::Mined(QWidget* w, GameManager* gameManager, int const& tailleCase): Square(w, gameManager, tailleCase){
}

Mined::~Mined() {
         // Pas d'allocation dynamique donc pas besoin de destructeur explicite
}

/*
 * Retourne vrai car une case de la classe Mined est minée
 */
bool Mined::isMined() const{
        return true;
}

void Mined::add() {}

/*
 * Affiche "*" sur le bouton, sinifiant une bombe
 */
void Mined::toAppear() {
    setEnabled(false);
    setText("*");
    _gameManager->lost();
}

