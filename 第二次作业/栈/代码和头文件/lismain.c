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
	printf("������ж�������Ҫ������ջ\n");
	scanf_s("%d", &sizes);
	initLStack(s);

	for (int i = 0; i<sizes; i++)
	{
		printf("�������%d������\n", i + 1);
		scanf_s("%d", &data);
		pushLStack(s, data);
	}
	printf("�������\n");
	isEmptyLStack(s);

	getTopLStack(s, &e);
	LStackLength(s, &length);
	printf("�������ջ��Ԫ��%d����Ϊ��%d��\n",e,length);

	printf("��ջһ������\n");
	popLStack(s, &datas);
	printf("����ջ������Ϊ%d\n",datas);
	getTopLStack(s, &e);
	LStackLength(s,&length);
	printf("�������ջ��Ԫ��%d����Ϊ��%d��\n",e,length);



	printf("���ջ\n");
	clearLStack(s);

	printf("ɾ��ջ\n");
	destoryLStack(s);

	system("pause");






}