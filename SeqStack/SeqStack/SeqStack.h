#pragma once
#define MaxStackSize 100               //�궨��

typedef int Datatype;                     

/*
˳���ջ��˳���Ĳ�ͬ����ͬ�㣺
��ͬ�㣺˳���ջ��˳�������ݳ�Ա��ͬ
��ͬ�㣺˳���ջ����ջ�ͳ�ջֻ�ܶԵ�ǰջ��Ԫ�ؽ���
*/
typedef struct
{
	Datatype stack[MaxStackSize];//˳���ջ�Ĵ�С
	int top;//��¼��ǰջ��λ�ã�Ҳ�����Դˣ�top��ֵ��֪����ǰջ�д���˶���Ԫ�أ�;ע�⣺ÿ���ջ�д��һ������top�������ƶ�һλ��top��ǵ�λ��ʼ����һ����λ�ã�û�д�����ݣ�
}SeqStack;

//��������
void StackInitiate(SeqStack*S);//��ʼ��
int StackNotEmpty(SeqStack S);//ջ���ǿշ�
int StackPush(SeqStack*S,Datatype x);//��ջ
int StackPop(SeqStack*S,Datatype *d);//��ջ
int StackTop(SeqStack*S, Datatype *d);//ȡջ��Ԫ��

