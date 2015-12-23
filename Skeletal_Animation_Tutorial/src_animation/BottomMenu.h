#pragma once

#include <glew.h>
#include <glaux.h>
#include "Texture.h"
#include "2dmod.h"
#include "DrawFigure.h"

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
		TextureImage Textures[9];

		void InitTexture() {
			Texture = new CTexture();
			Texture->LoadTexture(IL_JPG, "source/Menu.jpg", &Textures[0]);
			
		}

		/////////////////   TEXTURES    /////////////////

		void Draw() {

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, Textures[0].texID);

			Mode.Begin2D();
			DrawQuad(xLeft, yDown, xRight, yUp);
			Mode.End2D();

		}


		bool isVisible;



	private:
		TwoDMode Mode;

		const double yUp = 192;
		const double yDown = 0;
		const double xLeft = 0;
		const double xRight = 1280;

	};
}


