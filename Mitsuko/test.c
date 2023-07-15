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
	InitBoard(Board,LINE,COLUMN); //��ʼ������
	DisplayBoard(Board, LINE, COLUMN);  //��ӡ����
	char ret = 0;
	while (1)
	{
		PlayerMove(Board, LINE, COLUMN);
		//�ж���Ӯ
		ret = IsWin(Board, LINE, COLUMN);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(Board, LINE, COLUMN);
		ComputerMove(Board, LINE, COLUMN);
		//�ж���Ӯ
		ret = IsWin(Board, LINE, COLUMN);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(Board, LINE, COLUMN);

	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL)); //�������������������
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		case 1:
			game();
			break;
		default: 
			printf("�������������ѡ��:>\n");
			break;
		}
	} while (input);

}
