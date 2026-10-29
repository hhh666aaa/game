using namespace std;
#include <iostream>
#include "board.h"

int main() {
    srand(time(0));
    Board board(8, 8);
    board.PrintBoard();
    return 0;
}