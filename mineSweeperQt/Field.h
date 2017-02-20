/*
 * Field.h
 *
 *  Created on: 9 mai 2016
 */

#include <vector>
#include <QWidget>

#include "Square.h"
#include "gamemanager.h"

using namespace std;

#ifndef FIELD_H_
#define FIELD_H_

class Field {
public:
        Field(const int& = 0, const int& = 0, const int& = 0, GameManager* = 0);
        virtual ~Field();

        void createField(QWidget*);
        void calc();
        void placeAll();
        void appearAll();

private:
        vector<vector<Square*> > _field;
        int _n;
        int _m;
        int _tailleCase;
        GameManager* _gameManager;

        bool in_field(const int&, const int&) const;
        void add_to_neighbour(const int&,const int&);
};

#endif /* FIELD_H_ */
