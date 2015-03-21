#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

#include "maze.h"

using namespace std;

main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "NamUsage: maze_solver <maze file>" << endl;
		exit(1);
	}

	try {
		string mazeFileName = string(argv[1]);
		Maze maze = load(mazeFileName);
		cout << maze << endl;
		cout << endl << "-------- Solving the Maze --------" << endl << endl;
		 if (!maze.solve()) cout << "Maze couldn't be solved" << endl;
		 else
		 cout << "Maze solved" << endl;
	} catch (string e) {
		cerr << e << endl;
	}
}
