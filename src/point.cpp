#include "point.h"
#include"setdisplay.h"
#include<iostream>


void point::Print()
{
	SetCursorPosition(x, y);
	std::cout << "��" << std::endl;
	//WriteChar(x, y, "��", SetConsoleColor(COLOR_BLUE, COLOR_WHITE));
}

void point::Clear()
{
	SetCursorPosition(x, y);
	std::cout << "  ";
}

void point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
}
