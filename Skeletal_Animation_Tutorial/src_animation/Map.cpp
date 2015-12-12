#include "Map.h"

using namespace CourseWork;

Map::Map(int width, int height, int** pattern, vector<Monster*> monsters, Coordinates startPosition)
{
	_width = width;
	_height = height;
	_pattern = pattern;
	_monsters = monsters;
	_startPosition = startPosition;
}

vector<Monster*> CourseWork::Map::GetMonsters()
{
	return _monsters;
}
