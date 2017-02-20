#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QWidget>

class GameManager
{
public:
    GameManager(const int& = 0, QWidget* = 0);

    void addNbMine();
    void addNbDiscovered();
    void won();
    void lost();

private:
    int _nbMines;
    int _nbDiscovered;
    int _nbTotal;
    QWidget* _w;
};

#endif // GAMEMANAGER_H
