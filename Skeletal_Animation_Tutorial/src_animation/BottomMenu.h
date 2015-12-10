#pragma once

#include "InterfaceCoords.h"
#include <glew.h>

using namespace std;

namespace CourseWork {


	class BottomMenu
	{
	public:
		BottomMenu() {
			Menu.FrontRightUp.CoordsGive(0.167f, -0.03f, -0.1f);
			Menu.FrontLeftUp.CoordsGive(-0.167f, -0.03f, -0.1f);
			Menu.FrontLeftDown.CoordsGive(-0.167f, -0.1f, -0.1f);
			Menu.FrontRightDown.CoordsGive(0.167f, -0.1f, -0.1f);

			Menu.LeftRightUp.CoordsGive(-0.1f, -0.03f, 0.167f);
			Menu.LeftLeftUp.CoordsGive(-0.1f, -0.03f, -0.167f);
			Menu.LeftLeftDown.CoordsGive(-0.1f, -0.1f, -0.167f);
			Menu.LeftRightDown.CoordsGive(-0.1f, -0.1f, 0.167f);

			Menu.BackRightUp.CoordsGive(0.167f, -0.03f, 0.1f);
			Menu.BackLeftUp.CoordsGive(-0.167f, -0.03f, 0.1f);
			Menu.BackLeftDown.CoordsGive(-0.167f, -0.1f, 0.1f);
			Menu.BackRightDown.CoordsGive(0.167f, -0.1f, 0.1f);

			Menu.RightRightUp.CoordsGive(0.1f, -0.03f, 0.167f);
			Menu.RightLeftUp.CoordsGive(0.1f, -0.03f, -0.167f);
			Menu.RightLeftDown.CoordsGive(0.1f, -0.1f, -0.167f);
			Menu.RightRightDown.CoordsGive(0.1f, -0.1f, 0.167f);

			Position = 'f';
		};

		void Draw() {
			switch (Position)
			{
			case 'f':
				glBegin(GL_QUADS);
				glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
				glVertex3f(Menu.FrontRightUp.X(), Menu.FrontRightUp.Y(), Menu.FrontRightUp.Z());
				glVertex3f(Menu.FrontLeftUp.X(), Menu.FrontLeftUp.Y(), Menu.FrontLeftUp.Z());
				glVertex3f(Menu.FrontLeftDown.X(), Menu.FrontLeftDown.Y(), Menu.FrontLeftDown.Z());
				glVertex3f(Menu.FrontRightDown.X(), Menu.FrontRightDown.Y(), Menu.FrontRightDown.Z());
				glEnd();
				break;
			case 'l':
				glBegin(GL_QUADS);
				glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
				glVertex3f(Menu.LeftRightUp.X(), Menu.LeftRightUp.Y(), Menu.LeftRightUp.Z());
				glVertex3f(Menu.LeftRightDown.X(), Menu.LeftRightDown.Y(), Menu.LeftRightDown.Z());
				glVertex3f(Menu.LeftLeftDown.X(), Menu.LeftLeftDown.Y(), Menu.LeftLeftDown.Z());
				glVertex3f(Menu.LeftLeftUp.X(), Menu.LeftLeftUp.Y(), Menu.LeftLeftUp.Z());		
				glEnd();
				break;
			case 'b':
				glBegin(GL_QUADS);
				glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
				glVertex3f(Menu.BackRightUp.X(), Menu.BackRightUp.Y(), Menu.BackRightUp.Z());
				glVertex3f(Menu.BackRightDown.X(), Menu.BackRightDown.Y(), Menu.BackRightDown.Z());
				glVertex3f(Menu.BackLeftDown.X(), Menu.BackLeftDown.Y(), Menu.BackLeftDown.Z());
				glVertex3f(Menu.BackLeftUp.X(), Menu.BackLeftUp.Y(), Menu.BackLeftUp.Z());
				glEnd();
				break;
			case 'r':
				glBegin(GL_QUADS);
				glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
				glVertex3f(Menu.RightRightUp.X(), Menu.RightRightUp.Y(), Menu.RightRightUp.Z());
				glVertex3f(Menu.RightLeftUp.X(), Menu.RightLeftUp.Y(), Menu.RightLeftUp.Z());
				glVertex3f(Menu.RightLeftDown.X(), Menu.RightLeftDown.Y(), Menu.RightLeftDown.Z());
				glVertex3f(Menu.RightRightDown.X(), Menu.RightRightDown.Y(), Menu.RightRightDown.Z());
				glEnd();
				break;

			default:
				break;
			}

			
		}

		void Forvard() {

			switch (Position)
			{
			case 'f':
				MoveZ(-1.0f);
				break;
			case 'l':
				MoveX(-1.0f);
				break;
			case 'b':
				MoveZ(1.0f);
				break;
			case 'r':
				MoveX(1.0f);
				break;

			default:
				break;
			}
			
		}

		void Ago() {
			switch (Position)
			{
			case 'f':
				MoveZ(1.0f);
				break;
			case 'l':
				MoveX(1.0f);
				break;
			case 'b':
				MoveZ(-1.0f);
				break;
			case 'r':
				MoveX(-1.0f);
				break;

			default:
				break;
			}			
		}

		void TurnRight() {
			switch (Position)
			{
			case 'f':
				Position = 'r';
				break;
			case 'l':
				Position = 'f';
				break;
			case 'b':
				Position = 'l';
				break;
			case 'r':
				Position = 'b';
				break;

			default:
				break;
			}
		}

		void TurnLeft() {
			switch (Position)
			{
			case 'f':
				Position = 'l';
				break;
			case 'l':
				Position = 'b';
				break;
			case 'b':
				Position = 'r';
				break;
			case 'r':
				Position = 'f';
				break;

			default:
				break;
			}
		}

		void MoveZ(float _x) {
			Menu.FrontRightUp.AddZ(_x);
			Menu.FrontLeftUp.AddZ(_x);
			Menu.FrontLeftDown.AddZ(_x);
			Menu.FrontRightDown.AddZ(_x);

			Menu.LeftRightUp.AddZ(_x);
			Menu.LeftLeftUp.AddZ(_x);
			Menu.LeftLeftDown.AddZ(_x);
			Menu.LeftRightDown.AddZ(_x);

			Menu.BackRightUp.AddZ(_x);
			Menu.BackLeftUp.AddZ(_x);
			Menu.BackLeftDown.AddZ(_x);
			Menu.BackRightDown.AddZ(_x);

			Menu.RightRightUp.AddZ(_x);
			Menu.RightLeftUp.AddZ(_x);
			Menu.RightLeftDown.AddZ(_x);
			Menu.RightRightDown.AddZ(_x);
		}

		void MoveX(float _x) {
			Menu.FrontRightUp.AddX(_x);
			Menu.FrontLeftUp.AddX(_x);
			Menu.FrontLeftDown.AddX(_x);
			Menu.FrontRightDown.AddX(_x);

			Menu.LeftRightUp.AddX(_x);
			Menu.LeftLeftUp.AddX(_x);
			Menu.LeftLeftDown.AddX(_x);
			Menu.LeftRightDown.AddX(_x);

			Menu.BackRightUp.AddX(_x);
			Menu.BackLeftUp.AddX(_x);
			Menu.BackLeftDown.AddX(_x);
			Menu.BackRightDown.AddX(_x);

			Menu.RightRightUp.AddX(_x);
			Menu.RightLeftUp.AddX(_x);
			Menu.RightLeftDown.AddX(_x);
			Menu.RightRightDown.AddX(_x);
		}


	private:
		InterfaceCoords Menu;
		
		char Position;

	};
}


