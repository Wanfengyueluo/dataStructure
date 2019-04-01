/*
* @Author: WanFeng
* @Date:   2019-03-31 23:02:55
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-01 22:38:51
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//C99添加bool类型

//线性结构的数组实现
//未完成：数组的自增长因子，当分配的内存达到上限再次添加数据时数组自动申请内存
typedef struct ArrayList
{
    int *pBase;//存储数组的第一个元素的地址
    int len;//数组所能容纳的最大元素个数
    int cnt;//当前数组有效元素的个数
} Arr;

void init_arr(Arr *pArr, int length);//数组初始化
bool append_arr(Arr *pArr, int value);//数组追加数据
bool insert_arr(Arr *pArr, int pos, int value);//向数组中插入一个元素，pos的值从1开始
bool delete_arr(Arr *pArr, int pos, int *pValue);//删除数组中的一个元素
bool is_empty(Arr *pArr);//判断数组是否为空
bool is_full(Arr *pArr);//判断数组是否为满
void sort_arr(Arr *pArr);//数组排序
void show_arr(Arr *pArr);//打印数组
void inversion_arr(Arr *pArr);//数组翻转

int main(int argc, char const *argv[])
{
    Arr arr;
    int value;
    init_arr(&arr, 100);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 14);
    append_arr(&arr, 13);
    append_arr(&arr, 12);
    append_arr(&arr, 11);
    append_arr(&arr, 21);
    append_arr(&arr, 22);
    append_arr(&arr, 23);
    append_arr(&arr, 24);
    show_arr(&arr);

    insert_arr(&arr, 1, 99);
    show_arr(&arr);
    insert_arr(&arr, 6, 100);
    show_arr(&arr);
    if(1 == insert_arr(&arr, -1, 999))
    {
        show_arr(&arr);
    }

    //删除第一个元素
    if(delete_arr(&arr, 1, &value))
    {
        printf("删除成功\n");
        printf("您删除的元素是%d\n", value);
    }
    show_arr(&arr);

    inversion_arr(&arr);
    show_arr(&arr);

    sort_arr(&arr);
    show_arr(&arr);
    return 0;
}

void init_arr(Arr *pArr, int length)
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if(NULL == pArr->pBase)
    {
        printf("动态内存分配失败！\n");
        exit(-1);//终止程序
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
        printf("动态内存分配成功！\n");
    }
    return;
}
void show_arr(Arr *pArr)
{
    if(is_empty(pArr))
    {
        printf("该数组为空！\n");
    }
    else
    {
        for (int i = 0; i < pArr->cnt; ++i)
        {
            printf("%d ", pArr->pBase[i]);
        }
        printf("\n");
    }
}
bool is_empty(Arr *pArr)
{
    if(0 == pArr->cnt)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool is_full(Arr *pArr)
{
    if(pArr->cnt == pArr->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool append_arr(Arr *pArr, int value)
{
    if(is_full(pArr))
    {
        printf("数组已满！\n");
        return false;
    }
    else
    {
        pArr->pBase[pArr->cnt] = value;
        ++pArr->cnt;
        return true;
    }
}
bool insert_arr(Arr *pArr, int pos, int value)
{
    if(is_full(pArr))
    {
        return false;
    }
    if(pos < 1 || pos > pArr->cnt + 1)
    {
        printf("插入位置不合法！\n");
        return false;
    }
    for(int i = pArr->cnt - 1; i >= pos - 1; --i)
    {
        pArr->pBase[i + 1] = pArr->pBase[i];
    }
    pArr->pBase[pos - 1] = value;
    ++pArr->cnt;
    return true;
}

bool delete_arr(Arr *pArr, int pos, int *pValue)
{
    if(is_empty(pArr))
    {
        return false;
    }
    if (pos < 1 || pos > pArr->cnt)
    {
        return false;
    }
    *pValue = pArr->pBase[pos - 1];
    for (int i = pos; i < pArr->cnt; ++i)
    {
        pArr->pBase[i - 1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return true;
}
void inversion_arr(Arr *pArr)
{
    int begin = 0;
    int end = pArr->cnt - 1;
    for (; begin <= end; ++begin, --end)
    {
        int temp;
        temp = pArr->pBase[begin];
        pArr->pBase[begin] = pArr->pBase[end];
        pArr->pBase[end] = temp;
    }
}
void sort_arr(Arr *pArr)
{
    for (int i = 0; i < pArr->cnt; ++i)
    {
        for (int j = i + 1; j < pArr->cnt; ++j)
        {
            if(pArr->pBase[i] > pArr->pBase[j])
            {
                int temp;
                temp = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = temp;
            }
        }
    }
}