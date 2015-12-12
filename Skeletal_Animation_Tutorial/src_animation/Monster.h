#pragma once

#include "Environment.h"
#include "Character.h"

namespace CourseWork
{
	class Monster : Character
	{
	public:
		Monster(Coordinates position, int health, int armor, int damage, int dodge);
		Coordinates GetPosition() { return _position; };
		void SetPosition(int x, int y);
	private:
		Coordinates _position;
	};
}