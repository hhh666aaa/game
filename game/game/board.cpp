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


void Board::Swap(int r1, int c1, int r2, int c2) {
	
	if(this->IsAdjacent(r1, c1, r2, c2)==1) {
		auto temp = board[r1][c1];
		board[r1][c1] = board[r2][c2];
		board[r2][c2] = temp;
		
	}
	else {
		cout << "不相邻无法交换" << endl;
	}
	
}

bool Board::IsAdjacent(int r1, int c1, int r2, int c2) {
	
	int dr = abs(r1 - r2);
	int dc = abs(c1 - c2);
	
	return dr + dc == 1;
}
