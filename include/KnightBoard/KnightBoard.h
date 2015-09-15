//
// Created by wcmarsha on 9/14/2015.
//

#ifndef CRUISE_KNIGHTBOARD_H
#define CRUISE_KNIGHTBOARD_H

#include <vector>
#include <map>
#include <string>
#include <utility>
#include "Square/Square.h"

using std::pair;
using std::vector;
using std::map;
using std::string;

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

    /*
     * Determines whether the given sequence corresponds to valid knight moves.
     */
    bool validSequence(vector<std::pair<unsigned int, unsigned int> > sequence, bool printBoards);
    bool validSequence(vector<Square *> sequence, bool printBoards);

    /**
     * Gets the square at the given position.
     * position.first is the row, position.second is the column
     */
    Square *getSquare(pair<unsigned int, unsigned int> position);
    Square *getSquare(unsigned int row, unsigned int col);

    /**
     * Sets the square at the supplied coordinates to the given square reference.
     */
    void setSquare(unsigned int row, unsigned int col, Square * sq);

    /**
     * Prints the board, including its symbols and the location of the knight.
     */
    void printBoard();


    /**
     * Given a pointer to one teleport square, return a pointer to the other.
     * Assumes that there are only two.
     */
    Square *getOtherTeleport(Square *sq);

    /**
     * Finds the shortest path between the two squares specified by the supplies coordinates.
     */
    vector<Square *> findShortestPath(pair<unsigned int, unsigned int> start, pair<unsigned int, unsigned int> end);
    vector<Square *> findShortestPath(unsigned int s_row, unsigned int s_col, unsigned int e_row, unsigned int e_col);

    /**
     * A map of the weights for the given symbols.
     */
    static map<char, int> symbolWeights;
private:


    void init(char *board, unsigned int size);
    void constructEmptyBoard(unsigned int size);
    void setAdjacents();
    void determineAllConnections();
    pair<Square *, Square *> teleports;
    char **charBoard;
    vector<Square *> *board;
    unsigned int size;

};


#endif //CRUISE_KNIGHTBOARD_H
