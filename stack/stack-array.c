/*
* @Author: WanFeng
* @Date:   2019-04-03 23:26:02
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-04 00:09:10
*/
//栈的数组实现，静态栈
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct Stack
{
    int *pBase;
    int top;
    int bottom;
} STACK, *PSTACK;

void init(PSTACK);
bool push(PSTACK, int);
void traverse(PSTACK);
bool isFull(PSTACK);
bool pop(PSTACK,int *);
bool isEmpty(PSTACK);
void clear(PSTACK);

int main(int argc, char const *argv[])
{
    STACK S;
    int value;
    init(&S);
    push(&S, 1);
    traverse(&S);
    push(&S, 2);
    traverse(&S);
    push(&S, 3);
    traverse(&S);
    push(&S, 4);
    traverse(&S);
    if(pop(&S,&value)){
    	printf("出栈成功，出栈的元素是%d\n", value);
    }else{
    	printf("出栈失败！\n");
    }
    traverse(&S);
    if(pop(&S,&value)){
    	printf("出栈成功，出栈的元素是%d\n", value);
    }else{
    	printf("出栈失败！\n");
    }
    traverse(&S);
    clear(&S);
    traverse(&S);
    return 0;
}

//判断栈是否为满
bool isFull(PSTACK s)
{
    if(s->top == MAXSIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断栈是否为空
bool isEmpty(PSTACK s)
{
    if(s->top == s->bottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//初始化栈
void init(PSTACK s)
{
    s->pBase = (int *)malloc(sizeof(int) * MAXSIZE);
    if(s->pBase == NULL)
    {
        printf("栈分配失败！\n");
        exit(-1);
    }
    else
    {
        s->top = 0;
        s->bottom = 0;
        return;
    }
}

//入栈
bool push(PSTACK s, int value)
{
    if(!isFull(s))
    {
        s->pBase[s->top] = value;
        ++s->top;
        return true;
    }
    else
    {
        printf("该栈已满，入栈失败！\n");
        return false;
    }
}

//遍历栈
void traverse(PSTACK s)
{
    if(isEmpty(s))
    {
        printf("该栈为空！\n");
    }
    else
    {
        int i = 0;
        while(i < s->top)
        {
            printf("%d ", s->pBase[i]);
            ++i;
        }
        printf("\n");
        return;
    }
}

//出栈
bool pop(PSTACK s, int *pValue)
{
    if(isEmpty(s))
    {
        printf("该栈为空，出栈失败！\n");
        return false;
    }
    else
    {
    	*pValue = s->pBase[s->top-1];
        --s->top;
        return true;
    }
}

//清空栈
void clear(PSTACK s)
{
    if(isEmpty(s))
    {
        printf("该栈为空！\n");
        return;
    }
    else
    {
        s->top = s->bottom;
    }
}