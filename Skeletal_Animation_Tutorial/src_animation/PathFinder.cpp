#include "PathFinder.h"
#include <iostream>
using namespace std;

PathFinder::PathFinder(int ** matrix, int width, int height)
{
	/*_matrixSize = height*width;
	_weightMatrix = new int*[_matrixSize];
	_wayMatrix = new int*[_matrixSize];

	for (int i = 0; i < _matrixSize; i++)
	{
		_weightMatrix[i] = new int[_matrixSize];
		_wayMatrix[i] = new int[_matrixSize];
	}

	for (int i = 0; i < _matrixSize; i++)
	{
		for (int j = 0; i < _matrixSize; j++)
		{
			_weightMatrix[i][j] = INT_MAX;
			if (i != j)
				_wayMatrix[i][j] = j;
			else
				_wayMatrix[i][j] = INT_MAX;
		}
	}
	

	int k = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; i < width; j++)
		{
			if ((matrix[i][j + 1] == 0) && (j < width - 1))
			{
				_weightMatrix[k][j + 1] = 1;
				_weightMatrix[j + 1][k] = 1;
			}
			if ((matrix[i + 1][j] == 0) && (i < height - 1))
			{
				_weightMatrix[j + i*width][k] = 1;
				_weightMatrix[k][j + i*width] = 1;
			}
			k++;
		}
	}

	CalculateWays();*/
	W = width;
	H = height;
	/*px = new int[W*H];
	py = new int[W*H];*/
	grid = new int*[H];

	for (int i = 0; i < H; i++)
	{
		grid[i] = new int[W];
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (matrix[i][j] == 1)
				grid[i][j] = WALL;
			else
				grid[i][j] = BLANK;
		}
	}
}

void PathFinder::CalculateWays()
{
	for (int k = 0; k < _matrixSize - 1; k++)
		for (int i = 0; i < _matrixSize; i++)
			for (int j = 0; j < _matrixSize; j++)
			{
				if (_weightMatrix[i][j] > _weightMatrix[i][k] + _weightMatrix[k][j])
				{
					_weightMatrix[i][j] = _weightMatrix[i][k] + _weightMatrix[k][j];
					_wayMatrix[i][j] = k;
				}
			}
}


bool PathFinder::lee(int ax, int ay, int bx, int by , int* &px, int* &py, int &len, int** matrix)   // поиск пути из €чейки (ax, ay) в €чейку (bx, by)
{
	px = new int[W*H];
	py = new int[W*H];
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (matrix[i][j] == 1)
				grid[i][j] = WALL;
			else
				grid[i][j] = BLANK;
		}
	}
	//////////////////
	int dx[4] = { 1, 0, -1, 0 };   // смещени€, соответствующие сосед€м €чейки
	int dy[4] = { 0, 1, 0, -1 };   // справа, снизу, слева и сверху
	int d, x, y, k;
	bool stop;

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) return false;  // €чейка (ax, ay) или (bx, by) - стена

																	 // распространение волны
	d = 0;
	grid[ay][ax] = 0;            // стартова€ €чейка помечена 0
	do {
		stop = true;               // предполагаем, что все свободные клетки уже помечены
		for (y = 0; y < H; ++y)
			for (x = 0; x < W; ++x)
				if (grid[y][x] == d)                         // €чейка (x, y) помечена числом d
				{
					for (k = 0; k < 4; ++k)                    // проходим по всем непомеченным сосед€м
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
							grid[iy][ix] == BLANK)
						{
							stop = false;              // найдены непомеченные клетки
							grid[iy][ix] = d + 1;      // распростран€ем волну
						}
					}
				}
		d++;
	} while (!stop && grid[by][bx] == BLANK);

	if (grid[by][bx] == BLANK) return false;  // путь не найден

											  // восстановление пути
	len = grid[by][bx];            // длина кратчайшего пути из (ax, ay) в (bx, by)
	x = bx;
	y = by;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;                   // записываем €чейку (x, y) в путь
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
				grid[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           // переходим в €чейку, котора€ на 1 ближе к старту
				break;
			}
		}
	}
	px[0] = ax;
	py[0] = ay;                    // теперь px[0..len] и py[0..len] - координаты €чеек пути
	return true;
}