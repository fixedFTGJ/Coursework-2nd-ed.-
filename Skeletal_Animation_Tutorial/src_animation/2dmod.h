#pragma once

#include <glew.h>

using namespace std;

namespace CourseWork {


	class TwoDMode
	{
	public:
		void Begin2D()
		{
			glDisable(GL_DEPTH_TEST);
			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0, 1280, 0, 768);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();
		}

		void End2D()
		{
			glPopMatrix();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
			glEnable(GL_DEPTH_TEST);
		}
	};
}