#pragma once

#include "PlayableCharacter.h"
<<<<<<< HEAD
#include "Environment.h"
=======
>>>>>>> origin/master

namespace CourseWork
{
	class Party
	{
	public:
<<<<<<< HEAD
		Party(PlayableCharacter* character0, PlayableCharacter* character1, PlayableCharacter* character2, PlayableCharacter* character3, Coordinates position);
		Coordinates GetPosition() { return _position; };
		void SetPosition(int x, int y);
	private:
		PlayableCharacter* _characters[4];
		Coordinates _position;
=======
		Party(PlayableCharacter* character0, PlayableCharacter* character1, PlayableCharacter* character2, PlayableCharacter* character3);
	private:
		PlayableCharacter* _characters[4];
>>>>>>> origin/master
	};
}

