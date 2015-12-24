#pragma once

#include "Character.h"
#include <vector>
#include "Monster.h"
#include "Map.h"

using namespace std;
using namespace CourseWork;

class Ability
{
public:
	Ability(int cooldown) { _cooldown = cooldown; };
	virtual void Do() = 0;
	virtual void Reset() = 0;
	virtual void SetTarget(Monster* target) { _mtarget = target; };
	virtual void SetTarget(Character* target) { _ctarget = target; };
	virtual void SetLookAt(int x, int y) { _lookAt.X = x; _lookAt.Y = y; };
	virtual void SetCurrentCooldown() { _currentCooldown = _cooldown; _canBeUsed = false; };
	virtual void ReduceCooldown() 
	{
		_currentCooldown -= 1;
		if (_currentCooldown <= 0)
		{
			_canBeUsed = true;
		}
	};
	virtual bool CanBeUsed() { return _canBeUsed; };
	virtual void UpdateState() = 0;
protected:
	Character* _ctarget;
	Monster* _mtarget;
	Coordinates _lookAt;
	int _cooldown;
	int _currentCooldown;
	bool _canBeUsed;
};

class OnlyKineticAbility : public Ability
{
public:
	OnlyKineticAbility(int cooldown) : Ability(cooldown) {
		_mtarget = nullptr;
		_ctarget = nullptr;
	};
	void SetTarget(Monster* target) { Ability::SetTarget(target); };
	void SetTarget(Character* target) { Ability::SetTarget(target); };
};

class TargetAbility : public Ability
{
public:
	TargetAbility(int cooldown) : Ability(cooldown)
	{
		_mtarget = nullptr;
		_ctarget = nullptr;
	}
	void SetTarget(Monster* target) { Ability::SetTarget(target); };
	void SetTarget(Character* target) { Ability::SetTarget(target); };
};

class SelfAbility : public Ability
{
public:
	SelfAbility(Character* character, int cooldown) : Ability(cooldown)
	{
		_character = character;
	}
	void SetTarget(Monster* target) { Ability::SetTarget(target); };
	void SetTarget(Character* target) { Ability::SetTarget(target); };
protected:
	Character* _character;
};

class MassAbility : public Ability
{
public:
	MassAbility(vector<Character*> characters, int cooldown) : Ability(cooldown)
	{
		_characters = characters;
	}
	void SetTarget(Monster* target) { Ability::SetTarget(target); };
	void SetTarget(Character* target) { Ability::SetTarget(target); };
protected:
	vector<Character*> _characters;
};

class Provoke : public TargetAbility
{
public:
	Provoke(Character* character, int cooldown) : TargetAbility(cooldown) { _character = character; };
	
	void SetTarget(Character* target)
	{
		TargetAbility::SetTarget(target);
	}
	
	void Do()
	{
		_ctarget->Attack(_character);
	}
	
	void UpdateState() {};

	void Reset() {};
private:
	Character* _character;
};

class Rage : public SelfAbility
{
public:
	Rage(Character* character, int cooldown) : SelfAbility(character, cooldown) {};
	
	void UpdateState() 
	{
		_exDamage = _character->GetDamage();
	};

	void Do()
	{
		if (_character->GetHealth() > 10)
		{
			_exDamage = _character->GetDamage();
			_character->SetHealth(_character->GetHealth() - 10);
			_character->SetDamage(_exDamage + _exDamage / 3);
		}
	}

	void Reset()
	{
		_character->SetDamage(_exDamage);
	}
private:
	int _exDamage;
};

class Heal : public MassAbility
{
public:
	Heal(vector<Character*> characters, int cooldown) : MassAbility(characters, cooldown) {};
	
	void Do()
	{
		for (Character* character : _characters)
		{
			if (!character->IsDead())
			{
				if (character->GetHealth() + 20 >= character->GetHealthLimit())
					character->SetHealth(character->GetHealthLimit());
				else
					character->SetHealth(character->GetHealth() + 20);
			}
		}
	}

	void UpdateState() {};

	void Reset() {};
};

