#include <iostream>
#include <vector>

#include "maze.h"

using namespace std;

int main(){
	Maze maze = load();
	if(maze.solve() == true)
	cout<< "\nmaze solved\n";
}
