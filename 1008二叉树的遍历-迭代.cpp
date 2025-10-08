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

typedef struct Stack
{
    BiTree data;
    Stack* next;
}Stack;

Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = NULL;
    s->next = NULL;
    return s;
}

void push(Stack* s, BiTree e)
{
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

BiTree pop(Stack* s)
{
    if (s->next == NULL) 
        return NULL;
    Stack* q = s->next;
    BiTree e = q->data;
    s->next = q->next;
    free(q);
    return e;
}

int isEmpty(Stack* s)
{
    return s->next == NULL;  // 返回1表示空，返回0表示非空
}
//解释：
//•	当 s->next == NULL 时，返回值为 1（true），表示栈空
//•	当 s->next != NULL 时，返回值为 0（false），表示栈非空

char str[] = "ABDH#K###E##CFI###G#J##";//前序
int index = 0;

void creatTree(BiTree* T)//按照前序创建树
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

// 前序遍历（根-左-右）
void preOrderOperate(Stack* s, BiTree T)
{
    if (T == NULL) 
        return;

    push(s, T);  // 先将根节点入栈
    while (!isEmpty(s))  // 当栈不为空时
    {
        BiTree curr = pop(s);  // 弹出当前节点
        printf("%c ", curr->data);  // 访问当前节点

        // 由于栈是后进先出，为了保证左子树先于右子树遍历
        // 需要先压入右子树，再压入左子树
        if (curr->rchild!=NULL)
            push(s, curr->rchild);
        if (curr->lchild!=NULL)
            push(s, curr->lchild);
    }
}

// 中序遍历（左-根-右）
void inOrderOperate(Stack* s, BiTree T)
{
    BiTree curr = T;
    while (curr!=NULL || !isEmpty(s))
    {
        while (curr!=NULL)  // 将当前节点及其所有左子节点入栈
        {
            push(s, curr);
            curr = curr->lchild;
        }

        curr = pop(s);  // 弹出栈顶节点
        printf("%c ", curr->data);  // 访问该节点
        curr = curr->rchild;  // 处理右子树
    }
}

// 后序遍历（左-右-根）
void postOrderOperate(Stack* s, BiTree T)
{
    if (T == NULL)
        return;

    BiTree curr = T;           // 当前处理的节点
    BiTree lastVisited = NULL; // 记录最后访问的节点，用于判断右子树是否访问完成

    while (curr != NULL || !isEmpty(s))  // 当前节点不为空或栈不为空时继续处理
    {
        // 第一步：将当前节点及其所有左孩子入栈
        while (curr != NULL)
        {
            push(s, curr);     // 把当前节点压入栈
            curr = curr->lchild; // 移动到左子节点
        }

        // 第二步：查看栈顶节点（注意：这里只是查看，还不能急着访问）
        curr = s->next->data;

        // 第三步：判断是否可以访问当前节点
        // 条件1：该节点没有右子树(curr->rchild == NULL)
        // 条件2：该节点的右子树已经访问过(curr->rchild == lastVisited)
        if (curr->rchild == NULL || curr->rchild == lastVisited)
        {
            printf("%c ", curr->data);  // 访问当前节点
            lastVisited = curr;         // 更新最后访问的节点
            pop(s);                     // 将已访问的节点出栈
            curr = NULL;                // 重置当前节点
        }
        else
        {
            // 如果右子树还没访问，就转向右子树
            curr = curr->rchild;
        }
    }
}

int main()
{
    Stack* s = initStack();
    BiTree T;
    creatTree(&T);

    printf("前序遍历：");
    preOrderOperate(s, T);
    printf("\n");

    printf("中序遍历：");
    inOrderOperate(s, T);
    printf("\n");

    printf("后序遍历：");
    postOrderOperate(s, T);
    printf("\n");

    return 0;
}