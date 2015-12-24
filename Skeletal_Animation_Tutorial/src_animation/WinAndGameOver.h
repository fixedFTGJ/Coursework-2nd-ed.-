#pragma once

#include <glew.h>
#include <glaux.h>
#include "Texture.h"
#include "2dmod.h"
#include "DrawFigure.h"
#include "Button.h"

using namespace std;

namespace CourseWork {

	class WinLose
	{
	public:
		WinLose() {

			Win = true;
			isVisible = false;

		};

		/////////////////   TEXTURES    /////////////////

		CTexture *Texture;
		TextureImage Textures[10];

		void InitTexture() {
			Texture = new CTexture();
			Texture->LoadTexture(IL_JPG, "source/Win.jpg", &Textures[0]);
			Texture->LoadTexture(IL_JPG, "source/Lose.jpg", &Textures[1]);

			Texture->LoadTexture(IL_PNG, "source/buttons/win/Menu.png", &Textures[2]);
			Texture->LoadTexture(IL_PNG, "source/buttons/win/MenuPr.png", &Textures[3]);

			Texture->LoadTexture(IL_PNG, "source/buttons/win/Exit.png", &Textures[4]);
			Texture->LoadTexture(IL_PNG, "source/buttons/win/ExitPr.png", &Textures[5]);

			Texture->LoadTexture(IL_PNG, "source/buttons/lose/Menu.png", &Textures[6]);
			Texture->LoadTexture(IL_PNG, "source/buttons/lose/MenuPr.png", &Textures[7]);

			Texture->LoadTexture(IL_PNG, "source/buttons/lose/Exit.png", &Textures[8]);
			Texture->LoadTexture(IL_PNG, "source/buttons/lose/ExitPr.png", &Textures[9]);



			WinMenu.GetCoord(410, WWidth - 416, 410 + Textures[2].width, WWidth - 416 + Textures[2].height);
			WinExit.GetCoord(756, WWidth - 416, 756 + Textures[4].width, WWidth - 416 + Textures[4].height);

			LoseMenu.GetCoord(410, WWidth - 470, 410 + Textures[6].width, WWidth - 470 + Textures[6].height);
			LoseExit.GetCoord(756, WWidth - 470, 756 + Textures[8].width, WWidth - 470 + Textures[8].height);
		}

		/////////////////   TEXTURES    /////////////////

		void Draw() {

			glEnable(GL_TEXTURE_2D);
			

			Mode.Begin2D();

			
			if (Win)
			{
				glBindTexture(GL_TEXTURE_2D, Textures[0].texID);
				DrawQuad(xLeft, yDown, xRight, yUp);
				if (!WinMenu.isPressed)
				{
					WinMenu.Draw(Textures[2]);
				}
				else
				{
					WinMenu.Draw(Textures[3]);
				}

				if (!WinExit.isPressed)
				{
					WinExit.Draw(Textures[4]);
				}
				else
				{
					WinExit.Draw(Textures[5]);
				}
			}
			else
			{
				glBindTexture(GL_TEXTURE_2D, Textures[1].texID);
				DrawQuad(xLeft, yDown, xRight, yUp);
				if (!LoseMenu.isPressed)
				{
					LoseMenu.Draw(Textures[6]);
				}
				else
				{
					LoseMenu.Draw(Textures[7]);
				}

				if (!LoseExit.isPressed)
				{
					LoseExit.Draw(Textures[8]);
				}
				else
				{
					LoseExit.Draw(Textures[9]);
				}
			}

			Mode.End2D();
		}


		bool isVisible;
		bool Win;

		Button WinMenu;
		Button WinExit;

		Button LoseMenu;
		Button LoseExit;

	private:
		TwoDMode Mode;

		const double yUp = WWidth;
		const double yDown = 0;
		const double xLeft = 0;
		const double xRight = WHeight;

	};
}


