#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef char ElemType;

typedef struct TreeNode
{
	ElemType data;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";//ǰ��
int index = 0;
//������
void creatTree(BiTree* T)//����ǰ�򴴽���
{
	char ch = str[index++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;

		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}

}

void preOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

void inOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	inOrder(T->lchild);
	printf("%c ", T->data);
	inOrder(T->rchild);
}

void postOrder(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c ", T->data);
}

int main()
{
	BiTree T;
	creatTree(&T);
	preOrder(T);
	printf("\n");
	inOrder(T);
	printf("\n");
	postOrder(T);

	return 0;
}