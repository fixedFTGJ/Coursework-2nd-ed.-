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
		PlayableCharacter* Juggernaut = new PlayableCharacter(100, 10, 10, 10, 20, 5, 5, 25);
		PlayableCharacter* Medic = new PlayableCharacter(100, 10, 10, 10, 10, 5, 20, 20);
		PlayableCharacter* Assassin = new PlayableCharacter(100, 10, 10, 10, 15, 20, 10, 10);
		PlayableCharacter* Kinetic = new PlayableCharacter(100, 10, 10, 10, 5, 10, 30, 10);
		party = new Party(Juggernaut, Medic, Assassin, Kinetic, _dungeon->GetMaps()[0]->GetStartPosition());
	};
	void InitMapGraph();
	bool IsOver();
	Dungeon *_dungeon;
	Camera *cam;
	Party *party;
};
