/*
* @Author: WanFeng
* @Date:   2019-04-05 20:28:38
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-05 20:58:44
*/
//循环队列的实现 数组实现，静态队列
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 6
typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
} QUEUE, *PQUEUE;

void init(PQUEUE);
bool en_queue(PQUEUE, int); //入队
bool out_queue(PQUEUE, int *); //出队
void traverse_queue(PQUEUE);
bool full_queue(PQUEUE);
bool empty_queue(PQUEUE);

int main(int argc, char const *argv[])
{
    QUEUE Q;
    int val;
    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    traverse_queue(&Q);
    if(out_queue(&Q, &val))
    {
        printf("您出队的元素是%d\n", val);
    }
    else
    {
        printf("出队失败！\n");
    }
    traverse_queue(&Q);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    traverse_queue(&Q);
    return 0;
}

//初始化队列
void init(PQUEUE pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int) * MAXSIZE);
    pQ->front = 0;
    pQ->rear = 0;
}

//判断队列是否为满
bool full_queue(PQUEUE pQ)
{
    if((pQ->rear + 1) % MAXSIZE == pQ->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断队列是否为空
bool empty_queue(PQUEUE pQ)
{
    if(pQ->front == pQ->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//入队
bool en_queue(PQUEUE pQ, int value)
{
    if (full_queue(pQ))
    {
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear] = value;
        pQ->rear = (pQ->rear + 1) % MAXSIZE;
        return true;
    }
}

//出队
bool out_queue(PQUEUE pQ, int *pValue)
{
    if(empty_queue(pQ))
    {
        return false;
    }
    else
    {
        *pValue = pQ->pBase[pQ->front];
        pQ->front = (pQ->front + 1) % MAXSIZE;
        return true;
    }
}

//队列的遍历
void traverse_queue(PQUEUE pQ)
{
    int i = pQ->front;
    while(i != pQ->rear)
    {
        printf("%d ", pQ->pBase[i]);
        i = (i + 1) % MAXSIZE;
    }
    return;
}