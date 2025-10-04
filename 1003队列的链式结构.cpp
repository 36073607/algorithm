#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//队列的链式结构
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

//队列的链式结构-初始化
Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));//创建队列
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));//创建头节点
	node->data = 0;
	node->next = NULL;

	q->front = node;
	q->rear = node;
	return q;
}

//队列的链式结构-判断队列是否为空
int isEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

//队列的链式结构-入队
//如果你认为首节点是队头，那么就用尾插法
//如果你认为首节点是队尾，那么就用头插法
//这里用尾插法
void equeue(Queue* q, ElemType e)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;//尾插法，node为新的尾节点
	q->rear->next = node;//头节点的next指向第一个节点node
	q->rear = node;//队尾指向第一个节点

}

//队列的链式结构-出队
void dequeue(Queue* Q, ElemType* e)
{
	QueueNode* node = Q->front->next;//指向第一个节点
	*e = node->data;
	Q->front->next = node->next;//队头指向第二个节点
	if (node == Q->rear)//如果要删除的节点是队尾，即队列中除头节点外只有一个节点
	{
		Q->rear = Q->front;
	}
	free(node);

}

////队列的链式结构-获取队头元素
ElemType getFront(Queue* q)
{
	if (isEmpty(q))
	{
		printf("空的\n");
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