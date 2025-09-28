#define _CRT_SECURE_NO_WARNINGS
//928单向循环链表-判断是否有环
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
//判断是否有环
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
	//listNode(list);  -->死循环
	if (isCycle(list))
	{
		printf("有环\n");
	}
	else
	{
		printf("无环\n");
	}

	return 0;
}