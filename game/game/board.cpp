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

vector<Eliminate> Board::FindEliminates() {
    
    vector<vector<bool>> isEliminate(rows, vector<bool>(cols, false));

   
    for (int i = 0; i < rows; i++) {
        int sameCount = 1; 
        for (int j = 1; j < cols; j++) {
           
            if (board[i][j] != 0 && board[i][j] == board[i][j - 1]) {
                sameCount++;
            }
            else {
               
                if (sameCount >= 3) {
                   
                    for (int k = j - sameCount; k < j; k++) {
                        isEliminate[i][k] = true;
                    }
                }
                sameCount = 1; 
            }
        }
        
        if (sameCount >= 3) {
            for (int k = cols - sameCount; k < cols; k++) {
                isEliminate[i][k] = true;
            }
        }
    }

    
    for (int j = 0; j < cols; j++) {
        int sameCount = 1;
        for (int i = 1; i < rows; i++) {
            if (board[i][j] != 0 && board[i][j] == board[i - 1][j]) {
                sameCount++;
            }
            else {
                if (sameCount >= 3) {
                    for (int k = i - sameCount; k < i; k++) {
                        isEliminate[k][j] = true;
                    }
                }
                sameCount = 1;
            }
        }
       
        if (sameCount >= 3) {
            for (int k = rows - sameCount; k < rows; k++) {
                isEliminate[k][j] = true;
            }
        }
    }

    
    vector<Eliminate> result;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isEliminate[i][j]) {
                result.push_back({ i, j }); 
            }
        }
    }
    return result;

}

