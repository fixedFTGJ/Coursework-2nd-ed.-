#include "Monster.h"

using namespace CourseWork;

Monster::Monster(Coordinates position, int health, int armor, int damage, int dodge) : Character(health, armor, damage, dodge)
{
	_position = position;
	_orientation = Coordinates(0, 1);
	_rotation = 0;
}

void Monster::SetPosition(int x, int y)
{
	_position.X = x;
	_position.Y = y;
}

void CourseWork::Monster::SetOrientation(int x, int y)
{
	if ((x == 0) && (y == 1))
		_rotation = 0;
	if ((x == 0) && (y == -1))
		_rotation = 3;
	if ((x == 1) && (y == 0))
		_rotation = 1.5;
	if ((x == -1) && (y == 0))
		_rotation = -1.5;

	_orientation.X = x;
	_orientation.Y = y;
}
