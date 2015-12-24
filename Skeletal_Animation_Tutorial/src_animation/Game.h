#pragma once
#include "DungeonInitializer.h"
#include <glew.h>
#include <wglew.h>
#include <GL/glut.h>
#include "core.h"
#include "camera.h"
#include "Party.h"

using namespace CourseWork;

class Game
{
public:
	Game() 
	{
		DungeonInitializer init;
		_dungeon = init.Initialize();
		_currentMap = 0;
		vector<Ability*> juggernautAbilities;
		vector<Ability*> medicAbilities;
		vector<Ability*> assassinAbilities;
		vector<Ability*> kineticAbilities;
		PlayableCharacter* Juggernaut = new PlayableCharacter(100, 10, 10, 10, 20, 5, 5, 25);
		PlayableCharacter* Medic = new PlayableCharacter(100, 10, 10, 10, 10, 5, 20, 20);
		PlayableCharacter* Assassin = new PlayableCharacter(100, 10, 10, 10, 15, 20, 10, 10);
		PlayableCharacter* Kinetic = new PlayableCharacter(100, 10, 10, 10, 5, 10, 30, 10);
		party = new Party(Juggernaut, Medic, Assassin, Kinetic, _dungeon->GetMaps()[_currentMap]->GetStartPosition());
		juggernautAbilities.push_back(new Rage(Juggernaut, 3));
		juggernautAbilities.push_back(new Provoke(Juggernaut, 5));
		medicAbilities.push_back(new Heal(ToCharacter(party->GetCharacters()),10));
		medicAbilities.push_back(new Reinforce(ToCharacter(party->GetCharacters()), 10));
		assassinAbilities.push_back(new Empower(Assassin, 10));
		assassinAbilities.push_back(new DodgeMaster(Assassin, 10));
		kineticAbilities.push_back(new Stun(10));
		kineticAbilities.push_back(new GetAway(5, _dungeon->GetMaps()[_currentMap]));
		kineticAbilities.push_back(new GetOverHere(5));
		Juggernaut->SetAbilities(juggernautAbilities);
		Medic->SetAbilities(medicAbilities);
		Assassin->SetAbilities(assassinAbilities);
		Kinetic->SetAbilities(kineticAbilities);
	};
	void InitMapGraph();
	void ResetGame()
	{
		DungeonInitializer init;
		_dungeon = init.Initialize();
		_currentMap = 0;
		vector<Ability*> juggernautAbilities;
		vector<Ability*> medicAbilities;
		vector<Ability*> assassinAbilities;
		vector<Ability*> kineticAbilities;
		PlayableCharacter* Juggernaut = new PlayableCharacter(100, 10, 10, 10, 20, 5, 5, 25);
		PlayableCharacter* Medic = new PlayableCharacter(100, 10, 10, 10, 10, 5, 20, 20);
		PlayableCharacter* Assassin = new PlayableCharacter(100, 10, 10, 10, 15, 20, 10, 10);
		PlayableCharacter* Kinetic = new PlayableCharacter(100, 10, 10, 10, 5, 10, 30, 10);
		party = new Party(Juggernaut, Medic, Assassin, Kinetic, _dungeon->GetMaps()[_currentMap]->GetStartPosition());
		juggernautAbilities.push_back(new Rage(Juggernaut, 3));
		juggernautAbilities.push_back(new Provoke(Juggernaut, 5));
		medicAbilities.push_back(new Heal(ToCharacter(party->GetCharacters()), 10));
		medicAbilities.push_back(new Reinforce(ToCharacter(party->GetCharacters()), 10));
		assassinAbilities.push_back(new Empower(Assassin, 10));
		assassinAbilities.push_back(new DodgeMaster(Assassin, 10));
		kineticAbilities.push_back(new Stun(10));
		kineticAbilities.push_back(new GetAway(5, _dungeon->GetMaps()[_currentMap]));
		kineticAbilities.push_back(new GetOverHere(5));
		Juggernaut->SetAbilities(juggernautAbilities);
		Medic->SetAbilities(medicAbilities);
		Assassin->SetAbilities(assassinAbilities);
		Kinetic->SetAbilities(kineticAbilities);
	}
	bool IsOver();
	bool IsNextLevel();
	vector<Character*> ToCharacter(vector<PlayableCharacter*> playableCharacters)
	{
		vector<Character*> temp;
		for (PlayableCharacter* pl : playableCharacters)
		{
			temp.push_back(pl);
		}
		return temp;
	};
	Dungeon *_dungeon;
	Camera *cam;
	Party *party;
	int _currentMap;
};
