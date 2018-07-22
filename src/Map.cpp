#include"Map.h"
Map::Map()
{
}
Map::~Map()
{
}
int Map::Init()
{
	CBgNode *pNode = nullptr;
	for (size_t nRow = 0; nRow < GAME_ROW; nRow++)
	{
		for (size_t nCol = 0; nCol < GAME_COL; nCol++)
		{
			if ((nRow==0||nRow==GAME_COL-1)||(nCol==0||nCol==GAME_COL-1))
			{
				pNode = new CBgNode(nRow, nCol, true);
			}
			else
			{
				pNode = new CBgNode(nRow, nCol, false);
			}
			emplace_back(pNode);
		}
	}
	return 0;
}

int Map::Show()
{
	CBgNode *pNode = nullptr;
	iterator it = begin();
	while (it != end())
	{
		pNode = *it;
		pNode->Show();
		it++;
	}
	return 0;
}