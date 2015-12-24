#pragma once

#include "Environment.h"
#include "Character.h"

namespace CourseWork
{
	class Monster : public Character
	{
	public:
		Monster(Coordinates position, int health, int armor, int damage, int dodge);
		Coordinates GetPosition() { return _position; };
		void SetPosition(int x, int y);
		Coordinates GetOrientation() { return _orientation; };
		void SetOrientation(int x, int y);
		float GetRotation() { return _rotation; };
		void SwitchActivity();
		bool IsActive();
	private:
		bool _isActive;
		Coordinates _position;
		Coordinates _orientation;
		float _rotation;
	};
}