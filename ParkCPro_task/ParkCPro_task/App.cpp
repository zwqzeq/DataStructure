#include<iostream>                 
#include"Park.h"     

using namespace std;              //��׼�����ռ�

//������ں���
int main()
{
	
	Queue sqPark;//ͣ����
	Queue sqAisle;//��ʱ����
	InitQueue(sqPark, 100);	//��ʼ��ͣ����
	InitQueue(sqAisle, 10);	//��ʼ����ʱ����
	bool running = true;
	char key[10] = {0};         
	while (running) 
	{
		//����˵�
		cout << "=====ͣ��������=====" << endl;
		cout << "1�������볡" << endl;
		cout << "2�������뿪" << endl;
		cout << "3���鿴ͣ����" << endl;
		cout << "4���˳�" << endl;
		cout << "�����������ţ�1-4��:" << endl;

		cin >> key; //�����û�����

		//�����û�����
		switch (key[0]){		
		case'1'://�����볡
			InPark(sqPark, sqAisle);
		    break;
		case'2':	//�����뿪
			OutPark(sqPark, sqAisle);
			break;	
		case'3':	//�鿴ͣ����
			ViewPark(sqPark, sqAisle);
			break;
		case'4':	//�˳�
			running = false;
			cout << "�ټ���" << endl;
			break;
		default :
			cout<<"�������"<<endl;
			break;
		}
	}
	//���ٶ���
	DestoryQueue(sqPark);
	DestoryQueue(sqAisle);
	return 0;
}