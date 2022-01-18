#include "board.h"

Board::Board(int n, int winCase):_size(n), _winCase(winCase) {
    // initialize empty board of size n * n
    _state = new int*[n];
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            _state[row][col] = 0;
        }
    }
}

Board::~Board(){
    delete[](_state);
}

bool Board::makeMove(int row, int col){

    return false;
}

void Board::renderBoard () {
    for ( int i = 0; i < this->_size; i++){
        cout << '-';
    }
    cout << endl;
    for (int i = 0; i < this->_size; i++){
        for (int j = 0; j < this->_size; j++){
            cout << "|";
            int val = this->_state[i][j];
            switch (val){
                case 1:
                    cout << "X";
                    break;
                case 2:
                    cout << "O";
                    break;
                default:
                    cout << " ";
                    break;
            }
        }
        cout << "|" << endl;
    }
    return;
}


bool Board::checkWinner () {
    return true;
}
