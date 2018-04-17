#include <stdio.h>
#include "stack.h" 
#include <stdlib.h>


//顺序栈(基于数组的)
Status initStack(SqStack *s, int sizes)						//初始化栈
{
	s->elem = (ElemType	*)malloc(sizes * sizeof(ElemType));	//为数组申请空间
	s->top = -1;
	s->size = sizes;
	printf("初始化成功\n");
	return OK;
}


Status isEmptyStack(SqStack *s)								//判断栈是否为空,空返回ERROR
{
	if (s->top == -1)
	{
		printf("stack is empty\n");
		return ERROR;
	}

	else printf("stack is not empty\n");
	return OK;
}


Status getTopStack(SqStack *s, ElemType *e)					//得到栈头元素
{
	if (s->top == -1)									//若栈为空,返回ERROR
		return ERROR;
	else *e = s->elem[s->top];
	return OK;
}


Status clearStack(SqStack *s)								//清空栈
{
	ElemType *temp = 0;
	while (s->top != -1)									//当栈不为空，出栈
	{
		s->top = -1;
		s->size = 0;
		s->elem = 0;
	}
	printf("清空成功\n");
	return OK;
}


Status destoryStack(SqStack *s)								//销毁栈
{

	free(s);
	printf("销毁成功\n");
	return OK;

}


Status stackLength(SqStack *s, int *length)					//检测栈长度
{
	if (s->top != -1)									//若栈不空，为length赋值栈的长度
	{
		*length = s->top + 1;
		return OK;
	}
	else printf("stack is empty");
	return ERROR;
}

Status pushStack(SqStack *s, ElemType datas)					//入栈
{
	s->top++;												//栈顶指针加一
	s->elem[s->top] = datas;								//插入datas
	printf("成功入栈\n");
	return OK;
}

Status popStack(SqStack *s, ElemType *datas)					//出栈
{
	*datas = 1;
	if (s->top == -1)
		return ERROR;
	*datas = s->elem[s->top];
	s->top--;
	printf("成功出栈\n");
	return OK;
}

//链栈(基于链表的)
Status initLStack(LinkStack *s)					//初始化
{
	s = (LinkStack*)malloc(sizeof(LinkStack));	//为s申请空间
	if (s == NULL)
	{
		printf("申请失败");
		return ERROR;
	}
	s->top = NULL;
	s->count = 0;
	return OK;
}

Status isEmptyLStack(LinkStack *s)				//判断链表是否为空
{
	if (s->top == NULL || s->count == 0)		//满足条件则链表为空
		return ERROR;
	return OK;
}

Status getTopLStack(LinkStack *s, ElemType *e)  //得到链表头元素
{
	if (isEmptyLStack(s))
	{
		*e = s->top->data;
		return OK;
	}
	return ERROR;
}

Status clearLStack(LinkStack *s)   //清空链表
{
	ElemType *temp = 0;
	while (isEmptyLStack(s))									//当链表不为空，出栈
	{
		temp = 0;
		popLStack(s, temp);
	}
	printf("清空成功");
	return OK;
}

Status destoryLStack(LinkStack *s)   //销毁链表
{
	if (isEmptyLStack(s))
	{
		clearLStack(s);			//先清空后删除
		free(s);
		printf("销毁成功");
		return OK;
	}
	return ERROR;
}

Status LStackLength(LinkStack *s, int *length)    //检测链表长度
{
	if (isEmptyLStack(s))
	{
		*length = s->count;
		return  OK;
	}
	return ERROR;
}

Status pushLStack(LinkStack *s, ElemType datas)   //入栈
{
	StackNode* P = (StackNode*)malloc(sizeof(StackNode));	//为P申请空间
	if (P == NULL)
		return ERROR;
	P->data = datas;		//赋值
	P->next = s->top;		//链接	
	s->count++;				//增加一个元素个数
	s->top = P;				//将top栈顶指针提前
	return OK;

}

Status popLStack(LinkStack *s, ElemType *datas)   //出栈
{
	StackNode* P = (StackNode*)malloc(sizeof(StackNode));	//为P申请空间
	if (s->top == NULL)
	{
		printf("空栈，下溢");
		return ERROR;
	}
	*datas = s->top->data;
	P = s->top;
	s->top = s->top->next;
	s->count--;
	free(P);
	printf("出栈成功");
	return OK;

}
