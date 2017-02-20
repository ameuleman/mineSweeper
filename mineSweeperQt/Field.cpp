/*
 * Field.cpp
 *
 *  Created on: 9 mai 2016
 */

#include "Field.h"

#include <algorithm>
#include <iostream>

#include "functor.h"
#include "Exceptions.h"

using namespace std;

/*
 * Constructeur, initialise les diférents atribus
 */
Field::Field(int const& n, int const& m,  int const& tailleCase, GameManager* gameManager): _field(0),_n(0), _m(0), _tailleCase(0), _gameManager(gameManager) {
    try{
        if((n<0)||(m<0)||(tailleCase<0))
            throw NegativeDimensionException();
        _n=n;
        _m=m;
        _tailleCase=tailleCase;
    }
    catch(NegativeDimensionException const& e){
        cerr << e.what() << endl;
    }
}

/*
 * Désalouer explicitement chaque case du vecteur n'est plus indispensable depuis C++11
 * Donc, ici, un destructeur explicite n'est pas nécessaire
 */
Field::~Field() {
    // TODO Auto-generated destructor stub
}

/*
 * Vérifie si les coordonnés décrivent bien une case du champ de mine
 */
bool Field::in_field(int const& k, int const& l) const{
    return((k>=0)&&(k<_n)&&(l>=0)&&(l<_m));
}

/*
 * Ajoute 1 au nombre de bombes adjacentes de chaque case sans bombe
 */
void Field::add_to_neighbour(int const& i,int const& j){
    for (int k=i-1;k<=i+1;++k){
        for (int l=j-1;l<=j+1;++l){
            if ((in_field(k,l)) && !(_field[k][l]->isMined())){
                _field[k][l]->add();
            }
        }
    }
}

/*
 * génère
 */
void Field::createField(QWidget* w){
    try{
        if((w==0)||(_gameManager==0))
            throw UninitializedException();
        _field.resize(_n); //aloue le vector décrivant le champ de mine
        CreateLine createLine(_tailleCase, _m, _gameManager, w);
        generate(_field.begin(), _field.end(), createLine);
    }
    catch(UninitializedException const& e){
        cerr << e.what() << endl;
    }
}

/*
 * Calcul le nombre de bombe adjacentes pour chaque case sans bombe
 */
void Field::calc() {
    for (int i=0;i<_n;++i){
        for (int j=0;j<_m;++j){
            if (_field[i][j]->isMined()){ //Si la case est minée,
                add_to_neighbour(i,j); //incrémente les cases sans bombes adjacentes
            }
        }
    }
}

/*
 * positionne toutes les cases du champ de mine sur la fenêtre
 */
void Field::placeAll(){
    int x(0), y(0);
    for (int i=0;i<_n;++i){
        for (int j=0;j<_m;++j){
            _field[i][j]->move(x,y);
            y+=_tailleCase;
        }
        x+=_tailleCase;
        y=0;
    }
}

/*
 * Fait apparaitre le champ de mine en entier
 */
void Field::appearAll() {
    for_each(_field.begin(), _field.end(), AppearLine());
}
