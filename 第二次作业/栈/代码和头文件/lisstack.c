#include <stdio.h>
#include "stack.h" 
#include <stdlib.h>


//˳��ջ(���������)
Status initStack(SqStack *s, int sizes)						//��ʼ��ջ
{
	s->elem = (ElemType	*)malloc(sizes * sizeof(ElemType));	//Ϊ��������ռ�
	s->top = -1;
	s->size = sizes;
	printf("��ʼ���ɹ�\n");
	return OK;
}


Status isEmptyStack(SqStack *s)								//�ж�ջ�Ƿ�Ϊ��,�շ���ERROR
{
	if (s->top == -1)
	{
		printf("stack is empty\n");
		return ERROR;
	}

	else printf("stack is not empty\n");
	return OK;
}


Status getTopStack(SqStack *s, ElemType *e)					//�õ�ջͷԪ��
{
	if (s->top == -1)									//��ջΪ��,����ERROR
		return ERROR;
	else *e = s->elem[s->top];
	return OK;
}


Status clearStack(SqStack *s)								//���ջ
{
	ElemType *temp = 0;
	while (s->top != -1)									//��ջ��Ϊ�գ���ջ
	{
		popStack(s, temp);
	}
	return OK;
}


Status destoryStack(SqStack *s)								//����ջ
{

	free(s);
	return OK;

}


Status stackLength(SqStack *s, int *length)					//���ջ����
{
	if (s->top != -1)									//��ջ���գ�Ϊlength��ֵջ�ĳ���
	{
		*length = s->top + 1;
		return OK;
	}
	else printf("stack is empty");
	return ERROR;
}

Status pushStack(SqStack *s, ElemType datas)					//��ջ
{
	s->top++;												//ջ��ָ���һ
	s->elem[s->top] = datas;								//����datas
	printf("�ɹ���ջ\n");
	return OK;
}

Status popStack(SqStack *s, ElemType *datas)					//��ջ
{
	if (s->top == -1)
		return ERROR;
	*datas = s->elem[s->top];
	s->top--;
	printf("�ɹ���ջ\n");
	return OK;
}





//��ջ(���������)
Status initLStack(LinkStack *s)					//��ʼ��
{
	if (s == NULL)
	{
		printf("����ʧ��");
		return ERROR;
	}
	s->top = NULL;
	s->count = 0;
	printf("��ʼ���ɹ�\n");
	return OK;
}

Status isEmptyLStack(LinkStack *s)				//�ж������Ƿ�Ϊ��
{
	if ( s->count == 0)		//��������������Ϊ��
		return ERROR;
	printf("stack is not empty\n");
	return OK;
}

Status getTopLStack(LinkStack *s, ElemType *e)  //�õ�����ͷԪ��
{
	if ( s->count != 0)
	{
		*e = s->top->data;
		return OK;
	}
	return ERROR;
}

Status clearLStack(LinkStack *s)   //�������
{
	while ( s->count != 0)									//������Ϊ�գ���ջ
	{
		StackNode* P = (StackNode*)malloc(sizeof(StackNode));
		P = s->top;
		s->top = s->top->next;
		s->count--;
		free(P);
	}
	printf("��ճɹ�\n");

	return OK;
}

Status destoryLStack(LinkStack *s)   //��������(����������յ�������)
{
	if (s->count == 0)
	{ 
		free(s);
		printf("���ٳɹ�\n");
		return OK;
	}
	return ERROR;
}

Status LStackLength(LinkStack *s, int *length)    //���������
{
	if ( s->count != 0)
	{
		*length = s->count;
		return  OK;
	}
	return ERROR;
}

Status pushLStack(LinkStack *s, ElemType datas)   //��ջ
{
	StackNode* P = (StackNode*)malloc(sizeof(StackNode));	//ΪP����ռ�
	if (P == NULL)
		return ERROR;
	P->data = datas;		//��ֵ
	P->next = s->top;		//����	
	s->count++;				//����һ��Ԫ�ظ���
	s->top = P;				//��topջ��ָ����ǰ
	printf("��ջ�ɹ�\n");
	return OK;

}

Status popLStack(LinkStack *s, ElemType *datas)   //��ջ
{
	StackNode* P = (StackNode*)malloc(sizeof(StackNode));	//ΪP����ռ�
	if (s->top == NULL || s->count == 0)
	{
		printf("��ջ������");
		return ERROR;
	}

	P = s->top;
	*datas = P->data;	
	s->top = s->top->next;
	s->count--;
	free(P);
	printf("��ջ�ɹ�\n");
	return OK;

}
