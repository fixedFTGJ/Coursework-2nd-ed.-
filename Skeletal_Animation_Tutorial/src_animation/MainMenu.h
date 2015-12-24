#pragma once

#include <glew.h>
#include <glaux.h>
#include "Texture.h"
#include "2dmod.h"
#include "DrawFigure.h"
#include "Button.h"

using namespace std;

namespace CourseWork {

	class MainMenu
	{
	public:
		MainMenu() {

			isVisible = true;

		};

		/////////////////   TEXTURES    /////////////////

		CTexture *Texture;
		TextureImage Textures[9];

		void InitTexture() {
			Texture = new CTexture();
			Texture->LoadTexture(IL_JPG, "source/MainMenu.jpg", &Textures[0]);

			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/new.png", &Textures[1]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/newPr.png", &Textures[2]);

			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/cont.png", &Textures[3]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/contPr.png", &Textures[4]);

			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/help.png", &Textures[5]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/helpPr.png", &Textures[6]);

			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/ex.png", &Textures[7]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/exPr.png", &Textures[8]);

			NewGame.GetCoord(93, 523, 93 + Textures[1].width, 523 + Textures[1].height);
			Continue.GetCoord(93, 433, 93 + Textures[3].width, 433 + Textures[3].height);
			Options.GetCoord(93, 343, 93 + Textures[5].width, 343 + Textures[5].height);
			Exit.GetCoord(93, 253, 93 + Textures[7].width, 253 + Textures[7].height);

			NewGame.GetCoord(93, 523, 93 + Textures[1].width, 523 + Textures[1].height);
			Continue.GetCoord(93, 433, 93 + Textures[3].width, 433 + Textures[3].height);
			Options.GetCoord(93, 343, 93 + Textures[5].width, 343 + Textures[5].height);
			Exit.GetCoord(93, 253, 93 + Textures[7].width, 253 + Textures[7].height);
		}

		/////////////////   TEXTURES    /////////////////

		void Draw() {

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, Textures[0].texID);

			Mode.Begin2D();

			DrawQuad(xLeft, yDown, xRight, yUp);

			if (!NewGame.isPressed)
			{
				NewGame.Draw(Textures[1]);
			}
			else
			{
				NewGame.Draw(Textures[2]);
			}

			if (!Continue.isPressed)
			{
				Continue.Draw(Textures[3]);
			}
			else
			{
				Continue.Draw(Textures[4]);
			}

			if (!Options.isPressed)
			{
				Options.Draw(Textures[5]);
			}
			else
			{
				Options.Draw(Textures[6]);
			}

			if (!Exit.isPressed)
			{
				Exit.Draw(Textures[7]);
			}
			else
			{
				Exit.Draw(Textures[8]);
			}

			Mode.End2D();
		}


		bool isVisible;

		Button NewGame;
		Button Continue;
		Button Options;
		Button Exit;

	private:
		TwoDMode Mode;

		const double yUp = WWidth;
		const double yDown = 0;
		const double xLeft = 0;
		const double xRight = WHeight;

	};
}


