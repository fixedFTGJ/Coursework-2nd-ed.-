#pragma once

#include "Monster.h"
#include <vector>

using namespace CourseWork;
using namespace std;

class MonsterBehavior
{
public:
	MonsterBehavior(vector<Monster*> monsters) { _monsters = monsters; };
	
	bool Seek();
	void MoveToLocation();
private:
	vector<Monster*> _monsters;
};
