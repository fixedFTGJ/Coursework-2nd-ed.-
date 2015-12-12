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
		party = new Party(nullptr, nullptr, nullptr, nullptr, _dungeon->GetMaps()[0]->GetStartPosition());
	};
	void InitMapGraph();
	Dungeon *_dungeon;
	Camera *cam;
	Party *party;
	};
	void InitMapGraph();
	Dungeon *_dungeon;
	
private:
};
