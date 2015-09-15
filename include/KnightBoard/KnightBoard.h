//
// Created by wcmarsha on 9/14/2015.
//

#ifndef CRUISE_KNIGHTBOARD_H
#define CRUISE_KNIGHTBOARD_H

#include <vector>
#include <utility>
#include "Square/Square.h"

using std::pair;
using std::vector;

// Needs to be forward declared due to cyclic dependency
class Square;

class KnightBoard {
public:
    /**
     * Constructs a sizexsize board board of '.' squares.
     */
    KnightBoard(unsigned int size);

    /**
     * Reads in a graph as a 2-D grid, where 'size' represents the side length of the board. E.g,
     * for a 7x7 board, size = 7. The board should be heap-allocated, as a reference is maintained,
     * and going out of scope would free its memory.
     */
    KnightBoard(char *board, unsigned int size);

    bool validSequence(vector<std::pair<unsigned int, unsigned int> > sequence, bool printBoards);

    Square *getSquare(unsigned int row, unsigned int col);

    /**
     * Gets the square at the given position.
     * position.first is the row, position.second is the column
     */
    Square *getSquare(pair<unsigned int, unsigned int> position);
    void setSquare(unsigned int row, unsigned int col, Square * sq);
    bool setSquare(pair<unsigned int, unsigned int>, Square * sq);

    void printBoard();
private:

    void init(char *board, unsigned int size);
    void constructEmptyBoard(unsigned int size);
    void setAdjacents();
    void determineConnections();

    char **charBoard;
    vector<vector<Square *> > *board;
    unsigned int size;
};


#endif //CRUISE_KNIGHTBOARD_H
