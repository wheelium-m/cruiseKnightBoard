//
// Created by wcmarsha on 9/14/2015.
//

#ifndef CRUISE_SQUARE_H
#define CRUISE_SQUARE_H

#include <utility>
#include <vector>
#include "KnightBoard/KnightBoard.h"

using std::vector;
using std::pair;

// Needs to be forward declared due to cyclic dependency
class KnightBoard;

class Square {
public:
    Square(int row, int column, char symbol, KnightBoard *board);

    Square(pair<int, int> position, char symbol, KnightBoard *board);

    bool isConnected(Square *sq);
    bool isAdjacent(Square *sq);

    int getGetConnectionWeight(Square *sq);

    KnightBoard * getBoard();

    Square * getUp();
    Square * getRight();
    Square * getDown();
    Square * getLeft();

    Square * setUp(Square *sq);
    Square * setRight(Square *sq);
    Square * setDown(Square *sq);
    Square * setLeft(Square *sq);

    pair<int, int> getPosition();

    char symbol;
    bool containsKnight;

private:
    KnightBoard *board;
    vector<Square *> adjacents;
    vector<pair<Square *, int> > connections;
    pair<int, int> position;
};



#endif //CRUISE_SQUARE_H
