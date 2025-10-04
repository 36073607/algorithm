#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//���е���ʽ�ṹ
typedef int ElemType;
typedef struct QueueNode
{
	ElemType data;
	struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

//���е���ʽ�ṹ-��ʼ��
Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));//��������
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//����ͷ�ڵ�
	node->data = 0;
	node->next = NULL;

	q->front = node;
	q->rear = node;
	return q;
}

//���е���ʽ�ṹ-�ж϶����Ƿ�Ϊ��
int isEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

//���е���ʽ�ṹ-���
//�������Ϊ�׽ڵ��Ƕ�ͷ����ô����β�巨
//�������Ϊ�׽ڵ��Ƕ�β����ô����ͷ�巨
//������β�巨
void equeue(Queue* q, ElemType e)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;//β�巨��nodeΪ�µ�β�ڵ�
	q->rear->next = node;//ͷ�ڵ��nextָ���һ���ڵ�node
	q->rear = node;//��βָ���һ���ڵ�

}

//���е���ʽ�ṹ-����
void dequeue(Queue* Q, ElemType* e)
{
	QueueNode* node = Q->front->next;//ָ���һ���ڵ�
	*e = node->data;
	Q->front->next = node->next;//��ͷָ��ڶ����ڵ�
	if (node == Q->rear)//���Ҫɾ���Ľڵ��Ƕ�β���������г�ͷ�ڵ���ֻ��һ���ڵ�
	{
		Q->rear = Q->front;
	}
	free(node);

}

////���е���ʽ�ṹ-��ȡ��ͷԪ��
ElemType getFront(Queue* q)
{
	if (isEmpty(q))
	{
		printf("�յ�\n");
		return -1;
	}

	return q->front->next->data;
}

int main()
{
	Queue* q = initQueue();
	equeue(q, 10);
	equeue(q, 20);
	equeue(q, 30);
	equeue(q, 40);
	equeue(q, 50);

	ElemType e;
	dequeue(q, &e);
	printf("%d\n", e);
	dequeue(q, &e);
	printf("%d\n", e);

	printf("%d\n", getFront(q));

	return 0;
}