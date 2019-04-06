/*
* @Author: WanFeng
* @Date:   2019-04-06 12:26:13
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-06 12:33:11
*/

//阶乘算法的递归实现
#include <stdio.h>

int factorial(int);
int main(int argc, char const *argv[])
{
    int num;
    printf("请输入一个数：");
    fflush(stdout);
    scanf("%d", &num);
    printf("该数的阶乘为：%d\n", factorial(num));;

    return 0;
}

int factorial(int num)
{
    if(num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}