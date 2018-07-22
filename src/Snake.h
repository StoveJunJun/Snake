#pragma once
#include<list>
#include<iostream>
#include<iterator>
#include"setdisplay.h"
#define GAME_ROW 26
#define GAME_COL 26
//struct FoodNode
//{
//	FoodNode()
//	{
//		RefreshFood();
//	}
//	void RefreshFood()
//	{
//
//		//(rand()%(b-a+1))+a-1
//		int randRow;
//		int randCol;
//		do
//		{
//			randRow = rand() % GAME_ROW;
//			randCol = rand() % GAME_COL;
//
//		} while (randRow <= 0 || randRow >= GAME_ROW-1 || randCol <= 0 || randCol >= GAME_COL-1);
//		m_nRow = randRow;
//		m_nCol = randCol;
//	}
//	void Show()
//	{
//		WriteChar(m_nRow, m_nCol, "■", SetConsoleColor(COLOR_RED,COLOR_WHITE));
//	}
//	int m_nRow;
//	int m_nCol;
//};
struct SnakeNode
{
	void Show()
	{
		WriteChar(m_nRow, m_nCol, "●", SetConsoleColor(COLOR_BLUE, COLOR_WHITE));
	}
	void ShowHead()
	{
		WriteChar(m_nRow, m_nCol, "●", SetConsoleColor(COLOR_YELLOW, COLOR_WHITE));
	}
	void SetPos(int nRow, int nCol)
	{
		m_nRow = nRow;
		m_nCol = nCol;
	}

	SnakeNode(int _row, int _col)
	{
		m_nRow = _row;
		m_nCol = _col;
		m_pNext = nullptr;
		m_pPre = nullptr;
	}
	int m_nRow;
	int m_nCol;
	SnakeNode* m_pNext;
	SnakeNode* m_pPre;

};
class Snake:public std::list<SnakeNode*>
{
public:
	SnakeNode * HeadNode;
	enum Direction
	{
		UP=0,
		DOWN,
		LEFT,
		RIGHT
	};
	Direction Dir;
	Snake();
	//新蛇的初始化
	int  InitSnake();
	//初始化方向
	int DirectionInit();
	//改变方向
	int SetDir(Direction _Dir);
	//移动
	int OnStepMove();
	int StepMove();
	//身体变长
	int AddTail();
	//显示
	int Show();
	~Snake();
};
//typedef Snake CMySnake;