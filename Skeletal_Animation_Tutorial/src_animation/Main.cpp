#include <iostream> 
#include <vector> 
#include <string> 
#include <stdio.h>
#include <glew.h>
#include <wglew.h>
#include <windows.h>
#include <mmsystem.h>
#include <GL/glut.h>

using namespace std;
#pragma comment(lib,"winmm.lib")
///////////////////////////////////////////
#include "core.h"
#include "Bmp.h"
#include "ogl.h"
#include "glsl.h"
///////////////////////////////////////////
vec4f lightvec(-1, 0, -1, 0);
#include "Mesh.h"
///////////////////////////////////////////
#include "Game.h"
#include "camera.h"
#include "CollisionChecker.h"
#include "PathFinder.h"
//////////////////////////////////////////
Game g_game;
CollisionChecker checker;
PathFinder finder(g_game._dungeon->GetMaps()[0]);
bool f = true;
float x = 0;
float y = -5;
float z = 0;
bool isMute = false;

int WHeight = 1280;
int WWidth = 768;

/////////////////////////////////////////
vec3f GetLookAt()
{
	float model_view_matrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, model_view_matrix);
	vec3f normal(model_view_matrix[2], model_view_matrix[6], model_view_matrix[10]);
	return normal.norm();
};

#include "GameMenus.h"
//////////////////////////////////////////
float xInterf = 0.0f;
float yInterf = 0.0f;
float zInterf = 0.0f;


BottomMenu BtmM = BottomMenu();

MainMenu MM = MainMenu();
WinLose WL = WinLose();

float angle = 0.0;
float lx = 0.0f, lz = -1.0f;
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

////////////////////////////////////////
void Clear()
{
	// clear and basic
	glClearDepth(1);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// projection
	int vp[4];
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glGetIntegerv(GL_VIEWPORT, vp);
	gluPerspective(90.0, float(vp[2]) / float(vp[3]), 0.01, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
};

Monster* GetMonsterByPosition(int x, int y)
{
	vector<Monster*> monsters = g_game._dungeon->GetMaps()[0]->GetMonsters();
	for (Monster* m : monsters)
	{
		if ((m->GetPosition().X == x) && (m->GetPosition().Y == y) && (!m->IsDead()))
			return m;
	}
	return nullptr;
};

void Begin2D(void)
{
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, WWidth, 0, WHeight);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void End2D(void)
{
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}

void DrawQuad(float x, float y, float w, float h, uint texture)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	y = (float)WHeight - y - h;
	glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2f(0.0f, 0.0f);    glVertex2f(x, y);
	glTexCoord2f(1.0f, 0.0f);    glVertex2f(x + w, y);
	glTexCoord2f(0.0f, 1.0f);    glVertex2f(x, y + h);
	glTexCoord2f(1.0f, 1.0f);    glVertex2f(x + w, y + h);
	glEnd();
}

