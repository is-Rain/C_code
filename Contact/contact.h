#pragma once

//声明头文件
#include<stdio.h>

#include<string.h>

#include<stdlib.h>


#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 13
#define MAX_ADDR 30

//类型的声明
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//通讯录信息
typedef struct Contact
{
	PeoInfo data[MAX];
	int count;
}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//函数的声明

//增加联系人
void AddContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//显示联系人
void ShowContact(Contact* pc);

//排序联系人
void SortContact(Contact* pc);