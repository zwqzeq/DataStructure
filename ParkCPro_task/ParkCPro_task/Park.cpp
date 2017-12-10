#include<iostream>
#include"Park.h"

using namespace std;

//��ʼ������
int InitQueue(Queue &q,int nSize)
{
	//�����ڴ�ռ�
	q.base = (Car*)malloc(nSize*sizeof(Car));
	if (!q.base)
	{
		//�ڴ����ʧ��
		return ERROR;
	}
	//��ʼ��˳�����
	q.front = q.rear = 0;
	q.size = nSize;
	return OK;
}

//��ö��г���
int QueueLength(Queue q)
{
	return (q.rear - q.front + q.size)%q.size;
}

//�����βԪ��
int EnQueue(Queue &q, Car car)
{
	//������
	if ((q.rear + 1) % q.size == q.front)
	{
		return ERROR;
	}
	q.base[q.rear] = car;
	q.rear = (q.rear + 1) % q.size;
	return OK;
}

//ɾ������Ԫ��
int DeQueue(Queue &q, Car &car)
{
	//���п�
	if (q.front == q.rear)
	{
		return ERROR;
	}
	car = q.base[q.front];
	q.front = (q.front + 1) % q.size;
	return OK;
}

//������̬����ռ�
int DestoryQueue(Queue &q) 
{
	//�ͷſռ�
	if (q.base)
	{
		free(q.base);
		q.base = NULL;
	}
	q.front = q.rear = 0;
	q.size = 0;
	return OK;
}

//��������Ԫ��
int QueueTraverse(Queue q)
{
	if (q.front == q.rear)
	{
		return ERROR;
	}
	int i = q.front;
	while (i != q.rear)
	{
		Car car = q.base[i];
		cout << "���ƺ��룺" << car.lisence_plate << "\t�볡ʱ�䣺" << car.time << endl;
		i = (i + 1) % q.size;
	}
	return OK;
}

//�����볡
int InPark(Queue &sqPark, Queue &sqAisle)
{
	cout << "----- ����ͣ���� -----" << endl;
	Car car;
	cout << "�����복�ƺţ�";
	cin >> car.lisence_plate;
	cout << "�����볡ʱ�䣺";
	cin >> car.time;
	if (OK == EnQueue(sqPark, car))
	{
		cout << "����ͣ����"<< QueueLength(sqPark) << "��λֵ��" << endl;
	}
	else if (OK == EnQueue(sqAisle, car))
	{
		cout << "ͣ����������������ʱ����" << QueueLength(sqAisle) << "��λֵ��" << endl;
	}
	else
	{
		cout << "û�п��೵λ���뿪ͣ������" << endl;
	}
	return 0;
}

//�����뿪
int OutPark(Queue &sqPark, Queue &sqAisle)
{
	
	cout << "----- �뿪ͣ���� -----"<<endl;
	Car car;
	if (OK == DeQueue(sqPark, car))
	{
		int time;
		cout << car.lisence_plate << "�뿪ʱ�䣺";
		cin >> time;
		int fee = (time - car.time) * 2;
		cout << "�շ�" << fee << "Ԫ" << endl;
		if (OK == DeQueue(sqAisle, car))
		{
			cout << car.lisence_plate << "�ӹ�������ͣ����" << endl;
			cout << "�������볡ʱ�䣺";
			cin >> car.time;
			EnQueue(sqPark, car);
		}	
	}
	else
		{
			cout << "ͣ����û�г��뿪��" << endl;
		}
	return 0;
}

//�鿴ͣ����
int ViewPark(Queue &sqPark, Queue &sqAisle)
{
	cout << "----- �鿴ͣ���� -----" << endl;
	//��������ͣ��������
	QueueTraverse(sqPark);
	//����������ʱ��������
	QueueTraverse(sqAisle);
	return 0;
}
