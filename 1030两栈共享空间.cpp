#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct SqDoubleStack
{
	ElemType data[MAXSIZE];
	int top1;//ջ1���±�
	int top2;//ջ2���±�
}SqDoubleStack;

void initStack(SqDoubleStack* s)
{
	s->top1 = -1;
	s->top2 = MAXSIZE;
}

void push(SqDoubleStack* s, int stackNum, ElemType e)
{
	if (s->top1 + 1 == s->top2)
	{
		printf("����\n");
		return;
	}
	if (stackNum == 1)//��ջ1�в���
	{
		s->data[++s->top1] = e;
	}
	else if (stackNum == 2)//��ջ2�в���
	{
		s->data[--s->top2] = e;
	}
}

void pop(SqDoubleStack* s, int stackNum, ElemType* e)
{
	if (stackNum == 1)
	{
		if (s->top1 == -1)
		{
			printf("ջ1Ϊ��\n");
			return;
		}
		*e = s->data[s->top1--];
	}
	else if (stackNum == 2)
	{
		if (s->top2 == MAXSIZE)
		{
			printf("ջ2Ϊ��\n");
			return;
		}
		*e = s->data[s->top2++];
	}
}

void getTop(SqDoubleStack* s, int stackNum)
{
	if (stackNum == 1)
	{
		printf("%d\n", s->data[s->top1]);
	}
	else if (stackNum == 2)
	{
		printf("%d\n", s->data[s->top2]);
	}
}

int main()
{
	SqDoubleStack S;
	initStack(&S);
	push(&S, 1, 114);
	push(&S, 1, 514);
	push(&S, 2, 1919);
	push(&S, 2, 810);
	getTop(&S, 1);
	getTop(&S, 2);
	ElemType e;
	pop(&S, 2, &e);
	getTop(&S, 2);

	return 0;
}