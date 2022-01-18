#include "board.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

int main (int args, char*  argv[]) {
    int n, winCase;
    if (args <= 1){
        n = 3;
        winCase = 3;
    } else {
        n = atoi(argv[1]);
        winCase = 3;
    }
    Board* board = new Board(n, winCase);
    board->renderBoard();
    return 1;
}