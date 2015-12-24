#include "DungeonInitializer.h"

using namespace CourseWork;

DungeonInitializer::DungeonInitializer()
{

};

Dungeon* DungeonInitializer::Initialize()
{
	Map* loadedMap1;
	Map* loadedMap2;
	Map* loadedMap3;
	Map* loadedMap4;
	Map* loadedMap5;
	Monster* monster;
	vector<Map*> maps;
	vector<Monster*> monsters1;
	vector<Monster*> monsters2;
	vector<Monster*> monsters3;
	vector<Monster*> monsters4;
	vector<Monster*> monsters5;
	int** pattern1 = new int*[MapWidth];
	Coordinates startPosition;
	startPosition.X = 1;
	startPosition.Y = 1;
	int** pattern2 = new int*[MapWidth];
	int** pattern3 = new int*[MapWidth];
	int** pattern4 = new int*[MapWidth];
	int** pattern5 = new int*[MapWidth];

	pattern1[0] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};
	pattern1[1] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[2] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[3] = new int[MapWidth] {wall, floor, wall, floor, wall, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[4] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[5] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[6] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[7] = new int[MapWidth] {wall, floor, wall, wall, wall, wall, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[8] = new int[MapWidth] {wall, floor, wall, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[9] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[10] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[11] = new int[MapWidth] {wall, floor, floor, wall, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[12] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[13] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[14] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[15] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[16] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[17] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[18] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern1[19] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};

	pattern2[0] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};
	pattern2[1] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[2] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[3] = new int[MapWidth] {wall, floor, wall, floor, wall, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[4] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[5] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[6] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[7] = new int[MapWidth] {wall, floor, wall, wall, wall, wall, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[8] = new int[MapWidth] {wall, floor, wall, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[9] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[10] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[11] = new int[MapWidth] {wall, floor, wall, wall, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[12] = new int[MapWidth] {wall, floor, floor, wall, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[13] = new int[MapWidth] {wall, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[14] = new int[MapWidth] {wall, floor, floor, wall, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[15] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[16] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[17] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[18] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern2[19] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};

	pattern3[0] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};
	pattern3[1] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[2] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[3] = new int[MapWidth] {wall, floor, wall, floor, wall, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[4] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[5] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[6] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[7] = new int[MapWidth] {wall, floor, wall, wall, wall, wall, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[8] = new int[MapWidth] {wall, floor, wall, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[9] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[10] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[11] = new int[MapWidth] {wall, floor, floor, wall, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[12] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[13] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[14] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[15] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[16] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[17] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[18] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern3[19] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};

	pattern4[0] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};
	pattern4[1] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[2] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[3] = new int[MapWidth] {wall, floor, wall, floor, wall, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[4] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[5] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[6] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[7] = new int[MapWidth] {wall, floor, wall, wall, wall, wall, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[8] = new int[MapWidth] {wall, floor, wall, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[9] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[10] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[11] = new int[MapWidth] {wall, floor, floor, wall, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[12] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[13] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[14] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[15] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[16] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[17] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[18] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern4[19] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};

	pattern5[0] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};
	pattern5[1] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[2] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[3] = new int[MapWidth] {wall, floor, wall, floor, wall, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[4] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[5] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[6] = new int[MapWidth] {wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[7] = new int[MapWidth] {wall, floor, wall, wall, wall, wall, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[8] = new int[MapWidth] {wall, floor, wall, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[9] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[10] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[11] = new int[MapWidth] {wall, floor, floor, wall, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[12] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[13] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[14] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[15] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[16] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[17] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[18] = new int[MapWidth] {wall, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, floor, wall};
	pattern5[19] = new int[MapWidth] {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall};
	
	monster = new Monster(Coordinates(5, 5), 200, 10, 30, 15);
	monsters1.push_back(monster);
	monster = new Monster(Coordinates(10, 10), 200, 10, 30, 15);
	monsters1.push_back(monster);
	monster = new Monster(Coordinates(7, 9), 200, 10, 30, 15);
	monsters1.push_back(monster);
	monster = new Monster(Coordinates(11, 18), 200, 10, 30, 15);
	monsters1.push_back(monster);

	monster = new Monster(Coordinates(5, 5), 200, 10, 30, 15);
	monsters2.push_back(monster);
	monster = new Monster(Coordinates(10, 10), 200, 10, 30, 15);
	monsters2.push_back(monster);
	monster = new Monster(Coordinates(7, 9), 200, 10, 30, 15);
	monsters2.push_back(monster);
	monster = new Monster(Coordinates(11, 18), 200, 10, 30, 15);
	monsters2.push_back(monster);

	monster = new Monster(Coordinates(5, 5), 200, 10, 30, 15);
	monsters3.push_back(monster);
	monster = new Monster(Coordinates(10, 10), 200, 10, 30, 15);
	monsters3.push_back(monster);
	monster = new Monster(Coordinates(7, 9), 200, 10, 30, 15);
	monsters3.push_back(monster);
	monster = new Monster(Coordinates(11, 18), 200, 10, 30, 15);
	monsters3.push_back(monster);

	monster = new Monster(Coordinates(5, 5), 200, 10, 30, 15);
	monsters4.push_back(monster);
	monster = new Monster(Coordinates(10, 10), 200, 10, 30, 15);
	monsters4.push_back(monster);
	monster = new Monster(Coordinates(7, 9), 200, 10, 30, 15);
	monsters4.push_back(monster);
	monster = new Monster(Coordinates(11, 18), 200, 10, 30, 15);
	monsters4.push_back(monster);

	monster = new Monster(Coordinates(5, 5), 200, 10, 30, 15);
	monsters5.push_back(monster);
	monster = new Monster(Coordinates(10, 10), 200, 10, 30, 15);
	monsters5.push_back(monster);
	monster = new Monster(Coordinates(7, 9), 200, 10, 30, 15);
	monsters5.push_back(monster);
	monster = new Monster(Coordinates(11, 18), 200, 10, 30, 15);
	monsters5.push_back(monster);

	loadedMap1 = new Map(MapHeight, MapWidth, pattern1, monsters1, startPosition);
	loadedMap2 = new Map(MapHeight, MapWidth, pattern2, monsters2, startPosition);
	loadedMap3 = new Map(MapHeight, MapWidth, pattern3, monsters3, startPosition);
	loadedMap4 = new Map(MapHeight, MapWidth, pattern4, monsters4, startPosition);
	loadedMap5 = new Map(MapHeight, MapWidth, pattern5, monsters5, startPosition);

	maps.push_back(loadedMap1);
	maps.push_back(loadedMap2);
	maps.push_back(loadedMap3);
	maps.push_back(loadedMap4);
	maps.push_back(loadedMap5);

	return new Dungeon(maps);
};