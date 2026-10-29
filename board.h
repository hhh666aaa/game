#pragma once
using namespace std;
#include <vector>

class Board {
    int rows, cols;
    vector<vector<int>> board;
public:
    Board(int r, int c);
    void PrintBoard() const;
};
