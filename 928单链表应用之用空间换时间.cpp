#define _CRT_SECURE_NO_WARNINGS
// [2015] 用单链表保存n个整数，节点的结构为[data][link],且|data|<=n(n为正整数).
//        现要求设计一个时间复杂度尽可能高效的算法，对于链表中data的绝对值相等的节点，仅保留第一次出现的节点而删除其余绝对值相等的节点
//思想：用空间换时间
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
//删除绝对值相同的节点
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
		index = abs(p->next->data);//abs获取绝对值
		if (arr[index] == 0)//*(arr+index)也可以
		{
			arr[index] = 1;
			p = p->next;
		}
		else//p是要删除目标的前一个节点
		{
			Node* temp = p->next;//temp是临时创建的节点，指向要被删除的节点
			p->next = temp->next;
			free(temp);
		}
	}

	free(arr);//释放创造数组的空间
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