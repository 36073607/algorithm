#define _CRT_SECURE_NO_WARNINGS
//������Ӧ�� - ɾ���м�ڵ�
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
//ɾ���м�ڵ�
void delMiddleNode(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;//����ָ����ͷ�ڵ㣬ʹ���������м�ָ���ǰһ��
	while (fast != NULL && fast->next != NULL)//fast!=NULL����������Ϊż����fast->next!=NULL����������Ϊ����
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* temp = slow->next;
	slow->next = temp->next;
	free(temp);
}

int main()
{
	Node* list = initNode();
	Node* tail = findTail(list);
	tail = insertTail(tail, 1);
	tail = insertTail(tail, 2);
	tail = insertTail(tail, 3);
	tail = insertTail(tail, 4);
	tail = insertTail(tail, 5);
	tail = insertTail(tail, 6);
	listNode(list);
	printf("\n");

	delMiddleNode(list);
	listNode(list);
	printf("\n");

	return 0;
}