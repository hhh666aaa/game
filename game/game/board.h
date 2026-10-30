#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Board {
    int rows, cols;
    vector<vector<int>> board;  // 1-5 表示颜色，0 表示空
public:
    Board(int r, int c);
    void Print() const;
    
    void Swap(int r1, int c1, int r2, int c2);
    bool IsAdjacent(int r1, int c1, int r2, int c2);
};