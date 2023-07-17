#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


//��ʼ��ͨѶ¼
void Init_Contact(struct Contact* con)
{
	con->count = 0;
	memset(con->data, 0, sizeof(con->data));  //memset �ڴ����ú���
}
//������ϵ��
void Add_Contact(struct Contact* con)
{
	if (con->count == 100)
	{
		printf("ͨѶ¼����������ʧ�ܣ�");
		return 1;
	}
	printf("����������:>");
	scanf("%s",con->data[con->count].name);
	printf("����������:>");
	scanf("%d", &(con->data[con->count].age));
	printf("�������Ա�:>");
	scanf("%s",con->data[con->count].sex);
	printf("������绰����:>");
	scanf("%s", con->data[con->count].tele);
	printf("�������ͥסַ:>");
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
//ɾ����ϵ��
void Del_Contact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("����������ɾ������ϵ�˵�����:>");
	scanf("%s", name);
	int pos=Find_By_Name(con, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲����ڣ�\n");
	}
	int i = pos;
	for (i = pos; i < con->count-1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->count--;
	printf("ɾ���ɹ�\n");
}


//������ϵ��
void Search_Contact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("��������Ҫ���ҵ���ϵ�˵�����:>");
	scanf("%s", name);
	int pos=Find_By_Name(con, name);
	if (pos == -1)
	{
		printf("��Ҫ���ҵ���ϵ�˲�����\n");
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "������", "����:", "�Ա�:", "�绰����:", "��ͥסַ");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", con->data[pos].name,
		con->data[pos].age,
		con->data[pos].sex,
		con->data[pos],
		con->data[pos].addr);
}


//�޸���ϵ��
void Modify_Contact(struct Contact* con)
{
	char name[MAX_NAME];
	printf("��������Ҫ�޸ĵ���ϵ�˵�����:>");
	scanf("%s", name);
	int pos=Find_By_Name(con, name);
	if(pos==-1)
	{
		printf("��Ҫ�޸ĵ���ϵ�˲�����!\n");
	}
	printf("������Ҫ�޸ĵ�����:>");
	scanf("%s", con->data[pos].name);
	printf("������Ҫ�޸ĵ�����:>");
	scanf("%d", &(con->data[pos].age));
	printf("������Ҫ�޸ĵ��Ա�:>");
	scanf("%s", con->data[pos].sex);
	printf("������Ҫ�޸ĵĵ绰����:>");
	scanf("%s", con->data[pos].tele);
	printf("������Ҫ�޸ĵļ�ͥסַ:>");
	scanf("%s", con->data[pos].addr);
}

//��ʾ��ϵ��
void Show_Contact(struct Contact* con)
{
	int i = 0;
	for (i = 0; i < con->count; i++)
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n","������","����:","�Ա�:","�绰����:","��ͥסַ");
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

//����ϵ������
void Sort_Contact(struct Contact* con)
{
	//����������
	qsort(con->data, con->count, sizeof(PeoInfo), compare);
	printf("����ɹ���\n");
}
