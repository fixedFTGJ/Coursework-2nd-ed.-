#include "Party.h"

using namespace CourseWork;

Party::Party(PlayableCharacter* character0, PlayableCharacter* character1, PlayableCharacter* character2, PlayableCharacter* character3, Coordinates position)
{
	_characters.push_back(character0);
	_characters.push_back(character1);
	_characters.push_back(character2);
	_characters.push_back(character3);
	_position = position;
	_canMove = true;
}

vector<PlayableCharacter*> CourseWork::Party::GetCharacters()
{
	return _characters;
}

void Party::SetPosition(int x, int y)
{
	_position.X = x;
	_position.Y = y;
}