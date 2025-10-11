#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>//malloc
#include<cstdio>//printf
using namespace std;
typedef char TreeType;
typedef struct TreeNode
{
	TreeType data;
	TreeNode* lchild;
	TreeNode* rchild;
};

typedef TreeNode* BiTree;

typedef struct QueueNode
{
	TreeNode* data;
	QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

Queue* initQueue()
{
	QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));
	Queue* q = (Queue*)malloc(sizeof(Queue));
	head->data = NULL;
	head->next = NULL;

	q->front = head;
	q->rear = head;
	return q;
}

int isEmpty(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	return 0;
}

void equeue(Queue* q, TreeNode* e)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;
	q->rear->next = node;
	q->rear = node;

}

void dequeue(Queue* q, BiTree* e)
{
	// 先检查队列是否为空，避免对 NULL 解引用
	if (isEmpty(q))
	{
		*e = NULL;
		return;
	}

	QueueNode* tmp = q->front->next; // 原第一个节点（要删除的结点）
	*e = tmp->data;
	q->front->next = tmp->next;
	if (tmp == q->rear)
	{
		q->rear = q->front;
	}
	free(tmp);
}

int queueSize(Queue* q)
{
	int size = 0;
	QueueNode* tmp = q->front->next; // 从第一个有效节点开始
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}

char str[] = "ABDH##I##EJ###CF##G##";//前序遍历：#代表空
int index = 0;

void creatTree(BiTree* T)
{
	TreeType ch = str[index++];
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

int maxDepth(Queue* q, TreeNode* T)
{
	if (T == NULL)
	{
		return 0;
	}
	equeue(q, T);
	int depth = 0;
	while (!isEmpty(q))
	{
		int count = queueSize(q);
		while (count > 0)
		{
			TreeNode* curr = NULL;
			dequeue(q, &curr);
			if (curr != NULL)
			{
				if (curr->lchild != NULL)
				{
					equeue(q, curr->lchild);
				}
				if (curr->rchild != NULL)
				{
					equeue(q, curr->rchild);
				}
			}
			count--;
		}
		depth++;
	}

	return depth;
}

int main()
{
	Queue* q = initQueue();

	TreeNode* T;
	creatTree(&T);

	int ret = maxDepth(q, T);
	printf("%d\n", ret);

	return 0;
}