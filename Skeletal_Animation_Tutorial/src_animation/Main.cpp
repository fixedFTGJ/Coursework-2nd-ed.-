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
vec4f lightvec(-1,0,-1,0);
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

int WHight = 1280;
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

POINT mCursor;

BottomMenu BtmM = BottomMenu();

MainMenu MM = MainMenu();

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

void DrawScene()
{
	if ( GetAsyncKeyState(VK_ESCAPE) )  exit(0);
	// mouse pointer position
	POINT cursor;
	GetCursorPos(&cursor); 

	// camera orientation
	float	viewangle_x = float(cursor.x-1280/2)/4.0;
	float	viewangle_y = float(cursor.y-768/2)/4.0;

	static uint t0=timeGetTime(); 
	double time_elapsed=double(timeGetTime()-t0)/1000;

	// clear and basic
	glClearDepth(1);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	 //projection
	int vp[4];
	glMatrixMode( GL_PROJECTION);
	glLoadIdentity();
	glGetIntegerv(GL_VIEWPORT, vp);
	gluPerspective(55.0,float(vp[2])/float(vp[3]) , 0.01, 100);

	// modelview
	/*glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
	glRotatef( viewangle_y,1,0,0);		// set rotation
	glRotatef( viewangle_x,0,1,0);		// set rotation
	glTranslatef(x, y, z);*/
	if (f)
	{
		//PlaySound("recycle.wav", NULL, SND_FILENAME);
		g_game.cam = new Camera(g_game._dungeon->GetMaps()[0]->GetStartPosition().X*1.0 + 1.0, 0, g_game._dungeon->GetMaps()[0]->GetStartPosition().Y*1.0 + 1.0);
		g_game.cam->rotateLoc(90, 0, 1, 0);


		//g_game.cam->setView();
		f = !f;
	}

	//cam.setView();
	//cam.rotateLoc(180, 0, 1, 0);
	//cam.setView();
	// select level of detail for rendering
	// (lods are generated automatically by the ogre xml converter )
	int lod=0; 
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

	for(Monster* m : monsters)
	{ 
		monster.Draw(
			vec3f(m->GetPosition().X*g_game._dungeon->GetMaps()[0]->GetStep() + 1.0, -0.5, m->GetPosition().Y*g_game._dungeon->GetMaps()[0]->GetStep() + 1.0),
			vec3f(
				0,			// rotation
				m->GetRotation(),
				0)
			);
	}

	/*halo.Draw(
		vec3f(10, -0.5, 10),			// position
		vec3f(0, 0, 0),	// rotation
		0,							// LOD level
		0);*/
	
	if (BtmM.isVisible)
	{
		BtmM.Draw();
	}
	if (MM.isVisible)
	{
		MM.Draw();
	}

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

	static Mesh moon   ("../data/moon/moon.material",	//	required material file)
						"../data/moon/moon.mesh.xml");	//	required mesh file
		moon.Draw(
			vec3f( 5, 5, 19),		  		// position
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
	glutSwapBuffers();
}
void Timer(int value)
{
	vector<Monster*> monsters = g_game._dungeon->GetMaps()[0]->GetMonsters();
	int *px, *py;
	int len;
	for (Monster* m : monsters)
	{
		if ((m->GetPosition().X != g_game.party->GetPosition().X) || (m->GetPosition().Y != g_game.party->GetPosition().Y))
		{
			if (finder.lee(m->GetPosition().X, m->GetPosition().Y, g_game.party->GetPosition().X, g_game.party->GetPosition().Y, px, py, len))
			{
				/*for (int i = 0; i < len; i++)
				{
					cout << px[i] << " " << py[i] << endl;
				}*/
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
	/*for (Monster* m : monsters)
	{
		finder.lee(m->GetPosition().X, m->GetPosition().Y, g_game.party->GetPosition().X, g_game.party->GetPosition().Y);
		for (int i = 0; i < finder.len; i++)
		{
			cout << finder.px[0] << " " << finder.py[0] << endl;
		}
		m->SetPosition(finder.px[0], finder.py[0]);
	}*/
	glutPostRedisplay();
	glutTimerFunc(1000, Timer, 1);
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

	if (key == GLUT_KEY_UP)
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
			throughMonster = throughMonster || checker.Check(g_game.party, m);
		cout << g_game.party->GetPosition().X << " " << g_game.party->GetPosition().Y << " " << dx << " " << dy << endl;
		if (!checker.Check(g_game._dungeon->GetMaps()[0], g_game.party) && (!throughMonster))
		{
			g_game.cam->moveGlob(normal.x, normal.y, normal.z, -1.0);

			BtmM.Forward();
			MM.Forward();
		}
		else
		{
			g_game.party->SetPosition(temp.X, temp.Y);
		}
	}
	
	if (key == GLUT_KEY_DOWN)
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

		cout << g_game.party->GetPosition().X << " " << g_game.party->GetPosition().Y << " " << dx << " " << dy << endl;
		if (!checker.Check(g_game._dungeon->GetMaps()[0], g_game.party) && (!throughMonster))
		{
			g_game.cam->moveGlob(normal.x, normal.y, normal.z);

			BtmM.Back();
			MM.Back();
		}
		else
		{
			g_game.party->SetPosition(temp.X, temp.Y);
		}
	}
	if (key == GLUT_KEY_LEFT)
	{
		g_game.cam->rotateLoc(-90, 0, 1, 0);

		BtmM.TurnLeft();
		MM.TurnLeft();
	}
	if (key == GLUT_KEY_RIGHT)
	{
		g_game.cam->rotateLoc(90, 0, 1, 0);

		BtmM.TurnRight();
		MM.TurnRight();
	}
	if(key == GLUT_KEY_PAGE_UP)
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

	
	// Обновляется окно
	glutPostRedisplay();
};

class CVector3
{
public:
	CVector3() {
		x = 0;
		y = 0;
		z = 0;
	}
	CVector3(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}
	float x, y, z;
};

CVector3 t1;
CVector3 t2;

void calc_select_line(int mouse_x, int mouse_y, CVector3& p1, CVector3& p2)
{
	// mouse_x, mouse_y  - оконные координаты курсора мыши.
	// p1, p2            - возвращаемые параметры - концы селектирующего отрезка,
	//                     лежащие соответственно на ближней и дальней плоскостях
	//                     отсечения.
	GLint    viewport[4];    // параметры viewport-a.
	GLdouble projection[16]; // матрица проекции.
	GLdouble modelview[16];  // видовая матрица.
	GLdouble vx, vy, vz;       // координаты курсора мыши в системе координат viewport-a.
	GLdouble wx, wy, wz;       // возвращаемые мировые координаты.

	glGetIntegerv(GL_VIEWPORT, viewport);           // узнаём параметры viewport-a.
	glGetDoublev(GL_PROJECTION_MATRIX, projection); // узнаём матрицу проекции.
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);   // узнаём видовую матрицу.
													// переводим оконные координаты курсора в систему координат viewport-a.
	vx = mouse_x;
	vy = WHight - mouse_y - 1; // где height - текущая высота окна.

							   // вычисляем ближний конец селектирующего отрезка.
	vz = -1;
	gluUnProject(vx, vy, vz, modelview, projection, viewport, &wx, &wy, &wz);
	p1 = CVector3(wx, wy, wz);
	// вычисляем дальний конец селектирующего отрезка.
	vz = 1;
	gluUnProject(vx, vy, vz, modelview, projection, viewport, &wx, &wy, &wz);
	p2 = CVector3(wx, wy, wz);
}

void OtherKeys(unsigned char key, int x, int y)
{
	if (key == 'w') {
		yInterf += 0.001f;
		cout << "y = " << yInterf << endl;
	}
	if (key == 'a') {
		xInterf -= 0.001f;
		cout << "x = " << xInterf << endl;
	}
	if (key == 's') {
		yInterf -= 0.001f;
		cout << "y = " << yInterf << endl;
	}
	if (key == 'd') {
		xInterf += 0.001f;
		cout << "x = " << xInterf << endl;
	}
	if (key == 'q') {
		PlaySound("../data/sounds/fight_ambient.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	if (key == 'm')
	{
		PlaySound(NULL, NULL, SND_ASYNC);
	}
	if (key == 'z') {

		GetCursorPos(&mCursor);
		cout << mCursor.x << endl;
		cout << mCursor.y << endl;
		calc_select_line(mCursor.x, mCursor.y, t1, t2);
		cout << "X1 = " << t1.x << "Y1 = " << t1.y << "Z1 = " << t1.z << endl;
		cout << "X2 = " << t2.x << "Y2 = " << t2.y << "Z2 = " << t2.z << endl;
	}


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
		//PlaySound("D:\\materials.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
}
///////////////////////////////////////////
int main(int argc, char **argv) 
{ 
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE /*| GLUT_ALPHA */| GLUT_DEPTH);  
  glutInitWindowSize(WHight, WWidth);
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

  glutDisplayFunc(DrawScene);
  glutTimerFunc(1000, Timer, 1);
  glutIdleFunc(DrawScene);
  glewInit();
  wglSwapIntervalEXT(0);
  glutMainLoop();  
  return 0;
}
///////////////////////////////////////////
