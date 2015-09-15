#include <iostream>
#include <vector>
// Contains the knight board datastructure and graph representation
#include <KnightBoard/KnightBoard.h>

// The definition of the 32x32 knight board
#include <fullKnightBoard.h>

using namespace std;

int main() {

    KnightBoard *kn = new KnightBoard(board, 32);
    pair<int,int> begin(0,0);
    pair<int,int> end(0,31);
    vector<Square *> path = kn->findShortestPath(begin, end);
    kn->validSequence(path, true);

    return 0;
}

