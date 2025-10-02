#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//���е�˳��ṹ-ѭ������
#define MAXSIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;

//���е�˳��ṹ-��ʼ��
void initQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
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

//���е�˳��ṹ-ѭ������-���
int equeue(Queue* Q, ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//eg:0 1 3 4 5 6, front=0,rear=6,MAXSIZE=7
	{
		printf("����\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;//�ص�
	return 1;
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