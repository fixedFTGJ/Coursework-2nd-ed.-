#pragma once

#include "PlayableCharacter.h"
#include "Environment.h"
#include <vector>

using namespace std;

namespace CourseWork
{
	class Party
	{
	public:
		Party(PlayableCharacter* character0, PlayableCharacter* character1, PlayableCharacter* character2, PlayableCharacter* character3, Coordinates position);
		Coordinates GetPosition() { return _position; };
		vector<PlayableCharacter*> GetCharacters();
		void SetPosition(int x, int y);
	private:
		vector <PlayableCharacter*> _characters;
		Coordinates _position;
	};
}

