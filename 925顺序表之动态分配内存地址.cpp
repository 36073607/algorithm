#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
typedef struct SeqList
{
	ElemType* data;
	int length;
}SeqList;
SeqList* initList() //返回类型是结构体SeqList类型指针
{
	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
	if (L == NULL) // 检查 malloc 是否成功
	{
		printf("内存分配失败\n");
		return NULL;
	}
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (L->data == NULL) // 检查 malloc 是否成功
	{
		printf("内存分配失败\n");
		free(L); // 释放已分配的内存
		return NULL;
	}
	L->length = 0;
	return L;
}
//尾部添加元素
void appendElem(struct SeqList* L, ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("顺序表已满\n");
		return;
	}

	L->data[L->length] = e;
	L->length++;

}
//遍历
void listElem(struct SeqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}

}
//插入元素
int insertElem(struct SeqList* L, int pos, ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("表已经满了\n");
		return 1;
	}
	else if (pos < 1 || pos>L->length)
	{

		printf("插入位置错误\n");
		return 0;
	}
	else if (pos <= L->length)
	{

		for (int i = L->length - 1; i >= pos - 1; i--)//注意有等号根据具体情况而定
		{
			L->data[i + 1] = L->data[i];//注意前面是i+1,后面是i，根据具体情况而定
		}
		L->data[pos - 1] = e;
		L->length++;

	}
	return 1;
}
//5.顺序表-删除元素
void deleteElem(struct SeqList* L, int pos, ElemType* e)//第三个参数意义是告诉我删了什么东西
{
	if (L->length == 0)
	{
		printf("空表\n");
		return;
	}

	if (pos<1 || pos>L->length)
	{
		printf("删除有误,该元素不存在");
		return;
	}

	*e = L->data[pos - 1];//在 C/C++ 语法中，else if 必须紧跟在一个 if 或 else 语句块后面，不能跟在普通语句后面。所有下面不能用else if
	if (pos < L->length)//这里不取等的原因是：当pos=length,按照循环来说就意味着把pos后的元素覆盖到pos上去，但pos与length相等，而length之后的元素是无效的，把无效的元素放到顺序表中就是错的
	{
		for (int i = pos - 1; i < L->length - 1; i++)
		{
			L->data[i] = L->data[i + 1];
		}

	}
	L->length--;
}
//6.顺序表-查找
int findElem(struct SeqList* L, ElemType num_find)
{
	if (L->length == 0)
	{
		printf("空列表\n");
		return -1;
	}
	for (int i = 0; i < L->length; i++)
	{
		if (num_find == L->data[i])
			return i + 1;
	}
	return -1;
}

int main()
{
	SeqList* list = initList();
	appendElem(list, 88);
	appendElem(list, 45);
	appendElem(list, 97);
	listElem(list);

	printf("\n");

	insertElem(list, 2, 34);
	listElem(list);

	printf("\n");

	ElemType delData;
	deleteElem(list, 4, &delData);
	printf("被删除的元素为:%d\n", delData);
	listElem(list);

	printf("\n");

	printf("%d\n", findElem(list, 88));

	return 0;
}
