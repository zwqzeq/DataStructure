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
	printf("队头元素为：%d\n", d);
	printf("出队列：");
	while (QueueNotEmpty(q)) {
		QueueDelete(&q, &d);
		printf("%d  ", d);
	}
	QueueDestroy(q);
	printf("\n");
}