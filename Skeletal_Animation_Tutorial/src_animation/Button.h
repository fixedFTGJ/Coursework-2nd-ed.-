#pragma once

#include <glew.h>
#include <glaux.h>
#include "Texture.h"
#include "2dmod.h"
#include "DrawFigure.h"

using namespace std;

namespace CourseWork {

	class Button
	{
	public:
		Button() {
			isPressed = false;
		}

		Button(double _xL, double _yD, double _xR, double _yU) {

			yUp = _yU;
			yDown = _yD;
			xLeft = _xL;
			xRight = _xR;

			isPressed = false;
		};

		void GetCoord(double _xL, double _yD, double _xR, double _yU) {
			yUp = _yU;
			yDown = _yD;
			xLeft = _xL;
			xRight = _xR;

		}

		void Draw(TextureImage _TI) {
			Textures = _TI;

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, Textures.texID);

			DrawQuad(xLeft, yDown, xRight, yUp);

			glDisable(GL_BLEND);
		}

		bool Press(int x, int y) {
			if ((x >= xLeft && x <= xRight) &&
				(y >= (WWidth - yUp) && y <= (WWidth - yDown)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		bool isPressed;

		TextureImage Textures;

		double yUp;
		double yDown;
		double xLeft;
		double xRight;

	};
}


