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

    /**
     * Returns true if the other square, sq, is a valid knight's move away
     * from *this. Can only be invoked after KnightBoard::init() is called.
     */
    bool isConnected(Square *sq);

    /**
     * Returns true if the other square, sq, is immediately adjacent
     * to *this. Can only be invoked after KnightBoard::init() is called.
     */
    bool isAdjacent(Square *sq);

    KnightBoard * getBoard();

    /**
     * Returns the square that is immediately "up", "down", "left", or "right"
     * on the board.
     */
    Square * getAdjacent(string direction);

    Square * setUp(Square *sq);
    Square * setRight(Square *sq);
    Square * setDown(Square *sq);
    Square * setLeft(Square *sq);

    /**
     * Retrieves the position of the piece in the board.
     */
    pair<int, int> getPosition();

    /**
     * Traverses the graph, and figures out which other squares are a valid
     * knight's move away.
     */
    void determineConnections();

    // The symbol of the square on the map
    char symbol;

    // True, if the square currently contains the knight. Used for printing.
    bool containsKnight;

    // Each element of this vector contains a valid knight's move from this square.
    // pair.first is the connected square
    // pair.second is the weight of the connection
    vector<pair<Square *, int> > connections;

    // Used for traversing backwards with dijkstra's algorithm.
    Square *backEdge;

    // The weight of the path thus far.
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
