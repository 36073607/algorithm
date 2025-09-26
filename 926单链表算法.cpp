#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//单链表
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
//初始化
Node* intiList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
//头插法
void insertHead(struct Node* L, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
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
//尾插法
// 先获取尾节点地址
Node* gettail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)
		p = p->next;
	return p;
}
// 进行尾插法
Node* insertTail(Node* tail, ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;

	return p;//p是新的尾节点
}
//5.单链表-在指定位置插入数据
void insertNode(Node* L, int pos, ElemType e)
{
	//从第一个节点处是pos=1,而不是头结点处pos=1

	Node* p = L;//用来保存插入位置的前驱节点
	int i = 0;//遍历链表找到插入位置的前驱节点
	while (i < pos - 1)//循环到你想要插入这个位置的前一个位置
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("只有一个头节点，无法插入新节点\n");
			return;
		}

	}
	Node* q = (Node*)malloc(sizeof(Node));//要插入的新节点
	q->data = e;
	q->next = p->next;
	p->next = q;
}
//单链表-删除节点
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
			printf("该节点不存在\n");
			return;
		}
	}

	//p->next = (p->next)->next;  我自己写的

	Node* q = p->next;//创造q指向要删除的元素
	p->next = q->next;//要删除的元素的前驱 指向 要删除元素的后继
	free(q);//别忘了释放堆内存空间
}
//7.获取链表长度
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
//8.单链表-释放链表   这里指 把头节点之后的所有内容全释放掉，头节点保留
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
	Node* list = intiList();//头节点
	insertHead(list, 10);
	insertHead(list, 20);
	insertHead(list, 30);
	listNode(list);
	printf("\n");

	Node* list2 = intiList();//第二个头节点
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
