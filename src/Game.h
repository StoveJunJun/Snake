#pragma once
#include "Snake.h"
#include "Map.h"
#include"Logo.h"
#include"Food.h"
class Game
{
public:
	Game();
	~Game();

	Snake* m_pSnake;
	FoodNode*m_pFood;
	Map* m_pBg;
	BigFoodNode* m_pBigFood;
	int m_nCount;
	int GameSpeed;
	int score;
	int key;
	int HighScore;


	int MainLoop();
	int Init();
	int Show();
	void Select();
	void ShowWelcome();
	void ShowSorce();
	int IsEatFood();
	bool HitItSelf();
	bool IsDead();
	void RecordHighSocre();
	void WriteHighSocre();
	void PrintfGameOver();
	bool PlayAgain();
};