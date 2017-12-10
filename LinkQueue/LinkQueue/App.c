#include"LinkQueue.h"
#include<stdio.h>

void  main(void) {
	LQueue q;
	int i;
	Datatype d;
	QueueInitiate(&q);
	for (i=0;i<10;i++)
	{
		QueueAppend(&q, i +1);
	}
	QueueGet(q, &d);
	printf("��ͷԪ��Ϊ��%d\n", d);
	printf("�����У�");
	while (QueueNotEmpty(q)) {
		QueueDelete(&q, &d);
		printf("%d  ", d);
	}
	QueueDestroy(q);
	printf("\n");
}