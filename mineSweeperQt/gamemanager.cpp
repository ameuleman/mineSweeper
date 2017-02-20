#include <QMessageBox>
#include <iostream>

#include "gamemanager.h"
#include "Exceptions.h"

using namespace std;

GameManager::GameManager(int const& nbTotal, QWidget* w):_nbDiscovered(0),_nbMines(0), _nbTotal(nbTotal), _w(w){
}

void GameManager::addNbMine(){
    ++_nbMines;
}

void GameManager::addNbDiscovered(){
    ++_nbDiscovered;
    if(_nbMines==_nbTotal-_nbDiscovered){
        won();
    }
}

void GameManager::won(){
    QMessageBox::information(_w, "", "Victoire !");
    try{
        if(_w==0)
            throw UninitializedException();
        _w->close();
    }
    catch(UninitializedException const& e){
        cerr << e.what() << endl;
    }
}


void GameManager::lost(){
    QMessageBox::information(_w, "", "Défaite !");
    try{
        if(_w==0)
            throw UninitializedException();
        _w->close();
    }
    catch(UninitializedException const& e){
        cerr << e.what() << endl;
    }
}
