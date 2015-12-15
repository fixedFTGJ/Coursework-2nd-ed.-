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


bool PathFinder::lee(int ax, int ay, int bx, int by , int* &px, int* &py, int &len, int** matrix)   // ����� ���� �� ������ (ax, ay) � ������ (bx, by)
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
	int dx[4] = { 1, 0, -1, 0 };   // ��������, ��������������� ������� ������
	int dy[4] = { 0, 1, 0, -1 };   // ������, �����, ����� � ������
	int d, x, y, k;
	bool stop;

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) return false;  // ������ (ax, ay) ��� (bx, by) - �����

																	 // ��������������� �����
	d = 0;
	grid[ay][ax] = 0;            // ��������� ������ �������� 0
	do {
		stop = true;               // ������������, ��� ��� ��������� ������ ��� ��������
		for (y = 0; y < H; ++y)
			for (x = 0; x < W; ++x)
				if (grid[y][x] == d)                         // ������ (x, y) �������� ������ d
				{
					for (k = 0; k < 4; ++k)                    // �������� �� ���� ������������ �������
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
							grid[iy][ix] == BLANK)
						{
							stop = false;              // ������� ������������ ������
							grid[iy][ix] = d + 1;      // �������������� �����
						}
					}
				}
		d++;
	} while (!stop && grid[by][bx] == BLANK);

	if (grid[by][bx] == BLANK) return false;  // ���� �� ������

											  // �������������� ����
	len = grid[by][bx];            // ����� ����������� ���� �� (ax, ay) � (bx, by)
	x = bx;
	y = by;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;                   // ���������� ������ (x, y) � ����
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
				grid[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           // ��������� � ������, ������� �� 1 ����� � ������
				break;
			}
		}
	}
	px[0] = ax;
	py[0] = ay;                    // ������ px[0..len] � py[0..len] - ���������� ����� ����
	return true;
}