//
// Created by wcmarsha on 9/14/2015.
//

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "KnightBoard/KnightBoard.h"

using std::cout;
using std::endl;

// Common code for constructors.
void KnightBoard::init(char *board, unsigned int size) {
    this->size = size;
    this->constructEmptyBoard(size);
    for(unsigned int col = 0; col < size; col++){
        for(unsigned int row = 0; row < size; row++){
            Square *sq = new Square(row, col, board[size*row + col], this);
            this->setSquare(row, col, sq);
        }
    }
    setAdjacents();
}

KnightBoard::KnightBoard(unsigned int size) {
    char * kboard = (char *)malloc(size*size);
    for(int i = 0; i < size*size; i++){
        kboard[i] = '.';
    }
    init(kboard, size);
}

KnightBoard::KnightBoard(char *board, unsigned int size) {
    this->init(board, size);
}

bool KnightBoard::validSequence(vector<std::pair<unsigned int, unsigned int> > sequence, bool printBoards) {
    return false;
}

Square *KnightBoard::getSquare(unsigned int row, unsigned int col) {
    if(row >= this->size || row < 0 || col >= this->size || col < 0){
        return NULL;
    }
    return this->board->at(row)[col];
}

Square *KnightBoard::getSquare(pair<unsigned int, unsigned int> position) {
    return this->board->at(position.first)[position.second];
}

void KnightBoard::setSquare(unsigned int row, unsigned int col, Square *sq) {
    if(row >= size || row < 0 || col >= size || col < 0){
        throw new std::out_of_range("Arguments to setSquare() were out of range");
    }
    this->board->at(row)[col] = sq;
}

bool KnightBoard::setSquare(pair<unsigned int, unsigned int> position, Square *sq) {
    this->setSquare(position.first, position.second, sq);
}

void KnightBoard::constructEmptyBoard(unsigned int size) {
    vector<vector<Square *> > * _board = new vector<vector<Square *> >();
    for(unsigned int i = 0; i < size; i++) {
        vector<Square *> row = *(new vector<Square *>(size));
        _board->push_back(row);
    }
    this->board = _board;
}

void KnightBoard::setAdjacents() {
    for(unsigned int i = 0; i < this->size; i++){
        for(unsigned int j = 0; j < this->size; j++) {
            Square *sq = this->getSquare(i, j);

            sq->setUp(this->getSquare(i-1, j));
            sq->setRight(this->getSquare(i, j+1));
            sq->setDown(this->getSquare(i+1, j));
            sq->setLeft(this->getSquare(i, j-1));
        }
    }
}

void KnightBoard::printBoard() {
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < size; j++) {
            if(this->getSquare(i,j)->containsKnight)
                cout<<"K";
            else
                cout << this->getSquare(i, j)->symbol;
        }
        cout << endl;
    }
    cout << endl;
}
