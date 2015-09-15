//
// Created by wcmarsha on 9/14/2015.
//

#ifndef CRUISE_SQUARE_H
#define CRUISE_SQUARE_H

#include <utility>
#include <vector>
#include <map>
#include <string>
#include "KnightBoard/KnightBoard.h"

using std::vector;
using std::pair;
using std::map;
using std::string;

// Needs to be forward declared due to cyclic dependency
class KnightBoard;

class Square {
public:
    Square(int row, int column, char symbol, KnightBoard *board);

    Square(pair<int, int> position, char symbol, KnightBoard *board);

    bool isConnected(Square *sq);
    bool isAdjacent(Square *sq);

    int getGetConnectionLightestWeight(Square *sq);

    KnightBoard * getBoard();

    Square * getAdjacent(string direction);

    Square * getUp();
    Square * getRight();
    Square * getDown();
    Square * getLeft();

    Square * setUp(Square *sq);
    Square * setRight(Square *sq);
    Square * setDown(Square *sq);
    Square * setLeft(Square *sq);

    pair<int, int> getPosition();

    void determineConnections();

    char symbol;
    bool containsKnight;
    vector<pair<Square *, int> > connections;
    Square *backEdge;
    int path_weight;
private:
    vector<Square *> getDirectionalPath(vector<string> knightMove);

    KnightBoard *board;
    vector<Square *> adjacents;
    map<string, Square *> adjacentMap;
    pair<int, int> position;

    static vector<vector<string> > moves;

};



#endif //CRUISE_SQUARE_H
