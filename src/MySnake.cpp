// MySnake.cpp: 定义控制台应用程序的入口点。
//
#pragma comment(lib,"Winmm.lib")
#include "Snake.h"
#include"Game.h"
#include "Map.h"
#include<mmsystem.h>

int main()
{
	Game mygame;
	mygame.Init();
	mygame.MainLoop();
    return 1;
}

