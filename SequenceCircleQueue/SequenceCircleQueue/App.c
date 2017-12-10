#include<stdlib.h>
#include<stdio.h>
#include"SeqCQueue.h"

void main(void) {
	SeqCQueue SCQ;//创建队列
	int i;
	Datatype d;
	QueueInitiate(&SCQ);//初始化
	for (i = 0; i < 10; i++) {
	QueueAppend(&SCQ, i+1 );//入队列
	}
	printf("队头元素为： ");
	QueueGet(&SCQ, &d);//取队头元素
	printf("%d\n", d);                                                     //之前此处忘了写，出现没有输出结果
	printf("出队列：\n ");
	while(QueueNotEmpty(&SCQ)) {
		QueueDelete(&SCQ, &d);//出队列
		printf("%d  ", d);
	}
	printf("\n");
}