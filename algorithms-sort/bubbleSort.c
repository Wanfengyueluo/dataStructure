/*
* @Author: WanFeng
* @Date:   2019-04-18 00:32:47
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-18 22:37:14
*/
//冒泡排序Bubble Sort
#include <stdio.h>
#include <stdlib.h>

#ifndef MAXSIZE
#define MAXSIZE 100
#endif
void bubbleSort(int *, int);//冒泡排序
void randomArray(int *,int);//随机生成一个数组
int main(int argc, char const *argv[])
{
    int array[MAXSIZE];
    int length = 0;
    printf("请输入数组长度：");
    fflush(stdout);
    scanf("%d", &length);

    randomArray(array,length);
    printf("排序前： ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("排序后： ");
    bubbleSort(array, length);
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

/*
性能分析：
时间复杂度：
最坏：O(n^2)
最优：O(n)
平均：O(n^2)
空间复杂度：O(1)
*/
void bubbleSort(int *arr, int length)
{
    int i, j, temp;
    for(i = 0; i < length - 1; ++i)
    {
        for(j = i + 1; j < length; ++j)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void randomArray(int *arr,int length)
{
    for (int i = 0; i < length; ++i)
    {
        arr[i] = rand()%100;
    }
}