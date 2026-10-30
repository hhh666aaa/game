#include"board.h"

Board::Board(int r, int c) {
	this->rows = r;
	this->cols = c;
	for(int i = 0; i < rows; ++i) {
		vector<int> row;
		for(int j = 0; j < cols; ++j) {
			row.push_back(rand() % 6); // 0-5
		}
		board.push_back(row);
	}
}

void Board::Print() const {
	for(int i=0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

}