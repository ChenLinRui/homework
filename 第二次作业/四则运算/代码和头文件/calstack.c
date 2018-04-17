#include <stdio.h>
#include "calstack.h" 
#include <stdlib.h>
#define maxsize    20


//顺序栈(基于数组的)
Status initStack(SqStack *s)						//初始化栈
{
	s->elem = (ElemType	*)malloc(maxsize * sizeof(ElemType));	//为数组申请空间
	s->top = -1;
	return OK;
}


Status isEmptyStack(SqStack *s)								//判断栈是否为空,空返回ERROR
{
	if (s->top == -1)
		return ERROR;
	return OK;
}


int getTopStack(SqStack *s)					//得到栈头元素
{
	if (s->top == -1)									//若栈为空,返回ERROR
		return ERROR;
	 
	return  s->elem[s->top];
}


Status clearStack(SqStack *s)								//清空栈
{
	ElemType *temp = 0;
	while (s->top != -1)									//当栈不为空，出栈
	{
		s->top = -1;
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


Status stackLength(SqStack *s, int length)					//检测栈长度
{
	if (s->top != -1)									//若栈不空，为length赋值栈的长度
	{
		length = s->top + 1;
		return OK;
	}
	else printf("stack is empty");
	return ERROR;
}

int pushStack(SqStack *s, ElemType data)					//入栈
{
	s->top++;												//栈顶指针加一
	s->elem[s->top] = data;								//插入datas
	return data;
}

int popStack(SqStack *s)					//出栈
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
int calculate(ElemType *str)			//计算函数
{
	int i = 0, j = 0,temp = 0;
	SqStack* num = (SqStack*)malloc(sizeof(SqStack));				//存放数字的栈
	SqStack* opt = (SqStack*)malloc(sizeof(SqStack));				//存放运算符的栈
	initStack(num);
	initStack(opt);
	while (str[i] != '\0' || isEmptyStack(opt) != ERROR)			//执行条件：当字符数组还没遍历或运算符栈还没出栈完时
	{
		if (str[i] <= '9' && str[i] >= '0')							//当字符为数字时入栈
		{
			temp = str[i] - '0';
			pushStack(num, temp);
			i++;

		}
		else
		{
			if ((isEmptyStack(opt) == ERROR) || (getTopStack(opt) == '(' && str[i] != ')') || operator(str[i]) > operator(getTopStack(opt)))	/*当运算符栈空
																																				当运算符栈顶为前括号且字符数组不为后括号
																																				当字符数组的符号级别高于栈顶符号级别时*/
			{
				pushStack(opt, str[i]);
				i++;
				continue;
			}
			if (getTopStack(opt) == '(' && str[i] == ')')			//把前括号出栈,不参与其他运算避免空括号（）
			{
				popStack(opt);
				i++;
				continue;
			}
			if ((str[i] == '\0' && isEmptyStack(opt) == OK) || (str[i] == ')' && getTopStack(opt) != '(') || operator(str[i]) <= operator(getTopStack(opt)))/*进行运算
																																							  当数组遍历且运算符栈未空时
																																							  当前数组字符为后括号且运算符栈顶不为前括号
																																							  当数组字符等级低于或等于运算符栈顶等级
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
