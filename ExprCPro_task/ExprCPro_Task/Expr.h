
//���������ջ�Ľ��
typedef struct StackNodeOPND
{
	double value;                 //������
	StackNodeOPND *next;//ָ����
} *OPND;                           //����OPND����struct StackNodeOPND *����

//��������
int init(OPND &opnd);//��ʼ��������ջ
int push(OPND &opnd,const double value);//��������ջ
int pop(OPND &opnd,double &value);    //��������ջ
int getTop(OPND &opnd,double & value);//��ò�����ջ��Ԫ��
int getLenght(OPND &opnd);//��ò�����ջԪ�ظ���

//���������ջ�Ľ��
typedef struct StackNodeOPTR
{
	char op;                           //������
	StackNodeOPTR *next;  //ָ����
} *OPTR;                            //����OPTR����struct StackNodeOPTR *����

//��������
int init(OPTR &optr);//��ʼ��������ջ
int push(OPTR &optr,const char op);//��������ջ
int pop(OPTR &optr,char &op);//��������ջ
int getTop(OPTR &optr,char & op);//��ò�����ջ��Ԫ��
int getLenght(OPTR &optr);//��ò�����ջԪ�ظ���
int isEmpty(OPTR &optr);   //�жϲ�����ջ�Ƿ�Ϊ��

double parse (char expr[]);                          //�������ʽ
char precede(char a,char b);                       //�����������ȼ�
double calc(double a,char theta,double b);//������ʽ
