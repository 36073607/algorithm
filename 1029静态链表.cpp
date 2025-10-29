#define _CRT_SECURE_NO_WARNINGS
//��̬����������������������
//��ȱ�����ͬ����һ����������һ���Կ��ٺܴ�Ŀռ䣬����������һ��һ��һ������
//ͬ��������һ��ʼ��ȷ���ˣ������޷��޸�
#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct List
{
	ElemType data;
	int cur;//�α�
}List;
typedef List StaticList[MAXSIZE];

void initList(StaticList L)//-1��ʾ��β��-2��ʾ���н��
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L[i].data = 0;
		L[i].cur = -2; // ���нڵ��ʼ��Ϊ����
	}
	// ͷ�ڵ����⴦��
	L[0].cur = -1; // ͷ�ڵ�ָ���β
}

int listnum(StaticList L)
{
	int count = 0;
	int current = 0; // ��ͷ�ڵ㿪ʼ
	while (L[current].cur != -1)
	{
		count++;
		current = L[current].cur;
	}
	return count;
}

int getTail(StaticList L)
{
	int current = 0;
	while (L[current].cur != -1)
	{
		current = L[current].cur;
	}
	return current;
}

int findFreeNode(StaticList L)
{
	for (int i = 1; i < MAXSIZE; i++) // ��1��ʼ��0��ͷ�ڵ�
	{
		if (L[i].cur == -2) // �ҵ����нڵ�
		{
			return i;
		}
	}
	return -1; // û�п��нڵ�
}

int Tailcreat(StaticList L, ElemType e)
{
	int free_idx = findFreeNode(L);
	if (free_idx == -1)
	{
		printf("û�п��нڵ�\n");
		return 0;
	}

	int tail_idx = getTail(L);
	L[free_idx].data = e;
	L[free_idx].cur = -1; // �½ڵ�ָ���β

	if (tail_idx == 0) // ����ǿձ�
	{
		L[0].cur = free_idx; // ͷ�ڵ�ָ���½ڵ�
	}
	else
	{
		L[tail_idx].cur = free_idx; // β�ڵ�ָ���½ڵ�
	}

	return 1;
}

void insert(StaticList L, int sequence, ElemType e)//Ҫ�����λ�򣬲��������±�
{
	if (sequence < 1 || sequence > listnum(L) + 1)
	{
		printf("����λ������\n");
		return;
	}

	int free_idx = findFreeNode(L);
	if (free_idx == -1)
	{
		printf("û�п��нڵ�\n");
		return;
	}

	int prev_idx = 0;//ͷ�ڵ�
	int count = 0;//��¼λ��

	// �ҵ�Ҫ����λ�õ�ǰһ���ڵ�
	while (count < sequence - 1)
	{
		prev_idx = L[prev_idx].cur;
		count++;
	}

	// �����½ڵ�
	L[free_idx].data = e;
	L[free_idx].cur = L[prev_idx].cur;
	L[prev_idx].cur = free_idx;
}

void listDelete(StaticList L, int sequence)
{
	if (sequence < 1 || sequence > listnum(L))
	{
		printf("����λ������\n");
		return;
	}

	int prev_idx = 0;//ͷ�ڵ�
	int count = 0;//��¼λ��

	// �ҵ�Ҫɾ��λ�õ�ǰһ���ڵ�
	while (count < sequence - 1)
	{
		prev_idx = L[prev_idx].cur;
		count++;
	}

	int del_idx = L[prev_idx].cur; // Ҫɾ���Ľڵ�
	L[prev_idx].cur = L[del_idx].cur; // ǰһ���ڵ�ָ��ɾ���ڵ�ĺ�һ���ڵ�
	L[del_idx].cur = -2; // ��ɾ���ڵ���Ϊ����
}

void printlist(StaticList L)
{
	printf("��������: ");
	int current = L[0].cur; // ��һ����Ч�ڵ�
	while (current != -1)
	{
		printf("%d ", L[current].data);
		current = L[current].cur;
	}
	printf("\n");
}

int main()
{
	StaticList L;
	initList(L);

	// ����β�巨
	Tailcreat(L, 1);
	Tailcreat(L, 7);
	Tailcreat(L, 6);
	printf("��ʼ����: ");
	printlist(L);

	// ���Բ���
	insert(L, 2, 91);
	printf("��λ��2����91��: ");
	printlist(L);

	// ����ɾ��
	listDelete(L, 1);
	printf("ɾ��λ��1��: ");
	printlist(L);

	// ���Ա߽����
	insert(L, 5, 100); // Ӧ�ûᱨ��

	return 0;
}