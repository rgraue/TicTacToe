#include "board.h"

Board::Board(int n, int winCase):_size(n), _winCase(winCase) {
    // initialize empty board of size n * n
    this->_state = new int*[n];
    for (int i = 0; i < n; i++){
        this->_state[i] = new int[n];
    }
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            this->_state[row][col] = 0;
        }
    }
}

Board::~Board(){
    for (int i = 0; i < this->_size; i++){
        delete[](this->_state[i]);
    }
    delete[](_state);
}

bool Board::makeMove(int row, int col, int player){
    if (row > this->_size || col > this->_size || row < 0 || col < 0){
        return false;
    }
    if (this->_state[row-1][col-1] == 0){
        this->_state[row-1][col-1] = player;
    } else {
        return false;
    }
    return true;
}

void Board::renderBoard () {
    
    cout << this->printLine();
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
        cout << this->printLine();
    }
    return;
}

string Board::printLine(){
    string result = "";
    for ( int i = 0; i < this->_size*2+1; i++){
        result += "-";
    }
    return(result+="\n");
}


bool Board::checkWinner () {
    return true;
}
