#pragma comment(lib,"Winmm.lib")
#include "Game.h"
#include<vector>
#include <time.h>
#include <conio.h>
Game::Game()
{
}
Game::~Game()
{
	if (m_pSnake !=nullptr)
	{
		delete m_pSnake;
		m_pSnake = nullptr;
	}
	if (m_pFood != nullptr)
	{
		delete m_pFood;
		m_pFood = nullptr;
	}
	if (m_pBg != nullptr)
	{
		delete m_pBg;
		m_pBg = nullptr;
	}
	if (m_pBigFood!=nullptr)
	{
		delete m_pBigFood;
		m_pBigFood = nullptr;
	}
}
int Game::MainLoop()
{
	SetWindowSize("贪吃蛇", 30,39);
	ShowWelcome();
	Select();
	RecordHighSocre();
	while (true)
	{
		mciSendString(TEXT("open bgMusic.wma alias bgMusic"), NULL, 0, NULL);
		mciSendString(TEXT("play bgMusic repeat"), NULL, 0, NULL);
		system("cls");
		Init();
		char chControl = 0;
		clock_t clkStart = 0;
		clock_t clkFinish = 0;
		while (!IsDead())
		{
			clkFinish = clock();
			ShowSorce();
			if (clkFinish - clkStart > GameSpeed)
			{
				m_pSnake->StepMove();
				IsEatFood();
				Show();
				clkStart = clkFinish;
			}
			if (_kbhit())
			{
				chControl = _getch();
			}
			switch (chControl)
			{
			case 'w':
				if (m_pSnake->Dir != Snake::DOWN)
				{
					m_pSnake->SetDir(Snake::UP);
				}
				break;
			case 72:
				if (m_pSnake->Dir != Snake::DOWN)
				{
					m_pSnake->SetDir(Snake::UP);
				}
				break;

			case 's':
				if (m_pSnake->Dir != Snake::UP)
				{
					m_pSnake->SetDir(Snake::DOWN);
					break;
				}
			case 80:
				if (m_pSnake->Dir != Snake::UP)
				{
					m_pSnake->SetDir(Snake::DOWN);
				}
				break;

			case 'a':
				if (m_pSnake->Dir != Snake::RIGHT)
				{
					m_pSnake->SetDir(Snake::LEFT);
				}
				break;
			case 75:
				if (m_pSnake->Dir != Snake::RIGHT)
				{
					m_pSnake->SetDir(Snake::LEFT);
				}
				break;
			case 'd':
				if (m_pSnake->Dir != Snake::LEFT)
				{
					m_pSnake->SetDir(Snake::RIGHT);
				}
				break;
			case 77:
				if (m_pSnake->Dir != Snake::LEFT)
				{
					m_pSnake->SetDir(Snake::RIGHT);
				}
				break;
			case 27:
				system("pause");
				break;
			default:
				break;
			}
			chControl = 0;
		}
		PrintfGameOver();
		mciSendString(TEXT("close mymusic"), NULL, 0, NULL);
		if (PlayAgain() == false)
		{
			WriteHighSocre();
			Sleep(2);
			exit(0);
		}
		score = 0;
	}
	return 0;
}


int Game::Init()
{
	m_pSnake = new Snake;
	m_pFood = new FoodNode;
	m_pBg = new Map;
	m_pBigFood = new BigFoodNode;
	m_pBg->Init();
	m_pSnake->InitSnake();
	m_pFood->RefreshFood();
	return 0;
}

int Game::Show()
{
	m_pSnake->Show();
	m_pBg->Show();
	m_pFood->Show();
	return 0;
}

void Game::Select()//选择界面
{


	SetBackColor();//第一个选项设置背景色以表示当前选中

	WriteChar(22, 17, "初生小蛇", SetConsoleColor(COLOR_LIGHTBLUE, COLOR_BLACK));
	WriteChar(24, 17, "闯荡多年", SetConsoleColor(COLOR_LIGHTBLUE, COLOR_BLACK));
	WriteChar(26, 17, "蛇王在此", SetConsoleColor(COLOR_LIGHTBLUE, COLOR_BLACK));
	WriteChar(28, 17, "我已成仙", SetConsoleColor(COLOR_LIGHTBLUE, COLOR_BLACK));
	score = 0;

	/*上下方向键选择模块*/
	int ch;//记录键入值
	key = 1;//记录选中项，初始选择第一个
	bool flag = false;//记录是否键入Enter键标记，初始置为否
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://UP上方向键
			if (key > 1)//当此时选中项为第一项时，UP上方向键无效
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 22);//给待选中项设置背景色
					SetBackColor();
					std::cout << "初生小蛇";


					SetCursorPosition(17, 24);//将已选中项取消我背景色
					SetColor(3);
					std::cout << "闯荡多年";


					--key;
					break;
				case 3:
					SetCursorPosition(17, 24);
					SetBackColor();
					std::cout << "闯荡多年";

					SetCursorPosition(17, 26);
					SetColor(3);
					std::cout << "蛇王在此";

					--key;
					break;
				case 4:
					SetCursorPosition(17, 26);
					SetBackColor();
					std::cout << "蛇王在此";


					SetCursorPosition(17, 28);
					SetColor(3);
					std::cout << "我已成仙";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 24);
					SetBackColor();
					std::cout << "闯荡多年";
					SetCursorPosition(17, 22);
					SetColor(3);
					std::cout << "初生小蛇";


					++key;
					break;
				case 2:
					SetCursorPosition(17, 26);
					SetBackColor();
					std::cout << "蛇王在此";
					SetCursorPosition(17, 24);
					SetColor(3);
					std::cout << "闯荡多年";


					++key;
					break;
				case 3:
					SetCursorPosition(17, 28);
					SetBackColor();
					std::cout << "我已成仙";
					SetCursorPosition(17, 26);
					SetColor(3);
					std::cout << "蛇王在此";


					++key;
					break;
				}
			}
			break;

		case 13://Enter回车键
			flag = true;
			break;
		default://无效按键
			break;
		}
		if (flag)
			break;//输入Enter回车键确认，退出检查输入循环

		SetCursorPosition(0, 30);//将光标置于左下角，避免关标闪烁影响游戏体验
	}

	switch (key)//根据所选选项设置蛇的移动速度，speed值越小，速度越快
	{
	case 1:
		GameSpeed = 300;
		break;
	case 2:
		GameSpeed = 250;
		break;
	case 3:
		GameSpeed = 150;
		break;
	case 4:
		GameSpeed =100;
		break;
	default:
		break;
	}
}

