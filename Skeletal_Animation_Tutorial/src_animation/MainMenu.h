#pragma once

#include "InterfaceCoords.h"
#include <glew.h>
#include <glaux.h>
#include "Texture.h"

using namespace std;

namespace CourseWork {


	class MainMenu
	{
	public:
		MainMenu() {
			Menu.FrontRightUp.CoordsGive(0.087f + 2.0f, 0.052f, -0.1f + 2.0f);
			Menu.FrontLeftUp.CoordsGive(-0.087f + 2.0f, 0.052f, -0.1f + 2.0f);
			Menu.FrontLeftDown.CoordsGive(-0.087f + 2.0f, -0.052f, -0.1f + 2.0f);
			Menu.FrontRightDown.CoordsGive(0.087f + 2.0f, -0.052f, -0.1f + 2.0f);

			Menu.LeftRightUp.CoordsGive(-0.1f + 2.0f, 0.052f, 0.087f + 2.0f);
			Menu.LeftLeftUp.CoordsGive(-0.1f + 2.0f, 0.052f, -0.087f + 2.0f);
			Menu.LeftLeftDown.CoordsGive(-0.1f + 2.0f, -0.052f, -0.087f + 2.0f);
			Menu.LeftRightDown.CoordsGive(-0.1f + 2.0f, -0.052f, 0.087f + 2.0f);

			Menu.BackRightUp.CoordsGive(0.087f + 2.0f, 0.052f, 0.1f + 2.0f);
			Menu.BackLeftUp.CoordsGive(-0.087f + 2.0f, 0.052f, 0.1f + 2.0f);
			Menu.BackLeftDown.CoordsGive(-0.087f + 2.0f, -0.052f, 0.1f + 2.0f);
			Menu.BackRightDown.CoordsGive(0.087f + 2.0f, -0.052f, 0.1f + 2.0f);

			Menu.RightRightUp.CoordsGive(0.1f + 2.0f, 0.052f, 0.087f + 2.0f);
			Menu.RightLeftUp.CoordsGive(0.1f + 2.0f, 0.052f, -0.087f + 2.0f);
			Menu.RightLeftDown.CoordsGive(0.1f + 2.0f, -0.052f, -0.087f + 2.0f);
			Menu.RightRightDown.CoordsGive(0.1f + 2.0f, -0.052f, 0.087f + 2.0f);

			Position = 'r';

			isVisible = false;

		};

		/////////////////   TEXTURES    /////////////////

		CTexture *Texture;
		TextureImage Textures[2];

		void InitTexture() {
			Texture = new CTexture();
			Texture->LoadTexture(IL_JPG, "source/MainMenu.jpg", &Textures[0]);
			Texture->LoadTexture(IL_JPG, "source/MainMenu2.jpg", &Textures[1]);
		}
		/////////////////   TEXTURES    /////////////////

