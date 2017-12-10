#define ERROR -1
#define OK 0                    //�궨��
#include<stdio.h>
#include<malloc.h>        //Ԥ����ָ��

//�������
struct Car 
{
	//����
	char lisence_plate[10];
	//����ͣ������ʱ��
	int time;
};

//ѭ������
typedef struct SqQueue
{
	//����
	Car*base;
	//��ͷָ��
	int front;
	//��βָ��
	int rear;
	//���г���
	int size;
}Queue;


//������������
//��ʼ������SqQueue
int InitQueue(Queue&q, int nSize);
//���ٶ���
int DestoryQueue(Queue &q);
//�����βԪ��
int EnQueue(Queue &q, Car car);
//��ö��г���
int QueueLength(Queue q);
//ɾ������Ԫ��
int DeQueue(Queue &q, Car &car);
//��������Ԫ��
int QueueTraverse(Queue q);
//�����볡
int InPark(Queue &sqPark, Queue &sqAisle);
//�����뿪
int OutPark(Queue &sqPark, Queue &sqAisle);
//�鿴ͣ����
int ViewPark(Queue &sqPark, Queue &sqAisle);
