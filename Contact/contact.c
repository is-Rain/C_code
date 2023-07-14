#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


//初始化通讯录
void InitContact(Contact* pc)
{
	pc->count = 0;
	memset(pc->data,0,sizeof(pc->data));
}

//增加
void AddContact(Contact* pc)
{
	if (pc->count == 100)
	{
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话号码:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入家庭住址:>");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("联系人增加成功\n");
}

//显示
void ShowContact(Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话号码", "家庭住址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
			                                        pc->data[i].age,
			                                        pc->data[i].sex,
			                                        pc->data[i].tele,
			                                        pc->data[i].addr);
	}
}

//查找联系人
int FindByName(Contact* pc,char* name)
{
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//删除指定联系人信息
void DelContact(Contact* pc)
{
	if (pc->count == 0)
	{
		printf("通讯录为空，没有联系人可以删除！");
		return;
	}
	char name[MAX_NAME];
	printf("请输入要删除指定联系人的名字:>");
	scanf("%s", name);
	//1.先查找指定联系人
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("您查找的联系人不存在");
		return;
	}
	//2.真正删除指定联系人（后面的信息覆盖前面几年的信息）
	int i = 0;
	for (i = pos; i < pc->count-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");	
}

//修改指定联系人的信息
void ModifyContact(Contact* pc)
{
	if (pc->count == 0)
	{
		printf("通讯录为空");
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的联系人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("您要修改的联系人不存在");
		return;
	}
	printf("请输入要修改的联系人姓名:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入要修改的联系人年龄:>");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入要修改的联系人性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入要修改的联系人电话号码:>");
	scanf("%s", pc->data[pos].tele);
	printf("请输入要修改的联系人家庭住址:>");
	scanf("%s", pc->data[pos].addr);
	printf("修改成功\n");
}

//查找指定联系人
void SearchContact(Contact* pc)
{
	if (pc->count == 0)
	{
		printf("通讯录为空");
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入您要查找联系人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("您要查找的联系人不存在");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话号码", "家庭住址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
		                                        pc->data[pos].age,
		                                        pc->data[pos].sex,
		                                        pc->data[pos].tele,
		                                        pc->data[pos].addr);
}

int com_peo_by_nmae(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
void SortContact(Contact* pc)
{
	qsort(pc->data, pc->count, sizeof(PeoInfo), com_peo_by_nmae);
	printf("排序成功");
}
