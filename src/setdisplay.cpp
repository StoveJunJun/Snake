#include "setdisplay.h"
/*************************************
函数功能：打印字符到控制台制定位置
nHigh: 高度X行，行数
nWide: 宽度Y列，列数
pszChar: 打印的字符串（一个字符也要用字符串的形式）
wArr: 打印字符的属性：颜色
      可通过SetConsoleColor宏设置背景色

注意: 数据显示到界面上后会一直存在
      宽度 1 列为 1 个汉字 或 两个英文，
      可通过 宽度宏 WIDTH_UNIT 来控制
*************************************/
void WriteChar(int nHigh , int nWide , const char* pszChar , WORD wArr)
{
	CONSOLE_CURSOR_INFO cii;
	cii.dwSize = 1;
	cii.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE) , &cii);
	COORD loc;
	loc.X = nWide * (WIDTH_UNIT);
	loc.Y = nHigh;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , loc);
	printf(pszChar);
}


/*************************************
函数功能: 设置窗口信息
*pszWindewTitle: 窗口名称
nHigh: 高度X行，行数
nWide: 宽度Y列，列数
成功返回值: TRUE

注意：数值设置太大会出错，尤其是高度
      宽度 1 列为 1 个汉字 或 两个英文，
      可通过 宽度宏 WIDTH_UNIT 来控制
*************************************/
BOOL SetWindowSize(const char *pszWindowTitle , int nHight, int nWide)
{
	// Title
  nWide *= (WIDTH_UNIT);
  // nHight -= 1;
  nWide -= 1;
	SetConsoleTitleA(pszWindowTitle);
	HANDLE hStdin , hStdOut;
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// get max console window size
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD BufferSize = { pos.X , pos.Y };
	// set console buffer size
	if(!SetConsoleScreenBufferSize(hStdOut , BufferSize)){
		// set console buffer size FALSE
		printf("buffer err(%d,%d)%d\n" , BufferSize.X , BufferSize.Y , GetLastError());
		return FALSE;
	}
	SMALL_RECT srctWindow = { 0 , 0 , nWide , nHight };
	if(!SetConsoleWindowInfo(hStdOut , TRUE , &srctWindow)){
		// set console window size FALSE
		printf("size err %d\n" , GetLastError());
		return FALSE;
	}
	COORD Buffer = { nWide + 1 , nHight + 1 };
	// set console buffer size
	if(!SetConsoleScreenBufferSize(hStdOut , Buffer)){
		// set console buffer size FALSE
		printf("buffer err(%d, %d)%d\n" , BufferSize.X , BufferSize.Y , GetLastError());
		return FALSE;
	}
	return TRUE;
}

void SetCursorPosition(const int x, const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}