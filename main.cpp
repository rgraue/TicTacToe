/**
 * @file    main.cpp
 * @author  Ryan Graue
 * @brief   Simulates a game of tic tac toe
 * @version 0.1
 * @date    2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "board.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

int main (int args, char*  argv[]) {
    int n, winCase, row, col;
    int gameOver = 0;
    int currPlayer = 1;
    // sets board size. if no argument then size = 3
    if (args <= 1){
        n = 3;
        winCase = 3;
    } else {
        n = atoi(argv[1]);
        winCase = 3;
    }
    Board* board = new Board(n, winCase);
    // repeats until winner
    while (gameOver == 0){
        cout << "PLayer " << currPlayer << " Make your move\n";
        cin >> row >> col;
        if (board->makeMove(row, col, currPlayer)){ //if successful move switch to next player
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
    if (gameOver > 0){ // if winner
        cout << "Player " << gameOver << " wins" << endl;
    }
    board->~Board();
    return 1;
}