void DrawScene()
{
	if (GetAsyncKeyState(VK_ESCAPE))  exit(0);
	// mouse pointer position
	POINT cursor;
	GetCursorPos(&cursor);

	// camera orientation
	float	viewangle_x = float(cursor.x - 1280 / 2) / 4.0;
	float	viewangle_y = float(cursor.y - 768 / 2) / 4.0;

	static uint t0 = timeGetTime();
	double time_elapsed = double(timeGetTime() - t0) / 1000;

	// clear and basic
	glClearDepth(1);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//projection
	int vp[4];
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glGetIntegerv(GL_VIEWPORT, vp);
	gluPerspective(55.0, float(vp[2]) / float(vp[3]), 0.01, 100);

	// modelview
	/*	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
	glRotatef( viewangle_y,1,0,0);		// set rotation
	glRotatef( viewangle_x,0,1,0);	*/	// set rotation
	//	glTranslatef(x, y, z);
	if (f)
	{
		//PlaySound("recycle.wav", NULL, SND_FILENAME);
		g_game.cam = new Camera(g_game._dungeon->GetMaps()[0]->GetStartPosition().X*1.0 + 1.0, 0, g_game._dungeon->GetMaps()[0]->GetStartPosition().Y*1.0 + 1.0);
		g_game.cam->rotateLoc(90, 0, 1, 0);


		//g_game.cam->setView();
		f = !f;
	}
	vector<PlayableCharacter*> party = g_game.party->GetCharacters();
	BtmM.GetNumeralsN1(party[0]->GetHealth() / 100, party[0]->GetHealth() % 100 / 10, party[0]->GetHealth() % 100 % 10);
	BtmM.GetNumeralsN2(party[1]->GetHealth() / 100, party[1]->GetHealth() % 100 / 10, party[1]->GetHealth() % 100 % 10);
	BtmM.GetNumeralsN3(party[2]->GetHealth() / 100, party[2]->GetHealth() % 100 / 10, party[2]->GetHealth() % 100 % 10);
	BtmM.GetNumeralsN4(party[3]->GetHealth() / 100, party[3]->GetHealth() % 100 / 10, party[3]->GetHealth() % 100 % 10);

	//cam.setView();
	//cam.rotateLoc(180, 0, 1, 0);
	//cam.setView();
	// select level of detail for rendering
	// (lods are generated automatically by the ogre xml converter )
	int lod = 0;
	/*if(GetAsyncKeyState(VK_F1)) lod=1;
	if(GetAsyncKeyState(VK_F2)) lod=2;
	if(GetAsyncKeyState(VK_F3)) lod=3;
	if(GetAsyncKeyState(VK_F4)) lod=4;
	if(GetAsyncKeyState(VK_F5)) lod=5;*/
	/*if (GetAsyncKeyState(VK_UP))
	{
	cam.rotateLoc(180, 0, 1, 0);
	cam.setView();
	}*/
	g_game.cam->setView();
	static Mesh cube("../data/cube.material", "../data/cube.xml");
	static Mesh plane("../data/Untitled1.material", "../data/Untitled1.xml");
	static Mesh monster("../data/SW Storm trooper.material", "../data/SW Storm trooper.mesh.xml");
	/*static Mesh halo("../data/desktop.material",		//	required material file)
	"../data/Desktop.mesh.xml");*/
	vector<Monster*> monsters = g_game._dungeon->GetMaps()[0]->GetMonsters();
	//////////////////////
	loopi(0, g_game._dungeon->GetMaps()[0]->GetHeight())
	{
		loopj(0, g_game._dungeon->GetMaps()[0]->GetWidth())
		{
			if (g_game._dungeon->GetMaps()[0]->GetPattern()[i][j] == wall)
			{
				cube.Draw(
					vec3f(i*g_game._dungeon->GetMaps()[0]->GetStep() + 1.0, 0, j*g_game._dungeon->GetMaps()[0]->GetStep() + 1.0),		  		// position
					vec3f(
						0,			// rotation
						0,
						0)
					// LOD level
					);
			}
			else
			{
				plane.Draw(
					vec3f(i*g_game._dungeon->GetMaps()[0]->GetStep() + 1.0, -0.5, j*g_game._dungeon->GetMaps()[0]->GetStep() + 1.0),		  		// position
					vec3f(
						0,			// rotation
						0,
						0)
					// LOD level
					);
			}
		}
	}

	for (Monster* m : monsters)
	{
		if (!m->IsDead())
		{
			monster.Draw(
				vec3f(m->GetPosition().X*g_game._dungeon->GetMaps()[0]->GetStep() + 1.0, -0.5, m->GetPosition().Y*g_game._dungeon->GetMaps()[0]->GetStep() + 1.0),
				vec3f(
					0,			// rotation
					m->GetRotation(),
					0)
				);
		}
	}

	/*halo.Draw(
	vec3f(10, -0.5, 10),			// position
	vec3f(0, 0, 0),	// rotation
	0,							// LOD level
	0);*/



	/////////////////////
	/*cube.Draw(
	vec3f(1.1, -0, -1),		  		// position
	vec3f(
	0,			// rotation
	0,
	0),
	lod								// LOD level
	);

	plane.Draw(
	vec3f(0.1, -0, -1),		  		// position
	vec3f(
	0,			// rotation
	0,
	0),
	lod								// LOD level
	);*/
	// Test 1 : Halo character (animated mesh)

	/*static Mesh halo   ("../data/halo/halo.material",		//	required material file)
	"../data/halo/halo.mesh.xml",		//	required mesh file
	"../data/halo/halo.skeleton.xml");	//	optional skeleton file

	loopi(0,4)
	{
	// Set the skeleton to an animation at a given time

	//int idle = halo.animation.GetAnimationIndexOf("idle"); // <- in case we dont know the animation id
	halo.animation.SetPose(
	i/2,			// animation id (2 animations, 0 and 1, are available)
	time_elapsed );	// time in seconds

	// F6 : example to manually set the shoulder - for shooting a weapon e.g.
	if(GetAsyncKeyState(VK_F6))
	{
	// get the index
	int index  = halo.animation.GetBoneIndexOf("joint2");

	// get / modify / set the matrix
	matrix44 m = halo.animation.bones[ index ].matrix;
	m.x_component()=vec3f(1,0,0);
	m.y_component()=vec3f(0,1,0); // set the rotation to identity
	m.z_component()=vec3f(0,0,1);
	halo.animation.bones[ index ].matrix=m;

	// re-evaluate the childs
	loopi(0,halo.animation.bones[ index ].childs.size())
	{
	halo.animation.EvalSubtree(
	halo.animation.bones[ index ].childs[i],	// bone id
	halo.animation.animations[0],				// animation
	-1);										// key frame -1 means not use the animation
	}
	}

	// Draw the model

	halo.Draw(
	vec3f((i-1.5)*7,-5,7),			// position
	vec3f(0,time_elapsed*0.3,0),	// rotation
	lod,							// LOD level
	(i&1)==1 );						// draw skeleton ?
	}*/

	// Test 2 : moon (static mesh)

	static Mesh moon("../data/moon/moon.material",	//	required material file)
		"../data/moon/moon.mesh.xml");	//	required mesh file
	moon.Draw(
		vec3f(5, 5, 19),		  		// position
		vec3f(
			time_elapsed*0.1,			// rotation
			time_elapsed*0.1,
			time_elapsed*0.4),
		lod								// LOD level
		);

	// Swap
	/*static Mesh moon("../data/moon/moon.material",	//	required material file)
	"../data/moon/moon.mesh.xml");	//	required mesh file
	moon.Draw(
	vec3f(1.1, -0, -1),		  		// position
	vec3f(
	time_elapsed*0.2,			// rotation
	time_elapsed*0.1,
	time_elapsed*0.4),
	lod								// LOD level
	);*/

	/*Begin2D();
	DrawQuad(0.0f, 0.0f, 400.0f, 768.0f, 4);
	End2D();*/

	if (BtmM.isVisible)
	{
		BtmM.Draw();
	}
	if (MM.isVisible)
	{
		MM.Draw();
	}
	if (WL.isVisible)
	{
		WL.Draw();
	}

	glutSwapBuffers();
};

