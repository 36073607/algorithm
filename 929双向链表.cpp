#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//双向链表
//在双向链表的节点中有两个指针域，一个指向直接后继，另一个指向直接前驱
typedef int ElemType;
typedef struct doubleNode
{
	ElemType data = 0;
	struct doubleNode* prev, * next;
}doubleNode;

//双向链表-初始化链表
doubleNode* d_initList()
{
	doubleNode* head = (doubleNode*)malloc(sizeof(doubleNode));
	head->data = 0;
	head->prev = 0;
	head->next = 0;
	return head;
}

//双向链表-头插法
void inserthead(doubleNode* L, ElemType e)
{
	doubleNode* p = (doubleNode*)malloc(sizeof(doubleNode));
	p->data = e;
	p->prev = L;
	p->next = L->next;
	if (L->next != NULL)
	{
		L->next->prev = p;
	}
	L->next = p;
}

//双向链表-遍历
void listNode(doubleNode* L)
{
	doubleNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

}

//双向链表-尾插法
doubleNode* insertTail(doubleNode* tail, ElemType e)
{
	doubleNode* p = (doubleNode*)malloc(sizeof * p);
	p->data = e;
	p->next = NULL;
	p->prev = tail;
	tail->next = p;

	return p;
}

//双向链表-在指定位置插入数据
void insertdoubleNode(doubleNode* L, int pos, ElemType e)
{
	doubleNode* p = L;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;//p为目标位置的前一个节点
		if (p == NULL || p->next == NULL)
			return;
	}
	doubleNode* q = (doubleNode*)malloc(sizeof * q);//q为要插入的元素
	q->data = e;
	q->next = p->next;
	q->prev = p;

	p->next = q;
	p->next->prev = q;
}

//双向链表-删除节点
void doubleNodeDel(doubleNode* L, int pos)
{
	doubleNode* p = L;
	for (int i = 0; i < pos - 1; i++)//这里找待删元素的前驱节点；这里找待删元素的后继节点同理
	{
		p = p->next;
		if (p == NULL || p->next == NULL)
			return;
	}
	doubleNode* q = p->next;//指向待删节点
	p->next = q->next;
	q->next->prev = p;
	free(q);
	q == NULL;
}
