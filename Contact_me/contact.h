#pragma once

#include<stdio.h>

#include<string.h>

#define MAX_CON 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//������ϵ�˽ṹ����Ϣ
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//����ͨѶ¼�ṹ��
typedef struct Contact
{
	PeoInfo data[MAX_CON];  //PeoInfo���͵����飬�����PeoInfo���͵�����
	int count;
}Contact;

//��ʼ��ͨѶ¼
void Init_Contact(struct Contact* con);


//������������

//������ϵ��
void Add_Contact(struct Contact* con);

//ɾ����ϵ��
void Del_Contact(struct Contact* con);

//������ϵ��
void Search_Contact(struct Contact* con);

//�޸���ϵ��
void Modify_Contact(struct Contact* con);

//��ʾ��ϵ��
void Show_Contact(struct Contact* con);

//��ͨѶ¼����
void Sort_Contact(struct Contact* con);