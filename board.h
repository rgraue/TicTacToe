#include<iostream>
#include<stdlib.h>
#include <vector>

using namespace std;

class Board {
    int _size;
    int _winCase;
    int** _state;
    string printLine();
    int diagnalCheck();

public:
    Board(int, int);
    ~Board();
    bool makeMove(int, int, int);
    void renderBoard();
    int checkWinner();
};