void Timer(int value)
{
	if (MM.isVisible)
	{
		glutTimerFunc(1000, Timer, 1);
	}
	else
	{
		vector<Monster*> monsters = g_game._dungeon->GetMaps()[0]->GetMonsters();
		vector<PlayableCharacter*> party = g_game.party->GetCharacters();
		int *px, *py;
		int len;
		int characterIndex;
		bool underAttack = false;
		for (Monster* m : monsters)
		{
			if (((m->GetPosition().X != g_game.party->GetPosition().X) || (m->GetPosition().Y != g_game.party->GetPosition().Y)) && !(m->IsDead()))
			{
				if (finder.lee(m->GetPosition().X, m->GetPosition().Y, g_game.party->GetPosition().X, g_game.party->GetPosition().Y, px, py, len))
				{
					if ((len < 9) && (!m->IsActive()))
						m->SwitchActivity();

					if ((len == 1) && (m->IsActive()))
					{
						while (!underAttack)
						{
							characterIndex = rand() % 4;
							if (!party[characterIndex]->IsDead())
							{
								m->Attack(party[characterIndex]);
								underAttack = !underAttack;
							}
						}
					}

					if (m->IsActive())
					{
						if (px[1] - m->GetPosition().X == 1)
							m->SetOrientation(1, 0);
						if (px[1] - m->GetPosition().X == -1)
							m->SetOrientation(-1, 0);
						if (py[1] - m->GetPosition().Y == 1)
							m->SetOrientation(0, 1);
						if (py[1] - m->GetPosition().Y == -1)
							m->SetOrientation(0, -1);
						if (((px[1] != g_game.party->GetPosition().X) || (py[1] != g_game.party->GetPosition().Y)))
							m->SetPosition(px[1], py[1]);
					}
				}
			}
		}
		for (PlayableCharacter* pl : party)
		{
			if (!pl->IsDead())
			{
				pl->Regenerate();
				if (!pl->CanAttack())
				{
					pl->ReduceCooldown();
				}
				loopi(0, 2)
				{
					if(!pl->_abilities[i]->CanBeUsed())
						pl->_abilities[i]->ReduceCooldown();
				}
			}
		}

		if (!g_game.party->CanMove())
			g_game.party->SwitchAbilityToMove();

		if (g_game.IsOver())
			exit(0);
		glutPostRedisplay();
		glutTimerFunc(1000, Timer, 1);
	}
}

