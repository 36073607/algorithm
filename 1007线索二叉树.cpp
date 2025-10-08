#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
typedef char ElemType;

typedef struct ThreadNode
{
	ElemType data;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	int ltag;//ltag为0时，指向该结点左孩子；为1时，指向该结点的前驱
	int rtag;//rtag为0时，指向该结点右孩子；为1时，指向该结点的后继
}ThreadNode;

typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";//前序遍历：#代表空
int index = 0;

ThreadTree prev = NULL;//记录每一次线索化的过程中上一个访问的结点
// 确保全局变量 prev 被正确初始化

//造树--前序遍历版
void creatTree(ThreadTree* T)//二级指针
{
	char ch = str[index++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (ThreadTree)malloc(sizeof(ThreadNode));

		(*T)->data = ch;

		creatTree(&(*T)->lchild);
		if ((*T)->lchild != NULL)
		{
			(*T)->ltag = 0;
		}

		creatTree(&(*T)->rchild);
		if ((*T)->rchild != NULL)
		{
			(*T)->rtag = 0;
		}
	}
}

void threading(ThreadTree T);//声明

//开始线索化
void inOrderThreading(ThreadTree T, ThreadTree* head)
{
	//头结点
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->rchild = (*head);//这里本应指向最后一个结点，但这里还没正式线索化，只能委屈一下指向它自己；并防止在正式初始化时prev->lchild为空导致错误

	if (T == NULL)//传来了一个空树
	{
		(*head)->lchild = *head;
	}
	else//正常情况
	{
		(*head)->lchild = T;
		::prev = (*head);
		//•	prev：可能指向局部或全局变量，容易产生歧义。
		//• ::prev：只指向全局变量，编译器不会再混淆。

		threading(T);//正式线索化

		//最后一个结点线索化，这里的prev指的是最后一个访问的结点
		::prev->rchild = *head;
		::prev->rtag = 1;

		//头结点右孩子指向最后一个结点
		(*head)->rchild = ::prev;
	}

}

//正式线索化-按照中序遍历来去做这个线索化-中序线索化
void threading(ThreadTree T)
{
	if (T != NULL)
	{
		threading(T->lchild);
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = ::prev;
		}
		if (::prev->rchild == NULL)
		{
			::prev->rtag = 1;
			::prev->rchild = T;
		}
		::prev = T;
		threading(T->rchild);
	}

}
//由于左孩子需要指向前面的指针，所以用 现在 = 过去（时间往前走）
//由于右孩子需要指向后面的指针，所以用 过去=现在（时间往后走）
//毕竟不可能知道未来

//注：函数的先后顺序并不影响，有需要时声明即可；主要是在主函数内的顺序决定哪个函数先被执行
//所以，prev最开始就是指向头结点head

void inOrder(ThreadTree T)
{
	ThreadTree curr = T->lchild;//curr指向根结点
	while (curr != T)//curr不指向头结点
	{
		while (curr->ltag == 0)//找到中序遍历时的第一个结点
		{
			curr = curr->lchild;
		}
		printf("%c", curr->data);
		while (curr->rtag == 1 && curr->rchild != T)//注意这里是等于1,指 通过线索 找 线索化后的下一个结点
		{
			curr = curr->rchild;
			printf("%c", curr->data);
		}
		curr = curr->rchild;//类似于node=node->next
	}
	printf("\n");
}

int main()
{
	ThreadTree head;
	ThreadTree T;
	//创建
	creatTree(&T);
	//线索化
	inOrderThreading(T, &head);
	//基于线索遍历
	inOrder(head);

	return 0;
}
