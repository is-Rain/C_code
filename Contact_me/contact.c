#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


//初始化通讯录
void Init_Contact(struct Contact* con)
{
	con->count = 0;
	memset(con->data, 0, sizeof(con->data));  //memset 内存设置函数
}
//增加联系人
void Add_Contact(struct Contact* con)
{
	if (con->count == 100)
	{
		printf("通讯录已满，增加失败！");
		return 1;
	}
	printf("请输入姓名:>");
	scanf("%s",con->data[con->count].name);
	printf("请输入年龄:>");
	scanf("%d", &(con->data[con->count].age));
	printf("请输入性别:>");
	scanf("%s",con->data[con->count].sex);
	printf("请输入电话号码:>");
	scanf("%s", con->data[con->count].tele);
	printf("请输入家庭住址:>");
	scanf("%s", con->data[con->count].addr);
	con->count++;
}


static int Find_By_Name(struct Contact* con, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < con->count; i++)
	{
		if (strcmp(con->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void Del_Contact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("请输入你想删除的联系人的姓名:>");
	scanf("%s", name);
	int pos=Find_By_Name(con, name);
	if (pos == -1)
	{
		printf("要删除的人不存在！\n");
	}
	int i = pos;
	for (i = pos; i < con->count-1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->count--;
	printf("删除成功\n");
}


//查找联系人
void Search_Contact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("请输入你要查找的联系人的姓名:>");
	scanf("%s", name);
	int pos=Find_By_Name(con, name);
	if (pos == -1)
	{
		printf("您要查找的联系人不存在\n");
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名：", "年龄:", "性别:", "电话号码:", "家庭住址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", con->data[pos].name,
		con->data[pos].age,
		con->data[pos].sex,
		con->data[pos],
		con->data[pos].addr);
}


//修改联系人
void Modify_Contact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("请输入你要修改的联系人的姓名:>");
	scanf("%s", name);
	int pos=Find_By_Name(con, name);
	if(pos==-1)
	{
		printf("您要修改的联系人不存在!\n");
	}
	printf("请输入要修改的姓名:>");
	scanf("%s", con->data[pos].name);
	printf("请输入要修改的年龄:>");
	scanf("%d", &(con->data[pos].age));
	printf("请输入要修改的性别:>");
	scanf("%s", con->data[pos].sex);
	printf("请输入要修改的电话号码:>");
	scanf("%s", con->data[pos].tele);
	printf("请输入要修改的家庭住址:>");
	scanf("%s", con->data[pos].addr);
}

//显示联系人
void Show_Contact(struct Contact* con)
{
	int i = 0;
	for (i = 0; i < con->count; i++)
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","姓名：","年龄:","性别:","电话号码:","家庭住址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", con->data[i].name,
			con->data[i].age,
			con->data[i].sex,
			con->data[i],
			con->data[i].addr);
	}
}



char* compare(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

//给联系人排序
void Sort_Contact(struct Contact* con)
{
	//按姓名排序
	qsort(con->data, con->count, sizeof(PeoInfo), compare);
	printf("排序成功！\n");
}
