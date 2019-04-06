/*
* @Author: WanFeng
* @Date:   2019-04-06 13:44:00
* @Last Modified by:   WanFeng
* @Last Modified time: 2019-04-06 14:10:34
*/
//汉诺塔问题的实现
/*
	若n==1时直接从A移到C
	否则：
		1.将n-1从A借助C移到B
		2.直接将n从A移到C
		3.将n-1从B借助A移到C
*/
#include <stdio.h>

void towerofHanoi(int, char, char, char);
int main(int argc, char const *argv[])
{
	char ch1='A',ch2='B',ch3='C';
	towerofHanoi(3,ch1,ch2,ch3);
    return 0;
}

void towerofHanoi(int n, char ch1, char ch2, char ch3)
{
	if(n==1){
		printf("将编号为 %d 的盘子从 %c 移到 %c\n",n,ch1,ch3);
	}else{
		towerofHanoi(n-1,ch1,ch3,ch2);
		printf("将编号为 %d 的盘子从 %c 移到 %c\n",n,ch1,ch3);
		towerofHanoi(n-1,ch2,ch1,ch3);
	}
	return;
}