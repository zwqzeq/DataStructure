#include<stdlib.h>
#include<iostream>
#include"Polyn.h"
using namespace std;

//����������
void CreatePolyn(PLinkList &sPolyn) {
	sPolyn = (PLinkList)malloc(sizeof(PLNODE));        //Ϊͷ�ڵ㿪�ٿռ�
	if (sPolyn == NULL) {                                             //�ж�ͷ���sPolyn�Ƿ�Ϊ�� ,�Ǿ��˳�
		exit(0);                                                                //�˳� 
	}
	sPolyn->next = NULL;                                          //ͷ���ָ�����ÿ�
}

//������������β��
void ListInsert(PLinkList sPolyn, PLNODE sNewNode) {
	PLinkList sTemp = sPolyn;
	PLinkList psNewNode = (PLinkList)malloc(sizeof(PLNODE));//����һ�����
	//�ж�psNewNode�Ƿ�Ϊ��,�Ǿ��˳�
	*psNewNode = sNewNode;                                //ָ����ָ�����ֵ�޸�ΪsNewNode
	while (sTemp->next != NULL) {
		sTemp = sTemp->next;
	}
	sTemp->next = psNewNode;                           //�ڵ��������β��
	psNewNode->next = NULL;                            //��β�ڵ��ָ����Ϊ��
}

//������ʽ���
PLinkList AddPolyn(PLinkList sPolyn1, PLinkList sPolyn2) {
	PLinkList sPolynAdd;            
	CreatePolyn(sPolynAdd);                               //�����Ͷ���ʽ������

	//��������ָ��ֱ�ָ���һ,��������ʽ�ĵ�һ��
	PLinkList   sPolyn1Temp = sPolyn1->next;
	PLinkList   sPolyn2Temp = sPolyn2->next;
	PLNODE   sNewNode;                                   //Ҫ����Ͷ���ʽ�е��½ڵ�
	while ((sPolyn1Temp != NULL) && (sPolyn2Temp != NULL))
	{
		int nEx = (sPolyn1Temp->nExpn) - (sPolyn2Temp->nExpn);  //�����һ���͵ڶ�������ʽָ����
															
		if (nEx<0) {                                                 //��ָ����С��0
			sNewNode.nExpn = sPolyn1Temp->nExpn;
			sNewNode.dbCoef = sPolyn1Temp->dbCoef;
			ListInsert(sPolynAdd, sNewNode);     //����ȡ����������������
			sPolyn1Temp = sPolyn1Temp->next;//�ƶ�sPolynlTemp�Ľڵ�
		}
		else if (nEx == 0) {                                  //ָ���������
			double dbCo = sPolyn1Temp->dbCoef + sPolyn2Temp->dbCoef;
			if (dbCo != 0.0) {
				sNewNode.nExpn = sPolyn1Temp->nExpn;
				sNewNode.dbCoef = dbCo;
				ListInsert(sPolynAdd, sNewNode);//����ȡ���ĵ�����������
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

	//�����������ж��ĸ�û�����긳ֵ��������
	PLinkList sPolynTemp;
	CreatePolyn(sPolynTemp);//����������
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
	while (sPolynTemp != NULL) {//������������ʣ���㵽������
		sNewNode.nExpn = sPolynTemp->nExpn;
		sNewNode.dbCoef = sPolynTemp->dbCoef;
		ListInsert(sPolynAdd, sNewNode);
		sPolynTemp = sPolynTemp->next;
	}
	return sPolynAdd;
}

//ָ����ʽ�������ʽ������һ��
void PrintPoly(PLNODE sPTemp) {
	
	if (sPTemp.nExpn == 0) {                 //��ָ��Ϊ0��ֱ�����ϵ��
		cout << sPTemp.dbCoef;
	}

	else if (sPTemp.dbCoef == 1) {	   //��ϵ��Ϊ1ʱ
		if (sPTemp.nExpn == 1) {             //ָ��Ϊ1
			cout << "x";
		}
		else {                                             //ϵ��Ϊ1��ָ����Ϊ0,1
			cout << "x^" << sPTemp.nExpn;
		}
	}
	
	else if (sPTemp.dbCoef == -1) {           //��ϵ��Ϊ-1
		if (sPTemp.nExpn == 1) {           //ָ��Ϊ1
			cout << "-x";
		}
		else {                                     //ϵ��Ϊ-1��ָ����Ϊ0,1
			cout << "-x^" << sPTemp.nExpn;
		}
	}
	else                                         //ϵ����Ϊ1��-1��ָ��Ϊ1
	{
		if (sPTemp.nExpn == 1) {         //ϵ����Ϊ1��-1��ָ��Ϊ1��
			cout << sPTemp.dbCoef << "x";
		}
		else      //ָ����Ϊ0,1��ϵ����Ϊ-1��1
		{
			cout << sPTemp.dbCoef << "x^" << sPTemp.nExpn;
		}
	}
}

//һԪ����ʽ�������
void PrintPolyn(PLinkList sPolyn) {
	int nIndex = 0;
	PLinkList sPTemp = sPolyn->next;//sPTempָ���һ������
	while (sPTemp != NULL) {
		nIndex++;
		if (nIndex == 1) {                      //ֱ�������һ��
			PrintPoly(*sPTemp);
		}
		else if (sPTemp->dbCoef>0) {//���ϵ������0,�����+��
			cout << "+";
			PrintPoly(*sPTemp);
		}
		else {
			PrintPoly(*sPTemp);
		}
		sPTemp = sPTemp->next;
	}
}

//�ͷ�����
void FreePolyn(PLinkList sPolyn) {
	PLinkList sTemp = sPolyn;
	while (sPolyn != NULL) {
		sPolyn = sPolyn->next;
		free(sTemp);
		sTemp = sPolyn;
	}
}

//ð�ݷ�����
PLinkList ListSort(PLinkList sPolyn) {
	PLinkList sTemp1, sTemp2;//������������ʾð���������������������
	int nTemp = 0;                   //�м����
	double dbTemp = 0.0;      //�м����
	for (sTemp1 = sPolyn; sTemp1 != NULL; sTemp1 = sTemp1->next) {
		for (sTemp2 = sTemp1->next; sTemp2 != NULL; sTemp2 = sTemp2->next) {
			//���sTemp1�����ֵ���򽻻���������ָ��
			if (sTemp1->nExpn>sTemp2->nExpn) {
				nTemp = sTemp2->nExpn;
				sTemp2->nExpn = sTemp1->nExpn;
				sTemp1->nExpn = nTemp;
				dbTemp = sTemp2->dbCoef;//ͬʱ�����������ϵ��
				sTemp2->dbCoef = sTemp1->dbCoef;
				sTemp1->dbCoef = dbTemp;
			}
		}
	}
	return sPolyn;
}