#include "Snake.h"
#include<time.h>
#include<stdlib.h>
Snake::Snake()
{
}

int Snake::InitSnake()
{
	srand((unsigned)time(NULL));
	int randRow=rand() % GAME_ROW;
	int randCol = rand() % GAME_COL;
	//if (randRow==0|| randRow == GAME_ROW || randCol==0|| randCol == GAME_COL)
	//{
	//	randRow = rand() % GAME_ROW;
	//	randCol = rand() % GAME_COL;
	//}
	//HeadNode = new SnakeNode(randRow, randCol);
	HeadNode = new SnakeNode(10, 10);
	DirectionInit();
	emplace_back(HeadNode);

	return 1;
}

int Snake::DirectionInit()
{
	switch (rand()%4)
	{
	case 0:
		Dir = UP;
		break;
	case 1:
		Dir = DOWN;
		break;
	case 2:
		Dir = LEFT;
		break;
	case 3:
		Dir = RIGHT;
		break;
	default:
		break;
	}
	return 0;
}

int Snake::SetDir(Direction _Dir)
{
	Dir = _Dir;

	return 0;
}

int Snake::OnStepMove()
{
	StepMove();
	Show();
	return 0;
}

int Snake::StepMove()
{
	SnakeNode *pCurNode = nullptr;
	SnakeNode *pPreNode = nullptr;
	//尾部遍历
	pCurNode = back();
	while (pCurNode != HeadNode)
	{
		pPreNode = pCurNode->m_pPre;

		pCurNode->SetPos(pPreNode->m_nRow, pPreNode->m_nCol);

		pCurNode = pCurNode->m_pPre;
	}
	//设置头结点
	switch (Dir)
	{
	case Snake::UP:
		HeadNode->SetPos(HeadNode->m_nRow-1, HeadNode->m_nCol);
		break;
	case Snake::DOWN:
		HeadNode->SetPos(HeadNode->m_nRow+1, HeadNode->m_nCol);
		break;
	case Snake::RIGHT:
		HeadNode->SetPos(HeadNode->m_nRow, HeadNode->m_nCol+1);
		break;
	case Snake::LEFT:
		HeadNode->SetPos(HeadNode->m_nRow, HeadNode->m_nCol-1);
		break;
	}
	return 0;
}

int Snake::AddTail()
{
	SnakeNode* NewSnakeBody = new SnakeNode(0, 0);
	if (size()<=0)
	{
		if (NewSnakeBody != nullptr)
		{
			delete NewSnakeBody;
			NewSnakeBody = nullptr;
		}
		return -1;
	}
	else if (size() == 1)
	{
		switch (Dir)
		{
		case UP:
			NewSnakeBody->SetPos(HeadNode->m_nRow + 1, HeadNode->m_nCol);
			break;
		case DOWN:
			NewSnakeBody->SetPos(HeadNode->m_nRow - 1, HeadNode->m_nCol);
			break;
		case RIGHT:
			NewSnakeBody->SetPos(HeadNode->m_nRow, HeadNode->m_nCol+1);
			break;
		case LEFT:
			NewSnakeBody->SetPos(HeadNode->m_nRow, HeadNode->m_nCol-1);
			break;
		default:
			std::cout << "Error happens when addTail" << std::endl;
			break;
		}
		//把结点连接
		NewSnakeBody->m_pPre = HeadNode;
		HeadNode->m_pNext = NewSnakeBody;
		emplace_back(NewSnakeBody);
	}
	else 
	{
		SnakeNode *pLastOne = back();
		SnakeNode *pLastTwo = pLastOne->m_pPre;
		if (pLastOne->m_nRow==pLastTwo->m_nRow)
		{
			//左右跑
			if (pLastOne->m_nRow<pLastTwo->m_nRow)
			{
				//右边
				NewSnakeBody->SetPos(pLastOne->m_nRow , pLastOne->m_nCol-1);
			}
			//左边
			else
			{
				NewSnakeBody->SetPos(pLastOne->m_nRow, pLastOne->m_nCol+1);
			}
		}
		else if (pLastOne->m_nCol==pLastTwo->m_nCol)
		{
			if (pLastOne->m_nRow>pLastTwo->m_nRow)
			{
				//up
				NewSnakeBody->SetPos(pLastOne->m_nRow+1, pLastOne->m_nCol);
			}
			else
			{
				NewSnakeBody->SetPos(pLastOne->m_nRow-1, pLastOne->m_nCol);
			}

		}
		NewSnakeBody->m_pPre = pLastOne;
		pLastOne->m_pNext = NewSnakeBody;
		emplace_back(NewSnakeBody);
	}
	return 0;
}

int Snake::Show()
{
	system("cls");
	if (HeadNode== nullptr)
	{
		return -1;
	}
	Snake::iterator it = begin();
	while (it!=end())
	{
		SnakeNode *pNode = *it;
		if (it==begin())
		{
			pNode->ShowHead();//头
		}
		else
		{
			pNode->Show();//身体
		}

		it++;
	}
	printf("\r\n\r\n");
	return 0;
}

Snake::~Snake()
{
}
