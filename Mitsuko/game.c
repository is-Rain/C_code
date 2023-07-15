#define _CRE_SECURE_NO_WARNINGS 1

#include"game.h"

//初始化棋盘
void InitBoard(char Board[LINE][COLUMN], int line, int column)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < line; i++)
	{
		for (j = 0; j <column; j++)
		{
			Board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char Board[LINE][COLUMN], int line, int column)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf(" %c ", Board[i][j]);
			if (j < column - 1)
			{
				printf("|"); 
			}
		}
		printf("\n");
		if(i<line-1)
		{
			int j = 0;
			for (j = 0; j < column; j++)
			{
				printf("---"); 
				if (j < column - 1)
				{
					printf("|");
				}
			}
			printf("\n");

		}
	}
}

//玩家下棋
void PlayerMove(char Board[LINE][COLUMN], int line, int column)
{
	int x = 0; 
	int y = 0;
	printf("玩家下棋:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d %d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= line && y >= 1 && y <= column)
		{
			//判断该坐标是否被占用
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("已经下过该位置了，请重新输入:>\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}

//电脑下棋
void ComputerMove(char Board[LINE][COLUMN], int line, int column)
{
	printf("电脑下棋:>\n");
	while (1)
	{
		int x = rand() % line;
		int y = rand() % column;
		if (Board[x][y] == ' ')
		{
			Board[x][y] = '#';
			break;
		}
	}
}

// * --玩家赢   #  --电脑赢    Q --平局  C --继续
// 
//如果满了就返回1
//没满就返回0
int IsFull(char Board[LINE][COLUMN], int line, int column)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (Board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}


char IsWin(char Board[LINE][COLUMN], int line, int column)
{
	//行
	int i = 0;
	for (i = 0; i < LINE; i++)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][1] != ' ')
		{
			return Board[i][0];
		}
		//列
		int j = 0;
		if (Board[0][j] == Board[1][j] && Board[i][j] == Board[2][j] && Board[i][j] != ' ')
		{
			return Board[1][j];
		}
		if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[1][1] != ' ')
		{
			return Board[1][1];
		}
		if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[1][1] != ' ')
		{
			return Board[1][1];
		}
		//没有人赢就平局
		if (IsFull(Board, LINE, COLUMN))
		{
			return 'Q';
		}
	}
	//游戏继续
	return 'C';
}