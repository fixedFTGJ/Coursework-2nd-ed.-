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


bool PathFinder::lee(int ax, int ay, int bx, int by , int* &px, int* &py, int &len)   // поиск пути из €чейки (ax, ay) в €чейку (bx, by)
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