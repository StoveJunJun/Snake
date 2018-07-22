#include "setdisplay.h"
/*************************************
�������ܣ���ӡ�ַ�������̨�ƶ�λ��
nHigh: �߶�X�У�����
nWide: ���Y�У�����
pszChar: ��ӡ���ַ�����һ���ַ�ҲҪ���ַ�������ʽ��
wArr: ��ӡ�ַ������ԣ���ɫ
      ��ͨ��SetConsoleColor�����ñ���ɫ

ע��: ������ʾ�������Ϻ��һֱ����
      ��� 1 ��Ϊ 1 ������ �� ����Ӣ�ģ�
      ��ͨ�� ��Ⱥ� WIDTH_UNIT ������
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
��������: ���ô�����Ϣ
*pszWindewTitle: ��������
nHigh: �߶�X�У�����
nWide: ���Y�У�����
�ɹ�����ֵ: TRUE

ע�⣺��ֵ����̫�����������Ǹ߶�
      ��� 1 ��Ϊ 1 ������ �� ����Ӣ�ģ�
      ��ͨ�� ��Ⱥ� WIDTH_UNIT ������
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