#include<stdlib.h>
#include<iostream>
#include"Polyn.h"
using namespace std;

//创建空链表
void CreatePolyn(PLinkList &sPolyn) {
	sPolyn = (PLinkList)malloc(sizeof(PLNODE));        //为头节点开辟空间
	if (sPolyn == NULL) {                                             //判断头结点sPolyn是否为空 ,是就退出
		exit(0);                                                                //退出 
	}
	sPolyn->next = NULL;                                          //头结点指针域置空
}

//将结点插入链表尾部
void ListInsert(PLinkList sPolyn, PLNODE sNewNode) {
	PLinkList sTemp = sPolyn;
	PLinkList psNewNode = (PLinkList)malloc(sizeof(PLNODE));//创建一个结点
	//判断psNewNode是否为空,是就退出
	*psNewNode = sNewNode;                                //指针所指对象的值修改为sNewNode
	while (sTemp->next != NULL) {
		sTemp = sTemp->next;
	}
	sTemp->next = psNewNode;                           //节点插入链表尾部
	psNewNode->next = NULL;                            //将尾节点的指向置为空
}

//两多项式相加
PLinkList AddPolyn(PLinkList sPolyn1, PLinkList sPolyn2) {
	PLinkList sPolynAdd;            
	CreatePolyn(sPolynAdd);                               //创建和多项式空链表

	//定义两个指针分别指向第一,二个多项式的第一项
	PLinkList   sPolyn1Temp = sPolyn1->next;
	PLinkList   sPolyn2Temp = sPolyn2->next;
	PLNODE   sNewNode;                                   //要插入和多项式中的新节点
	while ((sPolyn1Temp != NULL) && (sPolyn2Temp != NULL))
	{
		int nEx = (sPolyn1Temp->nExpn) - (sPolyn2Temp->nExpn);  //计算第一个和第二个多项式指数差
															
		if (nEx<0) {                                                 //当指数差小于0
			sNewNode.nExpn = sPolyn1Temp->nExpn;
			sNewNode.dbCoef = sPolyn1Temp->dbCoef;
			ListInsert(sPolynAdd, sNewNode);     //将提取出来的项存入和链表
			sPolyn1Temp = sPolyn1Temp->next;//移动sPolynlTemp的节点
		}
		else if (nEx == 0) {                                  //指数差等于零
			double dbCo = sPolyn1Temp->dbCoef + sPolyn2Temp->dbCoef;
			if (dbCo != 0.0) {
				sNewNode.nExpn = sPolyn1Temp->nExpn;
				sNewNode.dbCoef = dbCo;
				ListInsert(sPolynAdd, sNewNode);//将提取出的的项存入和链表
			}
			sPolyn1Temp = sPolyn1Temp->next;
			sPolyn2Temp = sPolyn2Temp->next;
		}
		else {
			sNewNode.nExpn = sPolyn2Temp->nExpn;
			sNewNode.dbCoef = sPolyn2Temp->dbCoef;
			ListInsert(sPolynAdd, sNewNode);
			sPolyn2Temp = sPolyn2Temp->next;
		}
	}

	//定义新链表，判断哪个没遍历完赋值给新链表
	PLinkList sPolynTemp;
	CreatePolyn(sPolynTemp);//创建空链表，
	PLNODE sNewNode2;
	if (sPolyn1Temp != NULL&&sPolyn2Temp == NULL) {
		sNewNode2.nExpn = sPolyn1Temp->nExpn;
		sNewNode2.dbCoef = sPolyn1Temp->nExpn;
		ListInsert(sPolynTemp, sNewNode2);
		sPolyn1Temp = sPolyn1Temp->next;
	}
	else if (sPolyn2Temp != NULL&&sPolyn1Temp == NULL)
	{
		sNewNode2.nExpn = sPolyn2Temp->nExpn;
		sNewNode2.dbCoef = sPolyn2Temp->nExpn;
		ListInsert(sPolynTemp, sNewNode2);
		sPolyn2Temp = sPolyn2Temp->next;
	}
	else if (sPolyn2Temp == NULL&&sPolyn1Temp == NULL)
	{
		return sPolynAdd;
	}
	while (sPolynTemp != NULL) {//链接新链表中剩余结点到链表中
		sNewNode.nExpn = sPolynTemp->nExpn;
		sNewNode.dbCoef = sPolynTemp->dbCoef;
		ListInsert(sPolynAdd, sNewNode);
		sPolynTemp = sPolynTemp->next;
	}
	return sPolynAdd;
}

//指定格式输出多项式的任意一项
void PrintPoly(PLNODE sPTemp) {
	
	if (sPTemp.nExpn == 0) {                 //当指数为0，直接输出系数
		cout << sPTemp.dbCoef;
	}

	else if (sPTemp.dbCoef == 1) {	   //当系数为1时
		if (sPTemp.nExpn == 1) {             //指数为1
			cout << "x";
		}
		else {                                             //系数为1，指数不为0,1
			cout << "x^" << sPTemp.nExpn;
		}
	}
	
	else if (sPTemp.dbCoef == -1) {           //当系数为-1
		if (sPTemp.nExpn == 1) {           //指数为1
			cout << "-x";
		}
		else {                                     //系数为-1，指数不为0,1
			cout << "-x^" << sPTemp.nExpn;
		}
	}
	else                                         //系数不为1，-1，指数为1
	{
		if (sPTemp.nExpn == 1) {         //系数不为1，-1，指数为1，
			cout << sPTemp.dbCoef << "x";
		}
		else      //指数不为0,1；系数不为-1，1
		{
			cout << sPTemp.dbCoef << "x^" << sPTemp.nExpn;
		}
	}
}

//一元多项式整体输出
void PrintPolyn(PLinkList sPolyn) {
	int nIndex = 0;
	PLinkList sPTemp = sPolyn->next;//sPTemp指向第一个项数
	while (sPTemp != NULL) {
		nIndex++;
		if (nIndex == 1) {                      //直接输出第一项
			PrintPoly(*sPTemp);
		}
		else if (sPTemp->dbCoef>0) {//如果系数大于0,先输出+号
			cout << "+";
			PrintPoly(*sPTemp);
		}
		else {
			PrintPoly(*sPTemp);
		}
		sPTemp = sPTemp->next;
	}
}

//释放链表
void FreePolyn(PLinkList sPolyn) {
	PLinkList sTemp = sPolyn;
	while (sPolyn != NULL) {
		sPolyn = sPolyn->next;
		free(sTemp);
		sTemp = sPolyn;
	}
}

//冒泡法排序
PLinkList ListSort(PLinkList sPolyn) {
	PLinkList sTemp1, sTemp2;//这两个变量表示冒泡排序的两个遍历结点变量
	int nTemp = 0;                   //中间变量
	double dbTemp = 0.0;      //中间变量
	for (sTemp1 = sPolyn; sTemp1 != NULL; sTemp1 = sTemp1->next) {
		for (sTemp2 = sTemp1->next; sTemp2 != NULL; sTemp2 = sTemp2->next) {
			//如果sTemp1结点数值大，则交换两个结点的指数
			if (sTemp1->nExpn>sTemp2->nExpn) {
				nTemp = sTemp2->nExpn;
				sTemp2->nExpn = sTemp1->nExpn;
				sTemp1->nExpn = nTemp;
				dbTemp = sTemp2->dbCoef;//同时交换两个结点系数
				sTemp2->dbCoef = sTemp1->dbCoef;
				sTemp1->dbCoef = dbTemp;
			}
		}
	}
	return sPolyn;
}