void Game::ShowWelcome()
{
	mciSendString(TEXT("open win.wma alias startMusic"), NULL, 0, NULL);
	mciSendString(TEXT("play startMusic repeat"), NULL, 0, NULL);
	Logo *start = new Logo();
	start->Action();
	delete start;
	Sleep(1);
	mciSendString(TEXT("close startMusic"), NULL, 0, NULL);

	//WriteChar(25,  // 第 1 行
	//	15,  // 第 1 列
	//	"请按任意键开始游戏",
	//	SetConsoleColor(COLOR_BLACK, // 黑色前景
	//		COLOR_WHITE)  // 白色背景
	//);
}

void Game::ShowSorce()
{
	if (score>HighScore)
	{
		HighScore = score;
	}
	WriteChar(8, 28, "你的分数", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	std::cout << score<<std::endl;
	WriteChar(10, 28, "最高分 ", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	std::cout << HighScore << std::endl;

	WriteChar(12, 28, "左右：← → 或者 A D", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	WriteChar(13, 28, "上：↑ 或者 W", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	WriteChar(14, 28, "下：↓ 或者 S", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	WriteChar(15, 28, "按ESC暂停\n", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));

}

int Game::IsEatFood()
{
	if ((m_pSnake->HeadNode->m_nRow==m_pFood->m_nRow)&&(m_pSnake->HeadNode->m_nCol==m_pFood->m_nCol))
	{
		m_pSnake->AddTail();
		m_pFood->RefreshFood();
		score += 10;
		//m_nCount++;
		//if (m_nCount==5)
		//{
		//	m_pBigFood->RefreshFood();
		//	m_pBigFood->Show();
		//	m_nCount = 0;
		//}
	}
	return 0;
}

bool Game::HitItSelf()
{
	SnakeNode *pMove = nullptr;
	pMove = m_pSnake->HeadNode->m_pNext;
	int count=0;
	while (pMove)
	{
		if ((m_pSnake->HeadNode->m_nRow==pMove->m_nRow)&&(m_pSnake->HeadNode->m_nCol==pMove->m_nCol))
		{
			return true;
		}
		pMove = pMove->m_pNext;
	}
	pMove = nullptr;
	return false;
}

bool Game::IsDead()
{
	if ((m_pSnake->HeadNode->m_nRow == GAME_ROW-1) || (m_pSnake->HeadNode->m_nCol == GAME_COL-1) ||(m_pSnake->HeadNode->m_nCol == 0)|| (m_pSnake->HeadNode->m_nRow == 0))
	{
		return true;
	}
	else if(HitItSelf() == true)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Game::RecordHighSocre()
{
	FILE *fp = fopen("scoredata.txt", "r");
	if (fp==nullptr)
	{
		return;
	}
	int ndata[10];
	fscanf(fp,"%d", &ndata[0]);
	HighScore = ndata[0];
	fclose(fp);
}

void Game::WriteHighSocre()
{
	WriteChar(16, 15, "保存数据中。。。\n", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	
	FILE *fp2 = fopen("scoredata.txt", "w");
	if (fp2 == nullptr)
	{
		return;
	}
	fprintf(fp2, "%d", HighScore);
	fclose(fp2);
}

void Game::PrintfGameOver()
{
	system("cls");
	for (size_t i = 10; i < 30; i++)
	{
		WriteChar(12, i, "■", SetConsoleColor(COLOR_GREEN, COLOR_WHITE));
	}
	WriteChar(14, 15, "你挂啦!!", SetConsoleColor(COLOR_BLACK, COLOR_WHITE)); // 白色背景
	WriteChar(15, 15, "想再来一局吗？(y/n)", SetConsoleColor(COLOR_BLACK, COLOR_WHITE)); // 白色背景
	for (size_t i = 10; i < 30; i++)
	{
		WriteChar(17, i, "■", SetConsoleColor(COLOR_GREEN, COLOR_WHITE));
	}
}

bool Game::PlayAgain()
{
	while (true)
	{
		char ch = _getch();
		if (ch == 'y' || ch == 'Y' )
		{
			return true;
		}
		else if (ch == 'n' || ch == 'N')
		{
			return false;
		}
	}
}
