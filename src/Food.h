#pragma once
#include<iostream>
#include<iterator>
#include"setdisplay.h"
#define GAME_ROW 26
#define GAME_COL 26
struct FoodNode
{
	FoodNode()
	{
		RefreshFood();
	}
	void RefreshFood()
	{

		//(rand()%(b-a+1))+a-1
		int randRow;
		int randCol;
		do
		{
			randRow = rand() % GAME_ROW;
			randCol = rand() % GAME_COL;

		} while (randRow <= 0 || randRow >= GAME_ROW - 1 || randCol <= 0 || randCol >= GAME_COL - 1);
		m_nRow = randRow;
		m_nCol = randCol;
	}
	void Show()
	{
		WriteChar(m_nRow, m_nCol, "¡ö", SetConsoleColor(COLOR_RED, COLOR_WHITE));
	}
	int m_nRow;
	int m_nCol;
};

struct BigFoodNode
{
	BigFoodNode()
	{
		RefreshFood();
	}
	void RefreshFood()
	{

		//(rand()%(b-a+1))+a-1
		int randRow;
		int randCol;
		do
		{
			randRow = rand() % GAME_ROW;
			randCol = rand() % GAME_COL;

		} while (randRow <= 0 || randRow >= GAME_ROW - 1 || randCol <= 0 || randCol >= GAME_COL - 1);
		m_nRow = randRow;
		m_nCol = randCol;
	}
	void Show()
	{
		WriteChar(m_nRow, m_nCol, "¡ñ", SetConsoleColor(COLOR_THIN_PURPLE, COLOR_WHITE));
	}
	int m_nRow;
	int m_nCol;
};
class Food
{
public:
	Food();
	~Food();
};

