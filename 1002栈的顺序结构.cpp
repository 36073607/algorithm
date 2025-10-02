#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//ջ��˳��ṹʵ��
#define MAXSIZE 100//�ں궨���У�����Ҫʹ�õȺ�
typedef int ElemType;
typedef struct Stack
{
	ElemType data[MAXSIZE];
	int top;
}Stack;
//ջ�����±�ֵ����ջ��ָ��


//ջ��˳��ṹ-��ʼ��
void initStack(Stack* s)
{
	s->top = -1;
}


//ջ��˳��ṹ-�ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* s)
{
	if (s->top == -1)
	{
		printf("��\n");
		return 1;
	}
	else
		return 0;
}


//ջ��˳��ṹ-��ջ/ѹջ
int push(Stack* s, ElemType e)
{
	if (s->top >= MAXSIZE - 1)
	{
		printf("����\n");
		return 0;
	}

	s->top++;
	s->data[s->top] = e;
	return 1;
}


//ջ��˳��ṹ-��ջ
int pop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("�յ�\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}


//ջ��˳��ṹ-��ȡջ��Ԫ��
int getTop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("�յ�\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

int main()
{
	Stack s;
	initStack(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	ElemType e;
	pop(&s, &e);
	printf("%d\n", e);
	getTop(&s, &e);
	printf("%d\n", e);

	return 0;
}
