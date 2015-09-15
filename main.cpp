#include <iostream>
#include <vector>
#include <string>
#include <KnightBoard/KnightBoard.h>

using namespace std;

int main() {
    KnightBoard *kn = new KnightBoard(7);
    kn->printBoard();

    return 0;
}