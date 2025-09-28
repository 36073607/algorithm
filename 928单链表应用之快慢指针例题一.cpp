#define _CRT_SECURE_NO_WARNINGS
//单链表应用
// [2019] 假设一个链表只给出了头指针list,在不改变链表的前提下，设计一个尽可能高效的算法，查找链表中倒数第k个位置上的节点
//        若查找成功，算法输出该节点的data域的值，并返回1;否则，只返回0
//方法：双指针（快慢指针）
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
//查找倒数第k个元素
int FindNodeFS(Node* L, int k)
{
	Node* fast = L->next;
	Node* low = L->next;
	for (int i = 0; i < k; i++)//快指针比慢指针先走k个距离
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