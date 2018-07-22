#include "Logo.h"
#include<windows.h>
void Logo::PrintFirst()
{
	for (auto& point:startSnake)
	{
		point.Print();
		Sleep(speed);
	}
}
void Logo::PrintSecond()
{
	for (int i = 10; i != 40; ++i)
	{
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		startSnake.emplace_back(point(i, j));
		startSnake.back().Print();
		startSnake.front().Clear();
		startSnake.pop_front();
		Sleep(speed);
	}
}
void Logo::PrintThird()
{
	while (!startSnake.empty() || textSnake.back().GetX() < 33)
	{
		if (!startSnake.empty())
		{
			startSnake.front().Clear();
			startSnake.pop_front();
		}
		ClearText();
		PrintText();
		Sleep(speed);
	}
}
void Logo::PrintText()
{
	for (auto& point : textSnake)
	{
		if (point.GetX() >= 0)
		{
			point.Print();
		}
	}
}

void Logo::ClearText()
{
	for (auto& point:textSnake)
	{
		if (point.GetX()>=0)
			point.Clear();
		point.ChangePosition(point.GetX() + 1, point.GetY());
	}
}

void Logo::Action()
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}
