#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("********************************************\n");
	printf("***********     1.start      ***************\n");
	printf("***********     0.exit       ***************\n");
	printf("********************************************\n");

}

void game()
{
	char Board[LINE][COLUMN];
	InitBoard(Board,LINE,COLUMN); //初始化棋盘
	DisplayBoard(Board, LINE, COLUMN);  //打印棋盘
	char ret = 0;
	while (1)
	{
		PlayerMove(Board, LINE, COLUMN);
		//判断输赢
		ret = IsWin(Board, LINE, COLUMN);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(Board, LINE, COLUMN);
		ComputerMove(Board, LINE, COLUMN);
		//判断输赢
		ret = IsWin(Board, LINE, COLUMN);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(Board, LINE, COLUMN);

	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL)); //设置随机数的生成起点的
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏；\n");
			break;
		case 1:
			game();
			break;
		default: 
			printf("输入错误，请重新选择:>\n");
			break;
		}
	} while (input);

}
