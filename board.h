#include<iostream>
#include<stdlib.h>
#include <vector>

using namespace std;

class Board {
    int _size;
    int _winCase;
    int** _state;
    bool checkWinner();
    string printLine();

public:
    Board(int, int);
    ~Board();
    bool makeMove(int, int);
    void renderBoard();
};