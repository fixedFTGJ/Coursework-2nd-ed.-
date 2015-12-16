#include "PathFinder.h"
#include <iostream>
using namespace std;
using namespace CourseWork;

PathFinder::PathFinder(Map* map)
{
	_map = map;
	int W = _map->GetWidth(), H = _map->GetHeight();
	grid = new int*[H];
	/*int** matrix = _map->GetPattern();*/

	for (int i = 0; i < H; i++)
	{
		grid[i] = new int[W];
	}

	/*for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (matrix[i][j] == 1)
				grid[i][j] = WALL;
			else
				grid[i][j] = BLANK;
		}
	}*/
}


bool PathFinder::lee(int ax, int ay, int bx, int by , int* &px, int* &py, int &len)   // ����� ���� �� ������ (ax, ay) � ������ (bx, by)
{
	int W = _map->GetWidth(), H = _map->GetHeight();
	int** matrix = _map->GetPattern();
	px = new int[W*H];
	py = new int[W*H];
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (matrix[i][j] == 1)
				grid[j][i] = WALL;
			else
				grid[j][i] = BLANK;
		}
	}
	vector<Monster*> monsters = _map->GetMonsters();
	for (Monster* m : monsters)
	{
		grid[m->GetPosition().Y][m->GetPosition().X] = WALL;
	}
	grid[ay][ax] = BLANK;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << grid[i][j] << " ";;
		}
		cout << endl;
	}
	cout << endl;
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