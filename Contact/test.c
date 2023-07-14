#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void menu()
{
	printf("*****************************************************************\n");
	printf("******************   1.增加           2.删除   ******************\n");
	printf("******************   3.查找           4.修改   ******************\n");
	printf("******************   5.显示           6.排序   ******************\n");
	printf("******************   0.退出                    ******************\n");
	printf("*****************************************************************\n");
}
int main()
{
	Contact con;

	//初始化通讯录
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请输入您要进行的选项：>");
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
		case 0: printf("已退出，欢迎再次使用\n");
			break;
		default:printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}