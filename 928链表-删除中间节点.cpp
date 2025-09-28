#define _CRT_SECURE_NO_WARNINGS
//单链表应用 - 删除中间节点
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
//删除中间节点
void delMiddleNode(Node* head)
{
	Node* fast = head->next;
	Node* slow = head;//让慢指针在头节点，使其最终在中间指针的前一个
	while (fast != NULL && fast->next != NULL)//fast!=NULL限制了链表为偶数，fast->next!=NULL限制了链表为奇数
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