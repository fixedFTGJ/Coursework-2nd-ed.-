#pragma once

namespace CourseWork
{
	struct Coordinates
	{
		int X;
		int Y;

		Coordinates(int x, int y)
		{
			X = x;
			Y = y;
		}

		Coordinates()
		{
			X = 0;
			Y = 0;
		}
	};

	class Environment
	{
	public:
		Environment(bool isObstacle);
		bool IsObstacle();
	private:
		bool _isObstacle;
	};
}