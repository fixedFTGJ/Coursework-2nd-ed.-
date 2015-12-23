#pragma once

#include <glew.h>

using namespace std;


	void DrawQuad(double xLeft, double yDown, double xRight, double yUp)
	{
		glBegin(GL_QUADS);
		glTexCoord2f(1, 0);			glVertex2d(xRight, yUp);
		glTexCoord2f(0, 0);			glVertex2d(xLeft, yUp);
		glTexCoord2f(0, 1);			glVertex2d(xLeft, yDown);
		glTexCoord2f(1, 1);			glVertex2d(xRight, yDown);
		glEnd();
	}
