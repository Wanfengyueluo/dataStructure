/*
* @Author: WanFeng
* @Date:   2019-04-01 23:04:24
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-02 22:00:19
*/
//线性结构的链表实现 离散存储
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;//数据域
    struct Node *pNext;//指针域 注:不能写PNODE pNext;
} NODE, *PNODE;

PNODE create_list();//创建链表
void traverse_list(PNODE pHead);//遍历链表
bool is_empty(PNODE pHead);//判断链表是否为空
//函数声明的另一种形式
int length_list(PNODE);//链表的长度
bool insert_list(PNODE, int, int); //向链表中插入一个结点
bool delete_list(PNODE, int, int *); //删除一个结点
void sort_list1(PNODE);//链表的排序1
void sort_list2(PNODE);//链表的排序2

int main(int argc, char const *argv[])
{
    PNODE pHead = NULL;
    int value;
    pHead = create_list();//创建一个非循环单链表，并将该链表的头结点地址赋给pHead
    if(is_empty(pHead))
    {
        printf("链表为空\n");
    }
    else
    {
        printf("链表不为空\n");
    }
    printf("%d\n", length_list(pHead));
    traverse_list(pHead);//链表的遍历
    sort_list1(pHead);
    traverse_list(pHead);
    sort_list2(pHead);
    traverse_list(pHead);
    insert_list(pHead, 1, 100);
    traverse_list(pHead);
    if(delete_list(pHead, 2, &value))
    {
        printf("您删除的数据是%d\n", value);
    }
    else
    {
        printf("删除失败！\n");
    }

    traverse_list(pHead);
    return 0;
}
bool is_empty(PNODE pHead)
{
    if(NULL == pHead->pNext)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int len = 0;
    while(NULL != p)
    {
        ++len;
        p = p->pNext;
    }
    return len;
}
PNODE create_list()
{
    int len;//有效结点的个数
    int val;
    //分配一个不存放有效数据的头结点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(NULL == pHead)
    {
        printf("分配失败,程序终止！\n");
        exit(-1);
    }
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    printf("请输入链表的长度: ");
    fflush(stdout);//刷新缓冲区，打印prinf()函数的内容
    scanf("%d", &len);
    fflush(stdin);
    for (int i = 0; i < len; ++i)
    {
        printf("请输入第%d个结点的值: ", i + 1);
        fflush(stdout);
        scanf("%d", &val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("分配失败，程序终止！\n");
            exit(-1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    if(NULL == p)
    {
        printf("链表为空！\n");
        exit(-1);
    }
    while(NULL != p)
    {
        printf("%d-->", p->data);
        p = p->pNext;
    }
    printf("NULL\n");
}
void sort_list1(PNODE pHead)
{
    PNODE p = pHead->pNext;
    if(!is_empty(pHead))
    {
        while(NULL != p)
        {
            PNODE q = p->pNext;
            while(NULL != q)
            {
                if(p->data > q->data)
                {
                    int temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                q = q->pNext;
            }
            p = p->pNext;
        }
    }
}
//类似于数组的排序
void sort_list2(PNODE pHead)
{
    PNODE p = pHead->pNext;
    if(!is_empty(pHead))
    {
        int len = length_list(pHead);
        int i, j, temp;
        PNODE p, q;
        for (i = 0, p = pHead->pNext; i < len - 1; ++i, p = p->pNext)
        {
            for (j = i + 1, q = p->pNext; j < len; ++j, q = q->pNext)
            {
                if(p->data > q->data)
                {
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            }
        }
    }
}
//将结点插入到pos之前
bool insert_list(PNODE pHead, int pos, int value)
{
    PNODE p = pHead;
    int i = 0;
    //将p移到要删除的结点之前的位置
    while(NULL != p && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    if(i > pos - 1 || NULL == p)
    {
        return false;
    }
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("动态分配内存失败！\n");
        exit(-1);
    }
    pNew->data = value;
    pNew->pNext = p->pNext;
    p->pNext = pNew;
    return true;
}
bool delete_list(PNODE pHead, int pos, int *pValue)
{
    PNODE p = pHead;
    int i = 0;
    //将p移到要删除的结点之前的位置
    while(i < pos - 1 && NULL != p->pNext)
    {
        p = p->pNext;
        ++i;
    }
    if(i > pos - 1 || p->pNext == NULL)
    {
        return false;
    }
    *pValue = p->pNext->data;
    PNODE q = p->pNext;
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;
    return true;
}