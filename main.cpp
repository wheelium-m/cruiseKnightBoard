#include <iostream>
#include <vector>
// Contains the knight board datastructure and graph representation
#include <KnightBoard/KnightBoard.h>

// The definition of the 32x32 knight board
#include <fullKnightBoard.h>

using namespace std;

int main() {

    /////////////
    // Level 4 //
    /////////////
    // Levels 1-3 are covered in the provided unit tests in test/KnightBoard/KnightBoardTest.cpp

    // KnightBoard (optionally) takes a char array that defines the map.
    // The full Cruise knight board is defined in fullKnightBoard.h
    KnightBoard *kn = new KnightBoard(board, 32);

    // Coordinates are provided as pairs of ints, the first value is the row, second is the column.
    pair<int,int> begin(0,0);
    pair<int,int> end(0,31);

    // The knight board is represented as a graph, where Squares are the nodes, and valid knight's
    // moves are the edges. The shortest path is found using dijkstra's algorithm. A* would be a
    // a better alternative, but dijkstra is fine for small boards. Furthermore, the teleports
    // would throw off A*'s hueristics.
    vector<Square *> path = kn->findShortestPath(begin, end);

    // Asserts that each step in the sequence is valid.
    kn->validSequence(path, true);


    /////////////
    // Level 5 //
    /////////////
    // The longest path will work eventually, but the problem is brute-forced.
    // If I had more time, I'd look into tree pruning, or some way or reformulatng
    // the problem. It's a hard problem, not much in the way of optimal substructure.
    KnightBoard *kn_level5 = new KnightBoard(4);
    pair<int,int> begin_level5(0,0);
    pair<int,int> end_level5(3,3);
    vector<Square *> path_level5 = kn_level5->findLongestPath(begin_level5, end_level5);
    return kn_level5->validSequence(path_level5, true);

    return 0;
}

