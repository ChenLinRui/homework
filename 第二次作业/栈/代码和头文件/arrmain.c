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
	printf("������ж�������Ҫ����ջ\n");
	scanf_s("%d", &sizes);
	initStack(s, sizes);

	for (int i = 0; i<sizes; i++)
	{
		printf("�������%d������\n", i + 1);
		scanf_s("%d", &data);
		pushStack(s, data);
	}
	printf("�������\n");
	isEmptyStack(s);

	getTopStack(s, &e);
	stackLength(s, &length);
	printf("�������ջ��Ԫ��%d����Ϊ��%d��\n",e,length);

	printf("��ջһ������\n");
	popStack(s, &datas);
	getTopStack(s, &e);
	stackLength(s, &length);
	printf("�������ջ��Ԫ��%d����Ϊ��%d��\n",e,length);



	printf("���ջ\n");
	clearStack(s);

	printf("����ջ\n");
	destoryStack(s);

	system("pause");




}