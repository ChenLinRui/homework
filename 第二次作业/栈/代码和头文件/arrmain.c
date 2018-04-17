#include <stdio.h>
#include "stack.h" 
#include <stdlib.h>


void main()
{
	SqStack* s = (SqStack* )malloc(sizeof(SqStack));
	int sizes = 0;
	int data = 0;
	int e=1 ;
	int length=1 ;
	int datas=1  ;
	printf("请输出有多少数据要存入栈\n");
	scanf_s("%d", &sizes);
	initStack(s, sizes);

	for (int i = 0; i<sizes; i++)
	{
		printf("请输入第%d个数字\n", i + 1);
		scanf_s("%d", &data);
		pushStack(s, data);
	}
	printf("输入完成\n");
	isEmptyStack(s);

	getTopStack(s, &e);
	stackLength(s, &length);
	printf("现在输出栈顶元素%d，它为第%d个\n",e,length);

	printf("出栈一个数据\n");
	popStack(s, &datas);
	getTopStack(s, &e);
	stackLength(s, &length);
	printf("现在输出栈顶元素%d，它为第%d个\n",e,length);



	printf("清空栈\n");
	clearStack(s);

	printf("销毁栈\n");
	destoryStack(s);

	system("pause");




}