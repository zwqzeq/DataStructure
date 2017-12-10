#include "SeqStack.h"

//��ʼ��
void StackInitiate(SeqStack*S) {
	S->top = 0;
}

//ջ���ǿշ�
int StackNotEmpty(SeqStack S) {
	if (S.top <= 0) {
		return 0;//Ϊ�շ���0
	}
	else {
		return 1;//�ǿշ���1
	}
}

//��ջ
int StackPush(SeqStack*S, Datatype x) {
	if (S->top >= MaxStackSize) {
		printf("��ջ�������޷����룡\n");
		return 0;
	}
	S->stack[S->top] = x;
	(S->top)++;
	return 1;
}


//��ջ
int StackPop(SeqStack*S, Datatype *d) {
	if (S->top <= 0) {                /*Ϊʲôtop=0ʱ����ջҲΪ���أ�
									  top��ǵ���ջ��λ�ã���ջ�����ǿյģ�top��ǵ�λ�����ǿ�
									  ���磺��top=0ʱ��top����ڵ�һ����㣨���0����ʱ����Ԫ�ظ���Ϊ0��
									  �������һ�����ݵ���ջ������һ��Ԫ����ջ��ʱ����top�����ƶ�һλ��top=1��top��ǵ�λ��Ϊ�����1������ջ�ĵڶ�����㣬��ʱ��ջ�д�ŵ�����Ԫ�ظ���Ϊ1
									  */
		printf("��ջ�ѿ��޷���ջ��");
		return 0;
	}
	*d = S->stack[S->top-1];
	S->top--;
	return 1;
}

//ȡջ��Ԫ��
int StackTop(SeqStack*S, Datatype *d) {
	if (S->top <= 0) {
		printf("��ջ�ѿ��޷�ȡԪ��");
	}
	else {
		*d = S->stack[S->top - 1];
	}
}