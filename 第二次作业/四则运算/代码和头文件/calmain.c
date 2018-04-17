#include <stdio.h>
#include "calstack.h" 
#include <stdlib.h>
#define maxsize   20


void main()
{
	ElemType str[maxsize] = { "" };
	printf("请输入中缀表达式（只限十以内四则运算，请用英文符号）\n");
	scanf_s("%s", str,20);
	int result = 0;
	result = calculate(str);
	printf("结果为%d\n",result);
	system("pause");

}