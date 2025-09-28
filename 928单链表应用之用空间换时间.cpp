#define _CRT_SECURE_NO_WARNINGS
// [2015] �õ�������n���������ڵ�ĽṹΪ[data][link],��|data|<=n(nΪ������).
//        ��Ҫ�����һ��ʱ�临�ӶȾ����ܸ�Ч���㷨������������data�ľ���ֵ��ȵĽڵ㣬��������һ�γ��ֵĽڵ��ɾ���������ֵ��ȵĽڵ�
//˼�룺�ÿռ任ʱ��
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
//ɾ������ֵ��ͬ�Ľڵ�
void removeNode(Node* L, int n)
{
	Node* p = L;
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	int index = 0;
	for (int i = 0; i < n + 1; i++)
	{
		*(arr + i) = 0;
	}
	while (p->next != NULL)
	{
		index = abs(p->next->data);//abs��ȡ����ֵ
		if (arr[index] == 0)//*(arr+index)Ҳ����
		{
			arr[index] = 1;
			p = p->next;
		}
		else//p��Ҫɾ��Ŀ���ǰһ���ڵ�
		{
			Node* temp = p->next;//temp����ʱ�����Ľڵ㣬ָ��Ҫ��ɾ���Ľڵ�
			p->next = temp->next;
			free(temp);
		}
	}

	free(arr);//�ͷŴ�������Ŀռ�
}

int main()
{
	Node* list = initNode();
	Node* tail = findTail(list);
	tail = insertTail(tail, 21);
	tail = insertTail(tail, -15);
	tail = insertTail(tail, -15);
	tail = insertTail(tail, 7);
	tail = insertTail(tail, 15);
	listNode(list);
	printf("\n");

	removeNode(list, 21);
	listNode(list);
	printf("\n");

	return 0;
}