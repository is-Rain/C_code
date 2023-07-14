#pragma once

//����ͷ�ļ�
#include<stdio.h>

#include<string.h>

#include<stdlib.h>


#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 13
#define MAX_ADDR 30

//���͵�����
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼��Ϣ
typedef struct Contact
{
	PeoInfo data[MAX];
	int count;
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//����������

//������ϵ��
void AddContact(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//�޸���ϵ��
void ModifyContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);

//��ʾ��ϵ��
void ShowContact(Contact* pc);

//������ϵ��
void SortContact(Contact* pc);