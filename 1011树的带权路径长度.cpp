#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
using namespace std;
#define MAXSIZE 1000

typedef int ElemType;

typedef struct TreeNode
{
	ElemType weight;
	TreeNode* lchild;
	TreeNode* rchild;
}TreeNode;

typedef TreeNode* BiTree;

int weight[] = { 100, 42, 15, -1, -1, 27, -1, -1, 58, 28, 13, 5, -1, -1, 8, -1, -1, 15, -1, -1, 30, -1, -1 };
int index = 0;

void creatTree(BiTree* T)
{
	int tmp = weight[index++];
	if (tmp == -1)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->weight = tmp;
		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}
}

int WPL(BiTree T)
{
	BiTree SeqQueue[MAXSIZE];//创建顺序结构队列
	int front = 0;
	int rear = 0;

	SeqQueue[rear++] = T;//根结点入队
	int depth = 0;
	int value = 0;
	while (front != rear)
	{
		int count = rear - front;
		while (count > 0)
		{
			BiTree curr = NULL;

			curr = SeqQueue[front];
			front++;//出队

			if (curr->lchild != NULL)
			{
				SeqQueue[rear++] = curr->lchild;
			}
			if (curr->rchild != NULL)
			{
				SeqQueue[rear++] = curr->rchild;
			}

			if (curr->lchild == NULL && curr->rchild == NULL)
			{
				value += depth * curr->weight;
			}
			count--;
		}
		depth++;
	}

	return value;
}

int main()
{
	BiTree T;
	creatTree(&T);
	int ret = WPL(T);
	printf("%d\n", ret);

	return 0;
}