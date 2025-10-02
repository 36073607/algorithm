#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//栈的顺序结构初始化-动态分配内存
#define MAXSIZE 1000
typedef int ElemType;
typedef struct Stack
{
	int* data;
	int top;
};
Stack* initStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;

	return s;
}

//栈的顺序结构-判断栈是否为空
int isEmpty(Stack* s)
{
	if (s->top == -1)
	{
		printf("空\n");
		return 1;
	}
	else
		return 0;
}


//栈的顺序结构-进栈/压栈
int push(Stack* s, ElemType e)
{
	if (s->top >= MAXSIZE - 1)
	{
		printf("满了\n");
		return 0;
	}

	s->top++;
	s->data[s->top] = e;
	return 1;
}


//栈的顺序结构-出栈
int pop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}


//栈的顺序结构-获取栈顶元素
int getTop(Stack* s, ElemType* e)
{
	if (s->top == -1)
	{
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

int main()
{
	Stack* s = initStack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	ElemType e;
	pop(s, &e);
	printf("%d\n", e);
	getTop(s, &e);
	printf("%d\n", e);

	return 0;
}
