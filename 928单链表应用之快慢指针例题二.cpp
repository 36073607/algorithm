#define _CRT_SECURE_NO_WARNINGS
// [2012] 假定采用带头节点的单链表保存单词，当两个单词有相同的后缀时，则可共享相同的后缀存储空间
//        设str1和str2分别指向两个单词所在单链表的头节点，设计一个时间上尽可能高效的算法，找出由str1和str2所指向两个链表共同后缀的起始位置
//方法：双指针（快慢指针）
#include <iostream>
using namespace std;
typedef char ElemType;
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
		printf("%c ", p->data);
		p = p->next;
	}

}
//初始化通用后缀链表
Node* initListWithElem(ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = NULL;

	return p;
}
//链表相连
Node* insertTailWithNode(Node* tail, Node* node)
{
	tail->next = node;
	node->next = NULL;
	return node;
}
//查找共同后缀
// 求出链表长度
int listLength(Node* L)
{
	Node* p = L->next;
	int length = 0;
	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	return length;
}
// 查找
Node* findIntersectionNode(Node* a, Node* b)
{
	if (a == NULL || b == NULL)
		return NULL;

	int m = listLength(a);
	int n = listLength(b);
	Node* fast = NULL;
	Node* slow = NULL;
	int step = 0;//两个单词之间的差值，可以用于快指针先走的步数
	if (m >= n)
	{
		step = m - n;
		fast = a->next;
		slow = b->next;
	}
	else
	{
		step = n - m;
		fast = b->next;
		slow = a->next;
	}
	for (int i = 0; i < step; i++)
	{
		fast = fast->next;
	}
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast;//这里return slow 也一样，因为此时二者位置一样

}

int main()
{
	Node* listA = initNode();
	Node* listB = initNode();

	Node* tailA = findTail(listA);
	Node* tailB = findTail(listB);

	tailA = insertTail(tailA, 'l');
	tailA = insertTail(tailA, 'o');
	tailA = insertTail(tailA, 'a');
	tailA = insertTail(tailA, 'd');
	tailB = insertTail(tailB, 'b');
	tailB = insertTail(tailB, 'e');

	Node* nodeI = initListWithElem('i');
	tailA = insertTailWithNode(tailA, nodeI);
	tailB = insertTailWithNode(tailB, nodeI);
	Node* nodeN = initListWithElem('n');
	tailA = insertTailWithNode(tailA, nodeN);
	tailB = insertTailWithNode(tailB, nodeN);
	Node* nodeG = initListWithElem('g');
	tailA = insertTailWithNode(tailA, nodeG);
	tailB = insertTailWithNode(tailA, nodeG);

	listNode(listA);
	printf("\n");
	listNode(listB);
	printf("\n");

	printf("%c\n", findIntersectionNode(listA, listB)->data);

	return 0;
}