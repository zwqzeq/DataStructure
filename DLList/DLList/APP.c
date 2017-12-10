#include<stdio.h>
#include<malloc.h>
#include"DLList.h"

//程序入口
void main(void) {
	Dll *head;//创建头指针变量
	Datatype x=0;
	int i = 0;
	ListInitiate(&head);      //初始化
	for (i = 0; i < 10; i++) {
		DLLInsert(head,i,i+1);//插入
	}
	DLLDelete(head, 8, &x);//删除
	for (i = 0; i < ListLength(head); i++) {
		DLLGet(head, i, &x);//获取
		printf("%d    ", x);
	}
	printf("\n");
	//DLLDestroy(&head);
	void Destroy(Dll **head);
}

