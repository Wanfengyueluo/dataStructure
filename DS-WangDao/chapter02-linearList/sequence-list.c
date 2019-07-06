/*
* @Author: WanFeng
* @Date:   2019-05-12 23:59:02
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-05-14 00:13:41
*/
/*
线性表的顺序表示
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAXSIZE 100
#define ElementType int

typedef struct SqList
{
    ElementType *data;
    int length;
} SqList;

void InitList(SqList *);//顺序表的初始化
void InsertListEnd(SqList *, int);//从表的尾部插入值
void InsertList(SqList *, int, int);//向表的第i个位置插入值element
int IsEmpty(SqList *);//判断顺序表是否为空
int IsFull(SqList *);//判断顺序表是否为满
int Length(SqList *);//获取表的长度
void DeleteList(SqList *, int, int *);//删除表中第i个位置的值并返回删除的值
void printList(SqList *);//打印顺序表

int main(int argc, char const *argv[])
{
    SqList sqList;
    int i;
    int value;
    InitList(&sqList);
    //初始化后向表中插值
    for(i = 0; i < 5; ++i)
    {
        InsertListEnd(&sqList, i + 1);
    }
    printList(&sqList);
    //向表的第2个位置插入值6
    InsertList(&sqList, 2, 6);
    printList(&sqList);
    printf("表的长度为:%d\n", Length(&sqList));
    //删除表的第五个元素并返回删除的值
    DeleteList(&sqList, 5, &value);
    printList(&sqList);
    printf("删除的元素值为:%d\n", value);
    return 0;
}

void InitList(SqList *sqList)
{
    sqList->data = (ElementType *)malloc(sizeof(ElementType) * MAXSIZE);
    if(NULL == sqList->data)
    {
        printf("顺序表内存分配失败！\n");
        exit(-1);//分配失败终止程序
    }
    else
    {
        sqList->length = 0;
        printf("顺序表内存分配成功！\n");
    }
}

void InsertList(SqList *sqList, int index, int element)
{
    if(!IsFull(sqList))
    {
        if(index < 1 || index > sqList->length)//判断插入的位置是否合法
        {
            printf("插入位置不合法！\n");
        }
        else
        {
            int i;
            for(i = sqList->length; i >= index - 1; --i)
            {
                sqList->data[i + 1] = sqList->data[i];
            }
            sqList->data[index - 1] = element;
            sqList->length++;
        }
    }
    else
    {
        printf("表已满，插入失败！\n");
    }
}

int Length(SqList *sqList)
{
    return sqList->length;
}

void InsertListEnd(SqList *sqList, int element)
{
    if(!IsFull(sqList))
    {
        sqList->data[sqList->length] = element;
        sqList->length++;
    }
    else
    {
        printf("表已满，插入失败！\n");
    }
}

int IsEmpty(SqList *sqList)
{
    if(sqList->length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int IsFull(SqList *sqList)
{
    if(sqList->length == MAXSIZE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void DeleteList(SqList *sqList, int index, int *element)
{
    if(IsEmpty(sqList))
    {
        printf("该表为空，删除失败！\n");
    }
    else
    {
        if(index < 1 || index > sqList->length)//判断插入的位置是否合法
        {
            printf("删除的位置不合法！\n");
        }
        else
        {
            int i;
            *element = sqList->data[index - 1];
            for(i = index - 1; i < sqList->length; ++i)
            {
                sqList->data[i] = sqList->data[i + 1];
            }
            sqList->length--;
        }
    }
}

void printList(SqList *sqList)
{
    int i;
    for (i = 0; i < sqList->length; ++i)
    {
        printf("%d ", sqList->data[i]);
    }
    printf("\n");
}