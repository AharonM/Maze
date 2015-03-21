#include <iostream>
#include <vector>

#include "maze.h"

using namespace std;

int main(){
	//string file = "maze1.txt";
	Maze maze = load();
	if(maze.solve() == true)
	cout<< "\nmaze solved\n";
//	cout << maze;
}
