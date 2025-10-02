#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	int* data;
	int front;
	int rear;
};
//初始化
Queue* initQueue()
{
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	Q->data = (int*)malloc(sizeof(int) * MAXSIZE);
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
//队列的顺序结构-判断队列是否为空
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

//队列的顺序结构-出队
ElemType dequeue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		printf("空\n");
		return 0;
	}

	ElemType e = Q->data[Q->front];
	Q->front++;//队头的下标增加，给他覆盖掉
	return e;
}

//队列的顺序结构-调整队列(一些数据已经出队，需要将队列中其他数据往前移，使队头的下标从0开始)
int queueFull(Queue* Q)
{
	if (Q->front > 0)//我真的满了么？
	{
		int difference = Q->front;//差值，剩下的元素需要一次挪这么多步长
		for (int i = Q->front; i <= Q->rear; i++)
		{
			Q->data[i - difference] = Q->data[i];//核心
		}
		Q->front = 0;
		Q->rear = Q->rear - difference;
		return 1;
	}
	else
	{
		printf("真的满了\n");
		return 0;
	}
}

//队列的顺序结构-入队
void equeue(Queue* Q, ElemType e)
{
	if (Q->rear >= MAXSIZE)
	{
		if (!queueFull(Q))
		{
			printf("满了\n");
			return;
		}
	}
	Q->data[Q->rear] = e;
	Q->rear++;
}

//队列的顺序结构-获取队头数据
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

	printf("%d\n", dequeue(queue));
	printf("%d\n", dequeue(queue));

	ElemType e;
	getHead(queue, &e);
	printf("%d\n", e);

	return 0;

}