void SpecialKeys(int key, int x, int y)
{
	/*vec3f normal = GetLookAt();
	int dx = 0, dy = 0;
	if (normal.x == 1.0)
	dx = -1;
	if (normal.x == -1.0)
	dx = 1;
	if (normal.y == 1.0)
	dy = -1;
	if (normal.y == -1.0)
	dy = 1;

	Coordinates temp = g_game.party->GetPosition();
	g_game.party->SetPosition(temp.X + dx, temp.Y + dy);

	cout << g_game.party->GetPosition().X << " " << g_game.party->GetPosition().Y << " " << dx << " " << dy << endl;*/
	if (MM.isVisible)
		return;

	if (key == GLUT_KEY_UP)
	{
		if (g_game.party->CanMove())
		{
			vec3f normal = GetLookAt();
			int dx = 0, dy = 0;
			if (normal.x == 1.0)
				dx = -1;
			if (normal.x == -1.0)
				dx = 1;
			if (normal.z == 1.0)
				dy = -1;
			if (normal.z == -1.0)
				dy = 1;
			bool throughMonster = false;
			Coordinates temp = g_game.party->GetPosition();
			g_game.party->SetPosition(temp.X + dx, temp.Y + dy);
			vector<Monster*> monsters = g_game._dungeon->GetMaps()[0]->GetMonsters();
			for (Monster* m : monsters)
				throughMonster = throughMonster || (checker.Check(g_game.party, m) && (!m->IsDead()));
			if (!checker.Check(g_game._dungeon->GetMaps()[0], g_game.party) && (!throughMonster))
			{
				g_game.cam->moveGlob(normal.x, normal.y, normal.z, -1.0);
				g_game.party->SwitchAbilityToMove();
			}
			else
			{
				g_game.party->SetPosition(temp.X, temp.Y);
			}
		}
	}

	if (key == GLUT_KEY_DOWN)
	{
		if (g_game.party->CanMove())
		{
			vec3f normal = GetLookAt();
			int dx = 0, dy = 0;
			if (normal.x == 1.0)
				dx = 1;
			if (normal.x == -1.0)
				dx = -1;
			if (normal.z == 1.0)
				dy = 1;
			if (normal.z == -1.0)
				dy = -1;

			bool throughMonster = false;
			Coordinates temp = g_game.party->GetPosition();
			g_game.party->SetPosition(temp.X + dx, temp.Y + dy);
			vector<Monster*> monsters = g_game._dungeon->GetMaps()[0]->GetMonsters();
			for (Monster* m : monsters)
				throughMonster = throughMonster || checker.Check(g_game.party, m);

			if (!checker.Check(g_game._dungeon->GetMaps()[0], g_game.party) && (!throughMonster))
			{
				g_game.cam->moveGlob(normal.x, normal.y, normal.z);
				g_game.party->SwitchAbilityToMove();
			}
			else
			{
				g_game.party->SetPosition(temp.X, temp.Y);
			}
		}
	}
	if (key == GLUT_KEY_LEFT)
	{
		g_game.cam->rotateLoc(-90, 0, 1, 0);

	}
	if (key == GLUT_KEY_RIGHT)
	{
		g_game.cam->rotateLoc(90, 0, 1, 0);

	}
	if (key == GLUT_KEY_PAGE_UP)
		g_game.cam->rotateLoc(-90, 1, 0, 0);
	if (key == GLUT_KEY_PAGE_DOWN)
		g_game.cam->rotateLoc(90, 1, 0, 0);

	if (key == GLUT_KEY_F1) {
		if (BtmM.isVisible)
		{

			BtmM.isVisible = false;
		}
		else
		{
			BtmM.isVisible = true;
		}
	}

	if (key == GLUT_KEY_F2) {
		if (MM.isVisible)
		{
			MM.isVisible = false;
		}
		else
		{
			MM.isVisible = true;
		}
	}

	if (key == GLUT_KEY_F3) {
		WL.Win = true;
		if (WL.isVisible)
		{
			WL.isVisible = false;
		}
		else
		{
			WL.isVisible = true;
		}
	}

	if (key == GLUT_KEY_F4) {
		WL.Win = false;
		if (WL.isVisible)
		{
			WL.isVisible = false;
		}
		else
		{
			WL.isVisible = true;
		}
	}


	// Обновляется окно
	glutPostRedisplay();
};

