#pragma once

#include <vector>

using namespace std;

namespace CourseWork {


	class Coords
	{
	public:
		Coords()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		};

		Coords(float _x, float _y, float _z)
		{
			x = _x;
			y = _y;
			z = _z;
		};

		void CoordsGive(float _x, float _y, float _z) {
			x = _x;
			y = _y;
			z = _z;
		}

		float X() {
			return x;
		}

		float Y() {
			return y;
		}

		float Z() {
			return z;
		}

		void X(float _x) {
			x = _x;
		}

		void Y(float _y) {
			y = _y;
		}

		void Z(float _z) {
			z = _z;
		}

		void AddX(float _x) {
			x += _x;
		}

		void AddY(float _y) {
			y += _y;
		}

		void AddZ(float _z) {
			z += _z;
		}

	private:
		float x;
		float y;
		float z;
	};
}


