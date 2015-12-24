#pragma once

#include "Environment.h"
#include "Map.h"

using namespace CourseWork;

class PathFinder
{
public:
	PathFinder(/*Map* map*/);
	bool lee(int ax, int ay, int bx, int by, int* &px, int* &py, int &len, Map* _map);
	/*int *px, *py;*/
	/*int len;*/
private:
	//Map* _map;
	const int WALL = -1;         // непроходима€ €чейка
	const int BLANK = -2;         // свободна€ непомеченна€ €чейка
	int **grid;
};
