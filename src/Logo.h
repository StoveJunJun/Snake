#pragma once
#include<deque>
#include<vector>
#include"point.h"
class Logo
{
public:
	Logo():speed(35)
	{
		startSnake.emplace_back(point(0, 14));
		startSnake.emplace_back(point(1, 14));
		startSnake.emplace_back(point(2, 15));
		startSnake.emplace_back(point(3, 16));
		startSnake.emplace_back(point(4, 17));
		startSnake.emplace_back(point(5, 18));
		startSnake.emplace_back(point(6, 17));
		startSnake.emplace_back(point(7, 16));
		startSnake.emplace_back(point(8, 15));
		startSnake.emplace_back(point(9, 14));

		textSnake.emplace_back(point(-26, 14));//S
		textSnake.emplace_back(point(-25, 14));
		textSnake.emplace_back(point(-27, 15));
		textSnake.emplace_back(point(-26, 16));
		textSnake.emplace_back(point(-25, 17));
		textSnake.emplace_back(point(-27, 18));
		textSnake.emplace_back(point(-26, 18));

		//N
		textSnake.emplace_back(point(-23, 14));
		textSnake.emplace_back(point(-23, 15));
		textSnake.emplace_back(point(-23, 16));
		textSnake.emplace_back(point(-23, 17));
		textSnake.emplace_back(point(-23, 18));
		textSnake.emplace_back(point(-22, 15));
		textSnake.emplace_back(point(-21, 16));
		textSnake.emplace_back(point(-20, 17));
		textSnake.emplace_back(point(-19, 14));
		textSnake.emplace_back(point(-19, 15));
		textSnake.emplace_back(point(-19, 16));
		textSnake.emplace_back(point(-19, 17));
		textSnake.emplace_back(point(-19, 18));

		textSnake.emplace_back(point(-17, 18));//A
		textSnake.emplace_back(point(-16, 17));
		textSnake.emplace_back(point(-15, 16));
		textSnake.emplace_back(point(-14, 15));
		textSnake.emplace_back(point(-14, 16));
		textSnake.emplace_back(point(-13, 14));
		textSnake.emplace_back(point(-13, 16));
		textSnake.emplace_back(point(-12, 15));
		textSnake.emplace_back(point(-12, 16));
		textSnake.emplace_back(point(-11, 16));
		textSnake.emplace_back(point(-10, 17));
		textSnake.emplace_back(point(-9, 18));

		textSnake.emplace_back(point(-7, 14));//K
		textSnake.emplace_back(point(-7, 15));
		textSnake.emplace_back(point(-7, 16));
		textSnake.emplace_back(point(-7, 17));
		textSnake.emplace_back(point(-7, 18));
		textSnake.emplace_back(point(-6, 16));
		textSnake.emplace_back(point(-5, 15));
		textSnake.emplace_back(point(-5, 17));
		textSnake.emplace_back(point(-4, 14));
		textSnake.emplace_back(point(-4, 18));

		textSnake.emplace_back(point(-2, 14));//E
		textSnake.emplace_back(point(-2, 15));
		textSnake.emplace_back(point(-2, 16));
		textSnake.emplace_back(point(-2, 17));
		textSnake.emplace_back(point(-2, 18));
		textSnake.emplace_back(point(-1, 14));
		textSnake.emplace_back(point(-1, 16));
		textSnake.emplace_back(point(-1, 18));
		textSnake.emplace_back(point(0, 14));
		textSnake.emplace_back(point(0, 16));
		textSnake.emplace_back(point(0, 18));
	}
	void PrintFirst();
	void PrintSecond();
	void PrintThird();

	void PrintText();
	void ClearText();
	void Action();
private:
	std::deque<point> startSnake;
	std::vector<point> textSnake;
	int speed;
};

