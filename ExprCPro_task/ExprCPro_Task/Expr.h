
//定义操作数栈的结点
typedef struct StackNodeOPND
{
	double value;                 //操作数
	StackNodeOPND *next;//指针域
} *OPND;                           //定义OPND代替struct StackNodeOPND *类型

//函数声明
int init(OPND &opnd);//初始化操作数栈
int push(OPND &opnd,const double value);//操作数入栈
int pop(OPND &opnd,double &value);    //操作数出栈
int getTop(OPND &opnd,double & value);//获得操作数栈顶元素
int getLenght(OPND &opnd);//获得操作数栈元素个数

//定义操作符栈的结点
typedef struct StackNodeOPTR
{
	char op;                           //操作符
	StackNodeOPTR *next;  //指针域
} *OPTR;                            //定义OPTR代替struct StackNodeOPTR *类型

//函数声明
int init(OPTR &optr);//初始化操作符栈
int push(OPTR &optr,const char op);//操作符入栈
int pop(OPTR &optr,char &op);//操作符出栈
int getTop(OPTR &optr,char & op);//获得操作符栈顶元素
int getLenght(OPTR &optr);//获得操作符栈元素个数
int isEmpty(OPTR &optr);   //判断操作符栈是否为空

double parse (char expr[]);                          //解析表达式
char precede(char a,char b);                       //操作符的优先级
double calc(double a,char theta,double b);//计算表达式
