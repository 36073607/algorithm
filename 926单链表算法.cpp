#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//������
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
//��ʼ��
Node* intiList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
//ͷ�巨
void insertHead(struct Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
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
//β�巨
// �Ȼ�ȡβ�ڵ��ַ
Node* gettail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)
		p = p->next;
	return p;
}
// ����β�巨
Node* insertTail(Node* tail, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;

	return p;//p���µ�β�ڵ�
}
//5.������-��ָ��λ�ò�������
void insertNode(Node* L, int pos, ElemType e)
{
	//�ӵ�һ���ڵ㴦��pos=1,������ͷ��㴦pos=1

	Node* p = L;//�����������λ�õ�ǰ���ڵ�
	int i = 0;//���������ҵ�����λ�õ�ǰ���ڵ�
	while (i < pos - 1)//ѭ��������Ҫ�������λ�õ�ǰһ��λ��
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("ֻ��һ��ͷ�ڵ㣬�޷������½ڵ�\n");
			return;
		}

	}
	Node* q = (Node*)malloc(sizeof(Node));//Ҫ������½ڵ�
	q->data = e;
	q->next = p->next;
	p->next = q;
}
//������-ɾ���ڵ�
void deleteNode(Node* L, int pos)
{
	Node* p = L;
	int i = 0;
	while (i < pos - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("�ýڵ㲻����\n");
			return;
		}
	}

	//p->next = (p->next)->next;  ���Լ�д��

	Node* q = p->next;//����qָ��Ҫɾ����Ԫ��
	p->next = q->next;//Ҫɾ����Ԫ�ص�ǰ�� ָ�� Ҫɾ��Ԫ�صĺ��
	free(q);//�������ͷŶ��ڴ�ռ�
}
//7.��ȡ������
int listLength(Node* L)
{
	Node* p = L->next;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}
//8.������-�ͷ�����   ����ָ ��ͷ�ڵ�֮�����������ȫ�ͷŵ���ͷ�ڵ㱣��
void freeList(Node* L)
{
	Node* p = L->next;
	Node* q = NULL;
	int i = 0;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}
int main()
{
	Node* list = intiList();//ͷ�ڵ�
	insertHead(list, 10);
	insertHead(list, 20);
	insertHead(list, 30);
	listNode(list);
	printf("\n");

	Node* list2 = intiList();//�ڶ���ͷ�ڵ�
	Node* tail = gettail(list2);
	tail = insertTail(tail, 13);
	tail = insertTail(tail, 78);
	tail = insertTail(tail, 91);
	listNode(list2);
	printf("\n");

	insertNode(list2, 2, 9);
	listNode(list2);
	printf("\n");

	deleteNode(list2, 1);
	listNode(list2);
	printf("\n");

	printf("%d\n", listLength(list));

	freeList(list2);
	printf("%d\n", listLength(list2));

	return 0;
}
