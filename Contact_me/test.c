#define _CRT_SECURE_NO_WARNINGS 1.

#include"contact.h"

void menu()
{
	printf("**********************************************************************\n");
	printf("*********************1.add               2.del   *********************\n");
	printf("*********************3.search              4.modif   *****************\n");
	printf("*********************5.show              6.sort  *********************\n");
	printf("*********************0.exit                      *********************\n");
}
int main()
{
	Contact con;
	Init_Contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ������Ҫ���еĲ���:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1: 
			Add_Contact(&con);
			break;
		case 2:Del_Contact(&con);
			break;
		case 3:Search_Contact(&con);
			break;
		case 4:Modify_Contact(&con);
			break;
		case 5:Show_Contact(&con);
			break;
		case 6:Sort_Contact(&con);
			break;
		case 0:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("���벻��ȷ������������!\n");
			break;
		}

	} while (input);
}

