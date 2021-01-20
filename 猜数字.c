#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("***********************\n");
	printf("**** 1.play 0.exit ****\n");
	printf("***********************\n");
}
void game()
{
	int a = rand() / 100 + 1;          //rand函数可以返回一个从0~32767的随机数  
	int guss;                          //注：rand函数利用线性同余法产生的随机数不是真正的随机数，只是循环周期特别长，在一定范围内是随机的
	while (1)                          //在调用rand之前需要先调用srand函数设置随机数种子（初始值）
	{                                  //注：若不设置随机数种子则rand函数调用时默认设置为1
		printf("输入数字(1~100)\n");   //    若设置的初始值相同，则每次产生的随机数序列相同
	    scanf("%d", &guss);            //随机生成X`Y内的数字：rand()%(X-Y)+Y
		if (guss < a)
			printf("小了\n");
		else if (guss > a)
			printf("大了\n");
		else
		{
			printf("对了\n");
			break;
		}
	}
}
int main(int argc, char *argv[]) 
{
	srand((unsigned int)time(NULL));    //srand函数可以设置一个随机数种子
	int input;                          //void srand(unsigned int seed)	
	do                                  //参数seed必须为不断变化的unsigned int类型
	{                                   //若seed的值相同，则随机数种子相同，即rand产生的随机数序列相同
		menu();                         //用time函数可以生成不同的seed值
		printf("请选择(1/0)>:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:printf("退出成功\n");
			break;
		default:printf("输入错误，重新选择(1/0)\n");
			break;
		}
	} while (input);
	
	return 0;
}
