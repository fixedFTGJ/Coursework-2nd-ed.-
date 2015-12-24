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

			c11 = 2;
			c12 = 1;
			c13 = 0;
			c21 = 9;
			c22 = 8;
			c23 = 7;
			c31 = 6;
			c32 = 5;
			c33 = 4;
			c41 = 3;
			c42 = 2;
			c43 = 1;

			isVisible = true;

		};

		/////////////////   TEXTURES    /////////////////

		CTexture *Texture;
		TextureImage Textures[19];
		

		void InitTexture() {
			Texture = new CTexture();
			Texture->LoadTexture(IL_JPG, "source/BottomMenu.jpg", &Textures[0]);

			Texture->LoadTexture(IL_PNG, "source/buttons/bottommenu/jug/Power.png", &Textures[1]);
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

			InitNumerals();
		}

		/////////////////   TEXTURES    /////////////////
		TextureImage NumTextures[10];

		void InitNumerals() {
			Texture = new CTexture();
			Texture->LoadTexture(IL_PNG, "source/numerals/0.png", &NumTextures[0]);
			Texture->LoadTexture(IL_PNG, "source/numerals/1.png", &NumTextures[1]);
			Texture->LoadTexture(IL_PNG, "source/numerals/2.png", &NumTextures[2]);
			Texture->LoadTexture(IL_PNG, "source/numerals/3.png", &NumTextures[3]);
			Texture->LoadTexture(IL_PNG, "source/numerals/4.png", &NumTextures[4]);
			Texture->LoadTexture(IL_PNG, "source/numerals/5.png", &NumTextures[5]);
			Texture->LoadTexture(IL_PNG, "source/numerals/6.png", &NumTextures[6]);
			Texture->LoadTexture(IL_PNG, "source/numerals/7.png", &NumTextures[7]);
			Texture->LoadTexture(IL_PNG, "source/numerals/8.png", &NumTextures[8]);
			Texture->LoadTexture(IL_PNG, "source/numerals/9.png", &NumTextures[9]);

			N11.GetCoord(35, yUp - 170, 35 + NumTextures[c11].width, yUp - 170 + NumTextures[c11].height);
			N12.GetCoord(60, yUp - 170, 60 + NumTextures[c12].width, yUp - 170 + NumTextures[c12].height);
			N13.GetCoord(85, yUp - 170, 85 + NumTextures[c13].width, yUp - 170 + NumTextures[c13].height);

			N21.GetCoord(265, yUp - 170, 265 + NumTextures[c21].width, yUp - 170 + NumTextures[c21].height);
			N22.GetCoord(290, yUp - 170, 290 + NumTextures[c22].width, yUp - 170 + NumTextures[c22].height);
			N23.GetCoord(315, yUp - 170, 315 + NumTextures[c23].width, yUp - 170 + NumTextures[c23].height);

			N31.GetCoord(495, yUp - 170, 495 + NumTextures[c31].width, yUp - 170 + NumTextures[c31].height);
			N32.GetCoord(520, yUp - 170, 520 + NumTextures[c32].width, yUp - 170 + NumTextures[c32].height);
			N33.GetCoord(545, yUp - 170, 545 + NumTextures[c33].width, yUp - 170 + NumTextures[c33].height);

			N41.GetCoord(725, yUp - 170, 725 + NumTextures[c41].width, yUp - 170 + NumTextures[c41].height);
			N42.GetCoord(750, yUp - 170, 750 + NumTextures[c42].width, yUp - 170 + NumTextures[c42].height);
			N43.GetCoord(775, yUp - 170, 775 + NumTextures[c43].width, yUp - 170 + NumTextures[c43].height);
		}

		void DrawNumerals() {
			N11.Draw(NumTextures[c11]);
			N12.Draw(NumTextures[c12]);
			N13.Draw(NumTextures[c13]);

			N21.Draw(NumTextures[c21]);
			N22.Draw(NumTextures[c22]);
			N23.Draw(NumTextures[c23]);

			N31.Draw(NumTextures[c31]);
			N32.Draw(NumTextures[c32]);
			N33.Draw(NumTextures[c33]);

			N41.Draw(NumTextures[c41]);
			N42.Draw(NumTextures[c42]);
			N43.Draw(NumTextures[c43]);
		}

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

			DrawNumerals();

			Mode.End2D();

		}

		void GetNumeralsN1(int c1, int c2, int c3) {
			c11 = c1;
			c12 = c2;
			c13 = c3;
		}
		
		void GetNumeralsN2(int c1, int c2, int c3) {
			c21 = c1;
			c22 = c2;
			c23 = c3;
		}

		void GetNumeralsN3(int c1, int c2, int c3) {
			c31 = c1;
			c32 = c2;
			c33 = c3;
		}

		void GetNumeralsN4(int c1, int c2, int c3) {
			c41 = c1;
			c42 = c2;
			c43 = c3;
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

		Button N11;
		Button N12;
		Button N13;
		Button N21;
		Button N22;
		Button N23;
		Button N31;
		Button N32;
		Button N33;
		Button N41;
		Button N42;
		Button N43;

		int c11;
		int c12;
		int c13;
		int c21;
		int c22;
		int c23;
		int c31;
		int c32;
		int c33;
		int c41;
		int c42;
		int c43;


	private:
		TwoDMode Mode;

		const double yUp = 192;
		const double yDown = 0;
		const double xLeft = 0;
		const double xRight = 1280;

	};
}


