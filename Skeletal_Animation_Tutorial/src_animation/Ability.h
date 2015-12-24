#pragma once

#include "Character.h"
#include <vector>
#include "Monster.h"

using namespace std;
using namespace CourseWork;

class Ability
{
public:
	virtual void Do() = 0;
	virtual void Reset() = 0;
	virtual void SetTarget(Monster* target) { _mtarget = target; };
	virtual void SetTarget(Character* target) { _ctarget = target; };
	virtual void SetLookAt(int x, int y) { _lookAt.X = x; _lookAt.Y = y; };
protected:
	Character* _ctarget;
	Monster* _mtarget;
	Coordinates _lookAt;
};

class OnlyKineticAbility : public Ability
{
public:
	OnlyKineticAbility() : Ability() {
		_mtarget = nullptr;
		_ctarget = nullptr;
	};
	void SetTarget(Monster* target) { Ability::SetTarget(target); };
	void SetTarget(Character* target) { Ability::SetTarget(target); };
};

class TargetAbility : public Ability
{
public:
	TargetAbility()
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
	SelfAbility(Character* character)
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
	MassAbility(vector<Character*> characters)
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
	Provoke(Character* character) : TargetAbility() { _character = character; };
	
	void SetTarget(Character* target)
	{
		TargetAbility::SetTarget(target);
	}

	void Do()
	{
		_ctarget->Attack(_character);
	}

	void Reset() {};
private:
	Character* _character;
};

class Rage : public SelfAbility
{
public:
	Rage(Character* character) : SelfAbility(character) {};
	
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
	Heal(vector<Character*> characters) : MassAbility(characters) {};
	
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

	void Reset() {};
};

class Reinforce : public MassAbility
{
public:
	Reinforce(vector<Character*> characters) : MassAbility(characters) {};

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
	Empower(Character* character) : SelfAbility(character) {};

	void Do()
	{
		_exDamage = _character->GetDamage();
		_character->SetDamage(2*_character->GetDamage());
	}

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
	DodgeMaster(Character* character) : SelfAbility(character) {};

	void Do()
	{
		_exDodge = _character->GetDodge();
		_character->SetDodge(100);
	}

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
	Stun() : OnlyKineticAbility() {};

	void SetTarget(Monster* target)
	{
		OnlyKineticAbility::SetTarget(target);
	}

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
	GetOverHere() : OnlyKineticAbility() {};

	void SetTarget(Monster* target)
	{
		OnlyKineticAbility::SetTarget(target);
	}

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
	GetAway() : OnlyKineticAbility() {};

	void SetTarget(Monster* target)
	{
		OnlyKineticAbility::SetTarget(target);
	}

	void Do()
	{
		int dx = 0, dy = 0;
		if (_lookAt.X == 1)
		{
			dx = 2;
		}
		if (_lookAt.X == -1)
		{
			dx = -2;
		}
		if (_lookAt.Y == 1)
		{
			dy = 2;
		}
		if (_lookAt.Y == -1)
		{
			dy = -2;
		}
		_mtarget->SetPosition(_mtarget->GetPosition().X + dx, _mtarget->GetPosition().Y + dy);
	}

	void Reset() {};
};