#include<stdlib.h>
#include<stdio.h>
#include"SeqCQueue.h"

void main(void) {
	SeqCQueue SCQ;//��������
	int i;
	Datatype d;
	QueueInitiate(&SCQ);//��ʼ��
	for (i = 0; i < 10; i++) {
	QueueAppend(&SCQ, i+1 );//�����
	}
	printf("��ͷԪ��Ϊ�� ");
	QueueGet(&SCQ, &d);//ȡ��ͷԪ��
	printf("%d\n", d);                                                     //֮ǰ�˴�����д������û��������
	printf("�����У�\n ");
	while(QueueNotEmpty(&SCQ)) {
		QueueDelete(&SCQ, &d);//������
		printf("%d  ", d);
	}
	printf("\n");
}