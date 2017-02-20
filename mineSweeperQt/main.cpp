#include "Field.h"
#include "mainwindow.h"

#include <QApplication>
#include <cstdlib>
#include <ctime>
#include <iostream>

int const n=5;
int const m=5;
int const tailleCase=50;

int main(int argc, char *argv[])
{
    srand(time(0)); //Initialisation de la fonction permettant d'optenir des nombres aléatoires
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(n*tailleCase, m*tailleCase);

    GameManager* gameManager = new GameManager(n*m, &w);
    Field field(n, m, tailleCase, gameManager);
    field.createField(&w);
    field.calc();
    field.placeAll();

    w.show();

    return a.exec();
}
