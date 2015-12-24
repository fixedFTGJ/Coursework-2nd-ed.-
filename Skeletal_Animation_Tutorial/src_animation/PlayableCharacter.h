#pragma once

#include "Character.h"
#include "Ability.h"

namespace CourseWork
{
	class PlayableCharacter : public Character
	{
	public:
		PlayableCharacter(int health, int armor, int damage, int dodge, int strength, int agility, int intellegence, int stamina);
		void Regenerate();
		void SetAbilities(vector<Ability*> abilities) { _abilities = abilities; };
		vector<Ability*> _abilities;
	private:
		int _strength;
		int _agility;
		int _intellegence;
		int _stamina;
	};
}