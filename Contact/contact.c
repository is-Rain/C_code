#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	pc->count = 0;
	memset(pc->data,0,sizeof(pc->data));
}

//����
void AddContact(Contact* pc)
{
	if (pc->count == 100)
	{
		return;
	}
	printf("����������:>");
	scanf("%s", pc->data[pc->count].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰����:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ͥסַ:>");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("��ϵ�����ӳɹ�\n");
}

//��ʾ
void ShowContact(Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰����", "��ͥסַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
			                                        pc->data[i].age,
			                                        pc->data[i].sex,
			                                        pc->data[i].tele,
			                                        pc->data[i].addr);
	}
}

//������ϵ��
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

//ɾ��ָ����ϵ����Ϣ
void DelContact(Contact* pc)
{
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����ϵ�˿���ɾ����");
		return;
	}
	char name[MAX_NAME];
	printf("������Ҫɾ��ָ����ϵ�˵�����:>");
	scanf("%s", name);
	//1.�Ȳ���ָ����ϵ��
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("�����ҵ���ϵ�˲�����");
		return;
	}
	//2.����ɾ��ָ����ϵ�ˣ��������Ϣ����ǰ�漸�����Ϣ��
	int i = 0;
	for (i = pos; i < pc->count-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");	
}

//�޸�ָ����ϵ�˵���Ϣ
void ModifyContact(Contact* pc)
{
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��");
	}
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("��Ҫ�޸ĵ���ϵ�˲�����");
		return;
	}
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf("%s", pc->data[pos].name);
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf("%d", &(pc->data[pos].age));
	printf("������Ҫ�޸ĵ���ϵ���Ա�:>");
	scanf("%s", pc->data[pos].sex);
	printf("������Ҫ�޸ĵ���ϵ�˵绰����:>");
	scanf("%s", pc->data[pos].tele);
	printf("������Ҫ�޸ĵ���ϵ�˼�ͥסַ:>");
	scanf("%s", pc->data[pos].addr);
	printf("�޸ĳɹ�\n");
}

//����ָ����ϵ��
void SearchContact(Contact* pc)
{
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��");
	}
	char name[MAX_NAME] = { 0 };
	printf("��������Ҫ������ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("��Ҫ���ҵ���ϵ�˲�����");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰����", "��ͥסַ");
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
	printf("����ɹ�");
}
