#pragma once
#include<vector>
#include<iostream>
using namespace std;

  struct Eliminate { 
      int r, c;
  };

class Board {
    int rows, cols;
    vector<vector<int>> board;  // 1-5 表示颜色，0 表示空
public:
    Board(int r, int c);
    void Print() const;
    
    void Swap(int r1, int c1, int r2, int c2);
    bool IsAdjacent(int r1, int c1, int r2, int c2);

 
  
    vector<Eliminate> FindEliminates();  // 返回所有需要消除的位置
};

