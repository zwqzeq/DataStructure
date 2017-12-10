#include"SeqCQueue.h"

//���г�ʼ��
void QueueInitiate(SeqCQueue *Q) {
	 Q->rear = 0;//��β�����0                                       //֮ǰ�˴����ִ���д����int rear = 0;
	 Q->front = 0;//��ͷ�����0
	 Q->count = 0;//��������ʼ��Ϊ0
}

//���зǿշ�
int QueueNotEmpty(SeqCQueue *Q) {
	if (Q->count != 0) {
		return 1;//���зǿշ���1
	}
	return 0;//����Ϊ�շ���0
}

//�����
int QueueAppend(SeqCQueue *Q, Datatype x) {
	if (Q->count >= Max) {//����Ϊ	if (Q->count>0&&Q->rear==Q->front) 
		printf("�����������޷���ӣ�");
		return 0;//���ʧ��
	}
	Q->seqCQue[Q->rear] = x;//Ԫ�������
	Q->count++;//������Ԫ����Ŀ��һ
	(Q->rear)++;//��β�������ƶ�һλ
	if (Q->rear == Max) {
		Q->rear = 0;
	}
	return 1;//��ӳɹ�
}

/*int QueueAppend(SeqCQueue *Q, Datatype x) {
	if (Q->count > 0 && Q->rear == Q->front) {
		printf("�����������޷����룡");
		return 0;
	}
	else {
		Q->seqCQue[Q->rear] = x;
		Q->rear = (Q->rear + 1) % Max;
		Q->count++;
		return 1;
	}
}*/


//������
int  QueueDelete(SeqCQueue *Q, Datatype *d) {
	if (Q->count <= 0) {
		printf("�����ѿգ��޷������У�");
		return 0;//����ʧ��
	}
	*d = Q->seqCQue[Q->front];//�������е�Ԫ�ش�ŵ�d������
	Q->count--;//���������ݸ�����һ
	Q->front++;//��ͷ�������ƶ�һλ
	if (Q->front == Max) {
		Q->front = 0;
	}
	return 1;//���ӳɹ�
}

//ȡ��ͷԪ��
int QueueGet(SeqCQueue *Q, Datatype *d) {
	if (Q->count == 0) {
		printf("�����ѿգ��޷�ȡ��ͷ���ݣ�");
		return 0;
	}
	*d = Q->seqCQue[Q->front];//��ȡ�õĶ�ͷԪ�ش�ŵ�����d
	return 1;//ȡ��ͷԪ�سɹ�
}