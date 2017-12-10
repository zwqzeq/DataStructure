#include"Expr.h"                             //�����Զ����ͷ�ļ�
#include<stdlib.h>
#include<iostream>
using namespace std;

//�������ʽ
double parse(char expr[])
{

	OPND opnd = NULL;              //������ջ
	OPTR optr = NULL;                //������ջ

	//��ʼ��ջ
	init(opnd);
	init(optr);

	for (int i = 0; expr[i] != '\0'; i++)
	{
		//��һ���ַ�
		char c = expr[i];
		//����
		if (c >= '0'&&c <= '9' || c == '.')
		{
			//���������
			char token[20] = { 0 };
			int j = 0;
			while (expr[i + j] > '0'&&expr[i + j] <= '9' || expr[i + j] == '.')

			{

				token[j] = expr[i + j];
				j++;
			}
			token[j] = '\0';
			i = i + j - 1;
			//��tokenת�����֣�ѹ��������ջ
			double value = atof(token);
			push(opnd, value);

		}

		//���ż����㣻
		else
		{
			//���������
			if (isEmpty(optr))
			{
				push(optr, c);//������Ϊ��ֱ����ջ
			}
			else {
				char op = 0;
				getTop(optr, op);
				switch (precede(op, c))
				{
				case'<':push(optr, c);//ջ��Ԫ�����ȼ��ͣ�ֱ����ջ
					break;
				case'=':pop(optr, op);//��������
					break;
				case'>'://��ջ������������ջ
					double a = 0;
					double b = 0;
					//����������������һ��������
					pop(opnd, b);
					pop(opnd, a);
					pop(optr, op);
					//����������ջ
					push(opnd, calc(a, op, b));
					i--;/*�ؼ��������Ƚϵ�ǰ������;���ڽ�����һ�μ��㣬ջ�������������˸ı䡣��ǰ��������Ҫ��ջ�������������ٴαȽϣ�ʹ��i--��parseɨ����ʽѭ��һ��*/
					break;
				}//switch����
			}
		}
	}
	//���һ������
	while (optr != NULL)
	{
		if (!isEmpty(optr))
		{
			double a = 0;
			double b = 0;
			char op = 0;
			//����������������ջ
			pop(opnd, b);
			pop(opnd, a);
			pop(optr, op);
			//��������ջ
			push(opnd, calc(a, op, b));
		}
	}
	//���ս��
	double value = 0;
	pop(opnd, value);
	return value;
}

//�����������ʼ��
int init(OPND & opnd){
	//��������Ԫ��
	while(opnd != NULL) {
		//ɾ���ɽ��
		OPND temp = opnd;       //temp,��opndָ��ͬһ�����
		opnd = temp -> next;    //opnd����ƶ�һλ
		free(temp);                     //�ͷ�tempָ��ľɽ��ռ�
	}
	opnd=NULL;                    //opnd�ÿգ���ָ���κν��
	return 0;
}

//������ջ��ʼ��
int init(OPTR &optr)
{
	//��������Ԫ��
	while (optr != NULL)
	{
		OPTR temp = optr;
		optr = temp->next;
		free(temp);
	}
	optr = NULL;
	return 0;
}

//��������ջ
int push(OPND & opnd, const double value)
{
	//������㣬ջ������
	OPND temp = (OPND)malloc(sizeof(StackNodeOPND));
	if(!temp){
	    return -1;    //�������ʧ��
	}
	temp->value=value;//����������ŵ��մ����Ľ��
	temp->next=opnd;
	opnd = temp;
	return 0;
}

//��������ջ
int push(OPTR &optr, const char op)
{
	//������̬�ڵ㣬ջ�����ƣ�
	OPTR temp = (OPTR)malloc(sizeof(StackNodeOPTR));
	if (!temp) {
		return -1;
	}
	temp->op = op;
	temp->next = optr;
	optr = temp;
	return 0;
}

//��������ջ
int pop(OPND &opnd,double &value){
	if(opnd==NULL){                      //��ջ
	     return -1;
	}
	//����������
	 value=opnd->value;
	//ɾ���ɽ��
	OPND temp =opnd;
	opnd = temp->next;
	free(temp);
	return 0;
}

//���Ų�����ջ
int pop(OPTR &optr, char &op) {
	if (optr == NULL)//��ջ
	{
		return -1;
	}
	op = optr->op;
	//����������
	OPTR temp = optr;
	optr = temp->next;
	free(temp);
	return 0;
}

//���ջ��������
int getTop(OPND &opnd,double &value)
{
	if(opnd==NULL){
	return -1;
	}
	value = opnd->value;
	return 0;   
}

//���ջ��������
int getTop(OPTR &optr, char &op)
{
	if (optr == NULL)
	{
		return -1;
	}
	op = optr->op;
	return 0;
}

//�жϷ���ջ�Ƿ�Ϊ��
int isEmpty(OPTR &optr)
{
	if (optr == NULL)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//�������ѡ��
char precede(char a,char b)
{
	char aPriorTable[6][6]={//�����֮�����ѡ����ϵ����ڶ�ά������
	//�Ӻż��ų˺�/����������������
		{'>','>','<','<','<','>'},                //�Ӻ�
		{'>','>','<','<','<','>'},                //����
		{'>','>','>','>','<','>'},                //�˺�
		{'>','>','>','>','<','>'},                //����
		{'<','<','<','<','<','='},                //������
		{'>','>','>','>','>','>'}};              //������
		int x=-1;
		int y=-1;
		char opr[]="+-*/()" ;
		for(int i=0;i<6;i++) {
		  if (a  ==  opr[i])  x=i ;
		  if (b  ==  opr[i])  y=i ;
		}
		return aPriorTable[x][y] ;
	}

//���ʽ����
double calc(double a,char theta,double b)  {
    double value=0;
	switch (theta){
	case '+' :
		value = a+b;
		break;
	case '-' :
		value = a-b;
		break;
	case '*' :
		value = a*b;
		break;
	case '/' :
		value = a/b;
		break;
	default  :
		{
			cout<<"���ʽ����"<<endl;
		    exit(0);        //�˳�����
		}
	}   //switch����
	return value;
	}

//�������
int main(){
	cout<<"============���ʽ��ֵ============"<<endl;   //��ӡ�˵�
	cout<<"1֧�������������+-*/"<<endl;
	cout<<"2 ֧�����ţ���"<<endl;
	cout<<"3 ֧�ָ�����."<<endl;
	cout <<"��������ʽ�����س�����."<<endl;
    cout<<"���磺5*��3+4��/2"<<endl;

	//������ʽ
	char expr[256]={0};
	cout<<"���ʽ��";
	cin>>expr;

	//�������ʽ��������
	cout<<"�����"<<parse(expr)<<endl;
	return 0;
}



