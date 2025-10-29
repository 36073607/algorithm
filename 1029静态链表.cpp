#define _CRT_SECURE_NO_WARNINGS
//静态链表：借助数组来描述链表
//优缺点大致同链表一样，但可以一次性开辟很大的空间，不用像链表一样一个一个插入
//同样，表长在一开始就确定了，后期无法修改
#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct List
{
	ElemType data;
	int cur;//游标
}List;
typedef List StaticList[MAXSIZE];

void initList(StaticList L)//-1表示表尾，-2表示空闲结点
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L[i].data = 0;
		L[i].cur = -2; // 所有节点初始化为空闲
	}
	// 头节点特殊处理
	L[0].cur = -1; // 头节点指向表尾
}

int listnum(StaticList L)
{
	int count = 0;
	int current = 0; // 从头节点开始
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
	for (int i = 1; i < MAXSIZE; i++) // 从1开始，0是头节点
	{
		if (L[i].cur == -2) // 找到空闲节点
		{
			return i;
		}
	}
	return -1; // 没有空闲节点
}

int Tailcreat(StaticList L, ElemType e)
{
	int free_idx = findFreeNode(L);
	if (free_idx == -1)
	{
		printf("没有空闲节点\n");
		return 0;
	}

	int tail_idx = getTail(L);
	L[free_idx].data = e;
	L[free_idx].cur = -1; // 新节点指向表尾

	if (tail_idx == 0) // 如果是空表
	{
		L[0].cur = free_idx; // 头节点指向新节点
	}
	else
	{
		L[tail_idx].cur = free_idx; // 尾节点指向新节点
	}

	return 1;
}

void insert(StaticList L, int sequence, ElemType e)//要插入的位序，不是数组下标
{
	if (sequence < 1 || sequence > listnum(L) + 1)
	{
		printf("输入位序有误\n");
		return;
	}

	int free_idx = findFreeNode(L);
	if (free_idx == -1)
	{
		printf("没有空闲节点\n");
		return;
	}

	int prev_idx = 0;//头节点
	int count = 0;//记录位序

	// 找到要插入位置的前一个节点
	while (count < sequence - 1)
	{
		prev_idx = L[prev_idx].cur;
		count++;
	}

	// 插入新节点
	L[free_idx].data = e;
	L[free_idx].cur = L[prev_idx].cur;
	L[prev_idx].cur = free_idx;
}

void listDelete(StaticList L, int sequence)
{
	if (sequence < 1 || sequence > listnum(L))
	{
		printf("输入位序有误\n");
		return;
	}

	int prev_idx = 0;//头节点
	int count = 0;//记录位序

	// 找到要删除位置的前一个节点
	while (count < sequence - 1)
	{
		prev_idx = L[prev_idx].cur;
		count++;
	}

	int del_idx = L[prev_idx].cur; // 要删除的节点
	L[prev_idx].cur = L[del_idx].cur; // 前一个节点指向被删除节点的后一个节点
	L[del_idx].cur = -2; // 被删除节点标记为空闲
}

void printlist(StaticList L)
{
	printf("链表内容: ");
	int current = L[0].cur; // 第一个有效节点
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

	// 测试尾插法
	Tailcreat(L, 1);
	Tailcreat(L, 7);
	Tailcreat(L, 6);
	printf("初始链表: ");
	printlist(L);

	// 测试插入
	insert(L, 2, 91);
	printf("在位置2插入91后: ");
	printlist(L);

	// 测试删除
	listDelete(L, 1);
	printf("删除位置1后: ");
	printlist(L);

	// 测试边界情况
	insert(L, 5, 100); // 应该会报错

	return 0;
}