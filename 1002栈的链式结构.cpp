#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//ջ����ʽ�ṹʵ��
//����ͷ�ڵ���Ϊջ�ף�����ɾ��Ԫ�ؾ���O(n)�ˣ�ÿ�ζ�Ҫ���������������ͷ�巨�������ɾ������O(1)
//����β�ڵ���ջ�ף���һ���ڵ���ջ��
//ѹջ-->ͷ�巨   ��ջ-->ɾ����һ���ڵ�
typedef int ElemType;
typedef struct Stack
{
	ElemType data;
	struct Stack* next;
}Stack;
//ջ����ʽ�ṹʵ��-��ʼ��
Stack* iniStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//ջ����ʽ�ṹʵ��-�ж�ջ�Ƿ�Ϊ��
int is_Empty(Stack* s)
{
	if (s->next == NULL)
	{
		printf("��\n");
		return 0;
	}
	return 1;
}

//ջ����ʽ�ṹʵ��-��ջ/ѹջ (ͷ�巨)
void pushStack(Stack* s, ElemType e)
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}


//ջ����ʽ�ṹʵ��-��ջ
void popStack(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("��\n");
		return;
	}

	*e = s->next->data;//��ȡջ������
	Stack* tmp = s->next;
	s->next = tmp->next;
	free(tmp);

}


//ջ����ʽ�ṹʵ��-��ȡջ��Ԫ��
void getTop(Stack* s, ElemType* e)
{
	if (s->next == NULL)
	{
		printf("��\n");
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