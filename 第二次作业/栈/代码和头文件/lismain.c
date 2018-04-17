#include <stdio.h>
#include "stack.h" 
#include <stdlib.h>


void main()
{
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	int sizes = 1;
	int data = 1;
	int e=1;
	int length=1 ;
	int datas=1  ;
	printf("请输出有多少数据要存入链栈\n");
	scanf_s("%d", &sizes);
	initLStack(s);

	for (int i = 0; i<sizes; i++)
	{
		printf("请输入第%d个数字\n", i + 1);
		scanf_s("%d", &data);
		pushLStack(s, data);
	}
	printf("输入完成\n");
	isEmptyLStack(s);

	getTopLStack(s, &e);
	LStackLength(s, &length);
	printf("现在输出栈顶元素%d，它为第%d个\n",e,length);

	printf("出栈一个数据\n");
	popLStack(s, &datas);
	printf("被出栈的数据为%d\n",datas);
	getTopLStack(s, &e);
	LStackLength(s,&length);
	printf("现在输出栈顶元素%d，它为第%d个\n",e,length);



	printf("清空栈\n");
	clearLStack(s);

	printf("删除栈\n");
	destoryLStack(s);

	system("pause");






}