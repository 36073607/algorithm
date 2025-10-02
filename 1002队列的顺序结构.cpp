#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
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

//���е�˳��ṹ-�ж϶����Ƿ�Ϊ��
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

//���е�˳��ṹ-����
ElemType dequeue(Queue* Q)
{
	if (Q->front == Q->rear)
	{
		printf("��\n");
		return 0;
	}

	ElemType e = Q->data[Q->front];
	Q->front++;//��ͷ���±����ӣ��������ǵ�
	return e;
}

//���е�˳��ṹ-��������(һЩ�����Ѿ����ӣ���Ҫ������������������ǰ�ƣ�ʹ��ͷ���±��0��ʼ)
int queueFull(Queue* Q)
{
	if (Q->front > 0)//���������ô��
	{
		int difference = Q->front;//��ֵ��ʣ�µ�Ԫ����Ҫһ��Ų��ô�ಽ��
		for (int i = Q->front; i <= Q->rear; i++)
		{
			Q->data[i - difference] = Q->data[i];//����
		}
		Q->front = 0;
		Q->rear = Q->rear - difference;
		return 1;
	}
	else
	{
		printf("�������\n");
		return 0;
	}
}

//���е�˳��ṹ-���
void equeue(Queue* Q, ElemType e)
{
	if (Q->rear >= MAXSIZE)
	{
		if (!queueFull(Q))
		{
			printf("����\n");
			return;
		}
	}
	Q->data[Q->rear] = e;
	Q->rear++;
}

//���е�˳��ṹ-��ȡ��ͷ����
int getHead(Queue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		printf("����\n");
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

	printf("%d\n", dequeue(&queue));
	printf("%d\n", dequeue(&queue));

	ElemType e;
	getHead(&queue, &e);
	printf("%d\n", e);

	return 0;
}