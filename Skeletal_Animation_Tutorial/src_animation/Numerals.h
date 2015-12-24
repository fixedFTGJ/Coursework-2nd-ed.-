#pragma once

#include <glew.h>
#include <glaux.h>
#include "Texture.h"
#include "2dmod.h"
#include "DrawFigure.h"
#include "Button.h"

using namespace std;

namespace CourseWork {

	class BottomMenu
	{
	public:
		BottomMenu() {

			isVisible = false;

		};

		/////////////////   TEXTURES    /////////////////

		CTexture *Texture;
		TextureImage Textures[19];

		void InitTexture() {
			Texture = new CTexture();

			Texture->LoadTexture(IL_PNG, "source/numerals/Power.png", &Textures[1]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/jug/PowerPr.png", &Textures[2]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/jug/Provocation.png", &Textures[3]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/jug/ProvocationPr.png", &Textures[4]);

			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/med/Heal.png", &Textures[5]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/med/HealPr.png", &Textures[6]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/med/Buff.png", &Textures[7]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/med/BuffPr.png", &Textures[8]);

			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/ass/Backstab.png", &Textures[9]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/ass/BackstabPr.png", &Textures[10]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/ass/Evasion.png", &Textures[11]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/ass/EvasionPr.png", &Textures[12]);

			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/kin/Stun.png", &Textures[13]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/kin/StunPr.png", &Textures[14]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/kin/Push.png", &Textures[15]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/kin/PushPr.png", &Textures[16]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/kin/Drag_in.png", &Textures[17]);
			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/kin/Drag_inPr.png", &Textures[18]);

			Power.GetCoord(123, yUp - 84, 123 + Textures[1].width, yUp - 84 + Textures[1].height);
			Provocation.GetCoord(123, yUp - 112, 123 + Textures[3].width, yUp - 112 + Textures[3].height);
			Heal.GetCoord(353, yUp - 84, 353 + Textures[5].width, yUp - 84 + Textures[5].height);
			Buff.GetCoord(353, yUp - 112, 353 + Textures[7].width, yUp - 112 + Textures[7].height);
			Backstab.GetCoord(583, yUp - 84, 583 + Textures[9].width, yUp - 84 + Textures[9].height);
			Evasion.GetCoord(583, yUp - 112, 583 + Textures[11].width, yUp - 112 + Textures[11].height);
			Stun.GetCoord(813, yUp - 84, 813 + Textures[13].width, yUp - 84 + Textures[13].height);
			Push.GetCoord(813, yUp - 112, 813 + Textures[15].width, yUp - 112 + Textures[15].height);
			Drag_in.GetCoord(813, yUp - 140, 813 + Textures[17].width, yUp - 140 + Textures[17].height);

		}

		/////////////////   TEXTURES    /////////////////

		void Draw() {

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, Textures[0].texID);

			Mode.Begin2D();

			DrawQuad(xLeft, yDown, xRight, yUp);

			if (!Power.isPressed)
			{
				Power.Draw(Textures[1]);
			}
			else
			{
				Power.Draw(Textures[2]);
			}

			if (!Provocation.isPressed)
			{
				Provocation.Draw(Textures[3]);
			}
			else
			{
				Provocation.Draw(Textures[4]);
			}

			if (!Heal.isPressed)
			{
				Heal.Draw(Textures[5]);
			}
			else
			{
				Heal.Draw(Textures[6]);
			}

			if (!Buff.isPressed)
			{
				Buff.Draw(Textures[7]);
			}
			else
			{
				Buff.Draw(Textures[8]);
			}

			if (!Backstab.isPressed)
			{
				Backstab.Draw(Textures[9]);
			}
			else
			{
				Backstab.Draw(Textures[10]);
			}

			if (!Evasion.isPressed)
			{
				Evasion.Draw(Textures[11]);
			}
			else
			{
				Evasion.Draw(Textures[12]);
			}

			if (!Stun.isPressed)
			{
				Stun.Draw(Textures[13]);
			}
			else
			{
				Stun.Draw(Textures[14]);
			}

			if (!Push.isPressed)
			{
				Push.Draw(Textures[15]);
			}
			else
			{
				Push.Draw(Textures[16]);
			}

			if (!Drag_in.isPressed)
			{
				Drag_in.Draw(Textures[17]);
			}
			else
			{
				Drag_in.Draw(Textures[18]);
			}


			Mode.End2D();

		}


		bool isVisible;

		Button Power;
		Button Provocation;
		Button Heal;
		Button Buff;
		Button Backstab;
		Button Evasion;
		Button Stun;
		Button Push;
		Button Drag_in;


	private:
		TwoDMode Mode;

		const double yUp = 192;
		const double yDown = 0;
		const double xLeft = 0;
		const double xRight = 1280;

	};
}


#pragma once
