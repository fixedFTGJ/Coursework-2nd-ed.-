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
			Texture->LoadTexture(IL_JPG, "source/MainMenu1.jpg", &Textures[0]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/new.png", &Textures[1]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/newPr.png", &Textures[2]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/cont.png", &Textures[3]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/contPr.png", &Textures[4]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/opt.png", &Textures[5]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/optPr.png", &Textures[6]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/ex.png", &Textures[7]);
			Texture->LoadTexture(IL_PNG, "source/buttons/mainmenu/exPr.png", &Textures[8]);
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

		Button NewGame = Button(93, 523, 411, 568);
		Button Continue = Button(93, 433, 368, 478);
		Button Options = Button(93, 343, 331, 388);
		Button Exit = Button(93, 253, 222, 299);

	private:
		TwoDMode Mode;

		const double yUp = WWidth;
		const double yDown = 0;
		const double xLeft = 0;
		const double xRight = WHeight;

	};
}


