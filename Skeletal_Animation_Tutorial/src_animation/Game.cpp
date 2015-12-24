#include "Game.h"

void Game::InitMapGraph()
{

	loopi(0, _dungeon->GetMaps()[0]->GetHeight())
	{
		loopj(0, _dungeon->GetMaps()[0]->GetHeight())
		{
			
		}
	}
}

bool Game::IsOver()
{
	vector<PlayableCharacter*> characters = party->GetCharacters();
	return ((characters[0]->IsDead()) && (characters[1]->IsDead()) && (characters[2]->IsDead()) && (characters[3]->IsDead()));
}

bool Game::IsNextLevel()
{
	bool isNextLevel = true;
	vector<Monster*> monsters = _dungeon->GetMaps()[_currentMap]->GetMonsters();
	for (Monster* m : monsters)
	{
		isNextLevel = (isNextLevel) && (m->IsDead());
	}
	return isNextLevel;
}
