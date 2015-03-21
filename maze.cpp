#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stack>
#include "maze.h"

using namespace std;


ostream &operator <<(ostream &os, const Maze &maze){
	for(int i=0;i < maze.height()-2;i++){
		for(int j=0;j < maze.width();j++){
			Location location(j,i);
			if(maze.spec.at(i).at(j) == true){
				if(location == maze.start)
				os << "S";
				else if(location == maze.finish)
				os << "F";
				else
				os << "*";
			}
			else
			os << " ";		
		}
		os << endl;
	}
	return os;
}



bool Maze::isPath(const Location &location) const
{
	return (spec.at(location.y).at(location.x));
}




Maze load(string filename){
	vector<vector<bool> > spec;
	string str;
	int size=0,count=0;

	Location location,start,finish,current;
	fstream infile(filename.c_str());
	getline(infile,str);
	size = str.size();
	if(str[0] != '+' && str[size-1] != '+')
	cerr << "Input file is wrong.\n";
	str.erase(0,1);
	str.erase(size-2,1);
	
	while(getline(infile,str)){
	if(str[0] == '+')
	break;
	str.erase(0,1);
	str.erase(size-2,1);
	vector<bool> row;
	spec.push_back(row);
	for(int i=0;i < str.size();i++){
		current = Location(i,count);
		if(str[i] == 'S')
		start = current;
		if(str[i] == 'F')
		finish = current;

		if(str[i] == ' ')
		spec.at(count).push_back(false);
		else
		spec.at(count).push_back(true);
	}
		count++;
}

	for(int j=0;j < 2;j++){
		vector<bool> row;
		spec.push_back(row);
		for(int i=0;i < 2;i++)
		spec.at(count+j).push_back(false);
}
infile.close();
	Maze maze(spec,start,finish);
	return maze;
}


bool Maze::solve(){
	stack<Location> loc;
	stack<Location> direc;
	Location location;
	loc.push(start);
	direc.push(start);

while(!loc.empty()){
	current = loc.top();
	loc.pop();

	if (current == finish)
	return true;
	
	location = Location(current.x+1,current.y); //right
	if(location != direc.top() && isPath(location) == true){
	direc.push(current);
	current = location;
	loc.push(location);
	print(location);
	}


	location = Location(current.x-1,current.y); //left
	if(location != direc.top() && isPath(location) == true){
	direc.push(current);
	current = location;
	loc.push(location);
	print(location);
	}

	location = Location(current.x,current.y-1); //up
	if(location != direc.top() && isPath(location) == true){
	direc.push(current);
	current = location;
	loc.push(location);
	print(location);

	}

	location = Location(current.x,current.y+1); //down
	if(location != direc.top() && isPath(location) == true){
	direc.push(current);
	current = location;
	loc.push(location);
	print(location);
	}
	}
	return false;
}




void Maze::print(const Location &current){
		for(int i=0;i < height()-2;i++){
		for(int j=0;j < width();j++){
			Location location(j,i);
			if(spec.at(i).at(j) == true){
				if(location == start)
				cout << "S";
				else if(location == finish)
				cout << "F";
				else if(location == current)
				cout << "O";	
				else
				cout << "*";
			}
			else
			cout << " ";		
		}
		cout << endl;
	}
	cout << endl << endl;
}


