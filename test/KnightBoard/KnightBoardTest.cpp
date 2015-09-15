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
}

int main() {
    assert(CruiseTests::adjacentTest() == 0);
}