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
    if (row > this->_size || col > this->_size || row <= 0 || col <= 0){
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

// return -1 if board is full;
int Board::checkWinner () {
    int currCol, currRow;
    bool rowWin = true, colWin = true;
    for (int i = 0; i < this->_size; i++){
        currCol = this->_state[0][i];
        currRow = this->_state[i][0];
        for (int j = 0; j < this->_size; j++){
            // check for column win
            if (this->_state[i][j] != currCol){
                colWin = false;
            }
            // check for row win
            if (this->_state[j][i] != currRow){
                rowWin = false;
            }
        }
        if (rowWin && currRow > 0){
            return currRow;
        } else if (colWin && currCol > 0){
            return currCol;
        }
        rowWin = true;
        colWin = true;
    }
    int diagnal = this->diagnalCheck();
    if (diagnal > 0){
        return diagnal;
    }
    return 0;
}

int Board::diagnalCheck(){
    int leftCheck = this->_state[0][0];
    int rightCheck = this->_state[0][this->_size-1];
    bool rightWin = true, leftWin = true;
    // check the left Diagnal
    for (int i = 0; i < this->_size; i++){
        if (this->_state[i][i] != leftCheck){
            leftWin = false;
        }
    }
    for (int i = 0; i < this->_size; i++){
        if (this->_state[i][this->_size-1-i] != rightCheck){
            rightWin = false;
        }
    }
    if (rightWin && rightCheck > 0){
        return rightCheck;
    } else if (leftWin && leftCheck > 0){
        return leftCheck;
    }
    return -1;
}
