#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;
//后缀表达式求值
//遇到数字入栈，遇到字符出栈，然后计算结果，再将结果压回栈中
#define MAXSIZE 100
typedef int ElemType;
typedef struct Stack
{
    ElemType* arr;
    int top;
}Stack;

char expr[] = "82/2+56*-";
typedef enum contentType
{
    LEFT_PARE, RIGHT_PARE,
    ADD, SUB, MUL, DIV, MOD,
    EOS, NUM
}contentType;

//栈-顺序-动态 初始化
Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

//压栈
void push(Stack* s, ElemType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("满了\n");
        return;
    }

    s->top++;
    s->arr[s->top] = e;
}

//出栈
void pop(Stack* s, ElemType* e)
{
    if (s->top == -1)
    {
        printf("空的\n");
        return;
    }
    *e = s->arr[s->top];
    s->top--;
}

//获取字符
contentType getToken(char* symbol, int* index)
{
    *symbol = expr[*index];
    *index = *index + 1;
    switch (*symbol)
    {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PARE;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0': // 注意：字符串结束符
        return EOS;
    default:
        return NUM;
    }
}

//处理
void eval(Stack* s)
{
    char symbol;
    int index = 0;
    int op1, op2;
    contentType token;
    token = getToken(&symbol, &index);
    ElemType result;
    while (token != EOS)
    {
        if (token == NUM)
        {
            push(s, symbol - '0');
        }
        else
        {
            pop(s, &op2);
            pop(s, &op1);

            switch (token)
            {
            case ADD:
                push(s, op1 + op2);
                break;
            case SUB:
                push(s, op1 - op2);
                break;
            case MUL:
                push(s, op1 * op2);
                break;
            case DIV:
                push(s, op1 / op2);
                break;
            case MOD:
                push(s, op1 % op2);
                break;
            default:
                break;
            }
        }
        token = getToken(&symbol, &index);
    }
    pop(s, &result);
    printf("%d\n", result);
}

int main()
{
    Stack* s = initStack();
    eval(s);

    return 0;
}