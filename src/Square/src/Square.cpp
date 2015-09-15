//
// Created by wcmarsha on 9/14/2015.
//

#include <limits.h>
#include "Square/Square.h"


Square::Square(int row, int column, char symbol, KnightBoard *board)
        :adjacents(4), containsKnight(false) {
    this->position.first = row;
    this->position.second = column;
    this->symbol = symbol;
    this->board = board;
}

Square::Square(pair<int, int> position, char symbol, KnightBoard *board)
        :adjacents(4), containsKnight(false) {
    this->position.first = position.first;
    this->position.second = position.second;
    this->symbol = symbol;
    this->board = board;
}

bool Square::isConnected(Square *sq) {
    for (auto connection : connections) {
        if (connection.first == sq) {
            return true;
        }
    }
    return false;
}

bool Square::isAdjacent(Square *sq) {
    for (auto adjacent : adjacents) {
        if (adjacent == sq) {
            return true;
        }
    }
    return false;
}

KnightBoard *Square::getBoard() {
    return this->board;
}

int Square::getGetConnectionWeight(Square *sq) {
    for (auto connection : connections) {
        if (connection.first == sq) {
            return connection.second;
        }
    }
    return INT_MIN;
}

Square *Square::getUp() {
    return this->adjacents[0];
}

Square *Square::getRight() {
    return this->adjacents[1];
}

Square *Square::getDown() {
    return this->adjacents[2];
}

Square *Square::getLeft() {
    return this->adjacents[3];
}

Square *Square::setUp(Square *sq) {
    this->adjacents[0] = sq;
}

Square *Square::setRight(Square *sq) {
    this->adjacents[1] = sq;
}

Square *Square::setDown(Square *sq) {
    this->adjacents[2] = sq;
}

Square *Square::setLeft(Square *sq) {
    this->adjacents[3] = sq;
}

pair<int, int> Square::getPosition() {
    return position;
}
