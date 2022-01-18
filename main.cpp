#include "board.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

int main (int args, char*  argv[]) {
    int n, winCase, row, col;
    int gameOver = 0;
    int currPlayer = 1;
    if (args <= 1){
        n = 3;
        winCase = 3;
    } else {
        n = atoi(argv[1]);
        winCase = 3;
    }
    Board* board = new Board(n, winCase);
    while (gameOver == 0){
        cout << "PLayer " << currPlayer << " Make your move\n";
        cin >> row >> col;
        if (board->makeMove(row, col, currPlayer)){
            switch (currPlayer){
                case(1):
                    currPlayer = 2;
                    break;
                case(2):
                    currPlayer = 1;
                    break;
            }
            gameOver = board->checkWinner();
        } else {
            cout << "Invalid position. Go again" << endl;
        }
        board->renderBoard();
    }
    if (gameOver > 0){
        cout << "Player " << gameOver << " wins" << endl;
    }
    board->~Board();
    return 1;
}