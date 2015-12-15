#pragma once

#include "Environment.h"

class PathFinder
{
public:
	PathFinder(int** matrix, int width, int height);
	bool lee(int ax, int ay, int bx, int by, int* &px, int* &py, int &len, int** matrix);
	/*int *px, *py;*/
	/*int len;*/
private:
	void CalculateWays();
	int** _weightMatrix;
	int** _wayMatrix;
	int _matrixSize;
	/////
	int W;
	int H;     // координаты €чеек, вход€щих в путь
	const int WALL = -1;         // непроходима€ €чейка
	const int BLANK = -2;         // свободна€ непомеченна€ €чейка
	int **grid;
};