		void Draw() {

			glEnable(GL_TEXTURE_2D);

			switch (Position)
			{
			case 'f':
				glBindTexture(GL_TEXTURE_2D, Textures[0].texID);
				glBegin(GL_QUADS);
				glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte)255);
				glTexCoord2f(1, 0);
				glVertex3f(Menu.FrontRightUp.X(), Menu.FrontRightUp.Y(), Menu.FrontRightUp.Z());
				glTexCoord2f(0, 0);
				glVertex3f(Menu.FrontLeftUp.X(), Menu.FrontLeftUp.Y(), Menu.FrontLeftUp.Z());
				glTexCoord2f(0, 1);
				glVertex3f(Menu.FrontLeftDown.X(), Menu.FrontLeftDown.Y(), Menu.FrontLeftDown.Z());
				glTexCoord2f(1, 1);
				glVertex3f(Menu.FrontRightDown.X(), Menu.FrontRightDown.Y(), Menu.FrontRightDown.Z());
				glEnd();
				break;
			case 'l':
				glBindTexture(GL_TEXTURE_2D, Textures[1].texID);
				glBegin(GL_QUADS);
				glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte)255);
				glTexCoord2f(1, 0);
				glVertex3f(Menu.LeftRightUp.X(), Menu.LeftRightUp.Y(), Menu.LeftRightUp.Z());
				glTexCoord2f(1, 1);
				glVertex3f(Menu.LeftRightDown.X(), Menu.LeftRightDown.Y(), Menu.LeftRightDown.Z());
				glTexCoord2f(0, 1);
				glVertex3f(Menu.LeftLeftDown.X(), Menu.LeftLeftDown.Y(), Menu.LeftLeftDown.Z());
				glTexCoord2f(0, 0);
				glVertex3f(Menu.LeftLeftUp.X(), Menu.LeftLeftUp.Y(), Menu.LeftLeftUp.Z());
				glEnd();
				break;
			case 'b':
				glBindTexture(GL_TEXTURE_2D, Textures[1].texID);
				glBegin(GL_QUADS);
				glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte)255);
				glTexCoord2f(1, 0);
				glVertex3f(Menu.BackRightUp.X(), Menu.BackRightUp.Y(), Menu.BackRightUp.Z());
				glTexCoord2f(1, 1);
				glVertex3f(Menu.BackRightDown.X(), Menu.BackRightDown.Y(), Menu.BackRightDown.Z());
				glTexCoord2f(0, 1);
				glVertex3f(Menu.BackLeftDown.X(), Menu.BackLeftDown.Y(), Menu.BackLeftDown.Z());
				glTexCoord2f(0, 0);
				glVertex3f(Menu.BackLeftUp.X(), Menu.BackLeftUp.Y(), Menu.BackLeftUp.Z());
				glEnd();
				break;
			case 'r':
				glBindTexture(GL_TEXTURE_2D, Textures[0].texID);
				glBegin(GL_QUADS);
				glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte)255);
				glTexCoord2f(1, 0);
				glVertex3f(Menu.RightRightUp.X(), Menu.RightRightUp.Y(), Menu.RightRightUp.Z());
				glTexCoord2f(0, 0);
				glVertex3f(Menu.RightLeftUp.X(), Menu.RightLeftUp.Y(), Menu.RightLeftUp.Z());
				glTexCoord2f(0, 1);
				glVertex3f(Menu.RightLeftDown.X(), Menu.RightLeftDown.Y(), Menu.RightLeftDown.Z());
				glTexCoord2f(1, 1);
				glVertex3f(Menu.RightRightDown.X(), Menu.RightRightDown.Y(), Menu.RightRightDown.Z());
				glEnd();
				break;

			default:
				break;
			}
		}

		void Forward() {

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

		void Back() {
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

		bool isVisible;

		/////////////////   TEXTURES    /////////////////

		GLuint texture[1];

		GLvoid LoadGLTextures() {
			AUX_RGBImageRec *texture1;
			texture1 = auxDIBImageLoad("D:\\Menu.bmp");

			glGenTextures(1, &texture[0]);
			glBindTexture(GL_TEXTURE_2D, texture[0]);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);

			glEnable(GL_TEXTURE_2D);
		}

		void takeYUP() {
			Menu.FrontRightUp.AddY(0.001f);
			Menu.FrontRightDown.AddY(0.001f);
			Menu.FrontLeftUp.AddY(0.001f);
			Menu.FrontLeftDown.AddY(0.001f);
			cout << Menu.FrontRightUp.Y();
		}

		void takeYDown() {
			Menu.FrontRightUp.AddY(-0.001f);
			Menu.FrontRightDown.AddY(-0.001f);
			Menu.FrontLeftUp.AddY(-0.001f);
			Menu.FrontLeftDown.AddY(-0.001f);
			cout << Menu.FrontRightUp.Y();
		}

	private:
		InterfaceCoords Menu;


		char Position;

	};
}


