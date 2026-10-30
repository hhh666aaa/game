#include"board.h"
#include<iostream>
#include<cstdlib>
#include<ctime>	
using namespace std;

int main() {
	srand(time(0));
		Board b(8, 8);
	b.Print();
	return 0;
}