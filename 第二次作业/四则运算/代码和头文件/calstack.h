#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
	ERROR = 0, OK = 1
}Status;

typedef char ElemType;

typedef struct SqStack {
	ElemType	*elem;
	int top;      //”√”⁄’ª∂•÷∏’Î
}SqStack;




Status initStack(SqStack *s);
Status isEmptyStack(SqStack *s);

Status clearStack(SqStack *s);
Status destoryStack(SqStack *s);
Status stackLength(SqStack *s, int length);
int getTopStack(SqStack *s);
int pushStack(SqStack *s, ElemType data);
int popStack(SqStack *s);
int calculate(ElemType *str);
int operator(ElemType s);





#endif // STACK_H_INCLUDED
