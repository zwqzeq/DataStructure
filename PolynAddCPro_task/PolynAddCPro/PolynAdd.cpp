#include <iostream>
#include <stdlib.h>
#include "structDefine.h"
#include "Polyn.h"

using namespace std;

//函数声明
void InputData(int nOrder, PLinkList &sPolyn);
bool GetInt(int &value);

//程序入口
int main() {
	cout << "/*注意:系数为浮点类型,指数为整数(可为负)类型" << endl;
	cout << "请按指数从小到大的顺序输入多项式*/\n\n";
	//创建一元多项式
	PLinkList sPolynA = NULL;
	PLinkList sPolynB = NULL;
	PLinkList sPolynC = NULL;
	
	InputData(1, sPolynA);             //输入数据
	ListSort(sPolynA);                     //排序
	cout << endl;                          //换行
	InputData(2, sPolynB);         
	ListSort(sPolynB);                  
	cout << endl;

	//一元多项式求和
	sPolynC = AddPolyn(sPolynA, sPolynB);
	cout << "多项式和为:";
	//打印和一元多项式
	PrintPolyn(sPolynC);
	cout << endl;      //换行
	//释放链表
	FreePolyn(sPolynA);
	FreePolyn(sPolynB);
	FreePolyn(sPolynC);
	system("pause");           
	return 0;
}

//输入一元多项式数据
void InputData(int nOrder, PLinkList &sPolyn) {
	CreatePolyn(sPolyn);//创建空链表
	PLNODE sNewNode;//定义新节点
	int i, sum;          //项数
	double dbCoef;//系数
	int nExpn;        //指数
	cout << "\n请输入第" << nOrder << "个多项式项数:";
	GetInt(sum);    //判断指数是否输入的是整数
	for (i = 1; i <= sum; i++)
	{
		cout << "请输入第" << i << "项的系数:";
		cin >> dbCoef;                              //输入
		cout << "请输入第" << i << "项的指数:";
		GetInt(nExpn);
		cout << endl; //换行
		sNewNode.dbCoef = dbCoef;//存入数据
		sNewNode.nExpn = nExpn;
		ListInsert(sPolyn, sNewNode);//将新节点插入多项式链表的尾部
	}
	//打印多项式链表
	cout << "该多项式可表达为:";
	PrintPolyn(sPolyn);
}

//检查是否为整数
bool GetInt(int &value) {
	char str[256] = { 0 };
	fflush(stdin);//清除缓存区
	gets_s(str, 256);//等待输入数据,并将数据存到str中
	unsigned int index = 1;
	int nTemp = 0;
	//判断输入是否为负数
	if (str[0] == '-') {
		nTemp = 1;
	}
	//判断str中每个字符是否为0到9，是就继续循环，不是就返回false
	for (index = nTemp; index < strlen(str); index++) {
		if (str[index] > 9 && str[index] < 0) {
			cout << "数据输入有误";
			return false;
		}
		value = atoi(str);//判断输入的的字符串数字，把字符串转换为整数型
		return true;
	}
}




