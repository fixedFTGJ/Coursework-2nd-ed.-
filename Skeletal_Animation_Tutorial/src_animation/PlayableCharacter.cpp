#include "PlayableCharacter.h"

using namespace CourseWork;

PlayableCharacter::PlayableCharacter(int health, int armor, int damage, int dodge, int strength, int agility, int intellegence, int stamina) :
	Character(health+stamina, armor, damage+strength, dodge + agility)
{
	_strength = strength;
	_agility = agility;
	_intellegence = intellegence;
	_stamina = stamina;
}

void CourseWork::PlayableCharacter::Regenerate()
{
	if (_health < _healthLimit)
	{
		_health += _stamina / 10;
	}
	if (_health > _healthLimit)
		_health = _healthLimit;
}