class Reinforce : public MassAbility
{
public:
	Reinforce(vector<Character*> characters, int cooldown) : MassAbility(characters, cooldown) {};

	void Do()
	{
		for (Character* character : _characters)
		{
			if (!character->IsDead())
			{
				_exArmor.push_back(character->GetArmor());
				character->SetArmor(character->GetArmor() + 100);
			}
		}
	}

	void UpdateState() {};

	void Reset()
	{
		for (int i = _characters.size() - 1; i >= 0; i--)
		{
			_characters[i]->SetArmor(_exArmor[_exArmor.size()-1]);
			_exArmor.pop_back();
		}
	}
private:
	vector<int> _exArmor;
};

class Empower : public SelfAbility
{
public:
	Empower(Character* character, int cooldown) : SelfAbility(character, cooldown) {};

	void Do()
	{
		_exDamage = _character->GetDamage();
		_character->SetDamage(2*_character->GetDamage());
	}

	void UpdateState()
	{
		_exDamage = _character->GetDamage();
	};

	void Reset()
	{
		_character->SetDamage(_exDamage);
	}
private:
	int _exDamage;
};

class DodgeMaster : public SelfAbility
{
public:
	DodgeMaster(Character* character, int cooldown) : SelfAbility(character, cooldown) {};

	void Do()
	{
		_exDodge = _character->GetDodge();
		_character->SetDodge(100);
	}

	void UpdateState() 
	{
		_exDodge = _character->GetDodge();
	};

	void Reset()
	{
		_character->SetDodge(_exDodge);
	}
private:
	int _exDodge;
};

class Stun : public OnlyKineticAbility
{
public:
	Stun(int cooldown) : OnlyKineticAbility(cooldown) {};

	void SetTarget(Monster* target)
	{
		OnlyKineticAbility::SetTarget(target);
	}

	void UpdateState() {};

	void Do()
	{
		if(_mtarget->IsActive())
			_mtarget->SwitchActivity();
	}

	void Reset()
	{
		if (!_mtarget->IsActive())
			_mtarget->SwitchActivity();
	}
};

class GetOverHere : public OnlyKineticAbility
{
public:
	GetOverHere(int cooldown) : OnlyKineticAbility(cooldown) {};

	void SetTarget(Monster* target)
	{
		OnlyKineticAbility::SetTarget(target);
	}

	void UpdateState() {};

	void Do()
	{
		int dx = 0, dy = 0;
		if (_lookAt.X == 1)
		{
			dx = -2;
		}
		if (_lookAt.X == -1)
		{
			dx = 2;
		}
		if (_lookAt.Y == 1)
		{
			dy = -2;
		}
		if (_lookAt.Y == -1)
		{
			dy = 2;
		}
		_mtarget->SetPosition(_mtarget->GetPosition().X + dx, _mtarget->GetPosition().Y + dy);
	}

	void Reset() {};
};

class GetAway : public OnlyKineticAbility
{
public:
	GetAway(int cooldown, Map* map) : OnlyKineticAbility(cooldown) { _map = map; };

	void SetTarget(Monster* target)
	{
		OnlyKineticAbility::SetTarget(target);
	}

	void UpdateState() {};

	void Do()
	{
		int dx = 0, dy = 0;
		int dx1 = 0, dy1 = 0;
		if (_lookAt.X == 1)
		{
			dx = 2;
			dx1 = 1;
		}
		if (_lookAt.X == -1)
		{
			dx = -2;
			dx1 = -1;
		}
		if (_lookAt.Y == 1)
		{
			dy = 2;
			dy1 = 1;
		}
		if (_lookAt.Y == -1)
		{
			dy = -2;
			dy1 = -1;
		}
		if((_map->GetPattern()[_mtarget->GetPosition().X + dx][_mtarget->GetPosition().Y + dy] != wall) && (_map->GetPattern()[_mtarget->GetPosition().X + dx1][_mtarget->GetPosition().Y + dy1] != wall))
			_mtarget->SetPosition(_mtarget->GetPosition().X + dx, _mtarget->GetPosition().Y + dy);
	}

	void Reset() {};
private:
	Map* _map;
};