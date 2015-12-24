#include "Character.h"
#include <iostream>

using namespace CourseWork;
using namespace std;

Character::Character(int health, int armor, int damage, int dodge)
{
	_health = health;
	_armor = armor;
	_damage = damage;
	_dodge = dodge;
	_healthLimit = health;
	_isDead = false;
};

void Character::Attack(Character* target)
{
	if(!target->IsDead())
		target->ReceiveDamage(_damage);
};

void Character::ReceiveDamage(int damage)
{
	if ((!IsDodge()) && ((damage - _armor) > 0))
	{
		_health = _health - (damage - _armor);
	}
	if (_health <= 0)
		_isDead = !_isDead;
};

bool Character::IsDodge()
{
	if ((rand() % 100 + 1) <= _dodge)
		return true;
	else
		return false;
}
bool CourseWork::Character::IsDead()
{
	return _isDead;
}
;