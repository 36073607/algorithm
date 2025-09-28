#define _CRT_SECURE_NO_WARNINGS
//单链表应用 - 反转链表
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
//初始化，创建头节点
Node* initNode()
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = 0;
	p->next = NULL;

	return p;
}
//尾插法
// 查找最后一个元素
Node* findTail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)//注意一定是p->next != NULL, 不是p!=NULL（这样写最终结果返回的是NULL）
	{
		p = p->next;
	}
	return p;
}
//尾插法插入
Node* insertTail(Node* tail, ElemType e)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = NULL;
	tail->next = q;

	return q;
}
//遍历
void listNode(struct Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}

}
Node* reverseList(Node* L)
{
	Node* first = NULL;
	Node* second = L->next;
	Node* third = NULL;

	while (second != NULL)
	{
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}

	Node* head = initNode();//创建头节点
	head->next = first;

	return head;
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
	listNode(list);
	printf("\n");

	Node* reverse = reverseList(list);
	listNode(reverse);
	printf("\n");

	return 0;
}