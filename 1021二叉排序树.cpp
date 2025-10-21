#include <iostream>
using namespace std;
typedef int TreeType;
typedef struct TreeNode
{
	TreeType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

void preOrder(BiTree T)//�����ã�ȷ�������������ܹ���ȷ����
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//���Ҷ������������Ƿ����ָ��ֵ value
//����T:��ǰ���������
//����value:Ҫ���ҵ�ֵ1
//����parent:��ǰ�ڵ�ĸ����
//����pos:ָ�����������1�����ҵ��Ľڵ�
//����ֵ��1��ʾ�ҵ���0��ʾδ�ҵ�
int search_bst(BiTree T, int value, BiTree parent, BiTree* pos)
{
	if (T == NULL)
	{
		*pos = parent;//�ݹ鵽�ս�㣬����ʧ�ܣ�������㷵�أ��������ݿ����ڲ��룩
		return 0;
	}

	if (value == T->data)
	{
		*pos = T;//�ҵ�Ŀ��ֵ
		return 1;
	}
	else if (value > T->data)
	{
		return search_bst(T->rchild, value, T, pos);//Ҫ���ҵ�ֵ�ȵ�ǰ�ڵ�С������������
	}
	else if (value < T->data)
	{
		return search_bst(T->lchild, value, T, pos);//Ҫ����1��ֵ�ȵ�ǰ�ڵ������������
	}

}

void my_delete(BiTree* t);

void insert_bst(BiTree* T, TreeType value)
{
	BiTree pos = NULL;
	BiTree parent = NULL;
	BiTree curr = NULL;

	int ret = search_bst(*T, value, parent, &pos);

	if (ret == 0)
	{
		curr = new TreeNode;
		curr->data = value;
		curr->lchild = NULL;
		curr->rchild = NULL;

		if (pos == NULL)//����������Ϊ��
		{
			*T = curr;
		}
		else if (pos->data > value)
		{
			pos->lchild = curr;
		}
		else if (pos->data < value)
		{
			pos->rchild = curr;
		}
	}
	else
	{
		return;
	}
}

int delete_bst(BiTree* T, TreeType value)
{
	if (*T == NULL)
	{
		printf("not found\n");
	}
	else if (value > (*T)->data)
	{
		return delete_bst(&(*T)->rchild, value);
	}
	else if (value < (*T)->data)
	{
		return delete_bst(&(*T)->lchild, value);
	}
	else
	{
		my_delete(T);
		return 1;
	}
}

void my_delete(BiTree* t)
{
	BiTree temp = NULL;
	BiTree record = NULL;//��¼����������ġ�����������㡱
	if ((*t)->lchild == NULL)
	{
		temp = *t;
		*t = temp->rchild;
		delete temp;
	}
	else if ((*t)->rchild == NULL)
	{
		temp = *t;
		*t = temp->lchild;
		delete temp;
	}
	else//Ҫɾ���Ľ�����Һ��Ӷ���,������á����������ڵ㡱�滻
	{
		temp = *t;//����������tempΪrecord�ĸ����
		record = (*t)->lchild;
		while (record->rchild != NULL)// �ҵ������������ڵ㣨���ҽڵ㣩
		{
			temp = record;
			record = record->rchild;
		}

		(*t)->data = record->data;// ��record��ֵ�滻Ҫɾ���Ľڵ��ֵ

		// ɾ��record�ڵ�
		if (temp != *t)
		{
			temp->rchild = record->lchild;
			//���record�����ӣ�������Ӹ�record�ĸ����temp
		}
		else
		{
			temp->lchild = record->lchild;
			//�� record �ڵ�ǡ����Ҫɾ���ڵ��ֱ������ʱ���� temp == *t����
			//�� record ���������ҽӵ� temp��Ҳ����Ҫɾ���Ľڵ㣩������λ��
			//���������Ƴ� record �ڵ��ͬʱ�������� record ���ܴ��ڵ�������
		}
		delete record;
	}

}

int main()
{
	BiTree T = NULL;

	int treeArr[] = { 70,55,49,30,39,53,80,75,98,95 };//preorder
	int sz = sizeof(treeArr) / sizeof(treeArr[0]);
	for (int i = 0; i < sz; i++)
	{
		insert_bst(&T, treeArr[i]);
	}

	preOrder(T);//�鿴��ǰ���ṹ
	printf("\n");

	insert_bst(&T, 99);//����һ����ֵ99
	preOrder(T);//�ٴβ鿴
	printf("\n");

	delete_bst(&T, 49);
	preOrder(T);
	printf("\n");

	return 0;
}