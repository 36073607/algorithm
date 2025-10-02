#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//队列的顺序结构-循环队列
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType* data;
	int front;
	int rear;
}Queue;
//初始化
Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	q->front = 0;
	q->rear = MAXSIZE - 1;
	return q;
}
//入队
int equeue(Queue* Q, ElemType e)
{
	Q->rear = (Q->rear + 1) % MAXSIZE;//入队先让队尾移动
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("满了\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	return 1;
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
	Queue* queue = initQueue();
	

	equeue(queue, 10);
	equeue(queue, 20);
	equeue(queue, 30);
	equeue(queue, 40);
	equeue(queue, 50);

	ElemType e;
	dequeue(queue, &e);
	printf("%d\n", e);
	dequeue(queue, &e);
	printf("%d\n", e);

	getHead(queue, &e);
	printf("%d\n", e);

	return 0;
}