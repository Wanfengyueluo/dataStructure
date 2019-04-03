/*
* @Author: WanFeng
* @Date:   2019-04-03 21:54:24
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-03 23:14:35
*/
//栈的链表实现，动态栈
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;//栈顶
    PNODE pBottom;//栈底
} STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
bool pop(PSTACK, int *);
void traverse(PSTACK);
bool isEmpty(PSTACK);
void clear(PSTACK);

int main(int argc, char const *argv[])
{
    STACK S;
    int val;
    init(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 5);
    push(&S, 7);
    push(&S, 8);
    traverse(&S);
    if(pop(&S, &val))
    {
        printf("出栈的元素是%d\n", val);
    }
    else
    {
        printf("该栈为空，出栈失败！\n");
    }
    traverse(&S);
    /*
    if(pop(&S, &val))
    {
        printf("出栈的元素是%d\n", val);
    }
    else
    {
        printf("该栈为空，出栈失败！\n");
    }
    traverse(&S);
    */
    clear(&S);
    traverse(&S);
    return 0;
}

//创建一个空栈
void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("动态内存分配失败！\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;//或pS-pBottom->pNext = NULL:
    }
}

//压入栈
void push(PSTACK pS, int value)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = value;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

//压出栈
bool pop(PSTACK pS, int *pValue)
{
    if(isEmpty(pS))
    {
        return false;
    }
    else
    {
        PNODE p = pS->pTop;
        *pValue = p->data;
        pS->pTop = p->pNext;
        free(p);
        p = NULL;
        return true;
    }
}

//判断栈是否为空
bool isEmpty(PSTACK pS)
{
    if(pS->pTop == pS->pBottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//遍历栈
void traverse(PSTACK pS)
{
    if(isEmpty(pS))
    {
        printf("该栈为空！\n");
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        while(pS->pBottom != p)
        {
            printf("%d ", p->data);
            p = p->pNext;
        }
        printf("\n");
        return;
    }
}

//清空栈中的数据
void clear(PSTACK pS)
{
    if(isEmpty(pS))
    {
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;
        while(p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
        return;
    }
}