#pragma once
#include "Map.h"
#include "Monster.h"
#include "Party.h"

using namespace CourseWork;

class CollisionChecker
{
public:
	CollisionChecker() {};
	bool Check(Map* map, Monster* monster);
	bool Check(Map* map, Party* party);
private:
};
