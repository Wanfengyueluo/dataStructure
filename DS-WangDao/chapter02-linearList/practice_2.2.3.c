/*
* @Author: WanFeng
* @Date:   2019-07-06 12:37:09
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-07-06 14:22:19
*/
/*
	课本2.2.3综合题
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef struct SqList
{
    int *data;
    int length;
} SqList;

//1. 删除顺序表中最小元素(假设唯一)并返回其值，并用最后一个元素填补，为空则返回错误信息
int deleteMin(SqList *sqList)
{
    if (sqList->length == 0)
    {
        printf("该顺序表为空，无法删除！\n");
        return 0;
    }
    else
    {
        int min = sqList->data[0];
        int index = 0;
        for (int i = 0; i < sqList->length; ++i)
        {
            if (min > sqList->data[i])
            {
                min = sqList->data[i];
                index = i;
            }
        }
        sqList->data[index] = sqList->data[sqList->length - 1];
        sqList->length--;
        return min;
    }

}

//2. 顺序表元素倒置，要求高效且空间复杂度为O(1)
void reverseList(SqList *sqList)
{
    if(sqList->length == 0)
    {
        printf("该顺序表为空，无法倒置！\n");
    }
    else
    {
        int temp = 0;
        for (int i = 0; i < sqList->length / 2; ++i)
        {
            temp = sqList->data[i];
            sqList->data[i] = sqList->data[sqList->length - 1 - i];
            sqList->data[sqList->length - 1 - i] = temp;
        }
    }
}

//3. 对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中的所有值为x的元素
void deleteX(SqList *sqList, int x)
{
    if(sqList->length == 0)
    {
        printf("该顺序表为空，无法删除！\n");
    }
    else
    {
        int k = 0; //记录不为x的数
        for (int i = 0; i < sqList->length; ++i)
        {
            if(sqList->data[i] != x)
            {
                sqList->data[k] = sqList->data[i];
                ++k;
            }
        }
        sqList->length = k;//遍历之后线性表的长度为k
    }
}

//4. 从有序顺序表中删除其值在给定值s与t之间(包含s和t，要求s<t)的所有元素，若s或t不合理或表为空，返回错误信息
void deleteST(SqList *sqList, int s, int t)
{
    if (sqList->length == 0)
    {
        printf("该顺序表为空，无法删除！\n");
    }
    else if (s >= t)
    {
        printf("s , t的值不合法!\n");
    }
    else
    {
        int s_index = 0;
        int t_index = 0;
        for (s_index = 0; (s_index < sqList->length) && (sqList->data[s_index] < s); ++s_index); //找到大于或等于s的第一个元素下标
        if(s_index >= sqList->length)
        {
            printf("该表所有元素均小于s,无法删除\n");
        }
        else
        {
            for (t_index = s_index; (t_index < sqList->length) && (sqList->data[t_index] <= t); ++t_index);//找到大于t的第一个元素下标
            for (; t_index < sqList->length; ++t_index, ++s_index)
            {
                sqList->data[s_index] = sqList->data[t_index];
            }
            sqList->length = s_index;
        }
    }
}

//5. 从顺序表中删除其值在给定值s与t之间(包含s和t，要求s<t)的所有元素，若s或t不合理或表为空，返回错误信息
void deleteST2(SqList *sqList, int s, int t)
{
    if(sqList->length == 0)
    {
        printf("该顺序表为空，无法删除！\n");
    }
    else if(s >= t)
    {
        printf("s, t的值不合法！\n");
    }
    else
    {
        int k = 0;//记录不在s,t之间的元素个数
        for (int i = 0; i < sqList->length; ++i)
        {
            if(sqList->data[i] < s || sqList->data[i] > t)
            {
                sqList->data[k] = sqList->data[i];
                ++k;
            }
        }
        sqList->length = k;
    }
}


int main(int argc, char const *argv[])
{
    SqList sqList;
    sqList.data = (int *)malloc(sizeof(int) * MAXSIZE);
    sqList.length = 0;
    for (int i = 0; i < 10; ++i)
    {
        sqList.data[i] = i;
        sqList.length++;
    }
    /* test 1
    printf("%d\n", deleteMin(&sqList));
    */

    /* test 2
    reverseList(&sqList);
    for (int i = 0; i < sqList.length; ++i)
    {
    	printf("%d ", sqList.data[i]);
    }
    */

    /* test 3
    printf("%d\n", sqList.length);
    deleteX(&sqList, 3);
    for (int i = 0; i < sqList.length; ++i)
    {
        printf("%d ", sqList.data[i]);
    }
    */

    /* test 4
    for (int i = 0; i < sqList.length; ++i)
    {
        printf("%d ", sqList.data[i]);
    }
    deleteST(&sqList, 3, 7);
    for (int i = 0; i < sqList.length; ++i)
    {
        printf("%d ", sqList.data[i]);
    }
    */

    /* test 5
    deleteST2(&sqList, 3, 7);
    for (int i = 0; i < sqList.length; ++i)
    {
        printf("%d ", sqList.data[i]);
    }
    */

    return 0;
}