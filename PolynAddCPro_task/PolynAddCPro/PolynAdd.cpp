#include <iostream>
#include <stdlib.h>
#include "structDefine.h"
#include "Polyn.h"

using namespace std;

//��������
void InputData(int nOrder, PLinkList &sPolyn);
bool GetInt(int &value);

//�������
int main() {
	cout << "/*ע��:ϵ��Ϊ��������,ָ��Ϊ����(��Ϊ��)����" << endl;
	cout << "�밴ָ����С�����˳���������ʽ*/\n\n";
	//����һԪ����ʽ
	PLinkList sPolynA = NULL;
	PLinkList sPolynB = NULL;
	PLinkList sPolynC = NULL;
	
	InputData(1, sPolynA);             //��������
	ListSort(sPolynA);                     //����
	cout << endl;                          //����
	InputData(2, sPolynB);         
	ListSort(sPolynB);                  
	cout << endl;

	//һԪ����ʽ���
	sPolynC = AddPolyn(sPolynA, sPolynB);
	cout << "����ʽ��Ϊ:";
	//��ӡ��һԪ����ʽ
	PrintPolyn(sPolynC);
	cout << endl;      //����
	//�ͷ�����
	FreePolyn(sPolynA);
	FreePolyn(sPolynB);
	FreePolyn(sPolynC);
	system("pause");           
	return 0;
}

//����һԪ����ʽ����
void InputData(int nOrder, PLinkList &sPolyn) {
	CreatePolyn(sPolyn);//����������
	PLNODE sNewNode;//�����½ڵ�
	int i, sum;          //����
	double dbCoef;//ϵ��
	int nExpn;        //ָ��
	cout << "\n�������" << nOrder << "������ʽ����:";
	GetInt(sum);    //�ж�ָ���Ƿ������������
	for (i = 1; i <= sum; i++)
	{
		cout << "�������" << i << "���ϵ��:";
		cin >> dbCoef;                              //����
		cout << "�������" << i << "���ָ��:";
		GetInt(nExpn);
		cout << endl; //����
		sNewNode.dbCoef = dbCoef;//��������
		sNewNode.nExpn = nExpn;
		ListInsert(sPolyn, sNewNode);//���½ڵ�������ʽ�����β��
	}
	//��ӡ����ʽ����
	cout << "�ö���ʽ�ɱ��Ϊ:";
	PrintPolyn(sPolyn);
}

//����Ƿ�Ϊ����
bool GetInt(int &value) {
	char str[256] = { 0 };
	fflush(stdin);//���������
	gets_s(str, 256);//�ȴ���������,�������ݴ浽str��
	unsigned int index = 1;
	int nTemp = 0;
	//�ж������Ƿ�Ϊ����
	if (str[0] == '-') {
		nTemp = 1;
	}
	//�ж�str��ÿ���ַ��Ƿ�Ϊ0��9���Ǿͼ���ѭ�������Ǿͷ���false
	for (index = nTemp; index < strlen(str); index++) {
		if (str[index] > 9 && str[index] < 0) {
			cout << "������������";
			return false;
		}
		value = atoi(str);//�ж�����ĵ��ַ������֣����ַ���ת��Ϊ������
		return true;
	}
}




