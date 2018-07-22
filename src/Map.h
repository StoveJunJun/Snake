#pragma once
#include<vector>
#include"Snake.h"

struct CBgNode
{
	int m_nRow;
	int m_nCol;
	bool m_bIsVis;
	CBgNode(int nRow, int nCol, bool isVis)
	{
		m_nRow = nRow;
		m_nCol = nCol;
		m_bIsVis = isVis;
	}
	void Show()
	{
		if (m_bIsVis)
		{
			WriteChar(m_nRow, m_nCol, "¡ö", SetConsoleColor(COLOR_GREEN, COLOR_WHITE));
		}
	}
};
class Map :std::vector<CBgNode*>
{
public:
	Map();
	~Map();
	int Init();
	int Show();
};