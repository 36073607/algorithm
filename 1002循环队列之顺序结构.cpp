#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//队列的顺序结构-循环队列
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

//队列的顺序结构-初始化
void initQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

//队列的顺序结构-循环队列-判断队列是否为空
int isQ_Empty(Queue* Q)
{
	if (Q->front == Q->rear)//队列进行多次进出队列操作后，若队头与队尾相等，则队列为空
	{
		printf("空\n");
		return 1;
	}
	else
	{
		return 0;
	}

}

//队列的顺序结构-循环队列-入队
int equeue(Queue* Q, ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//eg:0 1 3 4 5 6, front=0,rear=6,MAXSIZE=7
	{
		printf("满了\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;//重点
	return 1;
}

//队列的顺序结构-循环队列-出队
int dequeue(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

//队列的顺序结构-循环队列-获取队头数据
int getHead(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}

int main()
{
	Queue queue;
	initQueue(&queue);

	equeue(&queue, 10);
	equeue(&queue, 20);
	equeue(&queue, 30);
	equeue(&queue, 40);
	equeue(&queue, 50);

	ElemType e;
	dequeue(&queue, &e);
	printf("%d\n", e);
	dequeue(&queue, &e);
	printf("%d\n", e);

	getHead(&queue, &e);
	printf("%d\n", e);

	return 0;
}