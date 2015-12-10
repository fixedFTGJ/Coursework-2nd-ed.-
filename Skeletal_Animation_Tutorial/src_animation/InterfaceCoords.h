#pragma once

#include <vector>
#include "Coords.h"

using namespace std;

namespace CourseWork {
	
	
	class InterfaceCoords
	{
	public:
		InterfaceCoords() {
			FrontRightUp.CoordsGive(0.0f, 0.0f, 0.0f);
			FrontLeftUp.CoordsGive(0.0f, 0.0f, 0.0f);
			FrontLeftDown.CoordsGive(0.0f, 0.0f, 0.0f);
			FrontRightDown.CoordsGive(0.0f, 0.0f, 0.0f);

			LeftRightUp.CoordsGive(0.0f, 0.0f, 0.0f);
			LeftLeftUp.CoordsGive(0.0f, 0.0f, 0.0f);
			LeftLeftDown.CoordsGive(0.0f, 0.0f, 0.0f);
			LeftRightDown.CoordsGive(0.0f, 0.0f, 0.0f);

			BackRightUp.CoordsGive(0.0f, 0.0f, 0.0f);
			BackLeftUp.CoordsGive(0.0f, 0.0f, 0.0f);
			BackLeftDown.CoordsGive(0.0f, 0.0f, 0.0f);
			BackRightDown.CoordsGive(0.0f, 0.0f, 0.0f);

			RightRightUp.CoordsGive(0.0f, 0.0f, 0.0f);
			RightLeftUp.CoordsGive(0.0f, 0.0f, 0.0f);
			RightLeftDown.CoordsGive(0.0f, 0.0f, 0.0f);
			RightRightDown.CoordsGive(0.0f, 0.0f, 0.0f);

		}

		Coords FrontRightUp;
		Coords FrontLeftUp;
		Coords FrontLeftDown;
		Coords FrontRightDown;

		Coords LeftRightUp;
		Coords LeftLeftUp;
		Coords LeftLeftDown;
		Coords LeftRightDown;

		Coords BackRightUp;
		Coords BackLeftUp;
		Coords BackLeftDown;
		Coords BackRightDown;

		Coords RightRightUp;
		Coords RightLeftUp;
		Coords RightLeftDown;
		Coords RightRightDown;

	private:


	};
}


