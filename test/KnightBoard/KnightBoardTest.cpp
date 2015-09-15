//
// Created by wcmarsha on 9/14/2015.
//

#include <iostream>
#include <vector>
#include <assert.h>
#include <KnightBoard/KnightBoard.h>

using std::vector;
using std::cout;
using std::endl;

namespace CruiseTests {

    int adjacentTest(){
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(boardSize);
        for(int i = 0; i < boardSize; i++){
            for(int j = 0; j < boardSize; j++){
                Square * s = kn->getSquare(i, j);
                vector<Square *> adjacents;

                adjacents.push_back(s->getUp());
                adjacents.push_back(s->getRight());
                adjacents.push_back(s->getDown());
                adjacents.push_back(s->getLeft());

                for(auto adj : adjacents){
                    if(NULL != adj) {
                        assert(s->isAdjacent(adj));
                        assert(adj->isAdjacent(s));
                    }
                }
            }
        }
        return 0;
    }

    int connectionsTest(){
        vector<int> numConns = {4,  6,  8,  8,  8,  6,  4,
        6,  8,  12, 12, 12, 8,  6,
        8,  12, 16, 16, 16, 12, 8,
        8,  12, 16, 16, 16, 12, 8,
        8,  12, 16, 16, 16, 12, 8,
        6,  8,  12, 12, 12, 8,  6,
        4,  6,  8,  8,  8,  6,  4};
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(boardSize);
        for(int i = 0; i < boardSize; i++){
            for(int j = 0; j < boardSize; j++){
                Square *s = kn->getSquare(i,j);
                int squareConns = s->connections.size();
                int expectedConns = numConns[boardSize * i + j];
                assert(squareConns == expectedConns);
            }
        }
        return 0;
    }

    bool validSequenceTest(){
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(boardSize);
        vector<pair<unsigned int, unsigned int> > seq1;
        seq1.push_back(*new pair<unsigned int, unsigned int>(0,0));
        seq1.push_back(*new pair<unsigned int, unsigned int>(1,2));
        seq1.push_back(*new pair<unsigned int, unsigned int>(2,0));
        seq1.push_back(*new pair<unsigned int, unsigned int>(3,2));
        seq1.push_back(*new pair<unsigned int, unsigned int>(5,3));
        return kn->validSequence(seq1, false);
    }

    bool invalidSequenceTest(){
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(boardSize);
        vector<pair<unsigned int, unsigned int> > seq1;
        seq1.push_back(*new pair<unsigned int, unsigned int>(0,0));
        seq1.push_back(*new pair<unsigned int, unsigned int>(1,2));
        seq1.push_back(*new pair<unsigned int, unsigned int>(2,0));
        seq1.push_back(*new pair<unsigned int, unsigned int>(3,3));
        seq1.push_back(*new pair<unsigned int, unsigned int>(5,3));
        return kn->validSequence(seq1, false);
    }

    bool shortestPathTest(){
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(boardSize);
        pair<int,int> begin(0,0);
        pair<int,int> end(6,6);
        vector<Square *> path = kn->findShortestPath(begin, end);
        return kn->validSequence(path, false);
    }

    bool shortestPathBarrierTest(){
        char board[] = {
                '.','.','.','B','.','.','.',
                '.','.','.','B','.','.','.',
                '.','.','.','B','.','.','.',
                '.','.','.','B','.','.','.',
                '.','.','.','B','.','.','.',
                '.','.','.','B','.','.','.',
                '.','.','.','.','.','.','.',
        };
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(board, boardSize);
        pair<int,int> begin(0,0);
        pair<int,int> end(0,6);
        vector<Square *> path = kn->findShortestPath(begin, end);
        return kn->validSequence(path, false);
    }

    bool shortestPathTeleportTest(){
        char board[] = {
                '.','.','.','.','.','.','.',
                '.','.','.','.','.','.','.',
                '.','T','.','.','.','.','.',
                '.','.','.','.','.','.','.',
                '.','.','.','.','.','T','.',
                '.','.','.','.','.','.','.',
                '.','.','.','.','.','.','.',
        };
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(board, boardSize);
        pair<int,int> begin(0,0);
        pair<int,int> end(6,6);
        vector<Square *> path = kn->findShortestPath(begin, end);
        return kn->validSequence(path, false);
    }

    bool shortestPathWaterTest(){
        char board[] = {
                '.','.','.','.','.','.','.',
                '.','.','.','.','.','.','.',
                '.','W','.','.','.','.','.',
                'W','W','W','.','.','.','.',
                'W','W','W','.','.','.','.',
                'W','W','.','.','.','.','.',
                '.','.','.','.','.','.','.',
        };
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(board, boardSize);
        pair<int,int> begin(0,0);
        pair<int,int> end(6,0);
        vector<Square *> path = kn->findShortestPath(begin, end);
        return kn->validSequence(path, false);
    }

    bool shortestPathLavaTest(){
        char board[] = {
                '.','.','.','.','.','.','.',
                '.','.','L','.','.','.','.',
                '.','W','.','.','.','.','.',
                'W','W','W','L','.','.','.',
                'W','W','W','.','.','.','.',
                'W','W','.','.','.','.','.',
                '.','.','.','.','.','.','.',
        };
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(board, boardSize);
        pair<int,int> begin(0,0);
        pair<int,int> end(6,0);
        vector<Square *> path = kn->findShortestPath(begin, end);
        return kn->validSequence(path, false);
    }

    bool shortestPathRocksTest(){
        char board[] = {
                '.','.','.','.','R','.','.',
                '.','.','R','.','R','.','.',
                '.','.','R','.','R','.','.',
                '.','.','R','.','.','.','.',
                '.','.','R','.','.','.','.',
                '.','.','.','.','R','R','.',
                '.','.','.','.','.','.','.',
        };
        int boardSize = 7;
        KnightBoard *kn = new KnightBoard(board, boardSize);
        pair<int,int> begin(0,0);
        pair<int,int> end(6,6);
        vector<Square *> path = kn->findShortestPath(begin, end);
        return kn->validSequence(path, false);
    }
}

int main() {
    assert(CruiseTests::adjacentTest() == 0);
    assert(CruiseTests::connectionsTest() == 0);
    assert(CruiseTests::validSequenceTest() == true);
    assert(CruiseTests::invalidSequenceTest() == false);
    assert(CruiseTests::shortestPathTest() == true);
    assert(CruiseTests::shortestPathBarrierTest() == true);
    assert(CruiseTests::shortestPathTeleportTest() == true);
    assert(CruiseTests::shortestPathWaterTest() == true);
    assert(CruiseTests::shortestPathLavaTest() == true);
    assert(CruiseTests::shortestPathRocksTest() == true);
}