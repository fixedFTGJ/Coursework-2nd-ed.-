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
		vector<Ability*> juggernautAbilities;
		vector<Ability*> medicAbilities;
		vector<Ability*> assassinAbilities;
		vector<Ability*> kineticAbilities;
		PlayableCharacter* Juggernaut = new PlayableCharacter(100, 10, 10, 10, 20, 5, 5, 25);
		PlayableCharacter* Medic = new PlayableCharacter(100, 10, 10, 10, 10, 5, 20, 20);
		PlayableCharacter* Assassin = new PlayableCharacter(100, 10, 10, 10, 15, 20, 10, 10);
		PlayableCharacter* Kinetic = new PlayableCharacter(100, 10, 10, 10, 5, 10, 30, 10);
		party = new Party(Juggernaut, Medic, Assassin, Kinetic, _dungeon->GetMaps()[0]->GetStartPosition());
		juggernautAbilities.push_back(new Rage(Juggernaut));
		juggernautAbilities.push_back(new Provoke(Juggernaut));
		medicAbilities.push_back(new Heal(ToCharacter(party->GetCharacters())));
		medicAbilities.push_back(new Reinforce(ToCharacter(party->GetCharacters())));
		assassinAbilities.push_back(new Empower(Assassin));
		assassinAbilities.push_back(new DodgeMaster(Assassin));
		kineticAbilities.push_back(new Stun());
		kineticAbilities.push_back(new GetAway());
		kineticAbilities.push_back(new GetOverHere());
		Juggernaut->SetAbilities(juggernautAbilities);
		Medic->SetAbilities(medicAbilities);
		Assassin->SetAbilities(assassinAbilities);
		Kinetic->SetAbilities(kineticAbilities);
	};
	void InitMapGraph();
	bool IsOver();
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
};
