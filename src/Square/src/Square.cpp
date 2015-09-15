//
// Created by wcmarsha on 9/14/2015.
//

#include <limits.h>
#include "Square/Square.h"


Square::Square(int row, int column, char symbol, KnightBoard *board)
        :adjacents(4), containsKnight(false), backEdge(NULL), path_weight(INT_MAX) {
    this->position.first = row;
    this->position.second = column;
    this->symbol = symbol;
    this->board = board;
}

Square::Square(pair<int, int> position, char symbol, KnightBoard *board)
        :adjacents(4), containsKnight(false), backEdge(NULL), path_weight(INT_MAX) {
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

Square *Square::setUp(Square *sq) {
    this->adjacents[0] = sq;
    this->adjacentMap["up"] = sq;
}

Square *Square::setRight(Square *sq) {
    this->adjacents[1] = sq;
    this->adjacentMap["right"] = sq;
}

Square *Square::setDown(Square *sq) {
    this->adjacents[2] = sq;
    this->adjacentMap["down"] = sq;
}

Square *Square::setLeft(Square *sq) {
    this->adjacents[3] = sq;
    this->adjacentMap["left"] = sq;
}

pair<int, int> Square::getPosition() {
    return position;
}

Square *Square::getAdjacent(string direction) {
    return adjacentMap[direction];
}

vector<Square *> Square::getDirectionalPath(vector<string> knightMove) {
    vector<Square *> *path = new vector<Square *>();
    path->push_back(this);
    path->push_back(this->getAdjacent(knightMove[0]));
    if(path->at(1) == NULL){
        delete path;
        return std::vector<Square *>();
    }
    path->push_back(path->at(1)->getAdjacent(knightMove[1]));
    if(path->at(2) == NULL){
        delete path;
        return std::vector<Square *>();
    }
    path->push_back(path->at(2)->getAdjacent(knightMove[2]));
    if(path->at(3) == NULL){
        delete path;
        return std::vector<Square *>();
    }

    for(auto square : *path){
        if(square->symbol == 'B') {
            delete path;
            return std::vector<Square *>();
        }
    }
    if(path->at(3)->symbol == 'R'){
        delete path;
        return std::vector<Square *>();
    }

    if(path->at(3)->symbol == 'T'){
        path->at(3) = this->getBoard()->getOtherTeleport(path->at(3));
    }

    return *path;
}

void Square::determineConnections() {
    for(auto move : moves){
        vector<Square *> path = getDirectionalPath(move);
        if(path.size() == 0)
            continue;
        int weight = this->board->symbolWeights[path[0]->symbol];
        this->connections.push_back(*(new pair<Square *, int>(path[3], weight)));
    }
}

vector<vector<string> > Square::moves = {
        {"up","up","left"},
        {"up","up","right"},
        {"up","left","left"},
        {"up","right","right"},
        {"right","right","up"},
        {"right","right","down"},
        {"right","up","up"},
        {"right","down","down"},
        {"down","down","right"},
        {"down","down", "left"},
        {"down","right","right"},
        {"down","left","left"},
        {"left","left","down"},
        {"left","left","up"},
        {"left","down","down"},
        {"left","up","up"}
};