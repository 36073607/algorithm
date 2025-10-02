#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//栈的链式结构实现
//若把头节点视为栈底，但是删除元素就是O(n)了，每次都要遍历，但是如果是头插法，插入和删除都是O(1)
//所以尾节点是栈底，第一个节点是栈顶
//压栈-->头插法   出栈-->删除第一个节点
typedef int ElemType;
typedef struct Stack
{
	ElemType data;
	struct Stack* next;
}Stack;
//栈的链式结构实现-初始化
Stack* iniStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//栈的链式结构实现-判断栈是否为空
int is_Empty(Stack* s)
{
	if (s->next == NULL)
	{
		printf("空\n");
		return 0;
	}
	return 1;
}

//栈的链式结构实现-进栈/压栈 (头插法)
void pushStack(Stack* s, ElemType e)
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}


//栈的链式结构实现-出栈
void popStack(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("空\n");
		return;
	}

	*e = s->next->data;//获取栈顶数据
	Stack* tmp = s->next;
	s->next = tmp->next;
	free(tmp);

}


//栈的链式结构实现-获取栈顶元素
void getTop(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("空\n");
		return;
	}

	*e = s->next->data;
}

int main()
{

	Stack* s = iniStack();
	pushStack(s, 10);
	pushStack(s, 20);
	pushStack(s, 30);

	ElemType e;
	popStack(s, &e);
	printf("%d\n", e);

	getTop(s, &e);
	printf("%d\n", e);

	return 0;
}