void OtherKeys(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		yInterf += 0.001f;
		cout << "y = " << yInterf << endl;
	}
	if (key == 'a')
	{
		xInterf -= 0.001f;
		cout << "x = " << xInterf << endl;
	}
	if (key == 's')
	{
		yInterf -= 0.001f;
		cout << "y = " << yInterf << endl;
	}
	if (key == 'd')
	{
		xInterf += 0.001f;
		cout << "x = " << xInterf << endl;
	}
	if (key == 'q')
	{
		PlaySound("../data/sounds/fight_ambient.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	if (key == 'm')
	{
		PlaySound(NULL, NULL, SND_ASYNC);
	}
	if (key == 'z')
	{
		cout << MM.Textures[2].width << endl;
		cout << MM.Textures[2].height << endl;
	}

	if (key == 'c')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		if (normal.x == 1.0)
			dx = -1;
		if (normal.x == -1.0)
			dx = 1;
		if (normal.z == 1.0)
			dy = -1;
		if (normal.z == -1.0)
			dy = 1;
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[0]->IsDead()) && (m != nullptr) && (!m->IsDead()) && (g_game.party->GetCharacters()[0]->CanAttack()))
		{
			g_game.party->GetCharacters()[0]->Attack(m);
			g_game.party->GetCharacters()[0]->SetCurrentAttackCooldown();
			if (m->IsDead())
			{
				if ((!g_game.party->GetCharacters()[0]->IsDead()))
					g_game.party->GetCharacters()[0]->GainExp(m->exp);
				if ((!g_game.party->GetCharacters()[1]->IsDead()))
					g_game.party->GetCharacters()[1]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[2]->IsDead()))
					g_game.party->GetCharacters()[2]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[3]->IsDead()))
					g_game.party->GetCharacters()[3]->GainExp(m->exp / 2);

				if ((g_game.party->GetCharacters()[0]->IsLevelUp()) && (!g_game.party->GetCharacters()[0]->IsDead()))
				{
					g_game.party->GetCharacters()[0]->LevelUp(5, 1, 1, 10);
				}
				if ((g_game.party->GetCharacters()[1]->IsLevelUp()) && (!g_game.party->GetCharacters()[1]->IsDead()))
				{
					g_game.party->GetCharacters()[1]->LevelUp(5, 1, 10, 1);
				}
				if ((g_game.party->GetCharacters()[2]->IsLevelUp()) && (!g_game.party->GetCharacters()[2]->IsDead()))
				{
					g_game.party->GetCharacters()[2]->LevelUp(5, 10, 1, 1);
				}
				if ((g_game.party->GetCharacters()[3]->IsLevelUp()) && (!g_game.party->GetCharacters()[3]->IsDead()))
				{
					g_game.party->GetCharacters()[3]->LevelUp(1, 5, 10, 1);
				}
			}
		}
	}

	if (key == 'v')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		if (normal.x == 1.0)
			dx = -1;
		if (normal.x == -1.0)
			dx = 1;
		if (normal.z == 1.0)
			dy = -1;
		if (normal.z == -1.0)
			dy = 1;
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[1]->IsDead()) && (m != nullptr) && (g_game.party->GetCharacters()[1]->CanAttack()))
		{
			g_game.party->GetCharacters()[1]->Attack(m);
			g_game.party->GetCharacters()[1]->SetCurrentAttackCooldown();
			if (m->IsDead())
			{
				if ((!g_game.party->GetCharacters()[0]->IsDead()))
					g_game.party->GetCharacters()[0]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[1]->IsDead()))
					g_game.party->GetCharacters()[1]->GainExp(m->exp);
				if ((!g_game.party->GetCharacters()[2]->IsDead()))
					g_game.party->GetCharacters()[2]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[3]->IsDead()))
					g_game.party->GetCharacters()[3]->GainExp(m->exp / 2);

				if ((g_game.party->GetCharacters()[0]->IsLevelUp()) && (!g_game.party->GetCharacters()[0]->IsDead()))
				{
					g_game.party->GetCharacters()[0]->LevelUp(5, 1, 1, 10);
				}
				if ((g_game.party->GetCharacters()[1]->IsLevelUp()) && (!g_game.party->GetCharacters()[1]->IsDead()))
				{
					g_game.party->GetCharacters()[1]->LevelUp(5, 1, 10, 1);
				}
				if ((g_game.party->GetCharacters()[2]->IsLevelUp()) && (!g_game.party->GetCharacters()[2]->IsDead()))
				{
					g_game.party->GetCharacters()[2]->LevelUp(5, 10, 1, 1);
				}
				if ((g_game.party->GetCharacters()[3]->IsLevelUp()) && (!g_game.party->GetCharacters()[3]->IsDead()))
				{
					g_game.party->GetCharacters()[3]->LevelUp(1, 5, 10, 1);
				}
			}
		}
	}

	if (key == 'b')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		if (normal.x == 1.0)
			dx = -1;
		if (normal.x == -1.0)
			dx = 1;
		if (normal.z == 1.0)
			dy = -1;
		if (normal.z == -1.0)
			dy = 1;
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[2]->IsDead()) && (m != nullptr) && (g_game.party->GetCharacters()[2]->CanAttack()))
		{
			g_game.party->GetCharacters()[2]->Attack(m);
			g_game.party->GetCharacters()[2]->SetCurrentAttackCooldown();
			if (m->IsDead())
			{
				if ((!g_game.party->GetCharacters()[0]->IsDead()))
					g_game.party->GetCharacters()[0]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[1]->IsDead()))
					g_game.party->GetCharacters()[1]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[2]->IsDead()))
					g_game.party->GetCharacters()[2]->GainExp(m->exp);
				if ((!g_game.party->GetCharacters()[3]->IsDead()))
					g_game.party->GetCharacters()[3]->GainExp(m->exp / 2);

				if ((g_game.party->GetCharacters()[0]->IsLevelUp()) && (!g_game.party->GetCharacters()[0]->IsDead()))
				{
					g_game.party->GetCharacters()[0]->LevelUp(5, 1, 1, 10);
				}
				if ((g_game.party->GetCharacters()[1]->IsLevelUp()) && (!g_game.party->GetCharacters()[1]->IsDead()))
				{
					g_game.party->GetCharacters()[1]->LevelUp(5, 1, 10, 1);
				}
				if ((g_game.party->GetCharacters()[2]->IsLevelUp()) && (!g_game.party->GetCharacters()[2]->IsDead()))
				{
					g_game.party->GetCharacters()[2]->LevelUp(5, 10, 1, 1);
				}
				if ((g_game.party->GetCharacters()[3]->IsLevelUp()) && (!g_game.party->GetCharacters()[3]->IsDead()))
				{
					g_game.party->GetCharacters()[3]->LevelUp(1, 5, 10, 1);
				}
			}
		}
	}

	if (key == 'n')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		if (normal.x == 1.0)
			dx = -1;
		if (normal.x == -1.0)
			dx = 1;
		if (normal.z == 1.0)
			dy = -1;
		if (normal.z == -1.0)
			dy = 1;
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[3]->IsDead()) && (m != nullptr) && (g_game.party->GetCharacters()[3]->CanAttack()))
		{
			g_game.party->GetCharacters()[3]->Attack(m);
			g_game.party->GetCharacters()[3]->SetCurrentAttackCooldown();
			if (m->IsDead())
			{
				if ((!g_game.party->GetCharacters()[0]->IsDead()))
					g_game.party->GetCharacters()[0]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[1]->IsDead()))
					g_game.party->GetCharacters()[1]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[2]->IsDead()))
					g_game.party->GetCharacters()[2]->GainExp(m->exp / 2);
				if ((!g_game.party->GetCharacters()[3]->IsDead()))
					g_game.party->GetCharacters()[3]->GainExp(m->exp);

				if ((g_game.party->GetCharacters()[0]->IsLevelUp()) && (!g_game.party->GetCharacters()[0]->IsDead()))
				{
					g_game.party->GetCharacters()[0]->LevelUp(5, 1, 1, 10);
				}
				if ((g_game.party->GetCharacters()[1]->IsLevelUp()) && (!g_game.party->GetCharacters()[1]->IsDead()))
				{
					g_game.party->GetCharacters()[1]->LevelUp(5, 1, 10, 1);
				}
				if ((g_game.party->GetCharacters()[2]->IsLevelUp()) && (!g_game.party->GetCharacters()[2]->IsDead()))
				{
					g_game.party->GetCharacters()[2]->LevelUp(5, 10, 1, 1);
				}
				if ((g_game.party->GetCharacters()[3]->IsLevelUp()) && (!g_game.party->GetCharacters()[3]->IsDead()))
				{
					g_game.party->GetCharacters()[3]->LevelUp(1, 5, 10, 1);
				}
			}
		}
	}

	if (key == 'f')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		if (normal.x == 1.0)
			dx = -1;
		if (normal.x == -1.0)
			dx = 1;
		if (normal.z == 1.0)
			dy = -1;
		if (normal.z == -1.0)
			dy = 1;
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[0]->IsDead()) && (m != nullptr) && (g_game.party->GetCharacters()[0]->_abilities[0]->CanBeUsed()))
		{
			g_game.party->GetCharacters()[0]->_abilities[0]->SetTarget(m);
			g_game.party->GetCharacters()[0]->_abilities[0]->Do();
			g_game.party->GetCharacters()[0]->_abilities[0]->SetCurrentCooldown();
			g_game.party->GetCharacters()[0]->_abilities[0]->Reset();
		}
	}

	if (key == 'r')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		if (normal.x == 1.0)
			dx = -1;
		if (normal.x == -1.0)
			dx = 1;
		if (normal.z == 1.0)
			dy = -1;
		if (normal.z == -1.0)
			dy = 1;
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[0]->IsDead()) && (m != nullptr) && (g_game.party->GetCharacters()[0]->_abilities[1]->CanBeUsed()))
		{
			g_game.party->GetCharacters()[0]->_abilities[1]->SetTarget((Character*)m);
			g_game.party->GetCharacters()[0]->_abilities[1]->Do();
			g_game.party->GetCharacters()[0]->_abilities[1]->SetCurrentCooldown();

		}
	}

	if (key == 'g')
	{
		if ((!g_game.party->GetCharacters()[1]->IsDead()) && (g_game.party->GetCharacters()[1]->_abilities[0]->CanBeUsed()))
		{
			g_game.party->GetCharacters()[1]->_abilities[0]->Do();
			g_game.party->GetCharacters()[1]->_abilities[0]->SetCurrentCooldown();
		}

	}

	if (key == 't')
	{
		if ((!g_game.party->GetCharacters()[1]->IsDead()) && (g_game.party->GetCharacters()[1]->_abilities[1]->CanBeUsed()))
		{
			g_game.party->GetCharacters()[1]->_abilities[1]->Do();
			g_game.party->GetCharacters()[1]->_abilities[1]->SetCurrentCooldown();
			g_game.party->GetCharacters()[1]->_abilities[1]->Reset();
		}
	}

	if (key == 'h')
	{
		if ((!g_game.party->GetCharacters()[2]->IsDead()) && (g_game.party->GetCharacters()[2]->_abilities[0]->CanBeUsed()))
		{
			g_game.party->GetCharacters()[2]->_abilities[0]->Do();
			g_game.party->GetCharacters()[2]->_abilities[0]->SetCurrentCooldown();
			g_game.party->GetCharacters()[2]->_abilities[0]->Reset();
		}
	}

	if (key == 'y')
	{
		if ((!g_game.party->GetCharacters()[2]->IsDead()) && (g_game.party->GetCharacters()[2]->_abilities[1]->CanBeUsed()))
		{
			g_game.party->GetCharacters()[2]->_abilities[1]->Do();
			g_game.party->GetCharacters()[2]->_abilities[1]->SetCurrentCooldown();
			g_game.party->GetCharacters()[2]->_abilities[1]->Reset();
		}
	}

	if (key == 'j')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		if (normal.x == 1.0)
			dx = -1;
		if (normal.x == -1.0)
			dx = 1;
		if (normal.z == 1.0)
			dy = -1;
		if (normal.z == -1.0)
			dy = 1;
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[3]->IsDead()) && (m != nullptr) && (g_game.party->GetCharacters()[3]->_abilities[0]->CanBeUsed()))
		{
			g_game.party->GetCharacters()[3]->_abilities[0]->SetTarget(m);
			g_game.party->GetCharacters()[3]->_abilities[0]->Do();
			g_game.party->GetCharacters()[3]->_abilities[0]->SetCurrentCooldown();
			g_game.party->GetCharacters()[3]->_abilities[0]->Reset();
		}
	}

	if (key == 'u')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		if (normal.x == 1.0)
			dx = -1;
		if (normal.x == -1.0)
			dx = 1;
		if (normal.z == 1.0)
			dy = -1;
		if (normal.z == -1.0)
			dy = 1;
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[3]->IsDead()) && (m != nullptr) && (g_game.party->GetCharacters()[3]->_abilities[1]->CanBeUsed()))
		{
			g_game.party->GetCharacters()[3]->_abilities[1]->SetTarget(m);
			g_game.party->GetCharacters()[3]->_abilities[1]->SetLookAt(dx, dy);
			g_game.party->GetCharacters()[3]->_abilities[1]->Do();
			g_game.party->GetCharacters()[3]->_abilities[1]->SetCurrentCooldown();
			g_game.party->GetCharacters()[3]->_abilities[1]->Reset();
		}
	}

	/*if (key == 'i')
	{
		vec3f normal = GetLookAt();
		int dx = 0, dy = 0;
		int dx1 = 0, dy1 = 0;
		if (normal.x == 1.0)
		{
			dx = -2;
			dx1 = -1;
		}
		if (normal.x == -1.0)
		{
			dx = 2;
			dx1 = 1;
		}
		if (normal.z == 1.0)
		{
			dy = -2;
			dy1 = -1;
		}
		if (normal.z == -1.0)
		{
			dy = 2;
			dy1 = 1;
		}
		Monster* m = GetMonsterByPosition(g_game.party->GetPosition().X + dx, g_game.party->GetPosition().Y + dy);
		if ((!g_game.party->GetCharacters()[3]->IsDead()) && (m != nullptr))
		{
			g_game.party->GetCharacters()[3]->_abilities[2]->SetTarget(m);
			g_game.party->GetCharacters()[3]->_abilities[1]->SetLookAt(dx1, dy1);
			g_game.party->GetCharacters()[3]->_abilities[2]->Do();
			g_game.party->GetCharacters()[3]->_abilities[2]->Reset();
		}
	}*/
	// Обновляется окно
	glutPostRedisplay();
}

