#define _CRT_SECURE_NO_WARNINGS
// [2012] �ٶ����ô�ͷ�ڵ�ĵ������浥�ʣ���������������ͬ�ĺ�׺ʱ����ɹ�����ͬ�ĺ�׺�洢�ռ�
//        ��str1��str2�ֱ�ָ�������������ڵ������ͷ�ڵ㣬���һ��ʱ���Ͼ����ܸ�Ч���㷨���ҳ���str1��str2��ָ����������ͬ��׺����ʼλ��
//������˫ָ�루����ָ�룩
#include <iostream>
using namespace std;
typedef char ElemType;
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
		printf("%c ", p->data);
		p = p->next;
	}

}
//��ʼ��ͨ�ú�׺����
Node* initListWithElem(ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = NULL;

	return p;
}
//��������
Node* insertTailWithNode(Node* tail, Node* node)
{
	tail->next = node;
	node->next = NULL;
	return node;
}
//���ҹ�ͬ��׺
// ���������
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
// ����
Node* findIntersectionNode(Node* a, Node* b)
{
	if (a == NULL || b == NULL)
		return NULL;

	int m = listLength(a);
	int n = listLength(b);
	Node* fast = NULL;
	Node* slow = NULL;
	int step = 0;//��������֮��Ĳ�ֵ���������ڿ�ָ�����ߵĲ���
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

	return fast;//����return slow Ҳһ������Ϊ��ʱ����λ��һ��

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