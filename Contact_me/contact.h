#pragma once

#include<stdio.h>

#include<string.h>

#define MAX_CON 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//创建联系人结构体信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//创建通讯录结构体
typedef struct Contact
{
	PeoInfo data[MAX_CON];  //PeoInfo类型的数组，存的是PeoInfo类型的数据
	int count;
}Contact;

//初始化通讯录
void Init_Contact(struct Contact* con);


//声明各个函数

//增加联系人
void Add_Contact(struct Contact* con);

//删除联系人
void Del_Contact(struct Contact* con);

//查找联系人
void Search_Contact(struct Contact* con);

//修改联系人
void Modify_Contact(struct Contact* con);

//显示联系人
void Show_Contact(struct Contact* con);

//给通讯录排序
void Sort_Contact(struct Contact* con);