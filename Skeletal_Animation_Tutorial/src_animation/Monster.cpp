#include "Monster.h"

using namespace CourseWork;

Monster::Monster(Coordinates position, int health, int armor, int damage, int dodge) : Character(health, armor, damage, dodge)
{
	_position = position;
}

void Monster::SetPosition(int x, int y)
{
	_position.X = x;
	_position.Y = y;
}
