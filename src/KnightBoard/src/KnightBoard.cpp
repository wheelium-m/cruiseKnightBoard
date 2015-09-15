//
// Created by wcmarsha on 9/14/2015.
//

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include "KnightBoard/KnightBoard.h"

using std::cout;
using std::endl;
using std::set;

// Common code for constructors.
void KnightBoard::init(char *_board, unsigned int size) {
    this->size = size;
    this->teleports.first = NULL;
    this->teleports.second = NULL;
    this->constructEmptyBoard(size);
    for(unsigned int col = 0; col < size; col++){
        for(unsigned int row = 0; row < size; row++){
            Square *sq = new Square(row, col, _board[size*row + col], this);
            if(_board[size*row + col] == 'T'){
                teleports.first == NULL ? teleports.first = sq : teleports.second = sq;
            }
            this->setSquare(row, col, sq);
        }
    }
    setAdjacents();
    determineAllConnections();
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
    vector<Square *> squareSequence;
    for(auto step : sequence){
        squareSequence.push_back(getSquare(step));
    }
    return validSequence(squareSequence, printBoards);
}


bool KnightBoard::validSequence(vector<Square *> squareSequence, bool printBoards) {
    Square *prev = NULL;
    for(auto square : squareSequence){
        if(!(NULL == prev)){
            if(!prev->isConnected(square)){
                return false;
            }
        }
        square->containsKnight = true;
        if(printBoards)
            this->printBoard();
        square->containsKnight = false;
        prev = square;
    }
    return true;
}

Square *KnightBoard::getSquare(unsigned int row, unsigned int col) {
    if(row >= this->size || row < 0 || col >= this->size || col < 0){
        return NULL;
    }
    return this->board->at(size*row + col);
}

Square *KnightBoard::getSquare(pair<unsigned int, unsigned int> position) {
    return this->board->at(size*position.first + position.second);
}

void KnightBoard::setSquare(unsigned int row, unsigned int col, Square *sq) {
    if(row >= size || row < 0 || col >= size || col < 0){
        throw new std::out_of_range("Arguments to setSquare() were out of range");
    }
    this->board->at(size*row + col) = sq;
}

void KnightBoard::constructEmptyBoard(unsigned int size) {
    vector<Square *> * _board = new vector<Square *>(size*size);
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
                cout<<"K ";
            else
                cout << this->getSquare(i, j)->symbol<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void KnightBoard::determineAllConnections() {
    for(auto square : *(this->board)){
        square->determineConnections();
    }
}


Square *KnightBoard::getOtherTeleport(Square *sq) {
    if(teleports.first == sq)
        return teleports.second;
    else
        return teleports.first;
}

vector<Square *> KnightBoard::findShortestPath(pair<unsigned int, unsigned int> start,
                                               pair<unsigned int, unsigned int> end) {
    typedef pair< Square *, pair<Square *, int> *> future_connection_t;
    typedef pair<Square *, int> connection_t;

    Square *sqStart = this->getSquare(start);
    Square *sqEnd = this->getSquare(end);

    sqStart->path_weight=0;
    //vector<Square *> *visited = new vector<Square *>();
    //visited->push_back(sqStart);

    set<Square *> *visited = new set<Square *>();
    set<future_connection_t *> *unvisited = new set<future_connection_t *>();
    visited->insert(sqStart);

    for(int i = 0; i < sqStart->connections.size(); i++){
        unvisited->insert(new future_connection_t(sqStart, &(sqStart->connections[i])));
    }

    // Perform dijkstra's algorithm iteratively.
    while(unvisited->size() > 0){
        // Get lightest connection
        int min_weight = INT_MAX;
        future_connection_t *lightest = NULL;

        for(auto unvisit : *unvisited){
            Square *internal = unvisit->first;
            Square *external = unvisit->second->first;
            int weight = unvisit->second->second;
            int path_weight = unvisit->first->path_weight;

            if(path_weight + weight < min_weight){
                min_weight = path_weight + weight;
                lightest = unvisit;
            }
        }
        lightest->second->first->path_weight = lightest->first->path_weight + lightest->second->second;
        lightest->second->first->backEdge = lightest->first;
        visited->insert(lightest->second->first);

        // Erase connections from unvisited for which a lighter path has been found
        vector<future_connection_t *> toErase;
        for(auto unvisit : *unvisited){
            if(unvisit->second->first == lightest->second->first){
                toErase.push_back(unvisit);
            }
        }
        for(auto eraseMe : toErase){
            unvisited->erase(eraseMe);
        }

        for(int i = 0; i < lightest->second->first->connections.size(); i++){
            connection_t *conn = &lightest->second->first->connections[i];
            if(visited->count(conn->first) == 0)
                unvisited->insert(new future_connection_t(lightest->second->first, conn));
        }

        // Return the path after backtracking.
        if(lightest->second->first == sqEnd){
            vector<Square *> *lightestPath = new vector<Square *>();
            lightestPath->push_back(lightest->second->first);
            Square *_backEdge = lightest->first;
            while(_backEdge != NULL){
                lightestPath->insert(lightestPath->begin(), _backEdge);
                _backEdge = _backEdge->backEdge;
            }
            delete visited;
            delete unvisited;
            return *lightestPath;
        }
    }




    return std::vector<Square *>();
}

vector<Square *> KnightBoard::findShortestPath(unsigned int s_row, unsigned int s_col, unsigned int e_row,
                                               unsigned int e_col) {
    pair<unsigned int,unsigned int> start(s_row,s_col), end(e_row,e_col);
    return findShortestPath(start, end);
}




map<char,int> KnightBoard::symbolWeights = {
        {'.', 1},
        {'B', INT_MAX},
        {'W', 2},
        {'R', INT_MAX},
        {'L', 5},
        {'T', 1}
};

