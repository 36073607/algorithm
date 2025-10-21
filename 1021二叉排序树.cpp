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

void preOrder(BiTree T)//调试用，确保二叉排序树能够正确生成
{
	if (T == NULL)
	{
		return;
	}
	printf("%d ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}

//查找二叉排序树中是否包含指定值 value
//参数T:当前子树根结点
//参数value:要查找的值1
//参数parent:当前节点的父结点
//参数pos:指针变量，用于1返回找到的节点
//返回值：1表示找到，0表示未找到
int search_bst(BiTree T, int value, BiTree parent, BiTree* pos)
{
	if (T == NULL)
	{
		*pos = parent;//递归到空结点，查找失败，将父结点返回（后面内容可用于插入）
		return 0;
	}

	if (value == T->data)
	{
		*pos = T;//找到目标值
		return 1;
	}
	else if (value > T->data)
	{
		return search_bst(T->rchild, value, T, pos);//要查找的值比当前节点小，往左子树找
	}
	else if (value < T->data)
	{
		return search_bst(T->lchild, value, T, pos);//要查找1的值比当前节点大，往右子树找
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

		if (pos == NULL)//二叉排序树为空
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
	BiTree record = NULL;//记录第三种情况的“左子树最大结点”
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
	else//要删除的结点左、右孩子都有,这里采用“左子树最大节点”替换
	{
		temp = *t;//第三种情况里，temp为record的父结点
		record = (*t)->lchild;
		while (record->rchild != NULL)// 找到左子树的最大节点（最右节点）
		{
			temp = record;
			record = record->rchild;
		}

		(*t)->data = record->data;// 用record的值替换要删除的节点的值

		// 删除record节点
		if (temp != *t)
		{
			temp->rchild = record->lchild;
			//如果record有左孩子，则把左孩子给record的父结点temp
		}
		else
		{
			temp->lchild = record->lchild;
			//当 record 节点恰好是要删除节点的直接左孩子时（即 temp == *t）：
			//将 record 的左子树挂接到 temp（也就是要删除的节点）的左孩子位置
			//这样就在移除 record 节点的同时，保留了 record 可能存在的左子树
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

	preOrder(T);//查看当前树结构
	printf("\n");

	insert_bst(&T, 99);//插入一个新值99
	preOrder(T);//再次查看
	printf("\n");

	delete_bst(&T, 49);
	preOrder(T);
	printf("\n");

	return 0;
}