void mouseMove(int x, int y) {

	if (xOrigin >= 0) {

		deltaAngle = (x - xOrigin) * 0.001f;

		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (MM.isVisible)
		{
			if (MM.NewGame.Press(x, y))
			{
				if (state == GLUT_DOWN)
				{
					MM.NewGame.isPressed = true;
				}
				else
				{
					MM.NewGame.isPressed = false;
					MM.isVisible = false;
					BtmM.isVisible = true;
					BtmM.Power.isPressed = false;
				}
			}
			else
			{
				if (state == GLUT_UP)
				{
					MM.NewGame.isPressed = false;
				}
			}

			if (MM.Continue.Press(x, y))
			{
				if (state == GLUT_DOWN)
				{
					MM.Continue.isPressed = true;
				}
				else
				{
					MM.Continue.isPressed = false;
					MM.isVisible = false;
				}
			}
			else
			{
				if (state == GLUT_UP)
				{
					MM.Continue.isPressed = false;
				}
			}

			if (MM.Options.Press(x, y))
			{
				if (state == GLUT_DOWN)
				{
					MM.Options.isPressed = true;
				}
				else
				{
					MM.Options.isPressed = false;
				}
			}
			else
			{
				if (state == GLUT_UP)
				{
					MM.Options.isPressed = false;
				}
			}

			if (MM.Exit.Press(x, y))
			{
				if (state == GLUT_DOWN)
				{
					MM.Exit.isPressed = true;
				}
				else
				{
					MM.Exit.isPressed = false;
					exit(0);
				}
			}
			else
			{
				if (state == GLUT_UP)
				{
					MM.Exit.isPressed = false;
				}
			}
		}
		else
		{
			if (BtmM.isVisible == true)
			{
				if (BtmM.Power.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Power.isPressed = true;
					}
					else
					{
						BtmM.Power.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Power.isPressed = false;
					}
				}

				if (BtmM.Provocation.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Provocation.isPressed = true;
					}
					else
					{
						BtmM.Provocation.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Provocation.isPressed = false;
					}
				}

				if (BtmM.Heal.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Heal.isPressed = true;
					}
					else
					{
						BtmM.Heal.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Heal.isPressed = false;
					}
				}

				if (BtmM.Buff.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Buff.isPressed = true;
					}
					else
					{
						BtmM.Buff.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Buff.isPressed = false;
					}
				}

				if (BtmM.Backstab.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Backstab.isPressed = true;
					}
					else
					{
						BtmM.Backstab.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Backstab.isPressed = false;
					}
				}

				if (BtmM.Evasion.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Evasion.isPressed = true;
					}
					else
					{
						BtmM.Evasion.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Evasion.isPressed = false;
					}
				}

				if (BtmM.Stun.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Stun.isPressed = true;
					}
					else
					{
						BtmM.Stun.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Stun.isPressed = false;
					}
				}

				if (BtmM.Push.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Push.isPressed = true;
					}
					else
					{
						BtmM.Push.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Push.isPressed = false;
					}
				}

				if (BtmM.MainMenu.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.MainMenu.isPressed = true;
					}
					else
					{
						BtmM.MainMenu.isPressed = false;
						MM.isVisible = true;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.MainMenu.isPressed = false;
					}
				}

				if (BtmM.Jug.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Jug.isPressed = true;
					}
					else
					{
						BtmM.Jug.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Jug.isPressed = false;
					}
				}

				if (BtmM.Med.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Med.isPressed = true;
					}
					else
					{
						BtmM.Med.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Med.isPressed = false;
					}
				}

				if (BtmM.Ass.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Ass.isPressed = true;
					}
					else
					{
						BtmM.Ass.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Ass.isPressed = false;
					}
				}

				if (BtmM.Kin.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						BtmM.Kin.isPressed = true;
					}
					else
					{
						BtmM.Kin.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						BtmM.Kin.isPressed = false;
					}
				}
			}

			if (WL.isVisible == true)
			{
				if (WL.WinMenu.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						WL.WinMenu.isPressed = true;
					}
					else
					{
						WL.WinMenu.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						WL.WinMenu.isPressed = false;
					}
				}

				if (WL.WinExit.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						WL.WinExit.isPressed = true;
					}
					else
					{
						WL.WinExit.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						WL.WinExit.isPressed = false;
					}
				}

				if (WL.LoseMenu.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						WL.LoseMenu.isPressed = true;
					}
					else
					{
						WL.LoseMenu.isPressed = false;
					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						WL.LoseMenu.isPressed = false;
					}
				}

				if (WL.LoseExit.Press(x, y))
				{
					if (state == GLUT_DOWN)
					{
						WL.LoseExit.isPressed = true;
					}
					else
					{
						WL.LoseExit.isPressed = false;

					}
				}
				else
				{
					if (state == GLUT_UP)
					{
						WL.LoseExit.isPressed = false;
					}
				}
			}

			

		}
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		cout << x << endl;
		cout << y << endl;
	}
}
///////////////////////////////////////////
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE /*| GLUT_ALPHA */ | GLUT_DEPTH);
	glutInitWindowSize(WHeight, WWidth);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Dungeon of Hope");

	// cam.setView();
	// Clear();
	// cam.setView();
	// Clear();
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(OtherKeys);

	BtmM.InitTexture();
	MM.InitTexture();
	WL.InitTexture();

	glutDisplayFunc(DrawScene);
	glutTimerFunc(1000, Timer, 1);
	glutIdleFunc(DrawScene);
	glewInit();
	wglSwapIntervalEXT(0);
	glutMainLoop();
	return 0;
}
///////////////////////////////////////////
