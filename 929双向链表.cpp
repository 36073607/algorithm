#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//˫������
//��˫������Ľڵ���������ָ����һ��ָ��ֱ�Ӻ�̣���һ��ָ��ֱ��ǰ��
typedef int ElemType;
typedef struct doubleNode
{
	ElemType data = 0;
	struct doubleNode* prev, * next;
}doubleNode;

//˫������-��ʼ������
doubleNode* d_initList()
{
	doubleNode* head = (doubleNode*)malloc(sizeof(doubleNode));
	head->data = 0;
	head->prev = 0;
	head->next = 0;
	return head;
}

//˫������-ͷ�巨
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

//˫������-����
void listNode(doubleNode* L)
{
	doubleNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

}

//˫������-β�巨
doubleNode* insertTail(doubleNode* tail, ElemType e)
{
	doubleNode* p = (doubleNode*)malloc(sizeof * p);
	p->data = e;
	p->next = NULL;
	p->prev = tail;
	tail->next = p;

	return p;
}

//˫������-��ָ��λ�ò�������
void insertdoubleNode(doubleNode* L, int pos, ElemType e)
{
	doubleNode* p = L;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;//pΪĿ��λ�õ�ǰһ���ڵ�
		if (p == NULL || p->next == NULL)
			return;
	}
	doubleNode* q = (doubleNode*)malloc(sizeof * q);//qΪҪ�����Ԫ��
	q->data = e;
	q->next = p->next;
	q->prev = p;

	p->next = q;
	p->next->prev = q;
}

//˫������-ɾ���ڵ�
void doubleNodeDel(doubleNode* L, int pos)
{
	doubleNode* p = L;
	for (int i = 0; i < pos - 1; i++)//�����Ҵ�ɾԪ�ص�ǰ���ڵ㣻�����Ҵ�ɾԪ�صĺ�̽ڵ�ͬ��
	{
		p = p->next;
		if (p == NULL || p->next == NULL)
			return;
	}
	doubleNode* q = p->next;//ָ���ɾ�ڵ�
	p->next = q->next;
	q->next->prev = p;
	free(q);
	q == NULL;
}
