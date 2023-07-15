#define _CRE_SECURE_NO_WARNINGS 1

#include"game.h"

//��ʼ������
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

//��ӡ����
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

//�������
void PlayerMove(char Board[LINE][COLUMN], int line, int column)
{
	int x = 0; 
	int y = 0;
	printf("�������:>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d %d", &x, &y);
		//�ж�����ĺϷ���
		if (x >= 1 && x <= line && y >= 1 && y <= column)
		{
			//�жϸ������Ƿ�ռ��
			if (Board[x - 1][y - 1] == ' ')
			{
				Board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�Ѿ��¹���λ���ˣ�����������:>\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}

//��������
void ComputerMove(char Board[LINE][COLUMN], int line, int column)
{
	printf("��������:>\n");
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

// * --���Ӯ   #  --����Ӯ    Q --ƽ��  C --����
// 
//������˾ͷ���1
//û���ͷ���0
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
	//��
	int i = 0;
	for (i = 0; i < LINE; i++)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][1] != ' ')
		{
			return Board[i][0];
		}
		//��
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
		//û����Ӯ��ƽ��
		if (IsFull(Board, LINE, COLUMN))
		{
			return 'Q';
		}
	}
	//��Ϸ����
	return 'C';
}