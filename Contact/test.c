#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void menu()
{
	printf("*****************************************************************\n");
	printf("******************   1.����           2.ɾ��   ******************\n");
	printf("******************   3.����           4.�޸�   ******************\n");
	printf("******************   5.��ʾ           6.����   ******************\n");
	printf("******************   0.�˳�                    ******************\n");
	printf("*****************************************************************\n");
}
int main()
{
	Contact con;

	//��ʼ��ͨѶ¼
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("��������Ҫ���е�ѡ�>");
		scanf("%d", &input);
		switch (input) 
		{
		case 1:AddContact(&con);
			break;
		case 2:DelContact(&con);
			break;
		case 3:SearchContact(&con);
			break;
		case 4:ModifyContact(&con);
			break;
		case 5:ShowContact(&con);
			break;
		case 6:SortContact(&con);
			break;
		case 0: printf("���˳�����ӭ�ٴ�ʹ��\n");
			break;
		default:printf("�����������������\n");
			break;
		}
	} while (input);
}