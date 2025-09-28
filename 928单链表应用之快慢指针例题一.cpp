#define _CRT_SECURE_NO_WARNINGS
//������Ӧ��
// [2019] ����һ������ֻ������ͷָ��list,�ڲ��ı������ǰ���£����һ�������ܸ�Ч���㷨�����������е�����k��λ���ϵĽڵ�
//        �����ҳɹ����㷨����ýڵ��data���ֵ��������1;����ֻ����0
//������˫ָ�루����ָ�룩
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
//���ҵ�����k��Ԫ��
int FindNodeFS(Node* L, int k)
{
	Node* fast = L->next;
	Node* low = L->next;
	for (int i = 0; i < k; i++)//��ָ�����ָ������k������
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		low = low->next;
	}

	printf("%d\n", low->data);

	return 1;
}
int main()
{
	Node* list = initNode();
	Node* tail = findTail(list);
	tail = insertTail(tail, 10);
	tail = insertTail(tail, 20);
	tail = insertTail(tail, 30);
	listNode(list);
	printf("\n");

	FindNodeFS(list, 2);

	return 0;
}