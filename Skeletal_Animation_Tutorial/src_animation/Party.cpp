#include "Party.h"

using namespace CourseWork;

<<<<<<< HEAD
Party::Party(PlayableCharacter* character0, PlayableCharacter* character1, PlayableCharacter* character2, PlayableCharacter* character3, Coordinates position)
=======
Party::Party(PlayableCharacter* character0, PlayableCharacter* character1, PlayableCharacter* character2, PlayableCharacter* character3)
>>>>>>> origin/master
{
	_characters[0] = character0;
	_characters[1] = character1;
	_characters[2] = character2;
	_characters[3] = character3;
<<<<<<< HEAD
	_position = position;
}

void Party::SetPosition(int x, int y)
{
	_position.X = x;
	_position.Y = y;
=======
>>>>>>> origin/master
}