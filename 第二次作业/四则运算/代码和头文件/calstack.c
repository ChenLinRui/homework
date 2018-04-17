#include <stdio.h>
#include "calstack.h" 
#include <stdlib.h>
#define maxsize    20


//˳��ջ(���������)
Status initStack(SqStack *s)						//��ʼ��ջ
{
	s->elem = (ElemType	*)malloc(maxsize * sizeof(ElemType));	//Ϊ��������ռ�
	s->top = -1;
	return OK;
}


Status isEmptyStack(SqStack *s)								//�ж�ջ�Ƿ�Ϊ��,�շ���ERROR
{
	if (s->top == -1)
		return ERROR;
	return OK;
}


int getTopStack(SqStack *s)					//�õ�ջͷԪ��
{
	if (s->top == -1)									//��ջΪ��,����ERROR
		return ERROR;
	 
	return  s->elem[s->top];
}


Status clearStack(SqStack *s)								//���ջ
{
	ElemType *temp = 0;
	while (s->top != -1)									//��ջ��Ϊ�գ���ջ
	{
		s->top = -1;
		s->elem = 0;
	}
	printf("��ճɹ�\n");
	return OK;
}


Status destoryStack(SqStack *s)								//����ջ
{

	free(s);
	printf("���ٳɹ�\n");
	return OK;

}


Status stackLength(SqStack *s, int length)					//���ջ����
{
	if (s->top != -1)									//��ջ���գ�Ϊlength��ֵջ�ĳ���
	{
		length = s->top + 1;
		return OK;
	}
	else printf("stack is empty");
	return ERROR;
}

int pushStack(SqStack *s, ElemType data)					//��ջ
{
	s->top++;												//ջ��ָ���һ
	s->elem[s->top] = data;								//����datas
	return data;
}

int popStack(SqStack *s)					//��ջ
{
	int e;
	if (s->top == -1)
		return ERROR;
	e = s->elem[s->top];
	s->top--;
	return e;
}
int operator(char s)
{
	switch (s)
	{
	case '(':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}
int calculate(ElemType *str)			//���㺯��
{
	int i = 0, j = 0,temp = 0;
	SqStack* num = (SqStack*)malloc(sizeof(SqStack));				//������ֵ�ջ
	SqStack* opt = (SqStack*)malloc(sizeof(SqStack));				//����������ջ
	initStack(num);
	initStack(opt);
	while (str[i] != '\0' || isEmptyStack(opt) != ERROR)			//ִ�����������ַ����黹û�����������ջ��û��ջ��ʱ
	{
		if (str[i] <= '9' && str[i] >= '0')							//���ַ�Ϊ����ʱ��ջ
		{
			temp = str[i] - '0';
			pushStack(num, temp);
			i++;

		}
		else
		{
			if ((isEmptyStack(opt) == ERROR) || (getTopStack(opt) == '(' && str[i] != ')') || operator(str[i]) > operator(getTopStack(opt)))	/*�������ջ��
																																				�������ջ��Ϊǰ�������ַ����鲻Ϊ������
																																				���ַ�����ķ��ż������ջ�����ż���ʱ*/
			{
				pushStack(opt, str[i]);
				i++;
				continue;
			}
			if (getTopStack(opt) == '(' && str[i] == ')')			//��ǰ���ų�ջ,���������������������ţ���
			{
				popStack(opt);
				i++;
				continue;
			}
			if ((str[i] == '\0' && isEmptyStack(opt) == OK) || (str[i] == ')' && getTopStack(opt) != '(') || operator(str[i]) <= operator(getTopStack(opt)))/*��������
																																							  ����������������ջδ��ʱ
																																							  ��ǰ�����ַ�Ϊ�������������ջ����Ϊǰ����
																																							  �������ַ��ȼ����ڻ���������ջ���ȼ�
																																							*/  
			{
				switch (popStack(opt))
				{
				case '+':
					pushStack(num, popStack(num) + popStack(num));
					break;
				case '-':
					j = popStack(num);
					pushStack(num, popStack(num) - j);
					break;
				case '*':
					pushStack(num, popStack(num) * popStack(num));
					break;
				case '/':
					j = popStack(num);
					pushStack(num, popStack(num) / j);
				}
				continue;
			}
		}


	}

	return popStack(num);


}
