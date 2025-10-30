#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct SqDoubleStack
{
	ElemType data[MAXSIZE];
	int top1;//栈1的下标
	int top2;//栈2地下标
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
		printf("满了\n");
		return;
	}
	if (stackNum == 1)//在栈1中插入
	{
		s->data[++s->top1] = e;
	}
	else if (stackNum == 2)//在栈2中插入
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
			printf("栈1为空\n");
			return;
		}
		*e = s->data[s->top1--];
	}
	else if (stackNum == 2)
	{
		if (s->top2 == MAXSIZE)
		{
			printf("栈2为空\n");
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