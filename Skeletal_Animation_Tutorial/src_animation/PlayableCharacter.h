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
		void GainExp(int exp) 
		{
			if(_level < 10)
				_experience += exp; 
		};
		bool IsLevelUp() { return (_experience >= _expLimit); };
		int GetCurrentAttackCooldown() { return _currentAttackCooldown; };
		void SetCurrentAttackCooldown() { _currentAttackCooldown = _attackCooldown; _canAttack = false; };
		void LevelUp(int strength, int agility, int intellegence, int stamina)
		{
			_healthLimit += stamina;
			_damage = _damage + strength;
			_strength += strength;
			_dodge += agility;
			_agility += agility;
			_expLimit *= 2;
			_experience = 0;
			_level += 1;
		};
		void ReduceCooldown()
		{
			_currentAttackCooldown -= 1;
			if (_currentAttackCooldown <= 0)
				_canAttack = true;
		}
		int GetLevel() { return _level; };
		bool CanAttack() { return _canAttack; };
		vector<Ability*> _abilities;
	private:
		int _strength;
		int _agility;
		int _intellegence;
		int _stamina;
		int _experience;
		int _expLimit;
		int _attackCooldown;
		int _currentAttackCooldown;
		int _level;
		bool _canAttack;
	};
}