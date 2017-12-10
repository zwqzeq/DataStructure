#include"Expr.h"                             //导入自定义的头文件
#include<stdlib.h>
#include<iostream>
using namespace std;

//解析表达式
double parse(char expr[])
{

	OPND opnd = NULL;              //操作数栈
	OPTR optr = NULL;                //操作符栈

	//初始化栈
	init(opnd);
	init(optr);

	for (int i = 0; expr[i] != '\0'; i++)
	{
		//读一个字符
		char c = expr[i];
		//数字
		if (c >= '0'&&c <= '9' || c == '.')
		{
			//处理操作数
			char token[20] = { 0 };
			int j = 0;
			while (expr[i + j] > '0'&&expr[i + j] <= '9' || expr[i + j] == '.')

			{

				token[j] = expr[i + j];
				j++;
			}
			token[j] = '\0';
			i = i + j - 1;
			//将token转成数字，压到操作数栈
			double value = atof(token);
			push(opnd, value);

		}

		//符号及运算；
		else
		{
			//处理操作符
			if (isEmpty(optr))
			{
				push(optr, c);//操作符为空直接入栈
			}
			else {
				char op = 0;
				getTop(optr, op);
				switch (precede(op, c))
				{
				case'<':push(optr, c);//栈顶元素优先级低，直接入栈
					break;
				case'=':pop(optr, op);//弹出括号
					break;
				case'>'://退栈并将运算结果入栈
					double a = 0;
					double b = 0;
					//弹出两个操作数和一个操作符
					pop(opnd, b);
					pop(opnd, a);
					pop(optr, op);
					//计算结果，入栈
					push(opnd, calc(a, op, b));
					i--;/*关键，继续比较当前操作符;由于进行了一次计算，栈顶操作符发生了改变。当前操作符需要与栈顶操作符进行再次比较，使用i--让parse扫描表达式循环一次*/
					break;
				}//switch结束
			}
		}
	}
	//最后一次运算
	while (optr != NULL)
	{
		if (!isEmpty(optr))
		{
			double a = 0;
			double b = 0;
			char op = 0;
			//操作数、操作符出栈
			pop(opnd, b);
			pop(opnd, a);
			pop(optr, op);
			//计算结果入栈
			push(opnd, calc(a, op, b));
		}
	}
	//最终结果
	double value = 0;
	pop(opnd, value);
	return value;
}

//操作数链表初始化
int init(OPND & opnd){
	//撤销链表元素
	while(opnd != NULL) {
		//删除旧结点
		OPND temp = opnd;       //temp,和opnd指向同一个结点
		opnd = temp -> next;    //opnd向后移动一位
		free(temp);                     //释放temp指向的旧结点空间
	}
	opnd=NULL;                    //opnd置空，不指向任何结点
	return 0;
}

//操作符栈初始化
int init(OPTR &optr)
{
	//销毁链表元素
	while (optr != NULL)
	{
		OPTR temp = optr;
		optr = temp->next;
		free(temp);
	}
	optr = NULL;
	return 0;
}

//操作数入栈
int push(OPND & opnd, const double value)
{
	//新增结点，栈顶上移
	OPND temp = (OPND)malloc(sizeof(StackNodeOPND));
	if(!temp){
	    return -1;    //新增结点失败
	}
	temp->value=value;//将操作数存放到刚创建的结点
	temp->next=opnd;
	opnd = temp;
	return 0;
}

//操作符入栈
int push(OPTR &optr, const char op)
{
	//新增动态节点，栈顶上移；
	OPTR temp = (OPTR)malloc(sizeof(StackNodeOPTR));
	if (!temp) {
		return -1;
	}
	temp->op = op;
	temp->next = optr;
	optr = temp;
	return 0;
}

//操作数出栈
int pop(OPND &opnd,double &value){
	if(opnd==NULL){                      //空栈
	     return -1;
	}
	//弹出操作数
	 value=opnd->value;
	//删除旧结点
	OPND temp =opnd;
	opnd = temp->next;
	free(temp);
	return 0;
}

//符号操作出栈
int pop(OPTR &optr, char &op) {
	if (optr == NULL)//空栈
	{
		return -1;
	}
	op = optr->op;
	//弹出操作数
	OPTR temp = optr;
	optr = temp->next;
	free(temp);
	return 0;
}

//获得栈顶操作数
int getTop(OPND &opnd,double &value)
{
	if(opnd==NULL){
	return -1;
	}
	value = opnd->value;
	return 0;   
}

//获得栈顶操作符
int getTop(OPTR &optr, char &op)
{
	if (optr == NULL)
	{
		return -1;
	}
	op = optr->op;
	return 0;
}

//判断符号栈是否为空
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

//运算符优选级
char precede(char a,char b)
{
	char aPriorTable[6][6]={//运算符之间的优选级关系存放在二维数组中
	//加号减号乘号/除号左括号右括号
		{'>','>','<','<','<','>'},                //加号
		{'>','>','<','<','<','>'},                //减号
		{'>','>','>','>','<','>'},                //乘号
		{'>','>','>','>','<','>'},                //除号
		{'<','<','<','<','<','='},                //左括号
		{'>','>','>','>','>','>'}};              //右括号
		int x=-1;
		int y=-1;
		char opr[]="+-*/()" ;
		for(int i=0;i<6;i++) {
		  if (a  ==  opr[i])  x=i ;
		  if (b  ==  opr[i])  y=i ;
		}
		return aPriorTable[x][y] ;
	}

//表达式计算
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
			cout<<"表达式错误！"<<endl;
		    exit(0);        //退出程序
		}
	}   //switch结束
	return value;
	}

//程序入口
int main(){
	cout<<"============表达式求值============"<<endl;   //打印菜单
	cout<<"1支持四则运算符：+-*/"<<endl;
	cout<<"2 支持括号（）"<<endl;
	cout<<"3 支持浮点数."<<endl;
	cout <<"请输入表达式，按回车结束."<<endl;
    cout<<"例如：5*（3+4）/2"<<endl;

	//输入表达式
	char expr[256]={0};
	cout<<"表达式：";
	cin>>expr;

	//解析表达式并输出结果
	cout<<"结果："<<parse(expr)<<endl;
	return 0;
}



