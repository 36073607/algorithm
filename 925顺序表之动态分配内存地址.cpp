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
SeqList* initList() //���������ǽṹ��SeqList����ָ��
{
	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
	if (L == NULL) // ��� malloc �Ƿ�ɹ�
	{
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	if (L->data == NULL) // ��� malloc �Ƿ�ɹ�
	{
		printf("�ڴ����ʧ��\n");
		free(L); // �ͷ��ѷ�����ڴ�
		return NULL;
	}
	L->length = 0;
	return L;
}
//β�����Ԫ��
void appendElem(struct SeqList* L, ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("˳�������\n");
		return;
	}

	L->data[L->length] = e;
	L->length++;

}
//����
void listElem(struct SeqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}

}
//����Ԫ��
int insertElem(struct SeqList* L, int pos, ElemType e)
{
	if (L->length >= MAXSIZE)
	{
		printf("���Ѿ�����\n");
		return 1;
	}
	else if (pos < 1 || pos>L->length)
	{

		printf("����λ�ô���\n");
		return 0;
	}
	else if (pos <= L->length)
	{

		for (int i = L->length - 1; i >= pos - 1; i--)//ע���еȺŸ��ݾ����������
		{
			L->data[i + 1] = L->data[i];//ע��ǰ����i+1,������i�����ݾ����������
		}
		L->data[pos - 1] = e;
		L->length++;

	}
	return 1;
}
//5.˳���-ɾ��Ԫ��
void deleteElem(struct SeqList* L, int pos, ElemType* e)//���������������Ǹ�����ɾ��ʲô����
{
	if (L->length == 0)
	{
		printf("�ձ�\n");
		return;
	}

	if (pos<1 || pos>L->length)
	{
		printf("ɾ������,��Ԫ�ز�����");
		return;
	}

	*e = L->data[pos - 1];//�� C/C++ �﷨�У�else if ���������һ�� if �� else ������棬���ܸ�����ͨ�����档�������治����else if
	if (pos < L->length)//���ﲻȡ�ȵ�ԭ���ǣ���pos=length,����ѭ����˵����ζ�Ű�pos���Ԫ�ظ��ǵ�pos��ȥ����pos��length��ȣ���length֮���Ԫ������Ч�ģ�����Ч��Ԫ�طŵ�˳����о��Ǵ��
	{
		for (int i = pos - 1; i < L->length - 1; i++)
		{
			L->data[i] = L->data[i + 1];
		}

	}
	L->length--;
}
//6.˳���-����
int findElem(struct SeqList* L, ElemType num_find)
{
	if (L->length == 0)
	{
		printf("���б�\n");
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
	printf("��ɾ����Ԫ��Ϊ:%d\n", delData);
	listElem(list);

	printf("\n");

	printf("%d\n", findElem(list, 88));

	return 0;
}
