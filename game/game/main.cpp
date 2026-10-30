#include"board.h"
#include<iostream>
#include<cstdlib>
#include<ctime>	
using namespace std;

int main() {
	srand(time(0));
		Board b(8, 8);
	b.Print();
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	b.Swap(r1,c1,r2,c2);
	b.Print();

	return 0;
}