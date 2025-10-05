#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100

typedef enum contentType
{
    LEFT_PARE, RIGHT_PARE,
    ADD, SUB, MUL, DIV, MOD,
    EOS, NUM
}contentType;

typedef struct Stack
{
    contentType* arr;//注意
    int top;
}Stack;

char expr[] = "x/(i-j)*y";//中缀表达式

Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (contentType*)malloc(sizeof(contentType) * MAXSIZE);
    s->top = 0;
    s->arr[s->top] = EOS; // 栈底为EOS
    return s;
}

void push(Stack* s, contentType e)
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("满了\n");
        return;
    }
    s->top++;
    s->arr[s->top] = e;
}

void pop(Stack* s, contentType* e)
{
    if (s->top == 0)
    {
        printf("空的\n");
        return;
    }
    *e = s->arr[s->top];
    s->top--;
}

contentType getToken(char* symbol, int* index)
{
    *symbol = expr[*index];
    (*index)++;
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
    case '\0':
        return EOS;
    default:
        return NUM;
    }
}

void token_print(contentType e)
{
    switch (e)
    {
    case ADD: 
        printf("+");
        break;
    case SUB: 
        printf("-");
        break;
    case MUL:
        printf("*"); 
        break;
    case DIV: 
        printf("/");
        break;
    case MOD:
        printf("%%");
        break;
    default: 
        return;
    }
}

void operate(Stack* s)
{
    char symbol;
    int index = 0;
    contentType token;
    // 优先级表
    int in_stack[] = { 0,19,12,12,13,13,13,0 };   // 栈内优先级
    int out_stack[] = { 20,19,12,12,13,13,13,0 }; // 栈外优先级
    contentType e;
    token = getToken(&symbol, &index);

    while (token != EOS)
    {
        if (token == NUM)
        {
            printf("%c", symbol);
        }
        else if (token == RIGHT_PARE)
        {
            while (s->arr[s->top] != LEFT_PARE)
            {
                pop(s, &e);
                token_print(e);
            }
            pop(s, &e); // 弹出左括号
        }
        else
        {
            while (out_stack[token] <= in_stack[s->arr[s->top]])
            {
                pop(s, &e);
                token_print(e);
            }
            push(s, token);
        }
        token = getToken(&symbol, &index);
    }
    // 清空栈中剩余运算符
    while (s->arr[s->top] != EOS)
    {
        pop(s, &e);
        token_print(e);
    }
}

int main()
{
    Stack* s = initStack();
    printf("%s\n", expr);
    operate(s);
    free(s->arr);
    free(s);
    return 0;
}