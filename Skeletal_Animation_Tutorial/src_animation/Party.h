#pragma once

#include "PlayableCharacter.h"
#include "Environment.h"

namespace CourseWork
{
	class Party
	{
	public:
		Party(PlayableCharacter* character0, PlayableCharacter* character1, PlayableCharacter* character2, PlayableCharacter* character3, Coordinates position);
		Coordinates GetPosition() { return _position; };
		void SetPosition(int x, int y);
	private:
		PlayableCharacter* _characters[4];
		Coordinates _position;
	};
}

