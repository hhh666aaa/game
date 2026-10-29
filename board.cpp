using namespace std;
#include "board.h"
#include <iostream>
#include <ctime>
#include<cstdlib>

Board::Board(int r, int c) : rows(r), cols(c) {
    
    board.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            board[i][j] = rand() % 5 + 1;
}

void Board::PrintBoard() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}