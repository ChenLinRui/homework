#include <stdio.h>
#include "calstack.h" 
#include <stdlib.h>
#define maxsize   20


void main()
{
	ElemType str[maxsize] = { "" };
	printf("��������׺���ʽ��ֻ��ʮ�����������㣬����Ӣ�ķ��ţ�\n");
	scanf_s("%s", str,20);
	int result = 0;
	result = calculate(str);
	printf("���Ϊ%d\n",result);
	system("pause");

}