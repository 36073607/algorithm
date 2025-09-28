#define _CRT_SECURE_NO_WARNINGS
//928����ѭ������-�ж��Ƿ��л�
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
//��ʼ��������ͷ�ڵ�
Node* initNode()
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = 0;
	p->next = NULL;

	return p;
}
//β�巨
// �������һ��Ԫ��
Node* findTail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)//ע��һ����p->next != NULL, ����p!=NULL������д���ս�����ص���NULL��
	{
		p = p->next;
	}
	return p;
}
//β�巨����
Node* insertTail(Node* tail, ElemType e)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = NULL;
	tail->next = q;

	return q;
}
//����
void listNode(struct Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

}
//�ж��Ƿ��л�
int isCycle(Node* head)
{
	Node* fast = head;
	Node* slow = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	Node* list = initNode();
	Node* tail = findTail(list);
	tail = insertTail(tail, 1);
	tail = insertTail(tail, 2);
	tail = insertTail(tail, 3);
	Node* three = tail;
	tail = insertTail(tail, 4);
	tail = insertTail(tail, 5);
	tail = insertTail(tail, 6);
	tail = insertTail(tail, 7);
	tail = insertTail(tail, 8);
	tail->next = tail;
	//listNode(list);  -->��ѭ��
	if (isCycle(list))
	{
		printf("�л�\n");
	}
	else
	{
		printf("�޻�\n");
	}

	return 0;
}