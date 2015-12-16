#include "CollisionChecker.h"

bool CollisionChecker::Check(Map * map, Monster * monster)
{
	return(map->GetPattern()[monster->GetPosition().X][monster->GetPosition().Y] == wall);
}

bool CollisionChecker::Check(Map * map, Party * party)
{
	return(map->GetPattern()[party->GetPosition().X][party->GetPosition().Y] == wall);
}

bool CollisionChecker::Check(Party * party, Monster * monster)
{
	return ((party->GetPosition().X == monster->GetPosition().X) && (party->GetPosition().Y == monster->GetPosition().Y));
}
