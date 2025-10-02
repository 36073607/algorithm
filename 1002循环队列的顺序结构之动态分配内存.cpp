#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//���е�˳��ṹ-ѭ������
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType* data;
	int front;
	int rear;
}Queue;
//��ʼ��
Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	q->front = 0;
	q->rear = MAXSIZE - 1;
	return q;
}
//���
int equeue(Queue* Q, ElemType e)
{
	Q->rear = (Q->rear + 1) % MAXSIZE;//������ö�β�ƶ�
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("����\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	return 1;
}

//���е�˳��ṹ-ѭ������-�ж϶����Ƿ�Ϊ��
int isQ_Empty(Queue* Q)
{
	if (Q->front == Q->rear)//���н��ж�ν������в���������ͷ���β��ȣ������Ϊ��
	{
		printf("��\n");
		return 1;
	}
	else
	{
		return 0;
	}

}

//���е�˳��ṹ-ѭ������-����
int dequeue(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("�յ�\n");
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

//���е�˳��ṹ-ѭ������-��ȡ��ͷ����
int getHead(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("�յ�\n");
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