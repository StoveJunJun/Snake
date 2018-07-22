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
	SetWindowSize("̰����", 30,39);
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

void Game::Select()//ѡ�����
{


	SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��

	WriteChar(22, 17, "����С��", SetConsoleColor(COLOR_LIGHTBLUE, COLOR_BLACK));
	WriteChar(24, 17, "��������", SetConsoleColor(COLOR_LIGHTBLUE, COLOR_BLACK));
	WriteChar(26, 17, "�����ڴ�", SetConsoleColor(COLOR_LIGHTBLUE, COLOR_BLACK));
	WriteChar(28, 17, "���ѳ���", SetConsoleColor(COLOR_LIGHTBLUE, COLOR_BLACK));
	score = 0;

	/*���·����ѡ��ģ��*/
	int ch;//��¼����ֵ
	key = 1;//��¼ѡ�����ʼѡ���һ��
	bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://UP�Ϸ����
			if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
			{
				switch (key)
				{
				case 2:
					SetCursorPosition(17, 22);//����ѡ�������ñ���ɫ
					SetBackColor();
					std::cout << "����С��";


					SetCursorPosition(17, 24);//����ѡ����ȡ���ұ���ɫ
					SetColor(3);
					std::cout << "��������";


					--key;
					break;
				case 3:
					SetCursorPosition(17, 24);
					SetBackColor();
					std::cout << "��������";

					SetCursorPosition(17, 26);
					SetColor(3);
					std::cout << "�����ڴ�";

					--key;
					break;
				case 4:
					SetCursorPosition(17, 26);
					SetBackColor();
					std::cout << "�����ڴ�";


					SetCursorPosition(17, 28);
					SetColor(3);
					std::cout << "���ѳ���";

					--key;
					break;
				}
			}
			break;

		case 80://DOWN�·����
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(17, 24);
					SetBackColor();
					std::cout << "��������";
					SetCursorPosition(17, 22);
					SetColor(3);
					std::cout << "����С��";


					++key;
					break;
				case 2:
					SetCursorPosition(17, 26);
					SetBackColor();
					std::cout << "�����ڴ�";
					SetCursorPosition(17, 24);
					SetColor(3);
					std::cout << "��������";


					++key;
					break;
				case 3:
					SetCursorPosition(17, 28);
					SetBackColor();
					std::cout << "���ѳ���";
					SetCursorPosition(17, 26);
					SetColor(3);
					std::cout << "�����ڴ�";


					++key;
					break;
				}
			}
			break;

		case 13://Enter�س���
			flag = true;
			break;
		default://��Ч����
			break;
		}
		if (flag)
			break;//����Enter�س���ȷ�ϣ��˳��������ѭ��

		SetCursorPosition(0, 30);//������������½ǣ�����ر���˸Ӱ����Ϸ����
	}

	switch (key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��
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

	//WriteChar(25,  // �� 1 ��
	//	15,  // �� 1 ��
	//	"�밴�������ʼ��Ϸ",
	//	SetConsoleColor(COLOR_BLACK, // ��ɫǰ��
	//		COLOR_WHITE)  // ��ɫ����
	//);
}

void Game::ShowSorce()
{
	if (score>HighScore)
	{
		HighScore = score;
	}
	WriteChar(8, 28, "��ķ���", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	std::cout << score<<std::endl;
	WriteChar(10, 28, "��߷� ", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	std::cout << HighScore << std::endl;

	WriteChar(12, 28, "���ң��� �� ���� A D", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	WriteChar(13, 28, "�ϣ��� ���� W", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	WriteChar(14, 28, "�£��� ���� S", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	WriteChar(15, 28, "��ESC��ͣ\n", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));

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
	WriteChar(16, 15, "���������С�����\n", SetConsoleColor(COLOR_BLACK, COLOR_WHITE));
	
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
		WriteChar(12, i, "��", SetConsoleColor(COLOR_GREEN, COLOR_WHITE));
	}
	WriteChar(14, 15, "�����!!", SetConsoleColor(COLOR_BLACK, COLOR_WHITE)); // ��ɫ����
	WriteChar(15, 15, "������һ����(y/n)", SetConsoleColor(COLOR_BLACK, COLOR_WHITE)); // ��ɫ����
	for (size_t i = 10; i < 30; i++)
	{
		WriteChar(17, i, "��", SetConsoleColor(COLOR_GREEN, COLOR_WHITE));
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
