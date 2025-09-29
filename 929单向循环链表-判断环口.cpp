#define _CRT_SECURE_NO_WARNINGS
//929����ѭ������-�жϻ���
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
//�жϻ���
Node* findEntrance(Node* L)
{
	Node* fast = L;
	Node* slow = L;
	int count = 1;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			fast = fast->next;
			while (fast != slow)
			{
				fast = fast->next;
				count++;
			}

			fast = L;
			slow = L;

			for (int i = 0; i < count; i++)
			{
				fast = fast->next;
			}
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}

			return fast;

		}

	}

	return NULL;

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
	tail->next = three;

	Node* p = findEntrance(list);
	printf("%d\n", p->data);

	return 0;
}